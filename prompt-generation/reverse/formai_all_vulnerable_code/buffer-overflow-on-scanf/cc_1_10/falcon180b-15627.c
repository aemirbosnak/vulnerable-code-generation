//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Defining structures
typedef struct {
    char name[50];
    int age;
    int height;
    int weight;
} Person;

typedef struct {
    char name[50];
    int age;
    int height;
    int weight;
    int bmi;
} PersonBMI;

// Defining functions
void createPerson(Person *person) {
    printf("Enter name: ");
    scanf("%s", person->name);
    printf("Enter age: ");
    scanf("%d", &person->age);
    printf("Enter height (in cm): ");
    scanf("%d", &person->height);
    printf("Enter weight (in kg): ");
    scanf("%d", &person->weight);
}

void displayPerson(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Height (in cm): %d\n", person.height);
    printf("Weight (in kg): %d\n", person.weight);
}

void calculateBMI(PersonBMI *personBMI) {
    personBMI->bmi = (personBMI->weight / (personBMI->height * personBMI->height)) * 10000;
}

void displayPersonBMI(PersonBMI personBMI) {
    printf("Name: %s\n", personBMI.name);
    printf("Age: %d\n", personBMI.age);
    printf("Height (in cm): %d\n", personBMI.height);
    printf("Weight (in kg): %d\n", personBMI.weight);
    printf("BMI: %.2f\n", personBMI.bmi / 10000);
}

int main() {
    srand(time(NULL));
    int numPeople;
    printf("Enter number of people: ");
    scanf("%d", &numPeople);

    Person people[numPeople];
    for (int i = 0; i < numPeople; i++) {
        createPerson(&people[i]);
    }

    for (int i = 0; i < numPeople; i++) {
        displayPerson(people[i]);
    }

    PersonBMI personBMIs[numPeople];
    for (int i = 0; i < numPeople; i++) {
        calculateBMI(&personBMIs[i]);
    }

    for (int i = 0; i < numPeople; i++) {
        displayPersonBMI(personBMIs[i]);
    }

    return 0;
}