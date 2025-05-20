//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100
#define RECORD_SIZE 50

struct Database {
    char records[MAX_RECORDS][RECORD_SIZE];
    int count;
};

int main() {
    struct Database database;
    database.count = 0;
    bool exit_program = false;

    while (!exit_program) {
        printf("\nMedieval Database\n");
        printf("1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Print records\n");
        printf("4. Exit\n");

        int option;
        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("Enter record: ");
            char record[RECORD_SIZE];
            scanf("%s", record);

            if (database.count >= MAX_RECORDS) {
                printf("Database is full\n");
            } else {
                strcpy(database.records[database.count], record);
                database.count++;
                printf("Record added successfully\n");
            }
        } else if (option == 2) {
            printf("Enter record to delete: ");
            char record[RECORD_SIZE];
            scanf("%s", record);

            bool found = false;
            for (int i = 0; i < database.count; i++) {
                if (strcmp(database.records[i], record) == 0) {
                    found = true;
                    for (int j = i; j < database.count - 1; j++) {
                        strcpy(database.records[j], database.records[j + 1]);
                    }
                    database.count--;
                    printf("Record deleted successfully\n");
                    break;
                }
            }
            if (!found) {
                printf("Record not found\n");
            }
        } else if (option == 3) {
            if (database.count == 0) {
                printf("Database is empty\n");
            } else {
                printf("Records in database:\n");
                for (int i = 0; i < database.count; i++) {
                    printf("%d. %s\n", i + 1, database.records[i]);
                }
            }
        } else if (option == 4) {
            exit_program = true;
        } else {
            printf("Invalid option\n");
        }
    }

    printf("Exiting program...\n");
    return 0;
}