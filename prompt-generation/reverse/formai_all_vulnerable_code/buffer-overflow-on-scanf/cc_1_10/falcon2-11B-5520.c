//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bank account
typedef struct {
    int account_number;
    char account_holder[20];
    int balance;
} Account;

// Function to initialize a new account
Account* create_account(int account_number, char account_holder[]) {
    Account* new_account = (Account*)malloc(sizeof(Account));
    if (new_account == NULL) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }
    new_account->account_number = account_number;
    strncpy(new_account->account_holder, account_holder, sizeof(new_account->account_holder));
    new_account->balance = 0;
    return new_account;
}

// Function to deposit money into an account
void deposit(Account* account, int amount) {
    if (amount < 0) {
        printf("Invalid deposit amount\n");
        return;
    }
    account->balance += amount;
    printf("Deposit of $%d successful\n", amount);
}

// Function to withdraw money from an account
void withdraw(Account* account, int amount) {
    if (amount < 0) {
        printf("Invalid withdrawal amount\n");
        return;
    }
    if (amount > account->balance) {
        printf("Insufficient funds\n");
        return;
    }
    account->balance -= amount;
    printf("Withdrawal of $%d successful\n", amount);
}

// Function to display account information
void display_account(Account* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Account Holder: %s\n", account->account_holder);
    printf("Balance: $%d\n", account->balance);
}

// Main function
int main() {
    int account_number, choice, amount;
    char account_holder[20];

    printf("Welcome to the Bank!\n");
    printf("Please enter your account number: ");
    scanf("%d", &account_number);
    Account* account = create_account(account_number, account_holder);

    while (1) {
        printf("1. Deposit\n2. Withdraw\n3. Display Account\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the deposit amount: ");
                scanf("%d", &amount);
                deposit(account, amount);
                break;
            case 2:
                printf("Enter the withdrawal amount: ");
                scanf("%d", &amount);
                withdraw(account, amount);
                break;
            case 3:
                display_account(account);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free(account);
    return 0;
}