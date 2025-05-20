//FormAI DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 1000
#define MAX_NAME_LENGTH 50

struct Person {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
};

struct Index {
    char name[MAX_NAME_LENGTH];
    int position;
};

struct Index indexTable[MAX_INDEX];
struct Person people[MAX_INDEX];

int numPeople = 0;
int numIndexes = 0;

void addPerson() {
    printf("Enter the person's name: ");
    scanf("%s", &people[numPeople].name);

    printf("Enter the person's age: ");
    scanf("%d", &people[numPeople].age);

    people[numPeople].id = numPeople;

    int indexFound = 0;
    for (int i = 0; i < numIndexes; i++) {
        if (strcmp(indexTable[i].name, people[numPeople].name) == 0) {
            indexFound = 1;
            indexTable[i].position = numPeople;
            break;
        }
    }

    if (!indexFound) {
        strcpy(indexTable[numIndexes].name, people[numPeople].name);
        indexTable[numIndexes].position = numPeople;
        numIndexes++;
    }

    numPeople++;
    printf("Person added!\n");
}

void searchByName() {
    printf("Enter the name to search for: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < numIndexes; i++) {
        if (strcmp(indexTable[i].name, name) == 0) {
            found = 1;
            struct Person person = people[indexTable[i].position];
            printf("Found %s - Age: %d\n", person.name, person.age);
        }
    }

    if (!found) {
        printf("%s not found.\n", name);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add a person\n");
        printf("2. Search by name\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPerson();
                break;
            case 2:
                searchByName();
                break;
            case 3:
                return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
}