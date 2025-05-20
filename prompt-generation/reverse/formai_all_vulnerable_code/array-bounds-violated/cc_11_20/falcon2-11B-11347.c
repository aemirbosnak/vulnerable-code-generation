//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    char name[100];
    int balance;
};

int main() {
    struct Account accounts[10];
    int numAccounts = 0;
    int choice, index, transaction;
    char operation;

    // Initialization
    printf("Enter the number of accounts: ");
    scanf("%d", &numAccounts);
    printf("\nEnter the account details:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Enter account name: ");
        scanf("%s", accounts[i].name);
        printf("Enter initial balance: ");
        scanf("%d", &accounts[i].balance);
        printf("\n");
    }

    // Menu
    do {
        printf("\nChoose an option:\n1. Add transaction\n2. Withdraw\n3. Deposit\n4. Display account details\n5. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // Add transaction
                printf("Enter operation (add/withdraw): ");
                scanf(" %c", &operation);
                printf("Enter transaction amount: ");
                scanf("%d", &transaction);
                if (operation == 'a') {
                    accounts[index].balance += transaction;
                    printf("Transaction successful.\n");
                } else if (operation == 'w') {
                    if (accounts[index].balance >= transaction) {
                        accounts[index].balance -= transaction;
                        printf("Transaction successful.\n");
                    } else {
                        printf("Insufficient balance.\n");
                    }
                }
                break;
            case 2: // Withdraw
                printf("Enter account number: ");
                scanf("%d", &index);
                if (index < numAccounts) {
                    printf("Enter operation (withdraw/deposit): ");
                    scanf(" %c", &operation);
                    if (operation == 'w') {
                        if (accounts[index].balance >= transaction) {
                            accounts[index].balance -= transaction;
                            printf("Transaction successful.\n");
                        } else {
                            printf("Insufficient balance.\n");
                        }
                    } else if (operation == 'd') {
                        printf("Enter deposit amount: ");
                        scanf("%d", &transaction);
                        accounts[index].balance += transaction;
                        printf("Transaction successful.\n");
                    }
                } else {
                    printf("Invalid account number.\n");
                }
                break;
            case 3: // Deposit
                printf("Enter account number: ");
                scanf("%d", &index);
                if (index < numAccounts) {
                    printf("Enter deposit amount: ");
                    scanf("%d", &transaction);
                    accounts[index].balance += transaction;
                    printf("Transaction successful.\n");
                } else {
                    printf("Invalid account number.\n");
                }
                break;
            case 4: // Display account details
                for (int i = 0; i < numAccounts; i++) {
                    printf("Account %d:\nName: %s\nBalance: %d\n", i+1, accounts[i].name, accounts[i].balance);
                }
                break;
            case 5: // Quit
                printf("Thank you for using the Personal Finance Planner.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}