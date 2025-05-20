//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int height;
    int weight;
} Person;

void createPerson(Person *person, char *name, int age, int height, int weight) {
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    person->height = height;
    person->weight = weight;
}

void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %d\n", person->height);
    printf("Weight: %d\n", person->weight);
}

bool searchPerson(Person *people, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found person with name %s!\n", name);
            printPerson(&people[i]);
            return true;
        }
    }
    printf("No person found with name %s.\n", name);
    return false;
}

int main() {
    Person people[MAX_SIZE];
    int size = 0;

    while (size < MAX_SIZE) {
        char name[50];
        int age, height, weight;

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter height: ");
        scanf("%d", &height);

        printf("Enter weight: ");
        scanf("%d", &weight);

        createPerson(&people[size], name, age, height, weight);
        size++;
    }

    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    searchPerson(people, size, searchName);

    return 0;
}