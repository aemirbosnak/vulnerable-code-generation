//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct account {
    int account_number;
    char name[50];
    float balance;
} Account;

void create_account(Account *account) {
    printf("Enter account number: ");
    scanf("%d", &account->account_number);
    printf("Enter account holder name: ");
    scanf("%s", account->name);
    printf("Enter initial balance: ");
    scanf("%f", &account->balance);
}

void deposit(Account *account) {
    printf("Enter amount to deposit: ");
    scanf("%f", &account->balance);
}

void withdraw(Account *account) {
    printf("Enter amount to withdraw: ");
    scanf("%f", &account->balance);
}

void check_balance(Account *account) {
    printf("Current balance: $%.2f\n", account->balance);
}

int main() {
    Account my_account;
    int choice;

    do {
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                check_balance(&my_account);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 5);

    return 0;
}