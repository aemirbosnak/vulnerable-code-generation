//FormAI DATASET v1.0 Category: Banking Record System ; Style: scientific
// C Banking Record System Example Program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bank_record {
    char name[50];
    int account_number;
    float balance;
};

// Function to add a new record
void add_record(struct bank_record *records, int size) {
    // Get the details of the new record from the user
    printf("Enter details of the new record:\n");
    printf("Name: ");
    scanf("%s", records[size].name);
    printf("Account Number: ");
    scanf("%d", &records[size].account_number);
    printf("Balance: ");
    scanf("%f", &records[size].balance);
    printf("Record added successfully!\n");
}

// Function to display all records
void display_records(struct bank_record *records, int size) {
    printf("List of all records:\n");
    printf("Name\t\tAccount Number\t\tBalance\n");
    for(int i=0; i<size; i++) {
        printf("%-15s\t%-15d\t$%.2f\n", records[i].name, records[i].account_number, records[i].balance);
    }
}

// Function to search for a record
void search_record(struct bank_record *records, int size) {
    int account_number;
    printf("Enter account number to search for: ");
    scanf("%d", &account_number);

    for(int i=0; i<size; i++) {
        if(records[i].account_number == account_number) {
            printf("Record found!\n");
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %d\n", records[i].account_number);
            printf("Balance: $%.2f\n", records[i].balance);
            return;
        }
    }

    printf("Record not found!\n");
}

int main() {
    int choice, size=0;
    struct bank_record *records = malloc(sizeof(struct bank_record));

    do {
        // Display menu and get user choice
        printf("\n");
        printf("Menu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add a new record
                size++;
                records = realloc(records, sizeof(struct bank_record)*(size+1));
                add_record(records, size-1);
                break;
            case 2:
                // Display all records
                display_records(records, size);
                break;
            case 3:
                // Search for a record
                search_record(records, size);
                break;
            case 4:
                // Exit the program
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again!\n");
                break;
        }
    } while(choice != 4);

    free(records);
    return 0;
}