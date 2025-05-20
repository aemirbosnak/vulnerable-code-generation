//FormAI DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

void printPerson(Person p) {
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}

int main() {
    int numPeople = 3;

    Person people[numPeople];
    people[0].id = 1;
    strcpy(people[0].name, "John");
    people[0].age = 23;
    people[1].id = 2;
    strcpy(people[1].name, "Sarah");
    people[1].age = 32;
    people[2].id = 3;
    strcpy(people[2].name, "Mike");
    people[2].age = 57;

    printf("Database:\n");
    for (int i = 0; i < numPeople; i++) {
        printPerson(people[i]);
    }

    printf("\nQuerying database...\n");

    // Query by ID
    printf("Enter ID to query: ");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < numPeople; i++) {
        if (people[i].id == id) {
            printf("Result:\n");
            printPerson(people[i]);
            break;
        }
    }

    // Query by name
    printf("Enter name to query: ");
    char name[50];
    scanf("%s", name);

    for (int i = 0; i < numPeople; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Result:\n");
            printPerson(people[i]);
            break;
        }
    }

    return 0;
}