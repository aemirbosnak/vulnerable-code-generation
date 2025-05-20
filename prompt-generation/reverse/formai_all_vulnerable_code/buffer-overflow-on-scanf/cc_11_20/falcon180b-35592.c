//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTION_LENGTH 100

typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    double balance;
} Account;

int main() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;

    while (num_accounts < MAX_ACCOUNTS) {
        printf("Enter account number: ");
        scanf("%d", &accounts[num_accounts].account_number);

        printf("Enter account holder name: ");
        scanf("%s", accounts[num_accounts].name);

        printf("Enter initial balance: ");
        scanf("%lf", &accounts[num_accounts].balance);

        num_accounts++;
    }

    while (1) {
        printf("\nWelcome to the Banking System!\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter account number: ");
            int account_number;
            scanf("%d", &account_number);

            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].account_number == account_number) {
                    printf("Enter deposit amount: ");
                    double deposit_amount;
                    scanf("%lf", &deposit_amount);

                    accounts[i].balance += deposit_amount;

                    printf("Deposit successful! New balance: %.2lf\n", accounts[i].balance);
                    break;
                }
            }
        } else if (choice == 2) {
            printf("Enter account number: ");
            int account_number;
            scanf("%d", &account_number);

            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].account_number == account_number) {
                    printf("Enter withdrawal amount: ");
                    double withdrawal_amount;
                    scanf("%lf", &withdrawal_amount);

                    if (accounts[i].balance >= withdrawal_amount) {
                        accounts[i].balance -= withdrawal_amount;

                        printf("Withdrawal successful! New balance: %.2lf\n", accounts[i].balance);
                    } else {
                        printf("Insufficient balance.\n");
                    }

                    break;
                }
            }
        } else if (choice == 3) {
            printf("Enter account number: ");
            int account_number;
            scanf("%d", &account_number);

            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].account_number == account_number) {
                    printf("Current balance: %.2lf\n", accounts[i].balance);
                    break;
                }
            }
        } else if (choice == 4) {
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}