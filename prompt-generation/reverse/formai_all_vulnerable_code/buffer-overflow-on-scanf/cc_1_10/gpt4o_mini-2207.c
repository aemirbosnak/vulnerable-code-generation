//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PEOPLE 100

// Structure to hold information about a person
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

// Function prototypes
void addPerson(Person *people, int *currentCount);
void displayPeople(const Person *people, int count);
void freeMemory(Person *people);

int main() {
    Person *people = (Person *)malloc(MAX_PEOPLE * sizeof(Person));
    if (people == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int currentCount = 0;
    int choice;
    
    while (1) {
        printf("\n1. Add Person\n");
        printf("2. Display People\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPerson(people, &currentCount);
                break;
            case 2:
                displayPeople(people, currentCount);
                break;
            case 3:
                freeMemory(people);
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    // Free memory at the end, though we should never reach here
    freeMemory(people);
    return 0;
}

// Function to add a person to the array
void addPerson(Person *people, int *currentCount) {
    if (*currentCount >= MAX_PEOPLE) {
        printf("Cannot add more people. Maximum limit reached.\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", people[*currentCount].name);
    printf("Enter age: ");
    scanf("%d", &people[*currentCount].age);
    
    (*currentCount)++;
    printf("Person added successfully!\n");
}

// Function to display all people
void displayPeople(const Person *people, int count) {
    if (count == 0) {
        printf("No people to display.\n");
        return;
    }
    
    printf("\n--- List of People ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }
}

// Function to free allocated memory
void freeMemory(Person *people) {
    free(people);
    printf("Memory successfully freed.\n");
}