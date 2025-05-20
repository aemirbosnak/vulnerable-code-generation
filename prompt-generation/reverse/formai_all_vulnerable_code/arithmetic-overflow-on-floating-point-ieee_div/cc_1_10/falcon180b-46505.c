//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float weight;
    float height;
    float bmi;
} Person;

void read_person(Person *person) {
    printf("Enter your name: ");
    scanf("%s", person->name);

    printf("Enter your age: ");
    scanf("%d", &person->age);

    printf("Enter your weight (in kg): ");
    scanf("%f", &person->weight);

    printf("Enter your height (in cm): ");
    scanf("%f", &person->height);

    person->bmi = person->weight / (person->height * person->height);
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Weight: %f kg\n", person->weight);
    printf("Height: %f cm\n", person->height);
    printf("BMI: %f\n", person->bmi);
}

int main() {
    Person person;
    char choice;

    do {
        printf("\n*** Fitness Tracker ***\n");
        printf("1. Enter personal information\n");
        printf("2. Print personal information\n");
        printf("3. Calculate BMI\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                read_person(&person);
                break;
            case '2':
                print_person(&person);
                break;
            case '3':
                printf("BMI: %f\n", person.bmi);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '4');

    return 0;
}