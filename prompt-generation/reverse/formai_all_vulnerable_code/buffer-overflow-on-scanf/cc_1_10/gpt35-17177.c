//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records in the database
#define MAX_NAME_LENGTH 50 // Maximum length of a name in the database
#define MAX_ADDRESS_LENGTH 100 // Maximum length of an address in the database
#define MAX_PHONE_LENGTH 20 // Maximum length of a phone number in the database

struct Record {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

int num_records = 0;
struct Record records[MAX_RECORDS];

int add_record(char *name, char *address, char *phone) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return -1;
    }

    strcpy(records[num_records].name, name);
    strcpy(records[num_records].address, address);
    strcpy(records[num_records].phone, phone);

    num_records++;
    printf("Record added successfully\n");

    return 0;
}

int search_record(char *name) {
    int i;

    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("Phone: %s\n", records[i].phone);

            return i;
        }
    }

    printf("Record not found\n");

    return -1;
}

int delete_record(char *name) {
    int i, j, index;

    index = search_record(name);

    if (index == -1) {
        return -1;
    }

    for (i = index; i < num_records - 1; i++) {
        strcpy(records[i].name, records[i + 1].name);
        strcpy(records[i].address, records[i + 1].address);
        strcpy(records[i].phone, records[i + 1].phone);
    }

    num_records--;
    printf("Record deleted successfully\n");

    return 0;
}

void print_database() {
    int i;

    printf("Database:\n");

    for (i = 0; i < num_records; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Address: %s\n", records[i].address);
        printf("Phone: %s\n", records[i].phone);
        printf("\n");
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Delete record\n");
        printf("4. Print database\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter address: ");
                scanf("%s", address);
                printf("Enter phone: ");
                scanf("%s", phone);

                add_record(name, address, phone);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);

                search_record(name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);

                delete_record(name);
                break;
            case 4:
                print_database();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\n");
    }

    return 0;
}