//FormAI DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

// define a C struct to hold banking record information
typedef struct {
    int account_number;
    char name[50];
    float balance;
} banking_record;

// declare array to hold banking records
banking_record records[MAX_RECORDS];

// function to add a new banking record to the array
void add_record() {
    int account_number;
    char name[50];
    float balance;
    int i;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    // check if account number already exists in array
    for (i = 0; i < MAX_RECORDS; i++) {
        if (records[i].account_number == account_number) {
            printf("Account number already exists.\n");
            return;
        }
    }

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter balance: ");
    scanf("%f", &balance);

    // add record to array
    for (i = 0; i < MAX_RECORDS; i++) {
        if (records[i].account_number == 0) {
            records[i].account_number = account_number;
            strncpy(records[i].name, name, 50);
            records[i].balance = balance;
            printf("Record added.\n");
            return;
        }
    }

    printf("Maximum number of records reached.\n");
}

// function to display all banking records in the array
void display_records() {
    int i;

    printf("Account Number\tName\t\tBalance\n");
    for (i = 0; i < MAX_RECORDS; i++) {
        if (records[i].account_number != 0) {
            printf("%d\t\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
        }
    }
}

// main function
int main() {
    int choice;

    // initialize all banking records to zero
    memset(records, 0, sizeof(records));

    while (1) {
        printf("1. Add record\n");
        printf("2. Display records\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}