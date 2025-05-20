//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    double balance;
} account;

void create_account(account *acc) {
    printf("Enter account name: ");
    scanf("%s", acc->name);
    acc->balance = 0.0;
}

void deposit(account *acc) {
    printf("Enter deposit amount: ");
    scanf("%lf", &acc->balance);
    printf("Deposit successful! New balance: $%.2lf\n", acc->balance);
}

void withdraw(account *acc) {
    printf("Enter withdrawal amount: ");
    scanf("%lf", &acc->balance);
    if (acc->balance >= 0.0) {
        printf("Withdrawal successful! New balance: $%.2lf\n", acc->balance);
    } else {
        printf("Insufficient funds. Withdrawal failed.\n");
    }
}

void check_balance(account *acc) {
    printf("Current balance: $%.2lf\n", acc->balance);
}

int main() {
    account my_account;
    int choice;

    create_account(&my_account);

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit(&my_account);
                break;
            case 2:
                withdraw(&my_account);
                break;
            case 3:
                check_balance(&my_account);
                break;
            case 4:
                printf("Thank you for using Personal Finance Planner!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= 4);

    return 0;
}