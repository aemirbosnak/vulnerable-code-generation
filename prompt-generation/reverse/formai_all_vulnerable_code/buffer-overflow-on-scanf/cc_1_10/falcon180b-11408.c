//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
    float weight;
} Person;

void read_person(Person *person) {
    printf("Enter your name: ");
    scanf("%s", person->name);

    printf("Enter your age: ");
    scanf("%d", &person->age);

    printf("Enter your height in meters: ");
    scanf("%f", &person->height);

    printf("Enter your weight in kilograms: ");
    scanf("%f", &person->weight);
}

void print_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Height: %0.2f meters\n", person.height);
    printf("Weight: %0.2f kilograms\n", person.weight);
}

int main() {
    Person you, partner;

    printf("Welcome to the C Fitness Tracker!\n");
    printf("This program will help you track your fitness goals and progress.\n");
    printf("Let's start by entering some information about yourself.\n");

    read_person(&you);
    printf("\n");

    printf("Now, let's enter some information about your partner.\n");
    read_person(&partner);

    printf("\n");
    printf("You and your partner are now ready to start tracking your fitness!\n");

    return 0;
}