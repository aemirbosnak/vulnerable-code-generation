//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_ACCOUNTS 10

typedef struct {
    char name[50];
    double balance;
} Account;

typedef struct {
    char category[50];
    double amount;
} Expense;

int main() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    int choice = 0;

    while (choice!= 4) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Account\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_accounts >= MAX_ACCOUNTS) {
                printf("Maximum number of accounts reached.\n");
            } else {
                printf("Enter account name: ");
                scanf("%s", accounts[num_accounts].name);
                printf("Enter account balance: $");
                scanf("%lf", &accounts[num_accounts].balance);
                num_accounts++;
            }
            break;

        case 2:
            if (num_expenses >= MAX_EXPENSES) {
                printf("Maximum number of expenses reached.\n");
            } else {
                printf("Enter expense category: ");
                scanf("%s", expenses[num_expenses].category);
                printf("Enter expense amount: $");
                scanf("%lf", &expenses[num_expenses].amount);
                num_expenses++;
            }
            break;

        case 3:
            printf("\nAccount Summary:\n");
            for (int i = 0; i < num_accounts; i++) {
                printf("%s: $%.2lf\n", accounts[i].name, accounts[i].balance);
            }

            printf("\nExpense Summary:\n");
            for (int i = 0; i < num_expenses; i++) {
                printf("%s: $%.2lf\n", expenses[i].category, expenses[i].amount);
            }
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}