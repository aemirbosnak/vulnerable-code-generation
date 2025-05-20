//FormAI DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// structure for bank account record
struct record {
    char account_no[20];
    char name[50];
    char address[100];
    int balance;
};

// function to add records to the system
void add_record(struct record *records, int *count) {
    char account_no[20];
    char name[50];
    char address[100];
    int balance;

    // get input from the user
    printf("Enter account number: ");
    scanf("%s", account_no);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter address: ");
    scanf("%s", address);
    printf("Enter balance: ");
    scanf("%d", &balance);

    // add record to the system
    strcpy(records[*count].account_no, account_no);
    strcpy(records[*count].name, name);
    strcpy(records[*count].address, address);
    records[*count].balance = balance;

    // increment record count
    (*count)++;

    printf("Record added successfully!\n");
}

// function to display all records in the system
void display_records(struct record *records, int count) {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }

    printf("Account No.\tName\tAddress\tBalance\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%s\t%d\n", records[i].account_no, records[i].name, records[i].address, records[i].balance);
    }
}

// main function
int main() {
    struct record records[MAX];
    int count = 0;

    while (1) {
        // show menu
        printf("\n1. Add record\n");
        printf("2. Display all records\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                display_records(records, count);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}