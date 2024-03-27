#include <iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		mAge = 0;
		mHeight = 0.2;
		mName = "Unknown";
		mSpecies = "unknown";
	}
	Animal(std::string name, int age, double height)
		:
		mName(name)
		, mAge(age)
		, mHeight(height)
		, mSpecies("unknown")
	{
		mAge = age;
	}

	void info()
	{
		std::cout << "Species: " << mSpecies << ", Name: " << mName << ", Age: " << mAge << ", Height: " << mHeight << "\n";
	}

	//Metoda czysto wirtualna = nie mozemy utworzyc obiektu tej klasy
	virtual void przedstaw_sie() = 0;

protected:
	std::string mName;
	std::string mSpecies;
	int mAge;
	double mHeight;
};

class Dog : public Animal
{
public:
	Dog()
		:
		Animal()
	{
		mSpecies = "dog";
	}
	Dog(std::string name, int age, double height)
		:
		Animal(name, age, height)
	{
		mSpecies = "dog";
	}

	void przedstaw_sie() override
	{
		cout << "Hau hau\n";
	}
};

class Cat : public Animal
{
public:
	Cat()
		:
		Animal()
	{
		mSpecies = "cat";
	}

	Cat(std::string name, int age, double height)
		:
		Animal(name, age, height)
	{
		mSpecies = "cat";
	}

	void przedstaw_sie() override
	{
		cout << "Miau Miau\n";
	}
};


class Monkey : public Animal
{
public:
	Monkey()
		:
		Animal()
	{
		mSpecies = "primates";
	}

	Monkey(std::string name, int age, double height)
		:
		Animal(name, age, height)
	{
		mSpecies = "primates";
	}

	void przedstaw_sie() override
	{
		cout << "maup maup\n";
	}
};

int main()
{
	/*cout << "Zwierze: \n";
	Animal a("example", 5,1);
	a.info();
	a.przedstaw_sie();*/

	cout << "Pies: \n";
	Dog d("Sparky", 2, 1);
	d.info();
	d.przedstaw_sie();

	cout << "Kot: \n";
	Cat c("Fiona", 2, 1);
	c.info();
	c.przedstaw_sie();

	cout << "Monkay: \n";
	Monkey m("Banana", 2, 1);
	m.info();
	m.przedstaw_sie();



	cout << "Przedstaw sie pies jako Animal*: \n";
	

	Animal** animal_array = new Animal * [10];

	animal_array[0] = &d;
	animal_array[1] = &c;



	Animal* animal = &m;
	animal->przedstaw_sie();


	return 0;
}