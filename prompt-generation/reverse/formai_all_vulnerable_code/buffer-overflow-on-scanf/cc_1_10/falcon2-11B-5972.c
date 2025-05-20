//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int balance;
} Account;

int main() {
    Account accounts[10]; // Create an array of 10 accounts
    int i, j;
    char choice;
    char name[50];
    int balance;

    printf("Welcome to the Bank!\n");
    printf("Please enter your name:\n");
    scanf("%s", name);

    for (i = 0; i < 10; i++) {
        accounts[i].name[0] = '\0';
        accounts[i].balance = 0;
    }

    printf("\nAccounts:\n");
    for (i = 0; i < 10; i++) {
        printf("Account %d: %s - %.2f\n", i+1, accounts[i].name, accounts[i].balance);
    }

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the amount to deposit: ");
                scanf("%d", &balance);
                accounts[i].balance += balance;
                break;
            case 2:
                printf("\nEnter the amount to withdraw: ");
                scanf("%d", &balance);
                if (accounts[i].balance >= balance) {
                    accounts[i].balance -= balance;
                } else {
                    printf("Insufficient funds.\n");
                }
                break;
            case 3:
                printf("\nYour current balance is %.2f.\n", accounts[i].balance);
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}