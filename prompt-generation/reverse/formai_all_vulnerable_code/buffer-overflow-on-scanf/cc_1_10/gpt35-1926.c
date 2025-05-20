//FormAI DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 20
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_ADDRESS_LENGTH];
};

void read_input(struct Record *record) {
    printf("Enter ID: ");
    scanf("%d", &record->id);
    printf("Enter Name: ");
    scanf("%s", record->name);
    printf("Enter Age: ");
    scanf("%d", &record->age);
    printf("Enter Address: ");
    scanf("%s", record->address);
}

void print_record(struct Record *record) {
    printf("ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    printf("Address: %s\n", record->address);
}

int main() {
    struct Record db[MAX_RECORDS] = {
        {1, "John Doe", 25, "123 Main St."},
        {2, "Jane Smith", 30, "456 Elm St."}
    };
    int num_records = 2;
    char input[10];

    while (1) {
        printf("Enter command (add, find, list, or quit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            if (num_records >= MAX_RECORDS) {
                printf("Database is full!\n");
            } else {
                struct Record new_record;
                read_input(&new_record);
                db[num_records++] = new_record;
                printf("Record added.\n");
            }
        } else if (strcmp(input, "find") == 0) {
            int id;
            printf("Enter ID to find: ");
            scanf("%d", &id);
            int found = 0;
            for (int i = 0; i < num_records; i++) {
                if (db[i].id == id) {
                    print_record(&db[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Record not found.\n");
            }
        } else if (strcmp(input, "list") == 0) {
            for (int i = 0; i < num_records; i++) {
                print_record(&db[i]);
            }
        } else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}