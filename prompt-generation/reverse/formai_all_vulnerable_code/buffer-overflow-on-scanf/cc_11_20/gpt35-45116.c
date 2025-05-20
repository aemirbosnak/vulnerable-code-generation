//FormAI DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct record {
    int id;
    char name[50];
    int age;
};

int main() {
    struct record database[MAX_RECORDS];
    int numRecords = 0;

    int choice;
    do {
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numRecords == MAX_RECORDS) {
                    printf("Database is full!\n");
                    break;
                }

                printf("\nEnter ID: ");
                scanf("%d", &database[numRecords].id);
                printf("Enter Name: ");
                scanf("%s", database[numRecords].name);
                printf("Enter Age: ");
                scanf("%d", &database[numRecords].age);

                numRecords++;

                printf("\nRecord added successfully!\n\n");
                break;

            case 2:
                if (numRecords == 0) {
                    printf("Database is empty!\n\n");
                    break;
                }

                printf("\nID\tName\tAge\n");
                printf("----------------------------------------\n");
                for (int i = 0; i < numRecords; i++) {
                    printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
                }
                printf("\n");

                break;

            case 3:
                if (numRecords == 0) {
                    printf("Database is empty!\n\n");
                    break;
                }

                int idToDelete, foundRecordIndex = -1;
                printf("\nEnter ID of Record to Delete: ");
                scanf("%d", &idToDelete);

                for (int i = 0; i < numRecords; i++) {
                    if (database[i].id == idToDelete) {
                        foundRecordIndex = i;
                        break;
                    }
                }

                if (foundRecordIndex == -1) {
                    printf("Record not found!\n\n");
                    break;
                }

                for (int i = foundRecordIndex; i < numRecords - 1; i++) {
                    database[i] = database[i+1];
                }

                numRecords--;

                printf("\nRecord deleted successfully!\n\n");

                break;

            case 4:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice! Please try again.\n\n");
        }

    } while (choice != 4);

    return 0;
}