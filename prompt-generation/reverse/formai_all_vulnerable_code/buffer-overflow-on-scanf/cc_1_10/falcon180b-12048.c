//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

void create_account(Account *account) {
    printf("Enter your name: ");
    scanf("%s", account->name);
    printf("Enter your account number: ");
    scanf("%d", &account->account_number);
    printf("Enter your initial balance: ");
    scanf("%f", &account->balance);
    printf("Account created successfully!\n");
}

void deposit_money(Account *account) {
    printf("Enter the amount you want to deposit: ");
    scanf("%f", &account->balance);
    account->balance += account->balance;
    printf("Deposit successful!\n");
}

void withdraw_money(Account *account) {
    printf("Enter the amount you want to withdraw: ");
    scanf("%f", &account->balance);
    account->balance -= account->balance;
    printf("Withdrawal successful!\n");
}

void check_balance(Account *account) {
    printf("Your current balance is: $%.2f\n", account->balance);
}

int main() {
    Account account;
    int choice;

    printf("Welcome to the Banking Record System!\n");
    printf("Enter 1 to create an account.\n");
    printf("Enter 2 to deposit money.\n");
    printf("Enter 3 to withdraw money.\n");
    printf("Enter 4 to check your balance.\n");
    printf("Enter 5 to exit.\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            create_account(&account);
            break;
        case 2:
            deposit_money(&account);
            break;
        case 3:
            withdraw_money(&account);
            break;
        case 4:
            check_balance(&account);
            break;
        case 5:
            printf("Thank you for using the Banking Record System!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}