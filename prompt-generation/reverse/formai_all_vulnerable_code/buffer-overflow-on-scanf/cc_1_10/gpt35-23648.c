//FormAI DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include <stdio.h>

// declare a struct for each expense entry
typedef struct Expense {
    int id;
    char description[50];
    float amount;
} Expense;

// function to add a new expense to the tracker
void addExpense(Expense expenses[], int *numExpenses) {
    Expense newExpense;

    printf("Enter expense description: ");
    scanf("%s", newExpense.description);

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    newExpense.id = *numExpenses;
    expenses[*numExpenses] = newExpense;

    printf("Expense added successfully.\n");

    *numExpenses = *numExpenses + 1;
}

// function to display all expenses in the tracker
void displayExpenses(Expense expenses[], int numExpenses) {
    if (numExpenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("ID\tDescription\tAmount\n");

    for (int i = 0; i < numExpenses; i++) {
        Expense expense = expenses[i];
        printf("%d\t%s\t$%.2f\n", expense.id, expense.description, expense.amount);
    }
}

int main() {
    Expense expenses[100];
    int numExpenses = 0;

    int choice;
    do {
        printf("\nExpense Tracker Menu\n");
        printf("====================\n");
        printf("1) Add Expense\n");
        printf("2) Display Expenses\n");
        printf("3) Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                displayExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Exiting Expense Tracker...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}