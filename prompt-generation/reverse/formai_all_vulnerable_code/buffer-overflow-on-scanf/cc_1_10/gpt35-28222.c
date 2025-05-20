//FormAI DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// structure to hold banking record
typedef struct {
    char name[50];
    int account_number;
    float balance;
} BankRecord;

// function to add a new record
void add_record(BankRecord *records, int num_records) {
    printf("\nAdding new record...\n");
    printf("Enter name: ");
    scanf("%s", records[num_records].name);
    printf("Enter account number: ");
    scanf("%d", &records[num_records].account_number);
    printf("Enter balance: ");
    scanf("%f", &records[num_records].balance);

    printf("Record added successfully!\n");
}

// function to print all records
void print_records(BankRecord *records, int num_records) {
    printf("\nPrinting all records...\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\nName: %s\nAccount number: %d\nBalance: %.2f\n\n", 
               i + 1, records[i].name, records[i].account_number, records[i].balance);
    }
}

int main() {
    int num_records = 0; // number of existing records
    int choice;

    // allocate memory for initial set of records
    BankRecord *records = (BankRecord*) malloc(sizeof(BankRecord));

    printf("Welcome to the Happy Bank record system!\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new record\n");
        printf("2. Print all records\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, num_records);
                num_records++;
                // re-allocate memory for record array with additional space
                records = (BankRecord*) realloc(records, (num_records + 1) * sizeof(BankRecord));
                break;
            case 2:
                print_records(records, num_records);
                break;
            case 3:
                printf("Thank you for using the Happy Bank record system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    // free memory allocated for records array
    free(records);

    return 0;
}