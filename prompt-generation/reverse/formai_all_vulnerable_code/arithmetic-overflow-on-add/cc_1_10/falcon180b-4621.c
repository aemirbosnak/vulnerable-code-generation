//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for bank account
typedef struct {
    char name[30];
    char account_number[20];
    int balance;
} Account;

// Function to create a new account
void create_account(Account *account) {
    printf("Enter account holder name: ");
    scanf("%s", account->name);
    printf("Enter account number: ");
    scanf("%s", account->account_number);
    account->balance = 0;
}

// Function to deposit money into an account
void deposit_money(Account *account, int amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(Account *account, int amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
    } else {
        printf("Insufficient balance in account\n");
    }
}

// Function to check account balance
void check_balance(Account *account) {
    printf("Account balance: %d\n", account->balance);
}

// Function to close an account
void close_account(Account *account) {
    printf("Account closed successfully\n");
}

// Main function to interact with user
int main() {
    Account my_account;
    int choice;

    do {
        printf("\nWelcome to XYZ Bank\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Close Account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(&my_account);
                printf("Account created successfully\n");
                break;
            case 2:
                printf("Enter amount to deposit: ");
                int deposit_amount;
                scanf("%d", &deposit_amount);
                deposit_money(&my_account, deposit_amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                int withdraw_amount;
                scanf("%d", &withdraw_amount);
                withdraw_money(&my_account, withdraw_amount);
                break;
            case 4:
                check_balance(&my_account);
                break;
            case 5:
                close_account(&my_account);
                break;
            case 6:
                printf("Thank you for using XYZ Bank services\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 6);

    return 0;
}