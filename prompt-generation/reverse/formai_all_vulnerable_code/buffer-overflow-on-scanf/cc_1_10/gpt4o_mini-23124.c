//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION_LEN 50

typedef struct {
    char description[MAX_DESCRIPTION_LEN];
    float amount;
} Entry;

typedef struct {
    float income;
    Entry expenses[MAX_ENTRIES];
    int expense_count;
} Finance;

void initializeFinance(Finance* finance) {
    finance->income = 0.0;
    finance->expense_count = 0;
}

void addIncome(Finance* finance, float amount) {
    if (amount < 0) {
        printf("Income cannot be negative!\n");
        return;
    }
    finance->income += amount;
    printf("Income of %.2f added successfully.\n", amount);
}

void addExpense(Finance* finance, const char* description, float amount) {
    if (amount < 0) {
        printf("Expense cannot be negative!\n");
        return;
    }
    if (finance->expense_count >= MAX_ENTRIES) {
        printf("Maximum expense entries reached!\n");
        return;
    }
    strcpy(finance->expenses[finance->expense_count].description, description);
    finance->expenses[finance->expense_count].amount = amount;
    finance->expense_count++;
    printf("Expense added successfully: %s - %.2f\n", description, amount);
}

void showReport(const Finance* finance) {
    printf("\nPersonal Finance Report:\n");
    printf("Total Income: %.2f\n", finance->income);
    float total_expenses = 0.0;
    for (int i = 0; i < finance->expense_count; i++) {
        printf("Expense: %s - %.2f\n", finance->expenses[i].description, finance->expenses[i].amount);
        total_expenses += finance->expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Balance: %.2f\n", finance->income - total_expenses);
}

int main() {
    Finance myFinance;
    initializeFinance(&myFinance);

    while (1) {
        int choice;
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Show Report\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            float income;
            printf("Enter income amount: ");
            scanf("%f", &income);
            addIncome(&myFinance, income);
        } else if (choice == 2) {
            char description[MAX_DESCRIPTION_LEN];
            float expense;
            printf("Enter expense description: ");
            getchar(); // Clear newline from buffer
            fgets(description, MAX_DESCRIPTION_LEN, stdin);
            description[strcspn(description, "\n")] = 0; // Remove trailing newline
            printf("Enter expense amount: ");
            scanf("%f", &expense);
            addExpense(&myFinance, description, expense);
        } else if (choice == 3) {
            showReport(&myFinance);
        } else if (choice == 4) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}