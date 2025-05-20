//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[256];
    int account_number;
    double balance;
} account;

int main() {
    account accounts[10];
    int num_accounts = 0;
    char input[256];

    while (1) {
        printf("1. Add account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Transfer money\n");
        printf("5. Print account info\n");
        printf("6. Exit\n");
        printf("> ");
        fgets(input, sizeof(input), stdin);

        switch (input[0]) {
            case '1':
                if (num_accounts >= 10) {
                    printf("Error: Maximum number of accounts reached.\n");
                } else {
                    printf("Enter name: ");
                    fgets(accounts[num_accounts].name, sizeof(accounts[num_accounts].name), stdin);
                    accounts[num_accounts].account_number = rand() % 1000000;
                    accounts[num_accounts].balance = 0.0;
                    num_accounts++;
                }
                break;
            case '2':
                printf("Enter account number: ");
                int account_number;
                scanf("%d", &account_number);
                int index = -1;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].account_number == account_number) {
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    printf("Error: Account not found.\n");
                } else {
                    printf("Enter amount to deposit: ");
                    double amount;
                    scanf("%lf", &amount);
                    accounts[index].balance += amount;
                }
                break;
            case '3':
                printf("Enter account number: ");
                scanf("%d", &account_number);
                index = -1;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].account_number == account_number) {
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    printf("Error: Account not found.\n");
                } else {
                    printf("Enter amount to withdraw: ");
                    double amount;
                    scanf("%lf", &amount);
                    if (amount > accounts[index].balance) {
                        printf("Error: Insufficient funds.\n");
                    } else {
                        accounts[index].balance -= amount;
                    }
                }
                break;
            case '4':
                printf("Enter source account number: ");
                int source_account_number;
                scanf("%d", &source_account_number);
                index = -1;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].account_number == source_account_number) {
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    printf("Error: Source account not found.\n");
                } else {
                    printf("Enter destination account number: ");
                    int destination_account_number;
                    scanf("%d", &destination_account_number);
                    int destination_index = -1;
                    for (int i = 0; i < num_accounts; i++) {
                        if (accounts[i].account_number == destination_account_number) {
                            destination_index = i;
                            break;
                        }
                    }
                    if (destination_index == -1) {
                        printf("Error: Destination account not found.\n");
                    } else {
                        printf("Enter amount to transfer: ");
                        double amount;
                        scanf("%lf", &amount);
                        if (amount > accounts[index].balance) {
                            printf("Error: Insufficient funds.\n");
                        } else {
                            accounts[index].balance -= amount;
                            accounts[destination_index].balance += amount;
                        }
                    }
                }
                break;
            case '5':
                for (int i = 0; i < num_accounts; i++) {
                    printf("Account %d:\n", accounts[i].account_number);
                    printf("Name: %s\n", accounts[i].name);
                    printf("Balance: %.2f\n", accounts[i].balance);
                    printf("\n");
                }
                break;
            case '6':
                return 0;
            default:
                printf("Invalid input.\n");
        }
    }
    return 0;
}