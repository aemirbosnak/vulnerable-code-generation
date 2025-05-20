//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET 100
#define MAX_EXPENSE 50
#define MAX_SAVINGS 50
#define MAX_ACCOUNT 10
#define MAX_SAVE_NAME 50

struct account {
    char name[MAX_SAVE_NAME];
    int balance;
};

struct account accounts[MAX_ACCOUNT];

void create_account(int index) {
    printf("Enter account name: ");
    scanf("%s", accounts[index].name);
    accounts[index].balance = 0;
}

void deposit(int index) {
    printf("Enter deposit amount: ");
    int amount;
    scanf("%d", &amount);
    accounts[index].balance += amount;
    printf("Deposit successful!\n");
}

void withdraw(int index) {
    printf("Enter withdrawal amount: ");
    int amount;
    scanf("%d", &amount);
    if(amount > accounts[index].balance) {
        printf("Insufficient funds.\n");
    } else {
        accounts[index].balance -= amount;
        printf("Withdrawal successful!\n");
    }
}

void check_balance(int index) {
    printf("Account balance: $%d\n", accounts[index].balance);
}

void main() {
    int choice;
    int index;

    printf("Welcome to Personal Finance Planner!\n");
    printf("Please create an account:\n");
    for(int i=0; i<MAX_ACCOUNT; i++) {
        create_account(i);
    }

    while(1) {
        printf("\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter account index: ");
                scanf("%d", &index);
                deposit(index);
                break;
            case 2:
                printf("Enter account index: ");
                scanf("%d", &index);
                withdraw(index);
                break;
            case 3:
                printf("Enter account index: ");
                scanf("%d", &index);
                check_balance(index);
                break;
            case 4:
                printf("Thank you for using Personal Finance Planner!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}