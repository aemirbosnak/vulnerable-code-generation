//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a bank account
typedef struct {
    int accountNumber;
    char accountHolderName[50];
    float balance;
} BankAccount;

// Function prototypes
void createAccount(BankAccount* account);
void deposit(BankAccount* account, float amount);
void withdraw(BankAccount* account, float amount);
void printAccountDetails(BankAccount* account);

int main() {
    BankAccount myAccount;
    char choice;

    do {
        printf("\nWelcome to the Banking Record System!\n");
        printf("Enter 'c' to create an account, 'd' to deposit money, 'w' to withdraw money, 'p' to print account details, or 'q' to quit:\n");
        scanf("%c", &choice);

        switch(choice) {
            case 'c':
                createAccount(&myAccount);
                break;
            case 'd':
                printf("Enter the amount you want to deposit:\n");
                scanf("%f", &myAccount.balance);
                break;
            case 'w':
                printf("Enter the amount you want to withdraw:\n");
                scanf("%f", &myAccount.balance);
                break;
            case 'p':
                printAccountDetails(&myAccount);
                break;
            case 'q':
                printf("Thank you for using the Banking Record System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 'q');

    return 0;
}

// Function to create a new bank account
void createAccount(BankAccount* account) {
    printf("Enter your name:\n");
    scanf("%s", account->accountHolderName);
    printf("Enter your account number:\n");
    scanf("%d", &account->accountNumber);
    account->balance = 0;
    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void deposit(BankAccount* account, float amount) {
    account->balance += amount;
    printf("Deposit successful! New balance: $%.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw(BankAccount* account, float amount) {
    if(account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal successful! New balance: $%.2f\n", account->balance);
    } else {
        printf("Insufficient funds.\n");
    }
}

// Function to print account details
void printAccountDetails(BankAccount* account) {
    printf("Account holder name: %s\n", account->accountHolderName);
    printf("Account number: %d\n", account->accountNumber);
    printf("Current balance: $%.2f\n", account->balance);
}