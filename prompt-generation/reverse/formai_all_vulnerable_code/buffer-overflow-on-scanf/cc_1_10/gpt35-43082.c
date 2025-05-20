//FormAI DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char category[20];
    double amount;
    char note[50];
    char date[11];
};

void printExpense(struct Expense expense);
double calculateTotalExpenses(struct Expense expenses[], int numExpenses);
void printExpensesByCategory(struct Expense expenses[], int numExpenses, char category[]);
void printExpensesByDate(struct Expense expenses[], int numExpenses, char date[]);
void addExpense(struct Expense expenses[], int *numExpenses);

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;
    
    do {
        printf("Expense tracker\n");
        printf("-----------------------------------------\n");
        printf("1. Add expense\n");
        printf("2. View total expenses\n");
        printf("3. View expenses by category\n");
        printf("4. View expenses by date\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1: addExpense(expenses, &numExpenses); break;
            case 2: printf("Total expenses: $%.2f\n", calculateTotalExpenses(expenses, numExpenses)); break;
            case 3: {
                char category[20];
                printf("Enter category: ");
                scanf("%s", category);
                printf("\n");
                printExpensesByCategory(expenses, numExpenses, category);
                break;
            }
            case 4: {
                char date[11];
                printf("Enter date (MM/DD/YYYY): ");
                scanf("%s", date);
                printf("\n");
                printExpensesByDate(expenses, numExpenses, date);
                break;
            }
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 5);
    
    return 0;
}

void printExpense(struct Expense expense) {
    printf("Category: %s\n", expense.category);
    printf("Amount: $%.2f\n", expense.amount);
    printf("Note: %s\n", expense.note);
    printf("Date: %s\n\n", expense.date);
}

double calculateTotalExpenses(struct Expense expenses[], int numExpenses) {
    double total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void printExpensesByCategory(struct Expense expenses[], int numExpenses, char category[]) {
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printExpense(expenses[i]);
        }
    }
}

void printExpensesByDate(struct Expense expenses[], int numExpenses, char date[]) {
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].date, date) == 0) {
            printExpense(expenses[i]);
        }
    }
}

void addExpense(struct Expense expenses[], int *numExpenses) {
    if (*numExpenses >= MAX_EXPENSES) {
        printf("Max number of expenses reached. Unable to add expense.\n");
        return;
    }
    
    struct Expense expense;
    
    printf("Enter category: ");
    scanf("%s", expense.category);
    printf("Enter amount: $");
    scanf("%lf", &expense.amount);
    printf("Enter note: ");
    scanf("%s", expense.note);
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", expense.date);
    
    printf("\nExpense added successfully.\n\n");
    
    expenses[*numExpenses] = expense;
    (*numExpenses)++;
}