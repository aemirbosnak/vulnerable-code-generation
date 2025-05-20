//FormAI DATASET v1.0 Category: Expense Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[50];
    float amount;
};

void addExpense(struct Expense *expenses, int *totalExpenses) {
    char category[50];
    float amount;
    printf("\nEnter expense category: ");
    scanf("%s", category);
    printf("Enter expense amount: ");
    scanf("%f", &amount);

    strcpy(expenses[*totalExpenses].category, category);
    expenses[*totalExpenses].amount = amount;
    *totalExpenses += 1;
}

void displayExpenses(struct Expense *expenses, int totalExpenses) {
    printf("\n\t%s\t\t%s\n", "Category", "Amount");
    for (int i = 0; i < totalExpenses; i++) {
        printf("\t%s\t\t%.2f\n", expenses[i].category, expenses[i].amount);
    }
}

float totalExpensesByCategory(struct Expense *expenses, int totalExpenses, char *category) {
    float total = 0;
    for (int i = 0; i < totalExpenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            total += expenses[i].amount;
        }
    }
    return total;
}

void displayTotalExpenses(struct Expense *expenses, int totalExpenses) {
    printf("\nExpense Summary:\n");
    printf("\nTotal Expenses:\t\t%.2f\n", totalExpensesByCategory(expenses, totalExpenses, ""));
    printf("\nHousing:\t\t%.2f", totalExpensesByCategory(expenses, totalExpenses, "Housing"));
    printf("\nTransportation:\t\t%.2f", totalExpensesByCategory(expenses, totalExpenses, "Transportation"));
    printf("\nGroceries:\t\t%.2f", totalExpensesByCategory(expenses, totalExpenses, "Groceries"));
    printf("\nEntertainment:\t\t%.2f", totalExpensesByCategory(expenses, totalExpenses, "Entertainment"));
    printf("\nUtilities:\t\t%.2f", totalExpensesByCategory(expenses, totalExpenses, "Utilities"));
    printf("\nOther:\t\t\t%.2f\n", totalExpensesByCategory(expenses, totalExpenses, "Other"));
}

int main() {
    struct Expense expenses[100];
    int totalExpenses = 0;
    int choice;
    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Display Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addExpense(expenses, &totalExpenses);
                break;
            case 2:
                displayExpenses(expenses, totalExpenses);
                break;
            case 3:
                displayTotalExpenses(expenses, totalExpenses);
                break;
            case 4:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.");
        }
    } while (choice != 4);

    return 0;
}