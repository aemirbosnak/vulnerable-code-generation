//FormAI DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a bank account
struct account {
    char name[50];
    int account_number;
    float balance;
};

// Function to add a new account to the record system
void add_account(struct account *accounts, int *account_count) {
    char name[50];
    float balance;
    printf("Enter name of account holder: ");
    scanf("%s", name);
    printf("Enter initial balance: ");
    scanf("%f", &balance);
    accounts[*account_count].account_number = *account_count + 1000;
    strcpy(accounts[*account_count].name, name);
    accounts[*account_count].balance = balance;
    printf("New account added successfully!\n");
    (*account_count)++;
}

// Function to display all the accounts in the record system
void display_accounts(struct account *accounts, int account_count) {
    printf("Account Number\tAccount Holder\t\tBalance\n");
    for (int i = 0; i < account_count; i++) {
        printf("%d\t\t%s\t\t%.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

// Function to deposit money into an account
void deposit(struct account *accounts, int account_count) {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    int account_index = -1;
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            account_index = i;
            break;
        }
    }
    if (account_index == -1) {
        printf("Account not found!\n");
    } else {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        accounts[account_index].balance += amount;
        printf("Deposit successful! Updated balance: %.2f\n", accounts[account_index].balance);
    }
}

// Function to withdraw money from an account
void withdraw(struct account *accounts, int account_count) {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    int account_index = -1;
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            account_index = i;
            break;
        }
    }
    if (account_index == -1) {
        printf("Account not found!\n");
    } else {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        if (amount > accounts[account_index].balance) {
            printf("Insufficient balance!\n");
        } else {
            accounts[account_index].balance -= amount;
            printf("Withdrawal successful! Updated balance: %.2f\n", accounts[account_index].balance);
        }
    }
}

int main() {
    struct account accounts[100];
    int account_count = 0;
    int choice;
    while (1) {
        printf("\n*******************\n");
        printf("1. Add account\n");
        printf("2. Display all accounts\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_account(accounts, &account_count);
                break;
            case 2:
                display_accounts(accounts, account_count);
                break;
            case 3:
                deposit(accounts, account_count);
                break;
            case 4:
                withdraw(accounts, account_count);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}