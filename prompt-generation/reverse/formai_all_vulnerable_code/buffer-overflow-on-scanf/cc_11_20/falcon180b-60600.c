//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 10
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_TRANSACTION_HISTORY 100

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    double amount;
} BudgetItem;

typedef struct {
    char description;
    double amount;
    int month;
    int year;
} Transaction;

int main() {
    char choice;
    int numBudgetItems = 0;
    BudgetItem budgetItems[MAX_BUDGET_ITEMS];
    int numTransactions = 0;
    Transaction transactions[MAX_TRANSACTION_HISTORY];

    printf("Welcome to the Personal Finance Planner!\n\n");

    while(1) {
        printf("Please choose an option:\n");
        printf("1. Add budget item\n");
        printf("2. Remove budget item\n");
        printf("3. View budget\n");
        printf("4. Add transaction\n");
        printf("5. View transaction history\n");
        printf("6. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numBudgetItems >= MAX_BUDGET_ITEMS) {
                    printf("Maximum number of budget items reached.\n");
                } else {
                    printf("Enter budget item name: ");
                    scanf("%s", budgetItems[numBudgetItems].name);
                    printf("Enter budget amount: $");
                    scanf("%lf", &budgetItems[numBudgetItems].amount);
                    numBudgetItems++;
                }
                break;
            case '2':
                if(numBudgetItems == 0) {
                    printf("No budget items to remove.\n");
                } else {
                    printf("Enter budget item to remove: ");
                    scanf("%s", budgetItems[numBudgetItems-1].name);
                    numBudgetItems--;
                }
                break;
            case '3':
                printf("Budget:\n");
                for(int i=0; i<numBudgetItems; i++) {
                    printf("%s - $%.2f\n", budgetItems[i].name, budgetItems[i].amount);
                }
                break;
            case '4':
                if(numTransactions >= MAX_TRANSACTION_HISTORY) {
                    printf("Maximum number of transactions reached.\n");
                } else {
                    printf("Enter transaction description: ");
                    scanf(" %c", &transactions[numTransactions].description);
                    printf("Enter transaction amount: $");
                    scanf("%lf", &transactions[numTransactions].amount);
                    printf("Enter transaction month (1-12): ");
                    scanf("%d", &transactions[numTransactions].month);
                    printf("Enter transaction year (YYYY): ");
                    scanf("%d", &transactions[numTransactions].year);
                    numTransactions++;
                }
                break;
            case '5':
                printf("Transaction history:\n");
                for(int i=0; i<numTransactions; i++) {
                    printf("%c - $%.2f - %02d/%04d\n", transactions[i].description, transactions[i].amount, transactions[i].month, transactions[i].year);
                }
                break;
            case '6':
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}