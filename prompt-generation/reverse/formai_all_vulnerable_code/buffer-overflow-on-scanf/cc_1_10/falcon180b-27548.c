//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int account_number;
    float balance;
} BankAccount;

void create_account(BankAccount* account) {
    printf("Enter your name: ");
    scanf("%s", account->name);
    printf("Enter your account number: ");
    scanf("%d", &account->account_number);
    account->balance = 0.0;
}

void deposit_money(BankAccount* account, float amount) {
    account->balance += amount;
    printf("Deposit successful! Your new balance is $%.2f\n", account->balance);
}

void withdraw_money(BankAccount* account, float amount) {
    if (amount > account->balance) {
        printf("Insufficient funds.\n");
        return;
    }
    account->balance -= amount;
    printf("Withdrawal successful! Your new balance is $%.2f\n", account->balance);
}

void check_balance(BankAccount* account) {
    printf("Your current balance is $%.2f\n", account->balance);
}

int main() {
    BankAccount account;
    char choice;
    int i = 0;

    do {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            create_account(&account);
            break;
        case '2':
            printf("Enter the amount to deposit: ");
            scanf("%f", &i);
            deposit_money(&account, i);
            break;
        case '3':
            printf("Enter the amount to withdraw: ");
            scanf("%f", &i);
            withdraw_money(&account, i);
            break;
        case '4':
            check_balance(&account);
            break;
        case '5':
            printf("Thank you for using our banking system.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '5');

    return 0;
}