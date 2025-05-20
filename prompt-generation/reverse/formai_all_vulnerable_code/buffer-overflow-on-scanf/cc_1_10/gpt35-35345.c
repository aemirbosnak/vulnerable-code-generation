//FormAI DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Structures
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// Define Constants
#define DATABASE_FILE "people.db"

// Define Functions
void addPerson();
void printPeople();
void printPerson(Person p);

// Main Function
int main() {
    int choice;
    do {
        // Menu
        printf("\n\n--- Database Program ---\n");
        printf("1. Add Person\n");
        printf("2. Print People\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Handle Choice
        switch (choice) {
            case 1:
                addPerson();
                break;
            case 2:
                printPeople();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}

// Add Person Function
void addPerson() {
    // Open File
    FILE* file = fopen(DATABASE_FILE, "ab");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    // Get Input
    Person p;
    printf("\nEnter Person Details\n");
    printf("ID: ");
    scanf("%d", &p.id);
    printf("Name: ");
    scanf("%s", p.name);
    printf("Age: ");
    scanf("%d", &p.age);

    // Write to File
    fwrite(&p, sizeof(Person), 1, file);

    // Close File
    fclose(file);

    printf("Person added to database successfully.\n");
}

// Print People Function
void printPeople() {
    // Open File
    FILE* file = fopen(DATABASE_FILE, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    // Read from File
    Person p;
    while (fread(&p, sizeof(Person), 1, file)) {
        printPerson(p);
    }

    // Close File
    fclose(file);
}

// Print Person Function
void printPerson(Person p) {
    printf("\nID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}