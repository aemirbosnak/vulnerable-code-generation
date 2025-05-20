//FormAI DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char account_type[20];
    double balance;
} BankAccount;

void display_menu() {
    printf("\n");
    printf("*** Welcome to MyBanking Record System ***\n\n");
    printf("1. Create an Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View Balance\n");
    printf("5. Exit\n");
    printf("\n");
}

void create_account(BankAccount *account) {
    printf("Enter your name: ");
    scanf("%s", account->name);

    printf("Enter your age: ");
    scanf("%d", &account->age);

    printf("Enter your account type (saving or current): ");
    scanf("%s", account->account_type);

    printf("Enter your initial balance: ");
    scanf("%lf", &account->balance);

    printf("\nAccount created successfully!\n\n");
}

void deposit(BankAccount *account) {
    double amount;

    printf("\nEnter amount to deposit: ");
    scanf("%lf", &amount);

    account->balance += amount;

    printf("\nDeposit successful!\n\n");
}

void withdraw(BankAccount *account) {
    double amount;

    printf("\nEnter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount > account->balance) {
        printf("\nInsufficient balance!\n\n");
    } else {
        account->balance -= amount;
        printf("\nWithdrawal successful!\n\n");
    }
}

void view_balance(BankAccount *account) {
    printf("\nName: %s\n", account->name);
    printf("Age: %d\n", account->age);
    printf("Account Type: %s\n", account->account_type);
    printf("Current balance: %.2lf\n\n", account->balance);
}

int main() {
    BankAccount my_account;
    int choice = 0;

    while (choice != 5) {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(&my_account);
                break;
            case 2:
                deposit(&my_account);
                break;
            case 3:
                withdraw(&my_account);
                break;
            case 4:
                view_balance(&my_account);
                break;
            case 5:
                printf("\nThank you for using MyBanking Record System!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}