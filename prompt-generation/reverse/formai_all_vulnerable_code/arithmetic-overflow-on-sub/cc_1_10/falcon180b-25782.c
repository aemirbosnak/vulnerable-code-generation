//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int balance;
} account;

void create_account(account *acc, char *name, int age, int balance) {
    acc->name = (char*) malloc(strlen(name) + 1);
    strcpy(acc->name, name);
    acc->age = age;
    acc->balance = balance;
    printf("Account created for %s.\n", name);
}

void deposit_money(account *acc, int amount) {
    acc->balance += amount;
    printf("%s deposited $%d.\n", acc->name, amount);
}

void withdraw_money(account *acc, int amount) {
    if(acc->balance >= amount) {
        acc->balance -= amount;
        printf("%s withdrew $%d.\n", acc->name, amount);
    } else {
        printf("Insufficient funds.\n");
    }
}

void check_balance(account *acc) {
    printf("%s's balance is $%d.\n", acc->name, acc->balance);
}

int main() {
    account user_account;
    char name[MAX_SIZE];
    int age, choice, amount;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    create_account(&user_account, name, age, 0);

    while(1) {
        printf("\n1. Deposit money\n2. Withdraw money\n3. Check balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the amount to deposit: ");
                scanf("%d", &amount);
                deposit_money(&user_account, amount);
                break;
            case 2:
                printf("Enter the amount to withdraw: ");
                scanf("%d", &amount);
                withdraw_money(&user_account, amount);
                break;
            case 3:
                check_balance(&user_account);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}