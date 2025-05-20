//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a bank account
struct Account {
    char name[100];
    int balance;
    struct Account *next;
};

// Function to create a new account
struct Account* create_account(char name[], int balance) {
    struct Account* new_account = (struct Account*)malloc(sizeof(struct Account));
    strcpy(new_account->name, name);
    new_account->balance = balance;
    new_account->next = NULL;
    return new_account;
}

// Function to delete an account
void delete_account(struct Account* account) {
    if (account!= NULL) {
        struct Account* temp = account->next;
        free(account);
        account = temp;
    }
}

// Function to update the balance of an account
void update_balance(struct Account* account, int new_balance) {
    account->balance = new_balance;
}

// Function to deposit funds into an account
void deposit(struct Account* account, int amount) {
    account->balance += amount;
}

// Function to withdraw funds from an account
void withdraw(struct Account* account, int amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to display the balance of an account
void display_balance(struct Account* account) {
    printf("%s - %.2f\n", account->name, account->balance);
}

// Function to display all accounts in the system
void display_all_accounts(struct Account* account) {
    while (account!= NULL) {
        printf("%s - %.2f\n", account->name, account->balance);
        account = account->next;
    }
}

// Main function
int main() {
    // Create a linked list of accounts
    struct Account* accounts = NULL;
    int choice = 1;

    while (choice!= 0) {
        printf("1. Create an account\n");
        printf("2. Update the balance of an account\n");
        printf("3. Deposit funds into an account\n");
        printf("4. Withdraw funds from an account\n");
        printf("5. Display the balance of an account\n");
        printf("6. Display all accounts\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the account: ");
                scanf("%s", accounts->name);
                printf("Enter the initial balance: ");
                scanf("%d", &accounts->balance);
                accounts = create_account(accounts->name, accounts->balance);
                break;
            case 2:
                printf("Enter the name of the account: ");
                scanf("%s", accounts->name);
                printf("Enter the new balance: ");
                scanf("%d", &accounts->balance);
                update_balance(accounts, accounts->balance);
                break;
            case 3:
                printf("Enter the name of the account: ");
                scanf("%s", accounts->name);
                printf("Enter the amount to deposit: ");
                scanf("%d", &accounts->balance);
                deposit(accounts, accounts->balance);
                break;
            case 4:
                printf("Enter the name of the account: ");
                scanf("%s", accounts->name);
                printf("Enter the amount to withdraw: ");
                scanf("%d", &accounts->balance);
                withdraw(accounts, accounts->balance);
                break;
            case 5:
                printf("Enter the name of the account: ");
                scanf("%s", accounts->name);
                display_balance(accounts);
                break;
            case 6:
                display_all_accounts(accounts);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}