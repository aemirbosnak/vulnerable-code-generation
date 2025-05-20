//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 100

typedef struct {
    char name[MAX_FIELD_SIZE];
    char address[MAX_FIELD_SIZE];
    char phone[MAX_FIELD_SIZE];
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record(char *name, char *address, char *phone) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }

    strcpy(database[num_records].name, name);
    strcpy(database[num_records].address, address);
    strcpy(database[num_records].phone, phone);

    num_records++;

    printf("Record added successfully.\n");
}

void search_record(char *name) {
    int i;

    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Name: %s\nAddress: %s\nPhone: %s\n", database[i].name, database[i].address, database[i].phone);
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    int choice;

    do {
        printf("1. Add record\n2. Search record\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", database[num_records].name);
                printf("Enter address: ");
                scanf("%s", database[num_records].address);
                printf("Enter phone: ");
                scanf("%s", database[num_records].phone);
                add_record(database[num_records].name, database[num_records].address, database[num_records].phone);
                break;

            case 2:
                printf("Enter name to search: ");
                scanf("%s", database[num_records].name);
                search_record(database[num_records].name);
                break;

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}