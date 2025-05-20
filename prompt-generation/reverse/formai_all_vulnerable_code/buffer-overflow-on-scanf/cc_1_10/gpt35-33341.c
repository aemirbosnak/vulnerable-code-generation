//FormAI DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// Function declarations
void addPerson(Person* db, int* count);
void searchById(Person* db, int count);
void searchByName(Person* db, int count);
void displayAll(Person* db, int count);

int main() {
    Person db[MAX_SIZE];
    int count = 0;
    int choice;

    do {
        printf("1. Add person\n");
        printf("2. Search by ID\n");
        printf("3. Search by name\n");
        printf("4. Display all\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPerson(db, &count);
                break;
            case 2:
                searchById(db, count);
                break;
            case 3:
                searchByName(db, count);
                break;
            case 4:
                displayAll(db, count);
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

/*
 * Function to add a person to the database.
 */
void addPerson(Person* db, int* count) {
    int id;
    char name[50];
    int age;

    printf("Enter person's ID: ");
    scanf("%d", &id);

    // Check if ID already exists
    for (int i = 0; i < *count; i++) {
        if (db[i].id == id) {
            printf("Person with ID %d already exists.\n", id);
            return;
        }
    }

    printf("Enter person's name: ");
    scanf(" %[^\n]s", name);

    printf("Enter person's age: ");
    scanf("%d", &age);

    // Add person to database
    db[*count].id = id;
    strcpy(db[*count].name, name);
    db[*count].age = age;
    (*count)++;

    printf("Person added to database successfully.\n");
}

/*
 * Function to search for a person by ID.
 */
void searchById(Person* db, int count) {
    int id;

    printf("Enter person's ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (db[i].id == id) {
            printf("Person found:\n");
            printf("ID: %d, Name: %s, Age: %d\n", db[i].id, db[i].name, db[i].age);
            return;
        }
    }

    printf("Could not find person with ID %d.\n", id);
}

/*
 * Function to search for a person by name.
 */
void searchByName(Person* db, int count) {
    char name[50];

    printf("Enter person's name: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(db[i].name, name) == 0) {
            printf("Person found:\n");
            printf("ID: %d, Name: %s, Age: %d\n", db[i].id, db[i].name, db[i].age);
            return;
        }
    }

    printf("Could not find person with name %s.\n", name);
}

/*
 * Function to display all persons in the database.
 */
void displayAll(Person* db, int count) {
    printf("ID\tName\tAge\n");
    printf("------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", db[i].id, db[i].name, db[i].age);
    }

    printf("------------------------------\n");
    printf("Found %d persons in the database.\n", count);
}