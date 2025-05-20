//FormAI DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000 // Maximum number of accounts
#define NAME_LENGTH 50 // Maximum length of account name
#define MAX_TRANSACTIONS 50 // Maximum number of transactions per account

// Structure to hold information about a single transaction
typedef struct {
    float amount;
    char description[100];
} transaction;

// Structure to hold information about a single account
typedef struct {
    int number;
    char name[NAME_LENGTH];
    float balance;
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} account;

account accounts[MAX_ACCOUNTS]; // Array of accounts
int num_accounts = 0; // Number of accounts in the array

// Function to print the menu options
void print_menu() {
    printf("===== Banking Record System =====\n");
    printf("1. Create a new account\n");
    printf("2. View account details\n");
    printf("3. Add a transaction to an account\n");
    printf("4. Print all accounts\n");
    printf("5. Quit\n");
    printf("Enter an option number: ");
}

// Function to create a new account
void create_account() {
    printf("Enter account name: ");
    char name[NAME_LENGTH];
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove the newline character
    float balance;
    printf("Enter starting balance: ");
    scanf("%f", &balance);
    getchar(); // Remove the newline character from the input buffer
    account new_account;
    new_account.number = num_accounts + 1;
    strcpy(new_account.name, name);
    new_account.balance = balance;
    new_account.num_transactions = 0;
    accounts[num_accounts] = new_account;
    num_accounts++;
    printf("Account created successfully.\n");
}

// Function to view the details of a single account
void view_account() {
    printf("Enter account number: ");
    int account_number;
    scanf("%d", &account_number);
    getchar(); // Remove the newline character from the input buffer
    account *acc = NULL;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].number == account_number) {
            acc = &accounts[i];
            break;
        }
    }
    if (acc == NULL) {
        printf("Account not found.\n");
        return;
    }
    printf("Account number: %d\n", acc->number);
    printf("Account name: %s\n", acc->name);
    printf("Account balance: %.2f\n", acc->balance);
    printf("Transaction history:\n");
    if (acc->num_transactions == 0) {
        printf("    No transactions.\n");
    } else {
        for (int i = 0; i < acc->num_transactions; i++) {
            printf("    Transaction %d: %.2f - %s\n", i+1, acc->transactions[i].amount, acc->transactions[i].description);
        }
    }
}

// Function to add a transaction to an account
void add_transaction() {
    printf("Enter account number: ");
    int account_number;
    scanf("%d", &account_number);
    getchar(); // Remove the newline character from the input buffer
    account *acc = NULL;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].number == account_number) {
            acc = &accounts[i];
            break;
        }
    }
    if (acc == NULL) {
        printf("Account not found.\n");
        return;
    }
    printf("Enter transaction amount: ");
    float amount;
    scanf("%f", &amount);
    getchar(); // Remove the newline character from the input buffer
    printf("Enter transaction description: ");
    char description[100];
    fgets(description, 100, stdin);
    description[strcspn(description, "\n")] = 0; // Remove the newline character
    transaction new_transaction;
    new_transaction.amount = amount;
    strcpy(new_transaction.description, description);
    acc->transactions[acc->num_transactions] = new_transaction;
    acc->num_transactions++;
    acc->balance += amount; // Update the account balance
    printf("Transaction added successfully.\n");
}

// Function to print details of all accounts
void print_all_accounts() {
    printf("===== All Accounts =====\n");
    if (num_accounts == 0) {
        printf("No accounts found.\n");
    } else {
        for (int i = 0; i < num_accounts; i++) {
            printf("Account number: %d\n", accounts[i].number);
            printf("Account name: %s\n", accounts[i].name);
            printf("Account balance: %.2f\n", accounts[i].balance);
            printf("Transaction history:\n");
            if (accounts[i].num_transactions == 0) {
                printf("    No transactions.\n");
            } else {
                for (int j = 0; j < accounts[i].num_transactions; j++) {
                    printf("    Transaction %d: %.2f - %s\n", j+1, accounts[i].transactions[j].amount, accounts[i].transactions[j].description);
                }
            }
        }
    }
}

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // Remove the newline character from the input buffer
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                view_account();
                break;
            case 3:
                add_transaction();
                break;
            case 4:
                print_all_accounts();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}