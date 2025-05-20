//FormAI DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the bank account record
typedef struct bank_account {
    int account_number;
    char account_holder_name[50];
    float balance;
} bank_account;

// Define the function prototypes
void add_account();
void display_account();
void update_account();
void delete_account();

// Global variables
bank_account accounts[50]; // array to hold bank accounts records
int num_of_accounts = 0; // variable to keep track of number of bank accounts records

// Main function
int main() {
    int choice;
  
    do {
        // Display menu
        printf("\n\n------------------ Bank Account Record System -------------------\n");
        printf("1. Add an Account\n");
        printf("2. Display an Account\n");
        printf("3. Update an Account\n");
        printf("4. Delete an Account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
      
        // Read in user choice
        scanf("%d", &choice);
        
        // Perform the selected operation
        switch(choice) {
            case 1: add_account(); break;
            case 2: display_account(); break;
            case 3: update_account(); break;
            case 4: delete_account(); break;
            case 5: exit(0); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    
    } while (1);
}

// Function to add a new bank account record
void add_account() {
    // Check if the number of bank account records has exceeded the maximum capacity
    if (num_of_accounts == 50) {
        printf("The maximum number of bank account records have been added.\n");
        return;
    }
    
    // Ask user for account details
    int account_number;
    char account_holder_name[50];
    float balance;
    
    printf("\nEnter new account details:\n");
    printf("Account Number: ");
    scanf("%d", &account_number);
    printf("Name of Account Holder: ");
    scanf("%s", account_holder_name);
    printf("Balance: $");
    scanf("%f", &balance);
    
    // Add the new account to the array of records
    accounts[num_of_accounts].account_number = account_number;
    strcpy(accounts[num_of_accounts].account_holder_name, account_holder_name);
    accounts[num_of_accounts].balance = balance;
    num_of_accounts++;
    
    printf("New Bank Account added successfully.\n");
}

// Function to display the details of an existing bank account record
void display_account() {
    // Ask user for the account number to be displayed
    int account_number;
    
    printf("\nEnter the Account Number you want to display: ");
    scanf("%d", &account_number);
    
    // Search for the account number in the array of records
    int i, account_found = 0;
    
    for (i = 0; i < num_of_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("\nAccount Number: %d\n", accounts[i].account_number);
            printf("Name of Account Holder: %s\n", accounts[i].account_holder_name);
            printf("Balance: $%.2f\n", accounts[i].balance);
            account_found = 1;
            break;
        }
    }
    
    if (!account_found) {
        printf("Account Number %d not found.\n", account_number);
    }
}

// Function to update the details of an existing bank account record
void update_account() {
    // Ask user for the account number to be updated
    int account_number;
    
    printf("\nEnter the Account Number you want to update: ");
    scanf("%d", &account_number);
    
    // Search for the account number in the array of records
    int i, account_found = 0;
    
    for (i = 0; i < num_of_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            // Ask user for the new account details
            char account_holder_name[50];
            float balance;
            
            printf("\nUpdate account details:\n");
            printf("Name of Account Holder: ");
            scanf("%s", account_holder_name);
            printf("Balance: $");
            scanf("%f", &balance);
            
            // Update the account details
            strcpy(accounts[i].account_holder_name, account_holder_name);
            accounts[i].balance = balance;
            account_found = 1;
            
            printf("Bank Account details updated successfully.\n");
            break;
        }
    }
    
    if (!account_found) {
        printf("Account Number %d not found.\n", account_number);
    }
}

// Function to delete an existing bank account record
void delete_account() {
    // Ask user for the account number to be deleted
    int account_number;
    
    printf("\nEnter the Account Number you want to delete: ");
    scanf("%d", &account_number);
    
    // Search for the account number in the array of records
    int i, account_found = 0;
    
    for (i = 0; i < num_of_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            // Shift the remaining records back by one position to fill the gap
            for (; i < num_of_accounts - 1; i++) {
                accounts[i] = accounts[i + 1];
            }
            
            num_of_accounts--;
            account_found = 1;
            
            printf("Bank Account deleted successfully.\n");
            break;
        }
    }
    
    if (!account_found) {
        printf("Account Number %d not found.\n", account_number);
    }
}