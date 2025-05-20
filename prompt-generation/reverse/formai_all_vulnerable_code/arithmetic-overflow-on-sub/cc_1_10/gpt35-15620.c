//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACCOUNTS 100

/* Define Account structure */
typedef struct Account {
    int account_number;
    char name[50];
    float balance;
} Account;

/* Array to hold accounts */
Account accounts[MAX_ACCOUNTS];

/* Function to create a new account */
void create_account(int account_number, char name[], float balance) {
    Account account;
    account.account_number = account_number;
    strcpy(account.name, name);
    account.balance = balance;
    int index = account_number - 1;
    accounts[index] = account;
    printf("Account created successfully!\n");
}

/* Function to search for an account */
int find_account(int account_number) {
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts[i].account_number == account_number) {
            return i;
        }
    }
    printf("Account not found.\n");
    return -1;
}

/* Function to deposit money */
void deposit(int account_number, float amount) {
    int index = find_account(account_number);
    if (index != -1) {
        accounts[index].balance += amount;
        printf("Deposit successful. New balance: %.2f\n", accounts[index].balance);
    }
}

/* Function to withdraw money */
void withdraw(int account_number, float amount) {
    int index = find_account(account_number);
    if (index != -1) {
        if (accounts[index].balance >= amount) {
            accounts[index].balance -= amount;
            printf("Withdrawal successful. New balance: %.2f\n", accounts[index].balance);
        } else {
            printf("Insufficient funds.\n");
        }
    }
}

/* Function to check balance */
void check_balance(int account_number) {
    int index = find_account(account_number);
    if (index != -1) {
        printf("Balance: %.2f\n", accounts[index].balance);
    }
}

/* Main function */
int main() {
    int choice, account_number, index;
    char name[50];
    float balance, amount;

    do {
        printf("Welcome to the futuristic banking system. Choose an option:\n");
        printf("1. Create new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter account number, name, and starting balance: ");
                scanf("%d %s %f", &account_number, name, &balance);
                create_account(account_number, name, balance);
                break;
            case 2:
                printf("Enter account number and deposit amount: ");
                scanf("%d %f", &account_number, &amount);
                deposit(account_number, amount);
                break;
            case 3:
                printf("Enter account number and withdrawal amount: ");
                scanf("%d %f", &account_number, &amount);
                withdraw(account_number, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                check_balance(account_number);
                break;
            case 5:
                printf("Thank you for using the futuristic banking system!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}