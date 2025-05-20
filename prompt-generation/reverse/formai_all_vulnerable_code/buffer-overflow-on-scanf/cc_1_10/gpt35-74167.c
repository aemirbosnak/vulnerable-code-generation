//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for holding banking record information
struct BankingRecord {
    char name[50];
    int account_num;
    float balance;
};

// Function for adding a new banking record to the system
void add_record(struct BankingRecord records[], int num_records) {
    struct BankingRecord new_record;
    
    // Prompt the user for record information
    printf("Enter the name of the account holder: ");
    scanf("%s", new_record.name);
    printf("Enter the account number: ");
    scanf("%d", &new_record.account_num);
    printf("Enter the account balance: ");
    scanf("%f", &new_record.balance);
    
    // Add the new record to the array of records
    records[num_records] = new_record;
}

// Function for displaying all banking records in the system
void display_records(struct BankingRecord records[], int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %d\n", records[i].account_num);
        printf("Balance: %.2f\n", records[i].balance);
        printf("\n");
    }
}

// Function for finding the banking record with the highest balance
void find_highest_balance(struct BankingRecord records[], int num_records) {
    float highest_balance = 0;
    int highest_balance_index = -1;
    
    // Find the record with the highest balance
    for (int i = 0; i < num_records; i++) {
        if (records[i].balance > highest_balance) {
            highest_balance = records[i].balance;
            highest_balance_index = i;
        }
    }
    
    // Display the record with the highest balance
    if (highest_balance_index == -1) {
        printf("There are no records in the system.\n");
    } else {
        printf("The account with the highest balance is:\n");
        printf("Name: %s\n", records[highest_balance_index].name);
        printf("Account Number: %d\n", records[highest_balance_index].account_num);
        printf("Balance: %.2f\n", records[highest_balance_index].balance);
    }
}

int main() {
    int choice;
    int num_records = 0;
    int max_records = 10;
    struct BankingRecord records[max_records];
    
    do {
        // Display menu
        printf("Please select an option:\n");
        printf("1. Add a new banking record\n");
        printf("2. Display all banking records\n");
        printf("3. Find the account with the highest balance\n");
        printf("4. Exit\n");
        
        // Prompt for user choice
        scanf("%d", &choice);
        
        // Act on user choice
        switch (choice) {
            case 1:
                if (num_records >= max_records) {
                    printf("The system is at capacity. No more records can be added.\n");
                } else {
                    add_record(records, num_records);
                    num_records++;
                }
                break;
            case 2:
                if (num_records == 0) {
                    printf("There are no records in the system.\n");
                } else {
                    display_records(records, num_records);
                }
                break;
            case 3:
                find_highest_balance(records, num_records);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}