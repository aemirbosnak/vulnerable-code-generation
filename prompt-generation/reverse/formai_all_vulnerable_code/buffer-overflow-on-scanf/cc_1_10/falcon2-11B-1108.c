//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
    char name[20];
    int account_no;
    int balance;
};

void deposit(struct bank_record *record) {
    printf("Enter amount to deposit: ");
    scanf("%d", &record->balance);
}

void withdraw(struct bank_record *record) {
    printf("Enter amount to withdraw: ");
    scanf("%d", &record->balance);
}

void display(struct bank_record *record) {
    printf("Name: %s\n", record->name);
    printf("Account No: %d\n", record->account_no);
    printf("Balance: %d\n", record->balance);
}

int main() {
    struct bank_record bank[100];
    int i, current_account;

    printf("Welcome to the Bank!\n");
    printf("Create a new account? (y/n): ");
    scanf("%c", &i);

    if (i == 'y' || i == 'Y') {
        printf("Enter name: ");
        scanf("%s", bank[0].name);
        bank[0].account_no = 1;
        bank[0].balance = 0;
        printf("Account created successfully!\n");
    } else {
        printf("Account already exists.\n");
    }

    while (1) {
        printf("1. Deposit\n2. Withdrawal\n3. Display balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &current_account);

        switch (current_account) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &current_account);
                deposit(bank + current_account);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &current_account);
                withdraw(bank + current_account);
                break;
            case 3:
                display(bank + current_account);
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}