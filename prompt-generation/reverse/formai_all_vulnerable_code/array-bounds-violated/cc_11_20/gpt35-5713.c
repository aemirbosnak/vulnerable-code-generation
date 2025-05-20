//FormAI DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records in the database

typedef struct {
    int id;
    char name[50];
    int age;
} Record;

Record database[MAX_RECORDS]; // Database array
int num_records = 0; // Number of records in the database

int main() {
    char input[50];
    while (1) {
        printf("Enter command: ");
        fgets(input, 50, stdin);
        input[strlen(input)-1] = '\0'; // Remove trailing newline

        // Insert record
        if (strncmp(input, "INSERT", 6) == 0) {
            char name[50];
            int age;
            sscanf(input, "INSERT %s %d", name, &age);
            Record record = {num_records, name, age};
            if (num_records == MAX_RECORDS) {
                printf("Database is full!\n");
            } else {
                database[num_records] = record;
                num_records++;
                printf("Record added with ID %d.\n", record.id);
            }
        }
        // Delete record
        else if (strncmp(input, "DELETE", 6) == 0) {
            int id;
            sscanf(input, "DELETE %d", &id);
            if (id >= num_records || id < 0) {
                printf("Invalid ID!\n");
            } else {
                for (int i = id; i < num_records-1; i++) {
                    database[i] = database[i+1];
                }
                num_records--;
                printf("Record deleted.\n");
            }
        }
        // Show all records
        else if (strcmp(input, "SHOW ALL") == 0) {
            printf("ID\tName\tAge\n");
            for (int i = 0; i < num_records; i++) {
                Record record = database[i];
                printf("%d\t%s\t%d\n", record.id, record.name, record.age);
            }
        }
        // Show record with specific ID
        else if (strncmp(input, "SHOW", 4) == 0) {
            int id;
            sscanf(input, "SHOW %d", &id);
            if (id >= num_records || id < 0) {
                printf("Invalid ID!\n");
            } else {
                Record record = database[id];
                printf("ID\tName\tAge\n");
                printf("%d\t%s\t%d\n", record.id, record.name, record.age);
            }
        }
        // Exit program
        else if (strcmp(input, "EXIT") == 0) {
            printf("Exiting...\n");
            break;
        }
        // Invalid command
        else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}