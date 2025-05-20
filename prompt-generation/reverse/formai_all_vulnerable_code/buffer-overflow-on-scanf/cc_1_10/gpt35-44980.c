//FormAI DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Structure for storing expenses
struct Expense {
    float amount;
    char category[20];
};

// Function to add expenses
void addExpense(struct Expense expenses[], int* count) {
    printf("Enter the amount: ");
    scanf("%f", &expenses[*count].amount);
    printf("Enter the category: ");
    scanf("%s", expenses[*count].category);
    (*count)++;
}

// Function to print all expenses
void printExpenses(struct Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses found!\n");
        return;
    }
    printf("Amount\tCategory\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f\t%s\n", expenses[i].amount, expenses[i].category);
    }
}

// Function to calculate total expenses
float calculateTotalExpenses(struct Expense expenses[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    struct Expense expenses[100];
    int count = 0;
    int choice;

    // Display menu
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                printExpenses(expenses, count);
                break;
            case 3:
                printf("Total expenses: %.2f\n", calculateTotalExpenses(expenses, count));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}