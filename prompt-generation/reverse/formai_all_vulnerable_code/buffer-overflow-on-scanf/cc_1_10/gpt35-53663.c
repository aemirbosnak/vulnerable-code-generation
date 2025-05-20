//FormAI DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int account_number;
    char first_name[50];
    char last_name[50];
    float balance;
};

void createAccount(struct Account acc[], int *index) {
    printf("Enter account number: ");
    scanf("%d", &acc[*index].account_number);
    printf("Enter first name: ");
    scanf("%s", acc[*index].first_name);
    printf("Enter last name: ");
    scanf("%s", acc[*index].last_name);
    printf("Enter initial balance: ");
    scanf("%f", &acc[*index].balance);
    (*index)++;
}

void deposit(struct Account acc[], int index) {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < index; i++) {
        if (acc[i].account_number == account_number) {
            float deposit_amount;
            printf("Enter deposit amount: ");
            scanf("%f", &deposit_amount);
            acc[i].balance += deposit_amount;
            printf("Deposit of %.2f successful.\nNew balance: %.2f\n", deposit_amount, acc[i].balance);
            return;
        }
    }
    printf("Account number not found.\n");
}

void withdraw(struct Account acc[], int index) {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < index; i++) {
        if (acc[i].account_number == account_number) {
            float withdrawal_amount;
            printf("Enter withdrawal amount: ");
            scanf("%f", &withdrawal_amount);
            if (acc[i].balance < withdrawal_amount) {
                printf("Insufficient balance.\n");
                return;
            }
            acc[i].balance -= withdrawal_amount;
            printf("Withdrawal of %.2f successful.\nNew balance: %.2f\n", withdrawal_amount, acc[i].balance);
            return;
        }
    }
    printf("Account number not found.\n");
}

void displayAll(struct Account acc[], int index) {
    for (int i = 0; i < index; i++) {
        printf("--------------------\n");
        printf("Account number: %d\n", acc[i].account_number);
        printf("Name: %s %s\n", acc[i].first_name, acc[i].last_name);
        printf("Balance: %.2f\n", acc[i].balance);
    }
}

void display(struct Account acc[], int index) {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < index; i++) {
        if (acc[i].account_number == account_number) {
            printf("--------------------\n");
            printf("Account number: %d\n", acc[i].account_number);
            printf("Name: %s %s\n", acc[i].first_name, acc[i].last_name);
            printf("Balance: %.2f\n", acc[i].balance);
            return;
        }
    }
    printf("Account number not found.\n");
}

int main() {
    struct Account accounts[100];
    int index = 0;
    int choice;
    do {
        printf("\n\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display All Accounts\n");
        printf("5. Display Account Details\n");
        printf("6. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount(accounts, &index);
                break;
            case 2:
                deposit(accounts, index);
                break;
            case 3:
                withdraw(accounts, index);
                break;
            case 4:
                displayAll(accounts, index);
                break;
            case 5:
                display(accounts, index);
                break;
            case 6:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}