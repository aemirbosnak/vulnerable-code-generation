//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
} Person;

void init_person(Person* person) {
    strcpy(person->name, "");
    person->age = 0;
    person->height = 0;
}

void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %f\n", person->height);
}

int main() {
    Person* person1 = malloc(sizeof(Person));
    Person* person2 = malloc(sizeof(Person));

    init_person(person1);
    init_person(person2);

    strcpy(person1->name, "John");
    person1->age = 25;
    person1->height = 1.8;

    strcpy(person2->name, "Jane");
    person2->age = 30;
    person2->height = 1.7;

    printf("Person 1:\n");
    print_person(person1);

    printf("Person 2:\n");
    print_person(person2);

    printf("Comparing persons:\n");
    if (person1->age == person2->age) {
        printf("Both persons are the same age.\n");
    } else if (person1->age > person2->age) {
        printf("Person 1 is older than Person 2.\n");
    } else {
        printf("Person 2 is older than Person 1.\n");
    }

    if (person1->height == person2->height) {
        printf("Both persons are the same height.\n");
    } else if (person1->height > person2->height) {
        printf("Person 1 is taller than Person 2.\n");
    } else {
        printf("Person 2 is taller than Person 1.\n");
    }

    free(person1);
    free(person2);

    return 0;
}