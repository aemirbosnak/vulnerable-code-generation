//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PEOPLE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

void displayMenu();
void addPerson(Person* people, int* count);
void displayPeople(const Person* people, int count);
void freeMemory(Person* people);

int main() {
    Person* people = (Person*)malloc(MAX_PEOPLE * sizeof(Person));
    if (people == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    int count = 0;
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPerson(people, &count);
                break;
            case 2:
                displayPeople(people, count);
                break;
            case 3:
                freeMemory(people);
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    freeMemory(people);
    return 0;
}

void displayMenu() {
    printf("\n--- People Management Program ---\n");
    printf("1. Add Person\n");
    printf("2. Display People\n");
    printf("3. Exit\n");
}

void addPerson(Person* people, int* count) {
    if (*count >= MAX_PEOPLE) {
        printf("Reached maximum number of people. Cannot add more.\n");
        return;
    }

    Person newPerson;
    printf("Enter name: ");
    scanf("%s", newPerson.name); // Note: scanf may cause buffer overflow; in real usage, prefer safer functions.
    
    printf("Enter age: ");
    scanf("%d", &newPerson.age);
    
    people[*count] = newPerson;
    (*count)++;
    printf("Person added successfully!\n");
}

void displayPeople(const Person* people, int count) {
    if (count == 0) {
        printf("No people to display.\n");
        return;
    }
    
    printf("\n--- List of People ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }
}

void freeMemory(Person* people) {
    if (people != NULL) {
        free(people);
        printf("Memory freed successfully.\n");
    }
}