//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int account_number;
    float balance;
} Account;

void create_account(Account *account) {
    printf("Enter your name: ");
    scanf("%s", account->name);
    printf("Enter your account number: ");
    scanf("%d", &account->account_number);
    account->balance = 0.0;
}

void deposit(Account *account, float amount) {
    account->balance += amount;
    printf("Deposit successful! Your new balance is $%.2f\n", account->balance);
}

void withdraw(Account *account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal successful! Your new balance is $%.2f\n", account->balance);
    } else {
        printf("Insufficient funds!\n");
    }
}

void check_balance(Account *account) {
    printf("Your current balance is $%.2f\n", account->balance);
}

int main() {
    Account my_account;
    create_account(&my_account);

    int choice;
    while (1) {
        printf("\nBanking System\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                float deposit_amount;
                scanf("%f", &deposit_amount);
                deposit(&my_account, deposit_amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                float withdraw_amount;
                scanf("%f", &withdraw_amount);
                withdraw(&my_account, withdraw_amount);
                break;
            case 3:
                check_balance(&my_account);
                break;
            case 4:
                printf("Thank you for using our services!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}