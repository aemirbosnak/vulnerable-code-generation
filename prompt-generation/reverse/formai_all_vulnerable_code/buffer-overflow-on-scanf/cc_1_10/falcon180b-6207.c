//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_RECORDS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_NAME_LENGTH];
} record_t;

record_t database[MAX_NUM_RECORDS];
int num_records = 0;

void add_record(char* name, int age, char* address) {
    if (num_records >= MAX_NUM_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }

    strcpy(database[num_records].name, name);
    database[num_records].age = age;
    strcpy(database[num_records].address, address);

    num_records++;
}

void search_record(char* name) {
    int i;

    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Address: %s\n", database[i].address);
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nDatabase Menu:\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", database[num_records].name);
                printf("Enter age: ");
                scanf("%d", &database[num_records].age);
                printf("Enter address: ");
                scanf("%s", database[num_records].address);
                break;

            case 2:
                printf("Enter name to search: ");
                scanf("%s", database[num_records].name);
                search_record(database[num_records].name);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}