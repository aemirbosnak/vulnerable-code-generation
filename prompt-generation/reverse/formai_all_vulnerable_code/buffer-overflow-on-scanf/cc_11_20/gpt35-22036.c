//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[20];
    int age;
} Record;

int main() {
    // Initialize database with empty records
    Record database[MAX_RECORDS] = {0};
    int numRecords = 0;

    // Display menu options
    printf("Welcome to the Database Simulator!\n");
    while (1) {
        printf("\n");
        printf("1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Search record\n");
        printf("4. Display all records\n");
        printf("5. Quit\n");
        printf("\nEnter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add record
                if (numRecords < MAX_RECORDS) {
                    printf("\nEnter record details:\n");
                    printf("ID: ");
                    scanf("%d", &database[numRecords].id);

                    printf("Name: ");
                    scanf("%s", database[numRecords].name);

                    printf("Age: ");
                    scanf("%d", &database[numRecords].age);

                    printf("Record added successfully!\n");
                    numRecords++;
                }
                else {
                    printf("Database has reached maximum capacity!\n");
                }
                break;

            case 2: // Delete record
                printf("\nEnter ID of record to delete: ");
                int deleteID;
                scanf("%d", &deleteID);

                int deleteIndex = -1;
                for (int i = 0; i < numRecords; i++) {
                    if (database[i].id == deleteID) {
                        deleteIndex = i;
                        break;
                    }
                }

                if (deleteIndex >= 0) {
                    for (int i = deleteIndex; i < numRecords-1; i++) {
                        database[i] = database[i+1];
                    }

                    printf("Record deleted successfully!\n");
                    numRecords--;
                }
                else {
                    printf("Record with ID %d not found!\n", deleteID);
                }
                break;

            case 3: // Search record
                printf("\nEnter ID of record to search: ");
                int searchID;
                scanf("%d", &searchID);

                int searchIndex = -1;
                for (int i = 0; i < numRecords; i++) {
                    if (database[i].id == searchID) {
                        searchIndex = i;
                        break;
                    }
                }

                if (searchIndex >= 0) {
                    printf("Record found:\n");
                    printf("ID: %d\n", database[searchIndex].id);
                    printf("Name: %s\n", database[searchIndex].name);
                    printf("Age: %d\n", database[searchIndex].age);
                }
                else {
                    printf("Record with ID %d not found!\n", searchID);
                }
                break;

            case 4: // Display all records
                printf("\nAll records:\n");
                for (int i = 0; i < numRecords; i++) {
                    printf("ID: %d\n", database[i].id);
                    printf("Name: %s\n", database[i].name);
                    printf("Age: %d\n\n", database[i].age);
                }
                break;

            case 5: // Quit
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}