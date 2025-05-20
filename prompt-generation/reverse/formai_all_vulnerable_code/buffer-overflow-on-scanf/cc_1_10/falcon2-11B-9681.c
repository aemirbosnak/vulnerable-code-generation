//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accountNumber;
    char name[50];
    double balance;
};

int main() {
    struct Account* accounts[10]; // assuming there are 10 accounts
    int numAccounts = 10;
    int accountNumber = 0;
    char name[50];
    double balance = 0.0;

    printf("Welcome to the Mind-Bending C Banking Record System!\n");
    printf("Enter the number of accounts to create:\n");
    scanf("%d", &numAccounts);

    for (int i = 0; i < numAccounts; i++) {
        printf("Account %d:\n", i+1);
        printf("Enter account number:\n");
        scanf("%d", &accountNumber);

        printf("Enter account holder's name:\n");
        scanf(" %[^\n]s", name);

        printf("Enter initial balance:\n");
        scanf(" %lf", &balance);

        accounts[i] = (struct Account*)malloc(sizeof(struct Account));
        accounts[i]->accountNumber = accountNumber;
        strcpy(accounts[i]->name, name);
        accounts[i]->balance = balance;
    }

    printf("\nAccounts created successfully!\n");
    printf("Account Numbers:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%d ", accounts[i]->accountNumber);
    }
    printf("\n");

    printf("Account Holders:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%s ", accounts[i]->name);
    }
    printf("\n");

    printf("Initial Balances:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%.2f ", accounts[i]->balance);
    }
    printf("\n");

    return 0;
}