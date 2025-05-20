//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    char name[50];
    char account_number[20];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void create_account(char *name, char *account_number) {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Max number of accounts reached.\n");
        return;
    }

    strcpy(accounts[num_accounts].name, name);
    strcpy(accounts[num_accounts].account_number, account_number);
    accounts[num_accounts].balance = 0.0;
    num_accounts++;
}

void deposit(int index, float amount) {
    if (index >= 0 && index < num_accounts) {
        accounts[index].balance += amount;
        printf("Deposit successful.\n");
    } else {
        printf("Invalid account index.\n");
    }
}

void withdraw(int index, float amount) {
    if (index >= 0 && index < num_accounts) {
        if (accounts[index].balance >= amount) {
            accounts[index].balance -= amount;
            printf("Withdrawal successful.\n");
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Invalid account index.\n");
    }
}

void print_account(int index) {
    if (index >= 0 && index < num_accounts) {
        printf("Name: %s\n", accounts[index].name);
        printf("Account Number: %s\n", accounts[index].account_number);
        printf("Balance: %.2f\n", accounts[index].balance);
    } else {
        printf("Invalid account index.\n");
    }
}

int main() {
    char name[50], account_number[20];
    int choice, index;
    float amount;

    while (1) {
        printf("\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Print Account\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Account Number: ");
                scanf("%s", account_number);
                create_account(name, account_number);
                break;
            case 2:
                printf("Enter Account Index: ");
                scanf("%d", &index);
                printf("Enter Deposit Amount: ");
                scanf("%f", &amount);
                deposit(index, amount);
                break;
            case 3:
                printf("Enter Account Index: ");
                scanf("%d", &index);
                printf("Enter Withdrawal Amount: ");
                scanf("%f", &amount);
                withdraw(index, amount);
                break;
            case 4:
                printf("Enter Account Index: ");
                scanf("%d", &index);
                print_account(index);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice.\n");
                break;
        }
    }

    return 0;
}