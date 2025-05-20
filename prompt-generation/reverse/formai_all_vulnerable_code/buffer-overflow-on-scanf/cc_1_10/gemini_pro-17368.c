//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    int account_number;
    char *name;
    double balance;
} account;

account *accounts;
int num_accounts = 0;

void create_account(void) {
    account *new_account = malloc(sizeof(account));
    printf("Enter account number: ");
    scanf("%d", &new_account->account_number);
    printf("Enter name: ");
    char *name = malloc(100);
    scanf(" %[^\n]s", name);  
    new_account->name = name;
    printf("Enter balance: ");
    scanf("%lf", &new_account->balance);

    accounts = realloc(accounts, (num_accounts + 1) * sizeof(account));
    accounts[num_accounts] = *new_account;
    num_accounts++;

    printf("Account created successfully!\n");
}

void deposit(void) {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            double amount;
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw(void) {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            double amount;
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful!\n");
                return;
            } else {
                printf("Insufficient funds!\n");
                return;
            }
        }
    }
    printf("Account not found!\n");
}

void transfer(void) {
    int account_number1, account_number2;
    printf("Enter account number to transfer from: ");
    scanf("%d", &account_number1);
    printf("Enter account number to transfer to: ");
    scanf("%d", &account_number2);
    int i, j;
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number1) {
            for (j = 0; j < num_accounts; j++) {
                if (accounts[j].account_number == account_number2) {
                    double amount;
                    printf("Enter amount to transfer: ");
                    scanf("%lf", &amount);
                    if (accounts[i].balance >= amount) {
                        accounts[i].balance -= amount;
                        accounts[j].balance += amount;
                        printf("Transfer successful!\n");
                        return;
                    } else {
                        printf("Insufficient funds!\n");
                        return;
                    }
                }
            }
        }
    }
    printf("Account not found!\n");
}

void display_accounts(void) {
    printf("Accounts:\n");
    int i;
    for (i = 0; i < num_accounts; i++) {
        printf("%d %s %.2lf\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

int main(void) {
    int choice;
    while (1) {
        printf("\nBanking Record System\n\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Display Accounts\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                transfer();
                break;
            case 5:
                display_accounts();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n\n");
    }
    return 0;
}