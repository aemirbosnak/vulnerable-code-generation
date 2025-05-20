//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for bank account
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} BankAccount;

// Function to create a new bank account
void createAccount(BankAccount *account) {
    printf("Enter account number: ");
    scanf("%d", &account->accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", account->name);
    account->balance = 0.0;
}

// Function to deposit money into an account
void depositMoney(BankAccount *account) {
    printf("Enter amount to deposit: ");
    float amount;
    scanf("%f", &amount);
    account->balance += amount;
    printf("Deposit successful!\n");
}

// Function to withdraw money from an account
void withdrawMoney(BankAccount *account) {
    printf("Enter amount to withdraw: ");
    float amount;
    scanf("%f", &amount);
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal successful!\n");
    } else {
        printf("Insufficient balance!\n");
    }
}

// Function to display account details
void displayAccountDetails(BankAccount *account) {
    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Holder Name: %s\n", account->name);
    printf("Account Balance: $%.2f\n", account->balance);
}

// Main function
int main() {
    BankAccount account;
    int choice;
    do {
        printf("\nBanking System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                depositMoney(&account);
                break;
            case 3:
                withdrawMoney(&account);
                break;
            case 4:
                displayAccountDetails(&account);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);
    return 0;
}