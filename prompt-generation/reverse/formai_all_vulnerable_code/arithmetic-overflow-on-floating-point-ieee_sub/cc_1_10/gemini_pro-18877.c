//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
    char accountNum[11];
    char firstName[20];
    char lastName[20];
    double balance;
};

void createAccount(struct BankAccount *account) {
    printf("Welcome to the Amazing Bank!\n");
    printf("Please tell us your name:\n");
    scanf("%s %s", account->firstName, account->lastName);
    printf("Now, let's set up your account number:\n");
    gets(account->accountNum); // Clear the input buffer
    gets(account->accountNum); // Get the actual account number
    printf("Just a sec, generating your account...\n");
    account->balance = 0.0;
    printf("Here's your account details:\n");
    printf("Account Number: %s\n", account->accountNum);
    printf("Name: %s %s\n", account->firstName, account->lastName);
    printf("Balance: %.2lf\n", account->balance);
}

void deposit(struct BankAccount *account) {
    double amount;
    printf("How much would you like to deposit today?\n");
    scanf("%lf", &amount);
    account->balance += amount;
    printf("Deposit successful!\n");
    printf("Your new balance is: %.2lf\n", account->balance);
}

void withdraw(struct BankAccount *account) {
    double amount;
    printf("How much would you like to withdraw today?\n");
    scanf("%lf", &amount);
    if (amount > account->balance) {
        printf("Uh oh, it seems you don't have enough funds.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful!\n");
        printf("Your new balance is: %.2lf\n", account->balance);
    }
}

void checkBalance(struct BankAccount *account) {
    printf("Your account balance is: %.2lf\n", account->balance);
}

int main() {
    struct BankAccount myAccount;
    int choice;
    while (1) {
        printf("\nWelcome to your Amazing Bank account. Choose an option (1-4):\n");
        printf("1. Create an account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount(&myAccount);
                break;
            case 2:
                deposit(&myAccount);
                break;
            case 3:
                withdraw(&myAccount);
                break;
            case 4:
                checkBalance(&myAccount);
                break;
            case 5:
                printf("Thank you for banking with us. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid option. Please choose a number between 1 and 5.\n");
        }
    }
    return 0;
}