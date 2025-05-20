//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char name[50];
    char address[100];
    float balance;
} Account;

void create_account(Account* account) {
    printf("Enter account number: ");
    scanf("%d", &account->account_number);
    printf("Enter name: ");
    scanf("%s", account->name);
    printf("Enter address: ");
    scanf("%s", account->address);
    printf("Enter initial balance: ");
    scanf("%f", &account->balance);
    printf("Account created successfully.\n");
}

void deposit_money(Account* account) {
    printf("Enter amount to deposit: ");
    float deposit_amount;
    scanf("%f", &deposit_amount);
    account->balance += deposit_amount;
    printf("Deposit successful.\n");
}

void withdraw_money(Account* account) {
    printf("Enter amount to withdraw: ");
    float withdraw_amount;
    scanf("%f", &withdraw_amount);
    if(withdraw_amount > account->balance) {
        printf("Insufficient balance.\n");
    } else {
        account->balance -= withdraw_amount;
        printf("Withdrawal successful.\n");
    }
}

void check_balance(Account* account) {
    printf("Current balance: %.2f\n", account->balance);
}

int main() {
    Account my_account;
    int choice;

    do {
        printf("1. Create account\n2. Deposit money\n3. Withdraw money\n4. Check balance\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_account(&my_account);
                break;
            case 2:
                deposit_money(&my_account);
                break;
            case 3:
                withdraw_money(&my_account);
                break;
            case 4:
                check_balance(&my_account);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 5);

    return 0;
}