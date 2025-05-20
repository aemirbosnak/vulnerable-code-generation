//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for bank account
typedef struct {
    char name[30];
    char accountNumber[10];
    float balance;
} BankAccount;

// Function to display menu options
void displayMenu() {
    printf("\nBanking Record System\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
}

// Function to create account
void createAccount(BankAccount *account) {
    printf("\nEnter your name: ");
    scanf("%s", account->name);
    printf("Enter your account number: ");
    scanf("%s", account->accountNumber);
    account->balance = 0.0;
    printf("Account created successfully!\n");
}

// Function to deposit money
void depositMoney(BankAccount *account, float amount) {
    account->balance += amount;
    printf("\nAmount deposited successfully!\n");
}

// Function to withdraw money
void withdrawMoney(BankAccount *account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("\nAmount withdrawn successfully!\n");
    } else {
        printf("\nInsufficient balance!\n");
    }
}

// Function to check balance
void checkBalance(BankAccount *account) {
    printf("\nYour current balance is: %.2f\n", account->balance);
}

// Main function
int main() {
    BankAccount account;
    int choice;
    do {
        system("clear");
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                printf("\nEnter amount to deposit: ");
                float deposit;
                scanf("%f", &deposit);
                depositMoney(&account, deposit);
                break;
            case 3:
                printf("\nEnter amount to withdraw: ");
                float withdraw;
                scanf("%f", &withdraw);
                withdrawMoney(&account, withdraw);
                break;
            case 4:
                checkBalance(&account);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice!= 5);
    return 0;
}