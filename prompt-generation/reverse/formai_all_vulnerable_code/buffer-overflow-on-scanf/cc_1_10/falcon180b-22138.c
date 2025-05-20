//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Record;

int num_records = 0;
Record database[MAX_RECORDS];

void add_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", database[num_records].name);

    printf("Enter address: ");
    scanf("%s", database[num_records].address);

    num_records++;
}

void search_record() {
    printf("Enter name to search for: ");
    char search_name[MAX_NAME_LENGTH];
    scanf("%s", search_name);

    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, search_name) == 0) {
            printf("Name: %s\nAddress: %s\n", database[i].name, database[i].address);
            return;
        }
    }

    printf("No record found.\n");
}

int main() {
    printf("Welcome to the database simulation program.\n");

    while (1) {
        printf("\n1. Add record\n2. Search record\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}