//FormAI DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define our structure for bank records
typedef struct {
    char name[50];
    int account_number;
    float balance;
} bank_record;

// function to add a new record to the database
void add_record(bank_record records[], int *num_records) {
    // create a temporary record
    bank_record temp;
    
    printf("Please enter the customer name:\n");
    scanf("%s", temp.name);
    
    printf("Please enter the account number:\n");
    scanf("%d", &temp.account_number);
    
    printf("Please enter the balance:\n");
    scanf("%f", &temp.balance);
    
    // add the record to the array
    records[*num_records] = temp;
    
    // increment the number of records
    *num_records = *num_records + 1;
    
    printf("Record added successfully!\n");
}

// function to display all records in the database
void display_records(bank_record records[], int num_records) {
    int i;
    
    printf("=====================\n");
    printf("BANKING RECORD SYSTEM\n");
    printf("=====================\n");
    
    // loop through each record in the array and display its contents
    for (i = 0; i < num_records; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %d\n", records[i].account_number);
        printf("Balance: %.2f\n\n", records[i].balance);
    }
}

// function to search for a record by account number
void search_by_account_number(bank_record records[], int num_records) {
    int account_number, i;
    
    printf("Please enter the account number:\n");
    scanf("%d", &account_number);
    
    // loop through each record in the array
    for (i = 0; i < num_records; i++) {
        // check if the account number matches
        if (records[i].account_number == account_number) {
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %d\n", records[i].account_number);
            printf("Balance: %.2f\n", records[i].balance);
            
            // exit the loop since we found a match
            return;
        }
    }
    
    // if we get here, we didn't find a match
    printf("No record found with that account number.\n");
}

// function to calculate the total balance of all records
float calculate_total_balance(bank_record records[], int num_records) {
    int i;
    float total_balance = 0.0;
    
    // loop through each record in the array and add its balance to the total
    for (i = 0; i < num_records; i++) {
        total_balance = total_balance + records[i].balance;
    }
    
    return total_balance;
}

int main() {
    int choice, num_records = 0;
    bank_record records[100];
    
    while (1) {
        printf("Banking Record System\n");
        printf("=====================\n");
        printf("1. Add new record\n");
        printf("2. Display all records\n");
        printf("3. Search for record\n");
        printf("4. Calculate total balance\n");
        printf("5. Exit\n");
        
        printf("Please enter your choice (1-5):\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                display_records(records, num_records);
                break;
            case 3:
                search_by_account_number(records, num_records);
                break;
            case 4:
                printf("Total Balance: %.2f\n", calculate_total_balance(records, num_records));
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}