//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a bank account
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

// Function prototypes
void createAccount(Account* account);
void depositMoney(Account* account, float amount);
void withdrawMoney(Account* account, float amount);
void printAccountDetails(Account account);

// Main function
int main() {
    Account myAccount;
    int choice;

    createAccount(&myAccount);

    do {
        printf("\nWelcome to Sherlock's Banking System\n");
        printf("1. Deposit Money\n2. Withdraw Money\n3. Check Balance\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Amount to Deposit: ");
                scanf("%f", &myAccount.balance);
                depositMoney(&myAccount, myAccount.balance);
                break;
            case 2:
                printf("Enter Amount to Withdraw: ");
                scanf("%f", &myAccount.balance);
                withdrawMoney(&myAccount, myAccount.balance);
                break;
            case 3:
                printAccountDetails(myAccount);
                break;
            case 4:
                printf("Thank you for using Sherlock's Banking System. Goodbye!\n");
                break;
            default:
                printf("Invalid Choice. Please try again.\n");
        }
    } while(choice!= 4);

    return 0;
}

// Function to create a new bank account
void createAccount(Account* account) {
    printf("Enter Account Number: ");
    scanf("%d", &account->accountNumber);

    printf("Enter Your Name: ");
    scanf("%s", account->name);

    printf("Account Created Successfully!\n");
}

// Function to deposit money into the account
void depositMoney(Account* account, float amount) {
    account->balance += amount;
    printf("Deposit Successful! New Balance: $%.2f\n", account->balance);
}

// Function to withdraw money from the account
void withdrawMoney(Account* account, float amount) {
    if(account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal Successful! New Balance: $%.2f\n", account->balance);
    } else {
        printf("Insufficient Funds. Withdrawal Failed.\n");
    }
}

// Function to print account details
void printAccountDetails(Account account) {
    printf("\nAccount Details:\n");
    printf("Account Number: %d\n", account.accountNumber);
    printf("Name: %s\n", account.name);
    printf("Balance: $%.2f\n", account.balance);
}