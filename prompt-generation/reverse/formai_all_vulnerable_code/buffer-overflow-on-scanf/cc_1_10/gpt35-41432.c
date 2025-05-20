//FormAI DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a bank record
struct record {
    int account_number;
    char first_name[20];
    char last_name[20];
    int balance;
};

// Function to add a new record
void addrecord(struct record *records, int *num_records) {
    printf("Enter account number: ");
    scanf("%d", &(records[*num_records].account_number));
    printf("Enter first name: ");
    scanf("%s", records[*num_records].first_name);
    printf("Enter last name: ");
    scanf("%s", records[*num_records].last_name);
    printf("Enter balance: ");
    scanf("%d", &(records[*num_records].balance));
    (*num_records)++;
}

// Function to remove a record
void remrecord(struct record *records, int *num_records) {
    int account_number, i, found = 0;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (i = 0; i < *num_records; i++) {
        if (records[i].account_number == account_number) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < *num_records - 1; i++) {
            records[i] = records[i+1];
        }
        (*num_records)--;
        printf("Record removed.\n");
    } else {
        printf("Record not found.\n");
    }
}

// Function to print all records
void printrecords(struct record *records, int *num_records) {
    int i;
    printf("Account | First Name | Last Name | Balance\n");
    for (i = 0; i < *num_records; i++) {
        printf("%d | %s | %s | %d\n", records[i].account_number, records[i].first_name,
               records[i].last_name, records[i].balance);
    }
}

int main() {
    struct record records[20] = {};
    int num_records = 0, input;
    do {
        printf("1. Add record\n");
        printf("2. Remove record\n");
        printf("3. Print all records\n");
        printf("4. Exit\n");
        printf("Enter input: ");
        scanf("%d", &input);
        switch (input) {
            case 1:
                addrecord(records, &num_records);
                break;
            case 2:
                remrecord(records, &num_records);
                break;
            case 3:
                printrecords(records, &num_records);
                break;
            default:
                printf("Invalid input.\n");
        }
    } while (input != 4);
    return 0;
}