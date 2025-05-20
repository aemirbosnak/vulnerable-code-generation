//FormAI DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50

typedef struct Record {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Record;

int main() {
    Record database[MAX_RECORDS];
    int num_records = 0;
    char choice;

    printf("Welcome to the Database Simulator!\n\n");

    do {
        printf("Select an option:\n");
        printf("[A]dd a new record\n");
        printf("[S]earch for a record\n");
        printf("[L]ist all records\n");
        printf("[Q]uit\n\n");

        scanf(" %c", &choice);
        printf("\n");

        switch (choice) {
            case 'A':
            case 'a':
                if (num_records >= MAX_RECORDS) {
                    printf("Error: database is full\n\n");
                } else {
                    Record new_record;

                    printf("Enter name: ");
                    scanf("%s", new_record.name);

                    printf("Enter address: ");
                    scanf("%s", new_record.address);

                    database[num_records] = new_record;

                    num_records++;

                    printf("\nRecord added successfully\n\n");
                }

                break;
            case 'S':
            case 's':
                if (num_records == 0) {
                    printf("Error: database is empty\n\n");
                    break;
                }

                char search_name[MAX_NAME_LENGTH];

                printf("Enter name to search: ");
                scanf("%s", search_name);

                int found = 0;

                for (int i = 0; i < num_records; i++) {
                    if (strcmp(search_name, database[i].name) == 0) {
                        printf("\nRecord found:\n");
                        printf("Name: %s\n", database[i].name);
                        printf("Address: %s\n\n", database[i].address);

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nRecord not found\n\n");
                }

                break;
            case 'L':
            case 'l':
                if (num_records == 0) {
                    printf("Database is empty\n\n");
                    break;
                }

                printf("All Records:\n\n");

                for (int i = 0; i < num_records; i++) {
                    printf("Record #%d:\n", i + 1);
                    printf("Name: %s\n", database[i].name);
                    printf("Address: %s\n\n", database[i].address);
                }

                break;
            case 'Q':
            case 'q':
                printf("Exiting program...\n\n");

                return 0;
            default:
                printf("Error: invalid choice\n\n");
                break;
        }
    } while (1);

    return 0;
}