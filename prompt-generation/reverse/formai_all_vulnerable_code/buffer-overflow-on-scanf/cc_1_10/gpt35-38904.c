//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for holding bank record
struct bank_record {
    char name[50];
    int account_number;
    float balance;
};

// Function to add a new bank record
void add_record(struct bank_record records[], int *count) {
    printf("Enter the name of the account holder: ");
    scanf("%s", records[*count].name);
    printf("Enter the account number: ");
    scanf("%d", &records[*count].account_number);
    printf("Enter the initial balance: ");
    scanf("%f", &records[*count].balance);
    (*count)++;
}

// Function to display all bank records
void display_records(struct bank_record records[], int count) {
    printf("\nName\t\tAccount Number\t\tBalance\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", records[i].name, records[i].account_number, records[i].balance);
    }
}

int main() {
    // Initialize bank record array with a maximum of 50 records
    struct bank_record records[50];
    int count = 0;
    int choice;

    do {
        printf("\n");
        printf("1. Add new record\n");
        printf("2. Display all records\n");
        printf("3. Exit\n");
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
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}