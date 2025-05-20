//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char item[50];
    float cost;
    char date[11];
    char category[20];
} expenses[100];

void addExpense(int *numExpenses) {
    printf("\nAdding Expense:");
    printf("\nItem: ");
    scanf("%s", expenses[*numExpenses].item);
    printf("Cost: ");
    scanf("%f", &expenses[*numExpenses].cost);
    printf("Date (dd-mm-yyyy): ");
    scanf("%s", expenses[*numExpenses].date);
    printf("Category: ");
    scanf("%s", expenses[*numExpenses].category);
    (*numExpenses)++;
}

void viewExpenses(int numExpenses) {
    if (numExpenses == 0) {
        printf("\nNo expenses added yet.");
        return;
    }

    float totalCost = 0;
    printf("\nExpenses:\n");
    printf("%-20s%-10s%-15s%-20s", "Item", "Cost", "Date", "Category");
    printf("\n------------------------------------------------------------");
    for (int i = 0; i < numExpenses; i++) {
        printf("\n%-20s%-10.2f%-15s%-20s", expenses[i].item, expenses[i].cost, expenses[i].date, expenses[i].category);
        totalCost += expenses[i].cost;
    }
    printf("\n------------------------------------------------------------");
    printf("\nTotal Cost: %.2f", totalCost);
}

void generateReport(int numExpenses) {
    if (numExpenses == 0) {
        printf("\nNo expenses added yet.");
        return;
    }

    float totalCost = 0;
    char start[11], end[11];

    printf("\nGenerating Report:");
    printf("\nEnter starting date (dd-mm-yyyy): ");
    scanf("%s", start);
    printf("Enter ending date (dd-mm-yyyy): ");
    scanf("%s", end);

    printf("\nExpenses between %s and %s:", start, end);
    printf("\n%-20s%-10s%-15s%-20s", "Item", "Cost", "Date", "Category");
    printf("\n------------------------------------------------------------");
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].date, start) >= 0 && strcmp(expenses[i].date, end) <= 0) {
            printf("\n%-20s%-10.2f%-15s%-20s", expenses[i].item, expenses[i].cost, expenses[i].date, expenses[i].category);
            totalCost += expenses[i].cost;
        }
    }
    printf("\n------------------------------------------------------------");
    printf("\nTotal Cost: %.2f", totalCost);
}

int main() {
    int choice, numExpenses = 0;

    printf("CYBER EXPENSE TRACKER PROGRAM\n");

    while (1) {
        printf("\n\n1. Add Expense\n2. View Expenses\n3. Generate Report\n4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&numExpenses);
                break;
            case 2:
                viewExpenses(numExpenses);
                break;
            case 3:
                generateReport(numExpenses);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    }

    return 0;
}