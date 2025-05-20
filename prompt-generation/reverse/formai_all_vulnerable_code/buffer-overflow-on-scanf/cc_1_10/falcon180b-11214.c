//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for bank account
typedef struct {
    char account_number[10];
    char account_holder_name[50];
    float balance;
} BankAccount;

// Function to create a new bank account
void create_account(BankAccount *account) {
    printf("Enter account number: ");
    scanf("%s", account->account_number);
    printf("Enter account holder name: ");
    scanf("%s", account->account_holder_name);
    account->balance = 0.0;
    printf("Account created successfully!\n");
}

// Function to deposit money in an account
void deposit_money(BankAccount *account) {
    printf("Enter amount to deposit: ");
    scanf("%f", &account->balance);
    printf("Deposit successful!\n");
}

// Function to withdraw money from an account
void withdraw_money(BankAccount *account) {
    printf("Enter amount to withdraw: ");
    scanf("%f", &account->balance);
    printf("Withdrawal successful!\n");
}

// Function to display account details
void display_account(BankAccount *account) {
    printf("Account Number: %s\n", account->account_number);
    printf("Account Holder Name: %s\n", account->account_holder_name);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    BankAccount account;
    int choice;
    while(1) {
        printf("\nWelcome to the Banking Record System!\n");
        printf("1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Display Account Details\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_account(&account);
                break;
            case 2:
                deposit_money(&account);
                break;
            case 3:
                withdraw_money(&account);
                break;
            case 4:
                display_account(&account);
                break;
            case 5:
                printf("Thank you for using the Banking Record System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}