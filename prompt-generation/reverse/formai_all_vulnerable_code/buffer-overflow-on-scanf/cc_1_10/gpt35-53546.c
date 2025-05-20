//FormAI DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the name and account number
#define MAX_NAME_LENGTH 30
#define MAX_ACC_NUM_LENGTH 10

// Struct for the bank account
typedef struct account {
    char acc_num[MAX_ACC_NUM_LENGTH];
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

// Declare global variable for the number of accounts in the system
int num_accounts = 0;
// Declare an array of accounts with a maximum of 100
Account accounts[100];

// Function to add an account to the system
void add_account() {
    // Declare variables
    char acc_num[MAX_ACC_NUM_LENGTH];
    char name[MAX_NAME_LENGTH];
    float balance;

    // Get user input for account number
    printf("Enter account number: ");
    scanf("%s", acc_num);

    // Check if the account number already exists in the system
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].acc_num, acc_num) == 0) {
            printf("Error: Account number already exists in the system.\n");
            return;
        }
    }

    // Get user input for name and balance
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter balance: ");
    scanf("%f", &balance);

    // Create a new account with the user input information
    Account new_acc;
    strcpy(new_acc.acc_num, acc_num);
    strcpy(new_acc.name, name);
    new_acc.balance = balance;

    // Add the new account to the array of accounts and increment the number of accounts
    accounts[num_accounts++] = new_acc;

    printf("Account added successfully.\n");
}

// Function to remove an account from the system
void remove_account() {
    // Declare variables
    char acc_num[MAX_ACC_NUM_LENGTH];

    // Get user input for account number
    printf("Enter account number: ");
    scanf("%s", acc_num);

    // Check if the account number exists in the system
    int index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].acc_num, acc_num) == 0) {
            index = i;
            break;
        }
    }

    // If the account number does not exist, return an error message
    if (index == -1) {
        printf("Error: Account number not found in the system.\n");
        return;
    }

    // Remove the account from the array of accounts and shift the remaining accounts up
    for (int i = index; i < num_accounts - 1; i++) {
        accounts[i] = accounts[i + 1];
    }

    // Decrement the number of accounts
    num_accounts--;

    printf("Account removed successfully.\n");
}

// Function to deposit money into an account
void deposit_money() {
    // Declare variables
    char acc_num[MAX_ACC_NUM_LENGTH];
    float amount;

    // Get user input for account number
    printf("Enter account number: ");
    scanf("%s", acc_num);

    // Check if the account number exists in the system
    int index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].acc_num, acc_num) == 0) {
            index = i;
            break;
        }
    }

    // If the account number does not exist, return an error message
    if (index == -1) {
        printf("Error: Account number not found in the system.\n");
        return;
    }

    // Get user input for amount to deposit
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    // Add the amount to the balance of the account
    accounts[index].balance += amount;

    printf("Deposit successful.\n");
}

// Function to withdraw money from an account
void withdraw_money() {
    // Declare variables
    char acc_num[MAX_ACC_NUM_LENGTH];
    float amount;

    // Get user input for account number
    printf("Enter account number: ");
    scanf("%s", acc_num);

    // Check if the account number exists in the system
    int index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].acc_num, acc_num) == 0) {
            index = i;
            break;
        }
    }

    // If the account number does not exist, return an error message
    if (index == -1) {
        printf("Error: Account number not found in the system.\n");
        return;
    }

    // Get user input for amount to withdraw
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    // Check if there is enough balance to withdraw the amount
    if (amount > accounts[index].balance) {
        printf("Error: Insufficient balance.\n");
        return;
    }

    // Subtract the amount from the balance of the account
    accounts[index].balance -= amount;

    printf("Withdrawal successful.\n");
}

// Function to display the details of an account
void display_details() {
    // Declare variable
    char acc_num[MAX_ACC_NUM_LENGTH];

    // Get user input for account number
    printf("Enter account number: ");
    scanf("%s", acc_num);

    // Check if the account number exists in the system
    int index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].acc_num, acc_num) == 0) {
            index = i;
            break;
        }
    }

    // If the account number does not exist, return an error message
    if (index == -1) {
        printf("Error: Account number not found in the system.\n");
        return;
    }

    // Display the details of the account
    printf("Account Number: %s\n", accounts[index].acc_num);
    printf("Name: %s\n", accounts[index].name);
    printf("Balance: %.2f\n", accounts[index].balance);
}

// Function to display the details of all accounts in the system
void display_all_details() {
    // If there are no accounts in the system, return an error message
    if (num_accounts == 0) {
        printf("Error: No accounts in the system.\n");
        return;
    }

    // Display the details of all accounts in the system
    for (int i = 0; i < num_accounts; i++) {
        printf("Account Number: %s\n", accounts[i].acc_num);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("\n");
    }
}

// Main function to run the program
int main() {
    // Display the menu options to the user
    printf("Welcome to the Banking Record System!\n");
    printf("1. Add Account\n");
    printf("2. Remove Account\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Display Account Details\n");
    printf("6. Display All Account Details\n");
    printf("0. Exit\n\n");

    // Declare variable for user input
    int choice;

    // Loop until the user chooses to exit
    while (1) {
        // Get user input for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Based on the choice, call the appropriate function
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                remove_account();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                display_details();
                break;
            case 6:
                display_all_details();
                break;
            case 0:
                printf("Exiting Banking Record System. Thank you for using our system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }

        printf("\n");
    }

    return 0;
}