//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BankAccount {
    char name[100];
    float balance;
    struct BankAccount* next;
};

typedef struct BankAccount BankAccount;

void display_menu() {
    printf("\n1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Display Balance\n5. Exit\n");
}

void create_account() {
    BankAccount* new_account;
    char name[100];
    printf("\nEnter Account Holder's Name: ");
    scanf("%s", name);

    new_account = (BankAccount*) malloc(sizeof(BankAccount));
    strcpy(new_account->name, name);
    new_account->balance = 0.0;
    new_account->next = NULL;

    printf("\nAccount Created Successfully!\n");
}

void deposit_money() {
    BankAccount* account;
    float amount;
    printf("\nEnter Account Holder's Name: ");
    scanf("%s", account->name);
    printf("\nEnter Amount to Deposit: ");
    scanf("%f", &amount);

    if (amount > 0) {
        account->balance += amount;
        printf("\nAmount Deposited Successfully!\n");
    } else {
        printf("\nInvalid Amount!\n");
    }
}

void withdraw_money() {
    BankAccount* account;
    float amount;
    printf("\nEnter Account Holder's Name: ");
    scanf("%s", account->name);
    printf("\nEnter Amount to Withdraw: ");
    scanf("%f", &amount);

    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("\nAmount Withdrawn Successfully!\n");
    } else {
        printf("\nInvalid Amount!\n");
    }
}

void display_balance() {
    BankAccount* account;
    printf("\nEnter Account Holder's Name: ");
    scanf("%s", account->name);
    printf("\nAccount Balance: %.2f\n", account->balance);
}

void main() {
    BankAccount* head = NULL;

    while(1) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                display_balance();
                break;
            case 5:
                printf("\nExiting Program...\n");
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }
}