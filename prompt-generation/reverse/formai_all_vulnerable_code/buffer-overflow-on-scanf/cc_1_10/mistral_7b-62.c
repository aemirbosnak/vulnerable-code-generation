//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_LENGTH 50

typedef struct Record {
    char fields[MAX_FIELD_LENGTH][MAX_FIELD_LENGTH];
} Record;

Record database[MAX_RECORDS];
int current_record = 0;

void print_banner() {
    printf("\n-----------------------------------------\n");
    printf("|         Futuretech Database Simulation   |\n");
    printf("|          Version 1.0.0                |\n");
    printf("|                                       |\n");
    printf("-----------------------------------------\n");
}

void list_records() {
    if (current_record == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\nID\t| Field 1          | Field 2          | Field 3          |\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < current_record; i++) {
        printf("%d\t| %s             | %s             | %s             |\n", i+1, database[i].fields[0], database[i].fields[1], database[i].fields[2]);
    }
}

void add_record() {
    if (current_record == MAX_RECORDS) {
        printf("Database is full. Cannot add new record.\n");
        return;
    }

    printf("Enter values for the new record:\n");

    for (int i = 0; i < 3; i++) {
        printf("Field %d: ", i+1);
        scanf("%s", database[current_record].fields[i]);
    }

    current_record++;
    printf("Record added successfully.\n");
}

int main() {
    int choice;

    print_banner();

    while (1) {
        printf("\n1. List Records\n");
        printf("2. Add Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_records();
                break;
            case 2:
                add_record();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}