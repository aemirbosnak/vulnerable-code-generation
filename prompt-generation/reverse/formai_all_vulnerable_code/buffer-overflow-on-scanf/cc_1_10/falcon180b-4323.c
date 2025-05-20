//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUDGET_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    float budget;
    float spent;
} budget_category;

typedef struct {
    time_t date;
    char description[100];
    float amount;
    char category[50];
} transaction;

budget_category budget[MAX_BUDGET_CATEGORIES];
transaction transactions[MAX_TRANSACTIONS];
int num_budget_categories = 0;
int num_transactions = 0;

void add_budget_category() {
    if (num_budget_categories >= MAX_BUDGET_CATEGORIES) {
        printf("Maximum number of budget categories reached.\n");
        return;
    }

    printf("Enter budget category name: ");
    scanf("%s", budget[num_budget_categories].name);

    printf("Enter budget for this category: ");
    scanf("%f", &budget[num_budget_categories].budget);

    printf("Enter amount spent in this category so far: ");
    scanf("%f", &budget[num_budget_categories].spent);

    num_budget_categories++;
}

void display_budget() {
    printf("\nBudget:\n");
    for (int i = 0; i < num_budget_categories; i++) {
        printf("%s: $%.2f (Spent: $%.2f)\n", budget[i].name, budget[i].budget, budget[i].spent);
    }
}

void add_transaction() {
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Maximum number of transactions reached.\n");
        return;
    }

    time_t now = time(NULL);
    strftime(transactions[num_transactions].date, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    printf("Enter transaction description: ");
    scanf("%s", transactions[num_transactions].description);

    printf("Enter transaction amount: ");
    scanf("%f", &transactions[num_transactions].amount);

    printf("Enter category for this transaction (or leave blank for no category): ");
    scanf("%s", transactions[num_transactions].category);

    num_transactions++;
}

void display_transactions() {
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - $%.2f (%s)\n", transactions[i].date, transactions[i].amount, transactions[i].category);
    }
}

void display_summary() {
    float total_spent = 0;
    for (int i = 0; i < num_budget_categories; i++) {
        total_spent += budget[i].spent;
    }

    printf("\nSummary:\n");
    printf("Total spent: $%.2f\n", total_spent);
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");

    while (1) {
        printf("\nOptions:\n1. Add budget category\n2. Add transaction\n3. Display budget\n4. Display transactions\n5. Display summary\n6. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_budget_category();
                break;
            case 2:
                add_transaction();
                break;
            case 3:
                display_budget();
                break;
            case 4:
                display_transactions();
                break;
            case 5:
                display_summary();
                break;
            case 6:
                printf("Thank you for using the Personal Finance Planner!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}