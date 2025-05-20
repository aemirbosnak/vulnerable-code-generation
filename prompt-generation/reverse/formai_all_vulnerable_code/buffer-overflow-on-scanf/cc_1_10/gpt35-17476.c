//FormAI DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    int age;
    char address[50];
} Record;

void loadDatabase(Record* db, int* count) {
    // Read the database file
    FILE* file = fopen("database.txt", "r");
    if (file != NULL) {
        // Read the records from the file and add them to the database
        while (*count < MAX_RECORDS && !feof(file)) {
            fscanf(file, "%d %s %d %s", &db[*count].id, db[*count].name, &db[*count].age, db[*count].address);
            (*count)++;
        }
        fclose(file);
    }
}

void saveDatabase(Record* db, int count) {
    // Save the database to a file
    FILE* file = fopen("database.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < count; i++) {
            fprintf(file, "%d %s %d %s\n", db[i].id, db[i].name, db[i].age, db[i].address);
        }
        fclose(file);
    }
}

void printDatabase(Record* db, int count) {
    // Print the database to the console
    printf("\nID\tName\tAge\tAddress\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%s\n", db[i].id, db[i].name, db[i].age, db[i].address);
    }
}

void addRecord(Record* db, int* count) {
    // Prompt the user for the record details
    printf("\nAdding new record:\n");
    printf("Enter ID: ");
    scanf("%d", &db[*count].id);
    printf("Enter Name: ");
    scanf("%s", db[*count].name);
    printf("Enter Age: ");
    scanf("%d", &db[*count].age);
    printf("Enter Address: ");
    scanf("%s", db[*count].address);
    (*count)++;
}

void deleteRecord(Record* db, int* count) {
    // Prompt the user for the ID of the record to delete
    int id;
    printf("\nEnter ID of record to delete: ");
    scanf("%d", &id);

    // Find the record with the given ID and delete it
    for (int i = 0; i < *count; i++) {
        if (db[i].id == id) {
            // Shift the remaining records back one position to fill the gap
            for (int j = i; j < *count - 1; j++) {
                db[j] = db[j+1];
            }
            (*count)--;
            printf("Record with ID %d deleted.\n", id);
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
}

int main() {
    Record database[MAX_RECORDS];
    int count = 0;
    char choice;

    // Load the database from file if it exists
    loadDatabase(database, &count);

    printf("\nWelcome to My Happy Database!\n");

    do {
        printf("\nWhat would you like to do?\n\n");
        printf("1. Add a new record\n");
        printf("2. Delete a record\n");
        printf("3. Print the database\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addRecord(database, &count);
                break;

            case '2':
                deleteRecord(database, &count);
                break;

            case '3':
                printDatabase(database, count);
                break;

            case '4':
                // Save the database to file before exiting
                saveDatabase(database, count);
                printf("\nGoodbye! Have a happy day!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}