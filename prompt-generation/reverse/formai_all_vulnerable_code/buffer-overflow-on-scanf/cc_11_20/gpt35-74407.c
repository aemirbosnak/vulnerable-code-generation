//FormAI DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATABASE_SIZE 100 // Maximum number of records in the database
#define MAX_NAME_LENGTH 20 // Maximum length of name field
#define MAX_AGE_LENGTH 3 // Maximum length of age field

typedef struct {
    char name[MAX_NAME_LENGTH];
    char age[MAX_AGE_LENGTH];
} Record;

int main() {
    // Initialize database
    Record database[MAX_DATABASE_SIZE];
    int databaseSize = 0;

    // Print menu options
    printf("Welcome to the Database Simulation Program.\n");
    printf("MENU:\n");
    printf("1. Add Record\n");
    printf("2. Print All Records\n");
    printf("3. Search Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");

    // Loop until user exits
    while (1) {
        int option;
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                // Add record
                if (databaseSize >= MAX_DATABASE_SIZE) {
                    printf("Database is full. Cannot add more records.\n");
                    break;
                }

                Record newRecord;
                printf("\nEnter name: ");
                scanf("%s", newRecord.name);
                printf("Enter age: ");
                scanf("%s", newRecord.age);
                database[databaseSize++] = newRecord;
                printf("Record added successfully.\n");
                break;
            }
            case 2: {
                // Print all records
                if (databaseSize == 0) {
                    printf("Database is empty. There are no records to print.\n");
                    break;
                }

                printf("\nAll records in the database:\n");
                printf("Name\tAge\n");
                for (int i = 0; i < databaseSize; i++) {
                    printf("%s\t%s\n", database[i].name, database[i].age);
                }
                break;
            }
            case 3: {
                // Search record
                if (databaseSize == 0) {
                    printf("Database is empty. There are no records to search.\n");
                    break;
                }

                char searchName[MAX_NAME_LENGTH];
                printf("\nEnter name to search: ");
                scanf("%s", searchName);
                int foundIndex = -1;
                for (int i = 0; i < databaseSize; i++) {
                    if (strcmp(database[i].name, searchName) == 0) {
                        foundIndex = i;
                        break;
                    }
                }
                if (foundIndex == -1) {
                    printf("Record not found.\n");
                } else {
                    printf("Record found at index %d:\n", foundIndex);
                    printf("Name\tAge\n");
                    printf("%s\t%s\n", database[foundIndex].name, database[foundIndex].age);
                }
                break;
            }
            case 4: {
                // Delete record
                if (databaseSize == 0) {
                    printf("Database is empty. There are no records to delete.\n");
                    break;
                }

                char deleteName[MAX_NAME_LENGTH];
                printf("\nEnter name to delete: ");
                scanf("%s", deleteName);
                int deleteIndex = -1;
                for (int i = 0; i < databaseSize; i++) {
                    if (strcmp(database[i].name, deleteName) == 0) {
                        deleteIndex = i;
                        break;
                    }
                }
                if (deleteIndex == -1) {
                    printf("Record not found. Cannot delete.\n");
                } else {
                    for (int i = deleteIndex; i < databaseSize - 1; i++) {
                        database[i] = database[i + 1];
                    }
                    databaseSize--;
                    printf("Record deleted successfully.\n");
                }
                break;
            }
            case 5:
                // Exit
                printf("Exiting program. Thank you!\n");
                exit(0);
            default:
                // Invalid option
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}