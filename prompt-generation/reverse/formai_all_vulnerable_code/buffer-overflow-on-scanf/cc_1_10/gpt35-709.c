//FormAI DATASET v1.0 Category: Banking Record System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

struct record {
    char name[20];
    int account_number;
    int balance;
};

void new_account(struct record* record_ptr) {
    printf("\nEnter the following details to create a new account:\n");

    printf("Name: ");
    scanf("%s", record_ptr->name);

    printf("Account Number: ");
    scanf("%d", &record_ptr->account_number);

    printf("Balance: ");
    scanf("%d", &record_ptr->balance);

    printf("\nAccount created successfully!\n");
}

void display_account(struct record record_var) {
    printf("\nInformation for Account %d\n", record_var.account_number);

    printf("Name: %s\n", record_var.name);
    printf("Balance: %d\n", record_var.balance);
}

void deposit(struct record* record_var_ptr, int amount) {
    record_var_ptr->balance += amount;

    printf("\n$%d has been successfully deposited to Account %d.\n", amount, record_var_ptr->account_number);
}

void withdraw(struct record* record_var_ptr, int amount) {
    if (record_var_ptr->balance >= amount) {
        record_var_ptr->balance -= amount;

        printf("\n$%d has been successfully withdrawn from Account %d.\n", amount, record_var_ptr->account_number);
    }
    else {
        printf("\nInsufficient balance for Account %d.\n", record_var_ptr->account_number);
    }
}

int main() {
    struct record account1;
    struct record account2;

    new_account(&account1);
    new_account(&account2);

    display_account(account1);
    display_account(account2);

    deposit(&account1, 500);
    deposit(&account2, 1000);

    withdraw(&account1, 200);
    withdraw(&account2, 1500);

    display_account(account1);
    display_account(account2);

    return 0;
}