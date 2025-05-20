//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a bank account
typedef struct {
    int accountNumber;
    char name[50];
    char address[100];
    float balance;
} Account;

// Function to create a new bank account
void createAccount(Account *account) {
    printf("Enter account number: ");
    scanf("%d", &account->accountNumber);
    printf("Enter name: ");
    scanf("%s", account->name);
    printf("Enter address: ");
    scanf("%s", account->address);
    account->balance = 0;
    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void deposit(Account *account, float amount) {
    account->balance += amount;
    printf("Deposit successful! New balance: $%.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw(Account *account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal successful! New balance: $%.2f\n", account->balance);
    } else {
        printf("Insufficient funds!\n");
    }
}

// Function to check the balance of an account
void checkBalance(Account *account) {
    printf("Current balance: $%.2f\n", account->balance);
}

// Function to close an account
void closeAccount(Account *account) {
    printf("Account closed successfully!\n");
}

// Main function to interact with the user
int main() {
    Account myAccount;
    int choice;
    float amount;

    do {
        printf("\nBanking System\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check balance\n");
        printf("5. Close account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createAccount(&myAccount);
            break;
        case 2:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            deposit(&myAccount, amount);
            break;
        case 3:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            withdraw(&myAccount, amount);
            break;
        case 4:
            checkBalance(&myAccount);
            break;
        case 5:
            closeAccount(&myAccount);
            break;
        case 6:
            printf("Thank you for using our banking system!\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 6);

    return 0;
}