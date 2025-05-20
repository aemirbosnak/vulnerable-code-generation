//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float balance;
} Account;

Account accounts[100];
int numAccounts = 0;

void createAccount(char *name, float balance) {
    if (numAccounts >= 100) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }

    strcpy(accounts[numAccounts].name, name);
    accounts[numAccounts].balance = balance;
    numAccounts++;
}

void deposit(char *name, float amount) {
    int i;

    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            accounts[i].balance += amount;
            printf("Deposit successful.\n");
            return;
        }
    }

    printf("Error: Account not found.\n");
}

void withdraw(char *name, float amount) {
    int i;

    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful.\n");
                return;
            } else {
                printf("Error: Insufficient funds.\n");
                return;
            }
        }
    }

    printf("Error: Account not found.\n");
}

void showBalance(char *name) {
    int i;

    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Error: Account not found.\n");
}

int main() {
    char choice;
    char name[50];
    float amount;

    while (1) {
        printf("\nBanking Record System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Show Balance\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter balance: ");
            scanf("%f", &amount);
            createAccount(name, amount);
            break;
        case '2':
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter amount: ");
            scanf("%f", &amount);
            deposit(name, amount);
            break;
        case '3':
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter amount: ");
            scanf("%f", &amount);
            withdraw(name, amount);
            break;
        case '4':
            printf("Enter name: ");
            scanf("%s", name);
            showBalance(name);
            break;
        case '5':
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}