//FormAI DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

struct Transaction {
    char type[10];
    double amount;
    char category[50];
    char description[100];
};

int num_transactions = 0;

void print_menu() {
    printf("Expense Tracker\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. View Expenses by Category\n");
    printf("4. View Total Expenses\n");
    printf("5. Exit\n");
}

void add_transaction(struct Transaction transactions[MAX_TRANSACTIONS]) {
    struct Transaction t;

    printf("Enter transaction type (e.g. 'Expense' or 'Income'): ");
    scanf("%s", t.type);

    printf("Enter amount: ");
    scanf("%lf", &t.amount);

    printf("Enter category (e.g. 'Food', 'Entertainment', 'Utilities'): ");
    scanf("%s", t.category);

    printf("Enter description: ");
    scanf("%s", t.description);

    transactions[num_transactions] = t;
    num_transactions++;
}

void view_transactions(struct Transaction transactions[MAX_TRANSACTIONS]) {
    if (num_transactions == 0) {
        printf("There are no transactions to display.\n");
        return;
    }

    printf("Transaction History\n");
    printf("%-10s%-10s%-20s%-50s\n", "Type", "Amount", "Category", "Description");

    double total = 0;

    for (int i = 0; i < num_transactions; i++) {
        struct Transaction t = transactions[i];

        printf("%-10s$%-9.2lf%-20s%-50s\n", t.type, t.amount, t.category, t.description);

        if (strcmp(t.type, "Expense") == 0) {
            total -= t.amount;
        } else {
            total += t.amount;
        }
    }

    printf("\nTotal Expenses: $%.2lf\n", total);
}

void view_expenses_by_category(struct Transaction transactions[MAX_TRANSACTIONS]) {
    char category[50];

    printf("Enter category: ");
    scanf("%s", category);

    printf("Expenses in %s\n", category);
    printf("%-10s%-10s%-50s\n", "Type", "Amount", "Description");

    double total = 0;

    for (int i = 0; i < num_transactions; i++) {
        struct Transaction t = transactions[i];

        if (strcmp(t.category, category) == 0) {
            printf("%-10s$%-9.2lf%-50s\n", t.type, t.amount, t.description);

            if (strcmp(t.type, "Expense") == 0) {
                total -= t.amount;
            } else {
                total += t.amount;
            }
        }
    }

    printf("\nTotal Expenses in %s: $%.2lf\n", category, total);
}

void view_total_expenses(struct Transaction transactions[MAX_TRANSACTIONS]) {
    double expenses = 0;
    double income = 0;

    for (int i = 0; i < num_transactions; i++) {
        struct Transaction t = transactions[i];

        if (strcmp(t.type, "Expense") == 0) {
            expenses += t.amount;
        } else {
            income += t.amount;
        }
    }

    printf("Total Expenses: $%.2lf\n", expenses);
    printf("Total Income: $%.2lf\n", income);
    printf("Net Income: $%.2lf\n", income - expenses);
}

int main() {
    struct Transaction transactions[MAX_TRANSACTIONS];
    int choice;

    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction(transactions);
                break;
            case 2:
                view_transactions(transactions);
                break;
            case 3:
                view_expenses_by_category(transactions);
                break;
            case 4:
                view_total_expenses(transactions);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}