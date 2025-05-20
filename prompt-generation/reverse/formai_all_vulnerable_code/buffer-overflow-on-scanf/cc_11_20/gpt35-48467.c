//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRANSACTIONS 1000

typedef struct {
    int id;
    char name[50];
    float balance;
} account_t;

typedef struct {
    int id;
    float amount;
    char description[100];
    time_t transaction_time;
} transaction_t;

int main() {
    account_t accounts[100];
    int num_accounts = 0;
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;

    srand(time(NULL));

    while (1) {
        printf("Enter option:\n");
        printf("1. Create account\n");
        printf("2. View account\n");
        printf("3. Make transaction\n");
        printf("4. View transaction history\n");
        printf("5. Exit\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            printf("Enter account name:\n");
            char name[50];
            scanf("%s", name);

            account_t account;
            account.id = rand();
            strcpy(account.name, name);
            account.balance = 0;

            accounts[num_accounts++] = account;
            printf("Account created with id %d.\n", account.id);
        }
        else if (option == 2) {
            printf("Enter account id:\n");
            int id;
            scanf("%d", &id);

            int found = 0;
            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].id == id) {
                    printf("Account name: %s\n", accounts[i].name);
                    printf("Account balance: %.2f\n", accounts[i].balance);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Account with id %d not found.\n", id);
            }
        }
        else if (option == 3) {
            printf("Enter account id:\n");
            int id;
            scanf("%d", &id);

            int found = 0;
            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].id == id) {
                    printf("Enter transaction amount:\n");
                    float amount;
                    scanf("%f", &amount);

                    if (accounts[i].balance + amount < 0) {
                        printf("Insufficient funds.\n");
                    }
                    else {
                        accounts[i].balance += amount;

                        transaction_t transaction;
                        transaction.id = rand();
                        transaction.amount = amount;
                        printf("Enter transaction description:\n");
                        scanf("%s", transaction.description);
                        transaction.transaction_time = time(NULL);

                        transactions[num_transactions++] = transaction;

                        printf("Transaction id: %d\n", transaction.id);
                    }

                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Account with id %d not found.\n", id);
            }
        }
        else if (option == 4) {
            printf("Enter account id:\n");
            int id;
            scanf("%d", &id);

            int found = 0;
            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].id == id) {
                    for (int j = 0; j < num_transactions; j++) {
                        if (transactions[j].id == id) {
                            printf("Transaction id: %d\n", transactions[j].id);
                            printf("Transaction amount: %.2f\n", transactions[j].amount);
                            printf("Transaction description: %s\n", transactions[j].description);
                            printf("Transaction time: %s", ctime(&transactions[j].transaction_time));
                        }
                    }

                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Account with id %d not found.\n", id);
            }
        }
        else if (option == 5) {
            break;
        }
    }

    return 0;
}