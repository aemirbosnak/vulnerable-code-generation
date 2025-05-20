//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum size for our strings
#define MAX_NAME_LEN 50
#define MAX_PEOPLE 100

// Structure to hold information about a person
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char *bio; // Dynamic string for biography
} Person;

// Function declarations
void addPerson(Person *people, int *count);
void printPeople(const Person *people, int count);
void freeMemory(Person *people, int count);

int main() {
    Person *people = (Person *)malloc(MAX_PEOPLE * sizeof(Person));
    int count = 0;

    if (people == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    int choice;

    do {
        printf("1. Add Person\n");
        printf("2. Print People\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear the newline character from input buffer

        switch (choice) {
            case 1:
                addPerson(people, &count);
                break;
            case 2:
                printPeople(people, count);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    // Cleanup memory before exiting
    freeMemory(people, count);
    free(people);

    return EXIT_SUCCESS;
}

void addPerson(Person *people, int *count) {
    if (*count >= MAX_PEOPLE) {
        printf("Maximum number of people reached!\n");
        return;
    }

    Person *p = &people[*count];
    printf("Enter name: ");
    fgets(p->name, MAX_NAME_LEN, stdin);
    p->name[strcspn(p->name, "\n")] = 0; // Remove newline character

    printf("Enter age: ");
    scanf("%d", &p->age);
    getchar(); // clear the newline after scanf

    p->bio = (char *)malloc(256 * sizeof(char)); // allocate memory for biography
    if (p->bio == NULL) {
        fprintf(stderr, "Memory allocation for bio failed!\n");
        return;
    }

    printf("Enter biography: ");
    fgets(p->bio, 256, stdin);
    p->bio[strcspn(p->bio, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Person added successfully!\n");
}

void printPeople(const Person *people, int count) {
    if (count == 0) {
        printf("No people to display.\n");
        return;
    }

    printf("\n--- List of People ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Biography: %s\n", people[i].bio);
        printf("---------------------\n");
    }
}

void freeMemory(Person *people, int count) {
    for (int i = 0; i < count; i++) {
        free(people[i].bio); // Freeing biography memory
    }
}