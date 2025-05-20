//FormAI DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Define struct for a single record
typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Record;

// Declare global variables
Record db[MAX_RECORDS];
int num_records = 0;

// Function to add a new record to the database
void add_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    // Prompt user for record data
    Record new_record;
    printf("Enter name: ");
    fgets(new_record.name, 50, stdin);
    strtok(new_record.name, "\n"); // Remove newline character
    printf("Enter age: ");
    scanf("%d", &new_record.age);
    getchar(); // Clear input buffer before reading occupation
    printf("Enter occupation: ");
    fgets(new_record.occupation, 50, stdin);
    strtok(new_record.occupation, "\n"); // Remove newline character

    // Add new record to database
    db[num_records] = new_record;
    num_records++;
    printf("Record added to database.\n");
}

// Function to delete a record from the database
void delete_record() {
    // Prompt user for name of record to delete
    char name[50];
    printf("Enter name of record to delete: ");
    fgets(name, 50, stdin);
    strtok(name, "\n"); // Remove newline character
    
    // Find record in database and delete it
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(db[i].name, name) == 0) {
            int j;
            for (j = i; j < num_records - 1; j++) {
                db[j] = db[j+1];
            }
            num_records--;
            printf("Record deleted from database.\n");
            return;
        }
    }
    printf("Record not found in database.\n");
}

// Function to modify a record in the database
void modify_record() {
    // Prompt user for name of record to modify
    char name[50];
    printf("Enter name of record to modify: ");
    fgets(name, 50, stdin);
    strtok(name, "\n"); // Remove newline character
    
    // Find record in database and prompt user for new data
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(db[i].name, name) == 0) {
            printf("Enter new age: ");
            scanf("%d", &db[i].age);
            getchar(); // Clear input buffer before reading occupation
            printf("Enter new occupation: ");
            fgets(db[i].occupation, 50, stdin);
            strtok(db[i].occupation, "\n"); // Remove newline character
            printf("Record updated.\n");
            return;
        }
    }
    printf("Record not found in database.\n");
}

// Function to search for a record in the database
void search_record() {
    // Prompt user for name to search for
    char name[50];
    printf("Enter name to search for: ");
    fgets(name, 50, stdin);
    strtok(name, "\n"); // Remove newline character
    
    // Search for record in database and print data if found
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(db[i].name, name) == 0) {
            printf("Name: %s\nAge: %d\nOccupation: %s\n", db[i].name, db[i].age, db[i].occupation);
            return;
        }
    }
    printf("Record not found in database.\n");
}

// Main function
int main() {
    int choice;
    printf("Welcome to the database simulation program!\n");

    while (1) {
        // Display menu and prompt user for choice
        printf("\nPlease select an option:\n");
        printf("1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Modify record\n");
        printf("4. Search record\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        // Execute user's chosen option
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                modify_record();
                break;
            case 4:
                search_record();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}