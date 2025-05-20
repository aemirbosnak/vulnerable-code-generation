//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int balance;
} Account;

int main() {
    Account accounts[10];
    int num_accounts = 0;
    int choice;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do? (1-9)\n");
        printf("1. Create a new account\n");
        printf("2. Add expense\n");
        printf("3. Remove expense\n");
        printf("4. View account balance\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account name: ");
                fgets(accounts[num_accounts].name, sizeof(accounts[num_accounts].name), stdin);
                accounts[num_accounts].balance = 0;
                printf("Account %s created.\n", accounts[num_accounts].name);
                num_accounts++;
                break;

            case 2:
                printf("Enter expense amount: $");
                scanf("%f", &accounts[num_accounts - 1].balance);
                printf("Expense added to account %s.\n", accounts[num_accounts - 1].name);
                break;

            case 3:
                printf("Enter account name: ");
                fgets(accounts[num_accounts - 1].name, sizeof(accounts[num_accounts - 1].name), stdin);
                printf("Expense removed from account %s.\n", accounts[num_accounts - 1].name);
                accounts[num_accounts - 1].balance = 0;
                break;

            case 4:
                printf("Account balance: $%d\n", accounts[num_accounts - 1].balance);
                break;

            case 5:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}