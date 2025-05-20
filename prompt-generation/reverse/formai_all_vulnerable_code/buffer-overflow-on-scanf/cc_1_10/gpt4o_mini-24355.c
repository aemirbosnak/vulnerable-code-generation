//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10

typedef struct {
    char category[20];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count;
    float total_income;
    float total_expense;
} FinancePlanner;

void initialize(FinancePlanner *planner) {
    planner->transaction_count = 0;
    planner->total_income = 0;
    planner->total_expense = 0;
}

void add_transaction(FinancePlanner *planner, const char *category, float amount, const char *date, int is_income) {
    if (planner->transaction_count < MAX_TRANSACTIONS) {
        Transaction *t = &planner->transactions[planner->transaction_count];

        snprintf(t->category, sizeof(t->category), "%s", category);
        t->amount = amount;
        snprintf(t->date, sizeof(t->date), "%s", date);

        if (is_income) {
            planner->total_income += amount;
        } else {
            planner->total_expense += amount;
        }
        
        planner->transaction_count++;
        printf("Transaction added successfully.\n");
    } else {
        printf("Transaction limit reached!\n");
    }
}

void display_summary(const FinancePlanner *planner) {
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", planner->total_income);
    printf("Total Expenses: $%.2f\n", planner->total_expense);
    
    float balance = planner->total_income - planner->total_expense;
    printf("Net Balance: $%.2f\n", balance);
}

void list_transactions(const FinancePlanner *planner) {
    printf("\n--- Transactions ---\n");
    for (int i = 0; i < planner->transaction_count; i++) {
        printf("Date: %s | Category: %s | Amount: $%.2f\n", 
               planner->transactions[i].date, 
               planner->transactions[i].category, 
               planner->transactions[i].amount);
    }
}

int main() {
    FinancePlanner planner;
    initialize(&planner);

    int choice = 0;
    while (choice != 4) {
        printf("\n1. Add Income\n2. Add Expense\n3. View Summary\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char category[20], date[11];
            float amount;
            printf("Enter Income Category: ");
            scanf("%s", category);
            printf("Enter Amount: ");
            scanf("%f", &amount);
            printf("Enter Date (YYYY-MM-DD): ");
            scanf("%s", date);
            add_transaction(&planner, category, amount, date, 1);
        } else if (choice == 2) {
            char category[20], date[11];
            float amount;
            printf("Enter Expense Category: ");
            scanf("%s", category);
            printf("Enter Amount: ");
            scanf("%f", &amount);
            printf("Enter Date (YYYY-MM-DD): ");
            scanf("%s", date);
            add_transaction(&planner, category, amount, date, 0);
        } else if (choice == 3) {
            display_summary(&planner);
            list_transactions(&planner);
        } else if (choice == 4) {
            printf("Exiting the Personal Finance Planner.\n");
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}