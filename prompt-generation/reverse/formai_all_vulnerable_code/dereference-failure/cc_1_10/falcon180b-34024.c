//Falcon-180B DATASET v1.0 Category: Memory management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    Person *people = NULL;
    int numPeople = 0;
    char input[MAX_SIZE];

    while (1) {
        printf("Enter name and age (or 'done' to finish): ");
        fgets(input, MAX_SIZE, stdin);

        if (strcmp(input, "done") == 0) {
            break;
        }

        Person *newPerson = (Person *)malloc(sizeof(Person));
        if (newPerson == NULL) {
            printf("Error: Out of memory\n");
            return 1;
        }

        newPerson->name = strdup(input);
        sscanf(input, "%s %d", input, &newPerson->age);

        people = (Person *)realloc(people, sizeof(Person) * (numPeople + 1));
        if (people == NULL) {
            printf("Error: Out of memory\n");
            return 1;
        }

        people[numPeople] = *newPerson;
        numPeople++;
    }

    printf("Number of people: %d\n", numPeople);

    for (int i = 0; i < numPeople; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n\n", people[i].age);
    }

    free(people);
    return 0;
}