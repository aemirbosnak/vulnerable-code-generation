//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int age;
    float weight;
    int height;
    float bmi;
} Person;

void addPerson(Person *people, int *numPeople) {
    char name[50];
    int age;
    float weight, height;
    float bmi;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter weight (in kg): ");
    scanf("%f", &weight);

    printf("Enter height (in cm): ");
    scanf("%f", &height);

    bmi = weight / (height / 100) * 100;

    strcpy(people[*numPeople].name, name);
    people[*numPeople].age = age;
    people[*numPeople].weight = weight;
    people[*numPeople].height = height;
    people[*numPeople].bmi = bmi;

    (*numPeople)++;
}

void displayPerson(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Weight (in kg): %f\n", person.weight);
    printf("Height (in cm): %f\n", person.height);
    printf("BMI: %f\n\n", person.bmi);
}

void displayAllPeople(Person people[], int numPeople) {
    int i;

    for (i = 0; i < numPeople; i++) {
        displayPerson(people[i]);
    }
}

int main() {
    Person people[MAX_SIZE];
    int numPeople = 0;

    while (numPeople < MAX_SIZE) {
        printf("Enter 1 to add a person, 0 to exit: ");
        scanf("%d", &numPeople);

        if (numPeople == 1) {
            addPerson(people, &numPeople);
        }
    }

    printf("All people:\n");
    displayAllPeople(people, numPeople);

    return 0;
}