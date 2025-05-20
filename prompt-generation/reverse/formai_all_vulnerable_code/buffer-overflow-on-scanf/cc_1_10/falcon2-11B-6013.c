//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT_NAME_LENGTH 50
#define MAX_ACCOUNT_NUMBER_LENGTH 15
#define MAX_BALANCE_LENGTH 10
#define MAX_TRANSACTIONS_LENGTH 50

struct Account {
    char name[MAX_ACCOUNT_NAME_LENGTH];
    char number[MAX_ACCOUNT_NUMBER_LENGTH];
    char balance[MAX_BALANCE_LENGTH];
    char transactions[MAX_TRANSACTIONS_LENGTH];
};

int main() {
    struct Account account1, account2;
    char choice;

    while (1) {
        printf("Welcome to the Banking Record System!\n");
        printf("Enter 'a' to add an account:\n");
        printf("Enter 'l' to list accounts:\n");
        printf("Enter 'd' to delete an account:\n");
        printf("Enter 'q' to quit:\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter account name: ");
                fgets(account1.name, sizeof(account1.name), stdin);
                strncpy(account1.name, &account1.name[0], MAX_ACCOUNT_NAME_LENGTH - 1);
                printf("Enter account number: ");
                fgets(account1.number, sizeof(account1.number), stdin);
                strncpy(account1.number, &account1.number[0], MAX_ACCOUNT_NUMBER_LENGTH - 1);
                printf("Enter initial balance: ");
                scanf("%s", account1.balance);
                printf("Enter initial transactions: ");
                scanf("%s", account1.transactions);
                printf("Account added successfully.\n");
                break;
            case 'l':
                printf("Accounts:\n");
                printf("Name\t\t\tNumber\tBalance\tTransactions\n");
                printf("----------------------------\n");
                printf("%s\t\t\t%s\t%s\t%s\n", account1.name, account1.number, account1.balance, account1.transactions);
                printf("%s\t\t\t%s\t%s\t%s\n", account2.name, account2.number, account2.balance, account2.transactions);
                break;
            case 'd':
                printf("Enter account number to delete: ");
                scanf("%s", account1.number);
                if (strcmp(account1.number, account2.number) == 0) {
                    printf("Account deleted successfully.\n");
                } else {
                    printf("Account not found.\n");
                }
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}