//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char account_number[10];
    float balance;
} account;

void create_account(account *a) {
    printf("Enter your name: ");
    scanf("%s", a->name);
    printf("Enter your account number: ");
    scanf("%s", a->account_number);
    a->balance = 0.0;
}

void deposit(account *a, float amount) {
    a->balance += amount;
    printf("Deposit of %0.2f made. New balance is %0.2f\n", amount, a->balance);
}

void withdraw(account *a, float amount) {
    if(a->balance >= amount) {
        a->balance -= amount;
        printf("Withdrawal of %0.2f made. New balance is %0.2f\n", amount, a->balance);
    } else {
        printf("Insufficient funds.\n");
    }
}

void check_balance(account a) {
    printf("Your current balance is %0.2f\n", a.balance);
}

int main() {
    account my_account;
    char choice;
    float amount;

    create_account(&my_account);

    do {
        printf("\nBanking Menu:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&my_account, amount);
                break;
            case '2':
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&my_account, amount);
                break;
            case '3':
                check_balance(my_account);
                break;
            case '4':
                printf("Thank you for banking with us!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '4');

    return 0;
}