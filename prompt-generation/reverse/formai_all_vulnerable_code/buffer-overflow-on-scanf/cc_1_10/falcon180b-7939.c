//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    char category[50];
    float amount;
    int date;
} expense;

void addExpense(expense *expenses, int *numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);
    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[*numExpenses].date);
    (*numExpenses)++;
}

void printExpenses(expense *expenses, int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %s - $%.2f - %d\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

void sortExpenses(expense *expenses, int numExpenses) {
    for (int i = 0; i < numExpenses - 1; i++) {
        for (int j = i + 1; j < numExpenses; j++) {
            if (expenses[i].date > expenses[j].date) {
                expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    printf("Welcome to the Expense Tracker!\n");
    printf("Enter 1 to add an expense, 2 to print expenses, 3 to sort expenses, or 4 to quit:\n");

    int choice;
    while (choice!= 4) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                printExpenses(expenses, numExpenses);
                break;
            case 3:
                sortExpenses(expenses, numExpenses);
                printf("Expenses sorted by date:\n");
                printExpenses(expenses, numExpenses);
                break;
            case 4:
                printf("Thank you for using the Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}