//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    char *name;
    int account_number;
    double balance;
} account;

account *create_account(char *name, int account_number, double balance) {
    account *new_account = malloc(sizeof(account));
    new_account->name = strdup(name);
    new_account->account_number = account_number;
    new_account->balance = balance;
    return new_account;
}

void deposit(account *account, double amount) {
    account->balance += amount;
}

void withdraw(account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

void print_account(account *account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %d\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
}

int main() {
    account *accounts[100];
    int num_accounts = 0;

    while (1) {
        int choice;

        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Print Account\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[100];
                int account_number;
                double balance;

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter account number: ");
                scanf("%d", &account_number);

                printf("Enter balance: ");
                scanf("%lf", &balance);

                accounts[num_accounts++] = create_account(name, account_number, balance);

                break;
            }
            case 2: {
                int account_number;
                double amount;

                printf("Enter account number: ");
                scanf("%d", &account_number);

                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);

                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i]->account_number == account_number) {
                        deposit(accounts[i], amount);
                        break;
                    }
                }

                break;
            }
            case 3: {
                int account_number;
                double amount;

                printf("Enter account number: ");
                scanf("%d", &account_number);

                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);

                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i]->account_number == account_number) {
                        withdraw(accounts[i], amount);
                        break;
                    }
                }

                break;
            }
            case 4: {
                int account_number;

                printf("Enter account number: ");
                scanf("%d", &account_number);

                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i]->account_number == account_number) {
                        print_account(accounts[i]);
                        break;
                    }
                }

                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}