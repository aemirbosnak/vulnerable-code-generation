//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of a bank account
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
    time_t creationDate;
} Account;

// Function to create a new bank account
void createAccount(Account* account) {
    srand(time(NULL));
    account->accountNumber = rand() % 1000000;
    printf("Your account number is: %d\n", account->accountNumber);
    printf("Please enter your name: ");
    scanf("%s", account->name);
    printf("Your account has been created.\n");
}

// Function to deposit money into an account
void deposit(Account* account, float amount) {
    account->balance += amount;
    printf("Deposit successful. Your new balance is: $%.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw(Account* account, float amount) {
    if (amount > account->balance) {
        printf("Insufficient funds.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful. Your new balance is: $%.2f\n", account->balance);
    }
}

// Function to check the balance of an account
void checkBalance(Account* account) {
    printf("Your current balance is: $%.2f\n", account->balance);
}

// Function to close an account
void closeAccount(Account* account) {
    printf("Your account has been closed.\n");
}

// Main function
int main() {
    // Create a new bank account
    Account myAccount;
    createAccount(&myAccount);

    // Perform various transactions
    deposit(&myAccount, 1000);
    checkBalance(&myAccount);
    withdraw(&myAccount, 500);
    checkBalance(&myAccount);

    // Close the account
    closeAccount(&myAccount);

    return 0;
}