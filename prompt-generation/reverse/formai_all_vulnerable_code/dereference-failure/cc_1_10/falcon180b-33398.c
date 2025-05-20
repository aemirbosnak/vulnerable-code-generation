//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
    float weight;
    float bmi;
} Person;

void add_person(Person **people, int *count) {
    Person *new_person = (Person *)malloc(sizeof(Person));
    printf("Enter name: ");
    scanf("%s", new_person->name);
    printf("Enter age: ");
    scanf("%d", &new_person->age);
    printf("Enter height (in cm): ");
    scanf("%f", &new_person->height);
    printf("Enter weight (in kg): ");
    scanf("%f", &new_person->weight);
    new_person->bmi = new_person->weight / (new_person->height * new_person->height);
    (*count)++;
    *people = (Person *)realloc(*people, (*count) * sizeof(Person));
    (*people)[*count - 1] = *new_person;
}

void print_people(Person *people, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Height (in cm): %f\n", people[i].height);
        printf("Weight (in kg): %f\n", people[i].weight);
        printf("BMI: %f\n\n", people[i].bmi);
    }
}

int main() {
    Person *people = NULL;
    int count = 0;

    add_person(&people, &count);
    add_person(&people, &count);
    add_person(&people, &count);

    print_people(people, count);

    for (int i = 0; i < count; i++) {
        if (people[i].bmi > 25) {
            printf("Person %d is overweight.\n", i + 1);
        }
    }

    return 0;
}