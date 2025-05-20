//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME 50
#define MAX_AMOUNT 10000

typedef struct {
    char name[MAX_NAME];
    int account_number;
    double balance;
} account;

int main() {
    int choice, account_number;
    char name[MAX_NAME];
    double amount;
    account accounts[MAX_ACCOUNTS];

    printf("Welcome to the Capulet Banking System\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    // Check if account already exists
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("Account already exists for %s\n", name);
            return 0;
        }
    }

    // Create new account
    account_number = rand() % MAX_ACCOUNTS;
    while (accounts[account_number].name[0]!= '\0') {
        account_number = rand() % MAX_ACCOUNTS;
    }
    strcpy(accounts[account_number].name, name);
    accounts[account_number].account_number = account_number + 1;
    accounts[account_number].balance = 0.0;

    printf("Your account number is: %d\n", accounts[account_number].account_number);

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                if (amount <= 0) {
                    printf("Invalid amount.\n");
                } else {
                    accounts[account_number].balance += amount;
                    printf("Deposit successful.\n");
                }
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                if (amount <= 0 || amount > accounts[account_number].balance) {
                    printf("Invalid amount.\n");
                } else {
                    accounts[account_number].balance -= amount;
                    printf("Withdrawal successful.\n");
                }
                break;
            case 3:
                printf("Your current balance is: $%.2lf\n", accounts[account_number].balance);
                break;
            case 4:
                printf("Thank you for using the Capulet Banking System.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    return 0;
}