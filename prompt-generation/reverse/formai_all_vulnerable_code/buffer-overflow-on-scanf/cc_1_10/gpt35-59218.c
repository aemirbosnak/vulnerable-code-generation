//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h> // Standard Input/Output Functions
#include <stdlib.h> // Standard Library Functions
#include <stdbool.h> // Boolean Data Type

// Structure to hold the information of each person
typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
} Person;

// Function to print a person's information
void printPerson(Person p) {
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Gender: %c\n", p.gender);
}

int main() {
    // Declare and initialize the database as an array of Person structures
    Person database[10] = {
        { 1, "John", 25, 'M' },
        { 2, "Mary", 30, 'F' },
        { 3, "David", 21, 'M' },
        { 4, "Lisa", 27, 'F' },
        { 5, "Eric", 19, 'M' },
        { 6, "Sarah", 35, 'F' },
        { 7, "Peter", 42, 'M' },
        { 8, "Jessica", 29, 'F' },
        { 9, "Kevin", 23, 'M' },
        { 10, "Emily", 26, 'F' },
    };

    // Print the initial state of the database
    printf("Initial Database: \n");
    for (int i = 0; i < 10; i++) {
        printf("\nPerson %d:\n", i + 1);
        printPerson(database[i]);
    }

    // Prompt the user for input
    printf("\nEnter a person's ID to search for: ");
    int id;
    scanf("%d", &id);

    // Search for the person with the given ID
    bool found = false;
    for (int i = 0; i < 10; i++) {
        if (database[i].id == id) {
            printf("\nPerson found:\n");
            printPerson(database[i]);
            found = true;
            break;
        }
    }

    // If the person was not found, print an error message
    if (!found) {
        printf("\nError: Person not found in database.\n");
    }

    // Prompt the user for input
    printf("\nEnter a person's ID to delete: ");
    scanf("%d", &id);

    // Delete the person with the given ID
    found = false;
    for (int i = 0; i < 10; i++) {
        if (database[i].id == id) {
            // Shift all elements after the deleted element back one index
            for (int j = i + 1; j < 10; j++) {
                database[j - 1] = database[j];
            }
            found = true;
            break;
        }
    }

    // If the person was not found, print an error message
    if (!found) {
        printf("\nError: Person not found in database.\n");
    } else {
        // Print the updated state of the database
        printf("\nUpdated Database: \n");
        for (int i = 0; i < 9; i++) {
            printf("\nPerson %d:\n", i + 1);
            printPerson(database[i]);
        }
    }

    return 0;
}