//FormAI DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transaction {
    char date[20];
    char description[100];
    float amount;
    char type[10];
};

struct account {
    char name[50];
    char accNo[20];
    float balance;
    struct transaction trans[100];
    int transCount;
};

void addTransaction(struct account* acc) {
    struct transaction t;
    printf("Date: ");
    scanf("%s", t.date);
    printf("Description: ");
    scanf("%s", t.description);
    printf("Amount: ");
    scanf("%f", &t.amount);
    printf("Type: ");
    scanf("%s", t.type);
    acc->trans[acc->transCount] = t;
    acc->transCount++;
}

void viewTransactions(struct account acc) {
    printf("Transactions:\n");
    printf("Date\tDescription\tAmount\tType\n");
    for (int i = 0; i < acc.transCount; i++) {
        printf("%s\t%s\t%.2f\t%s\n", acc.trans[i].date, acc.trans[i].description, acc.trans[i].amount, acc.trans[i].type);
    }
}

void deposit(struct account* acc) {
    float amount;
    printf("Amount to deposit: ");
    scanf("%f", &amount);
    acc->balance += amount;
    printf("Deposit successful. New balance: %0.2f\n", acc->balance);
    addTransaction(acc);
}

void withdraw(struct account* acc) {
    float amount;
    printf("Amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > acc->balance) {
        printf("Insufficient balance.\n");
    } else {
        acc->balance -= amount;
        printf("Withdrawal successful. New balance: %0.2f\n", acc->balance);
        addTransaction(acc);
    }
}

void viewDetails(struct account acc) {
    printf("Account Details: \n");
    printf("Name: %s\n", acc.name);
    printf("Account No: %s\n", acc.accNo);
    printf("Balance: %0.2f\n", acc.balance);
    viewTransactions(acc);
}

int main() {
    struct account acc;
    printf("Enter name: ");
    scanf("%s", acc.name);
    printf("Enter account number: ");
    scanf("%s", acc.accNo);
    acc.balance = 0;
    acc.transCount = 0;
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Deposit\n2. Withdraw\n3. View details\n4. Exit\n\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                deposit(&acc);
                break;
            case 2:
                withdraw(&acc);
                break;
            case 3:
                viewDetails(acc);
                break;
            case 4:
                printf("Thank you!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}