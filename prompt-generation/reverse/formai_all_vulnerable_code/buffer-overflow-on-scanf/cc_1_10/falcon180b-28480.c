//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char account_holder_name[50];
    float balance;
} Account;

void create_account(Account* account) {
    printf("Enter account holder name: ");
    scanf("%s", account->account_holder_name);
    account->account_number = rand();
    account->balance = 0.0;
    printf("Account created with number: %d\n", account->account_number);
}

void deposit_money(Account* account, float amount) {
    account->balance += amount;
    printf("Deposit of %.2f made. New balance: %.2f\n", amount, account->balance);
}

void withdraw_money(Account* account, float amount) {
    if(amount > account->balance) {
        printf("Insufficient funds.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal of %.2f made. New balance: %.2f\n", amount, account->balance);
    }
}

void check_balance(Account* account) {
    printf("Current balance: %.2f\n", account->balance);
}

int main() {
    Account my_account;
    int choice;

    create_account(&my_account);

    do {
        printf("\n1. Deposit money\n2. Withdraw money\n3. Check balance\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &my_account.balance);
                deposit_money(&my_account, my_account.balance);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &my_account.balance);
                withdraw_money(&my_account, my_account.balance);
                break;
            case 3:
                check_balance(&my_account);
                break;
            case 4:
                printf("Thank you for using our banking system.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}