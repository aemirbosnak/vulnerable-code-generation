//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 50
#define MAX_STRING_LENGTH 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    float amount;
} BudgetItem;

typedef struct {
    BudgetItem items[MAX_BUDGET_ITEMS];
    int itemCount;
} Budget;

void displayMenu() {
    printf("Personal Finance Planner\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Budget\n");
    printf("4. Delete Item\n");
    printf("5. View Summary\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void addBudgetItem(Budget* budget, const char* name, float amount) {
    if (budget->itemCount < MAX_BUDGET_ITEMS) {
        strcpy(budget->items[budget->itemCount].name, name);
        budget->items[budget->itemCount].amount = amount;
        budget->itemCount++;
        printf("Added: %s - $%.2f\n", name, amount);
    } else {
        printf("Budget item limit reached.\n");
    }
}

void deleteBudgetItem(Budget* budget, const char* name) {
    for (int i = 0; i < budget->itemCount; i++) {
        if (strcmp(budget->items[i].name, name) == 0) {
            for (int j = i; j < budget->itemCount - 1; j++) {
                budget->items[j] = budget->items[j + 1];
            }
            budget->itemCount--;
            printf("Deleted item: %s\n", name);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

void viewBudget(const Budget* budget) {
    printf("\nCurrent Budget:\n");
    for (int i = 0; i < budget->itemCount; i++) {
        printf("%d. %s: $%.2f\n", i + 1, budget->items[i].name, budget->items[i].amount);
    }
    printf("\n");
}

float calculateTotalIncome(const Budget* budget) {
    float totalIncome = 0.0;
    for (int i = 0; i < budget->itemCount; i++) {
        if (budget->items[i].amount > 0) {
            totalIncome += budget->items[i].amount;
        }
    }
    return totalIncome;
}

float calculateTotalExpenses(const Budget* budget) {
    float totalExpenses = 0.0;
    for (int i = 0; i < budget->itemCount; i++) {
        if (budget->items[i].amount < 0) {
            totalExpenses += -budget->items[i].amount;
        }
    }
    return totalExpenses;
}

void viewSummary(const Budget* budget) {
    float totalIncome = calculateTotalIncome(budget);
    float totalExpenses = calculateTotalExpenses(budget);
    float balance = totalIncome - totalExpenses;

    printf("\nBudget Summary:\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Balance: $%.2f\n", balance);
    printf("\n");
}

int main() {
    Budget myBudget = { .itemCount = 0 };
    int choice;
    char name[MAX_STRING_LENGTH];
    float amount;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income source: ");
                scanf("%s", name);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                addBudgetItem(&myBudget, name, amount);
                break;

            case 2:
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addBudgetItem(&myBudget, name, -amount);
                break;

            case 3:
                viewBudget(&myBudget);
                break;

            case 4:
                printf("Enter name of item to delete: ");
                scanf("%s", name);
                deleteBudgetItem(&myBudget, name);
                break;

            case 5:
                viewSummary(&myBudget);
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}