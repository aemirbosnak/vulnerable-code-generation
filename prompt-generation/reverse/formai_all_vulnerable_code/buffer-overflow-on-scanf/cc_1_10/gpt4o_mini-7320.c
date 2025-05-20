//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_RECORDS 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

void printMenu() {
    printf("Welcome to the Person Record System\n");
    printf("1. Add Person\n");
    printf("2. Display All Persons\n");
    printf("3. Search Person by Name\n");
    printf("4. Exit\n");
}

int addPerson(Person *records, int *count) {
    if (*count >= MAX_RECORDS) {
        fprintf(stderr, "Error: Maximum number of records reached.\n");
        return -1;
    }
    
    printf("Enter Name: ");
    if (scanf("%s", records[*count].name) != 1) {
        fprintf(stderr, "Error: Invalid name input.\n");
        return -1;
    }
    
    printf("Enter Age: ");
    if (scanf("%d", &records[*count].age) != 1 || records[*count].age < 0) {
        fprintf(stderr, "Error: Invalid age input.\n");
        return -1;
    }

    (*count)++;
    return 0;
}

void displayPersons(Person *records, int count) {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("Displaying all persons:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d\n", records[i].name, records[i].age);
    }
}

void searchPersonByName(Person *records, int count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    if (scanf("%s", name) != 1) {
        fprintf(stderr, "Error: Invalid name input.\n");
        return;
    }
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("Found Person: Name: %s, Age: %d\n", records[i].name, records[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Person not found!\n");
    }
}

int main() {
    Person records[MAX_RECORDS];
    int count = 0;
    int choice;

    while (1) {
        printMenu();
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                if (addPerson(records, &count) == -1) {
                    fprintf(stderr, "Failed to add new person. Please try again.\n");
                } else {
                    printf("Person added successfully.\n");
                }
                break;

            case 2:
                displayPersons(records, count);
                break;

            case 3:
                searchPersonByName(records, count);
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                fprintf(stderr, "Error: Invalid option. Please select between 1 and 4.\n");
        }
    }

    return 0;
}