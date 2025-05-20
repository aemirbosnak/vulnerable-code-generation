//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int account_number;
    float balance;
} account;

void create_account(account* new_account) {
    printf("Enter your name: ");
    scanf("%s", new_account->name);
    printf("Enter your account number: ");
    scanf("%d", &new_account->account_number);
    new_account->balance = 0;
    printf("\nAccount created successfully!\n");
}

void deposit_money(account* account_to_deposit, float amount) {
    account_to_deposit->balance += amount;
    printf("\nDeposit successful! New balance: $%.2f\n", account_to_deposit->balance);
}

void withdraw_money(account* account_to_withdraw, float amount) {
    if (account_to_withdraw->balance >= amount) {
        account_to_withdraw->balance -= amount;
        printf("\nWithdrawal successful! New balance: $%.2f\n", account_to_withdraw->balance);
    } else {
        printf("\nInsufficient funds. Withdrawal failed.\n");
    }
}

void check_balance(account* account_to_check) {
    printf("\nCurrent balance: $%.2f\n", account_to_check->balance);
}

int main() {
    account my_account;
    int choice;

    printf("\nWelcome to the Ada Lovelace Bank!\n");
    printf("Please choose an option:\n");
    printf("1. Create account\n2. Deposit money\n3. Withdraw money\n4. Check balance\n5. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(&my_account);
                break;
            case 2:
                printf("\nEnter amount to deposit: ");
                float deposit_amount;
                scanf("%f", &deposit_amount);
                deposit_money(&my_account, deposit_amount);
                break;
            case 3:
                printf("\nEnter amount to withdraw: ");
                float withdraw_amount;
                scanf("%f", &withdraw_amount);
                withdraw_money(&my_account, withdraw_amount);
                break;
            case 4:
                check_balance(&my_account);
                break;
            case 5:
                printf("\nThank you for banking with us! Goodbye.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}