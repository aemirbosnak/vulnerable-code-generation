//FormAI DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char name[50];
    float amount;
    char category[20];
};

int numExpenses = 0;
struct Expense expenses[MAX_EXPENSES];

void addExpense() {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.");
        return;
    }
    struct Expense e;
    printf("Enter expense name: ");
    fgets(e.name, 50, stdin);
    printf("Enter expense amount: ");
    scanf("%f", &e.amount);
    printf("Enter expense category: ");
    scanf("%s", e.category);
    expenses[numExpenses++] = e;
    printf("Expense added successfully.\n");
}

void viewExpenses() {
    if (numExpenses == 0) {
        printf("No expenses found.\n");
        return;
    }
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s", expenses[i].name);
        printf("Amount: $%.2f\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("--------------------\n");
    }
}

void totalExpenses() {
    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", total);
}

int main() {
    int choice;
    do {
        printf("Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        getchar();  // flush input buffer
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                totalExpenses();
                break;
            case 4:
                printf("Exiting... Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice (1-4).\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}