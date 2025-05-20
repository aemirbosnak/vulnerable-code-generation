//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define MAX_SIZE 1000
#define MAX_NAME_SIZE 50
#define MAX_ACCOUNT_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    char account_number[MAX_ACCOUNT_SIZE];
    float balance;
} account;

void create_account(account *acc) {
    printf("Enter name: ");
    scanf("%s", acc->name);
    printf("Enter account number: ");
    scanf("%s", acc->account_number);
    printf("Enter initial balance: ");
    scanf("%f", &acc->balance);
}

void deposit(account *acc, float amount) {
    acc->balance += amount;
    printf("%s deposited $%.2f into account %s.\n", acc->name, amount, acc->account_number);
}

void withdraw(account *acc, float amount) {
    if(acc->balance >= amount) {
        acc->balance -= amount;
        printf("%s withdrew $%.2f from account %s.\n", acc->name, amount, acc->account_number);
    }
    else {
        printf("Insufficient funds.\n");
    }
}

void check_balance(account *acc) {
    printf("%s's balance is $%.2f.\n", acc->name, acc->balance);
}

int main() {
    account user_acc;
    create_account(&user_acc);
    int choice;
    float amount;

    do {
        printf("\n1. Deposit\n2. Withdraw\n3. Check balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&user_acc, amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&user_acc, amount);
                break;
            case 3:
                check_balance(&user_acc);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    while(choice!= 4);

    return 0;
}