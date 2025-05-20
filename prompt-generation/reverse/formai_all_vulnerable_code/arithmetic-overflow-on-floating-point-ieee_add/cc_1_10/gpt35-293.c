//FormAI DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int accountNumber;
    float balance;
} Account;

void createAccount(Account *account) {
    printf("Enter name: ");
    scanf("%s", account->name);
    printf("Enter account number: ");
    scanf("%d", &account->accountNumber);
    printf("Enter balance: ");
    scanf("%f", &account->balance);
    printf("Account created successfully!\n");
}

void viewAccount(Account *account) {
    printf("Name: %s\n", account->name);
    printf("Account number: %d\n", account->accountNumber);
    printf("Balance: %.2f\n", account->balance);
}

void deposit(Account *account, float amount) {
    account->balance += amount;
    printf("Deposit successful!\n");
}

void withdraw(Account *account, float amount) {
    if(account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal successful!\n");
    } else {
        printf("Withdrawal unsuccessful! Insufficient balance.\n");
    }
}

int main() {
    Account account;
    int choice;
    float amount;

    while(1) {
        printf("\nWelcome to Cheerful Bank\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Quit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                viewAccount(&account);
                break;
            case 3:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&account, amount);
                break;
            case 4:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&account, amount);
                break;
            case 5:
                printf("Thank you for banking with Cheerful Bank!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}