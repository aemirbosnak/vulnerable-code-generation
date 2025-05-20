//FormAI DATASET v1.0 Category: Banking Record System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[50];
    char accNum[10];
    double balance;
};

int showMenu();
struct account createAccount();
void displayAccount(struct account);
void deposit(struct account*, double);
void withdraw(struct account*, double);

int main() {
    int choice;
    struct account bankAcc;

    while (1) {
        choice = showMenu();

        switch (choice) {
            case 1:
                bankAcc = createAccount();
                printf("Successfully created account!\n\n");
                break;
            case 2:
                printf("\nEnter account number: ");
                scanf("%s", bankAcc.accNum);
                displayAccount(bankAcc);
                break;
            case 3:
                printf("\nEnter account number: ");
                scanf("%s", bankAcc.accNum);
                deposit(&bankAcc, 0);
                break;
            case 4:
                printf("\nEnter account number: ");
                scanf("%s", bankAcc.accNum);
                withdraw(&bankAcc, 0);
                break;
            case 5:
                printf("\nExiting program...\n");
                return 0;
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }
}

int showMenu() {
    int choice;

    printf("-----------------------------\n");
    printf(" Welcome to Bank of C\n");
    printf("-----------------------------\n");
    printf("1. Create Account\n");
    printf("2. Display Account\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");
    printf("-----------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

struct account createAccount() {
    struct account newAccount;

    printf("\nEnter name: ");
    scanf("%s", newAccount.name);
    printf("Enter account number: ");
    scanf("%s", newAccount.accNum);
    printf("Enter initial deposit amount: ");
    scanf("%lf", &newAccount.balance);

    return newAccount;
}

void displayAccount(struct account acc) {
    printf("\nName: %s", acc.name);
    printf("\nAccount number: %s", acc.accNum);
    printf("\nBalance: $%.2lf\n\n", acc.balance);
}

void deposit(struct account* accPtr, double amount) {
    printf("\nEnter deposit amount: ");
    scanf("%lf", &amount);

    if (amount > 0) {
        accPtr->balance += amount;
        printf("\nDeposit successful!\n");
        displayAccount(*accPtr);
    }
    else {
        printf("\nInvalid deposit amount.\n\n");
    }
}

void withdraw(struct account* accPtr, double amount) {
    printf("\nEnter withdrawal amount: ");
    scanf("%lf", &amount);

    if (amount > 0 && amount <= accPtr->balance) {
        accPtr->balance -= amount;
        printf("\nWithdrawal successful!\n");
        displayAccount(*accPtr);
    }
    else {
        printf("\nInvalid withdrawal amount.\n\n");
    }
}