//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the maximum number of records in the database
#define MAX_RECORDS 100

// Define a struct for a single record in the database
typedef struct {
    int id;
    char name[50];
    float salary;
} Record;

int main() {
    int num_records = 0; // track the number of records in the database
    Record database[MAX_RECORDS]; // initialize an empty database

    // While loop to prompt user for actions until they choose to exit
    while (1) {
        printf("Enter one of the following actions: add, remove, search, print, exit\n");
        char action[10];
        scanf("%s", action);

        // Add a new record to the database
        if (strcmp(action, "add") == 0) {
            if (num_records == MAX_RECORDS) {
                printf("Error: database is full\n");
            } else {
                Record new_record;
                printf("Enter ID: ");
                scanf("%d", &new_record.id);
                printf("Enter name: ");
                scanf("%s", new_record.name);
                printf("Enter salary: ");
                scanf("%f", &new_record.salary);
                database[num_records] = new_record;
                num_records++;
            }
        }

        // Remove a record from the database
        else if (strcmp(action, "remove") == 0) {
            if (num_records == 0) {
                printf("Error: database is empty\n");
            } else {
                printf("Enter ID: ");
                int id_to_remove;
                scanf("%d", &id_to_remove);
                int record_index = -1;
                for (int i = 0; i < num_records; i++) {
                    if (database[i].id == id_to_remove) {
                        record_index = i;
                        break;
                    }
                }
                if (record_index == -1) {
                    printf("Error: ID not found\n");
                } else {
                    for (int i = record_index; i < num_records - 1; i++) {
                        database[i] = database[i+1]; // shift remaining records down one index
                    }
                    num_records--;
                }
            }
        }

        // Search for a specific record by ID
        else if (strcmp(action, "search") == 0) {
            printf("Enter ID: ");
            int id_to_find;
            scanf("%d", &id_to_find);
            int record_index = -1;
            for (int i = 0; i < num_records; i++) {
                if (database[i].id == id_to_find) {
                    record_index = i;
                    break;
                }
            }
            if (record_index == -1) {
                printf("Error: ID not found\n");
            } else {
                printf("Record found:\n");
                printf("ID: %d\n", database[record_index].id);
                printf("Name: %s\n", database[record_index].name);
                printf("Salary: %.2f\n", database[record_index].salary);
            }
        }

        // Print all records in the database
        else if (strcmp(action, "print") == 0) {
            if (num_records == 0) {
                printf("Error: database is empty\n");
            } else {
                for (int i = 0; i < num_records; i++) {
                    printf("Record %d:\n", i+1);
                    printf("ID: %d\n", database[i].id);
                    printf("Name: %s\n", database[i].name);
                    printf("Salary: %.2f\n", database[i].salary);
                }
            }
        }

        // Exit the program
        else if (strcmp(action, "exit") == 0) {
            break;
        }

        // Invalid input
        else {
            printf("Error: invalid input\n");
        }
    }

    return 0;
}