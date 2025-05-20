//FormAI DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>

#define MAX_EXPENSES 100

// Structure for expense entry
struct Expense {
    int id;
    char category[20];
    float amount;
};

// Function declarations
int addExpense(struct Expense expenses[], int count);
void displayExpenses(struct Expense expenses[], int count);
void displayTotalExpenses(struct Expense expenses[], int count);

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int count = 0, choice;

    do {
        // Display menu options
        printf("\nSelect an option:\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. View total expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            count = addExpense(expenses, count);
            break;
        case 2:
            displayExpenses(expenses, count);
            break;
        case 3:
            displayTotalExpenses(expenses, count);
            break;
        case 4:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new expense
int addExpense(struct Expense expenses[], int count) {
    struct Expense expense;
    printf("\nEnter expense details:\n");
    printf("ID: ");
    scanf("%d", &expense.id);
    printf("Category: ");
    scanf("%s", expense.category);
    printf("Amount: ");
    scanf("%f", &expense.amount);
    expenses[count++] = expense;
    printf("Expense added successfully.\n");
    return count;
}

// Function to display all expenses
void displayExpenses(struct Expense expenses[], int count) {
    printf("\nExpenses list:\n");
    printf("ID\tCategory\tAmount\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", expenses[i].id, expenses[i].category, expenses[i].amount);
    }
}

// Function to display total expenses
void displayTotalExpenses(struct Expense expenses[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("\nTotal expenses: %.2f\n", total);
}