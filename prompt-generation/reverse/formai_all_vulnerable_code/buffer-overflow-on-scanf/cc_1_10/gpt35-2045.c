//FormAI DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int amount;
    char category[25];
    char date[11]; // format: mm/dd/yyyy
    char notes[100];
} Expense;

void printHeader() {
    printf("%-15s%-15s%-15s%-25s\n", "Date", "Amount", "Category", "Notes");
    printf("---------------------------------------------------------------------\n");
}

void printExpense(Expense e) {
    printf("%-15s%-15d%-15s%-25s\n", e.date, e.amount, e.category, e.notes);
}

void insertExpense(Expense expenses[], int *count) {
    Expense newExpense;
    printf("Enter expense details:\n");
    printf("Amount: ");
    scanf("%d", &newExpense.amount);
    printf("Category: ");
    scanf("%s", newExpense.category);
    printf("Date (mm/dd/yyyy): ");
    scanf("%s", newExpense.date);
    printf("Notes: ");
    scanf("%s", newExpense.notes);

    expenses[*count] = newExpense;
    (*count)++;
}

void viewAllExpenses(Expense expenses[], int count) {
    printHeader();
    for (int i = 0; i < count; i++) {
        printExpense(expenses[i]);
    }
    printf("\n");
}

void filterExpensesByCategory(Expense expenses[], int count) {
    char category[25];
    printf("Enter category name: ");
    scanf("%s", category);

    printHeader();
    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printExpense(expenses[i]);
        }
    }
    printf("\n");
}

void filterExpensesByDate(Expense expenses[], int count) {
    char startDate[11];
    char endDate[11];
    printf("Enter start date (mm/dd/yyyy): ");
    scanf("%s", startDate);
    printf("Enter end date (mm/dd/yyyy): ");
    scanf("%s", endDate);

    printHeader();
    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].date, startDate) >= 0 && strcmp(expenses[i].date, endDate) <= 0) {
            printExpense(expenses[i]);
        }
    }
    printf("\n");
}

void deleteExpense(Expense expenses[], int *count) {
    char date[11];
    printf("Enter date of expense to delete (mm/dd/yyyy): ");
    scanf("%s", date);

    int indexToDelete = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(expenses[i].date, date) == 0) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("No expense found with date %s\n", date);
    } else {
        for (int i = indexToDelete; i < *count - 1; i++) {
            expenses[i] = expenses[i+1];
        }
        (*count)--;
        printf("Expense with date %s has been deleted\n", date);
    }
}

int main() {
    Expense expenses[100];
    int count = 0;
    int choice;

    while (1) {
        printf("Menu:\n");
        printf("1. Add expense\n");
        printf("2. View all expenses\n");
        printf("3. Filter expenses by category\n");
        printf("4. Filter expenses by date range\n");
        printf("5. Delete expense\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertExpense(expenses, &count);
                break;
            case 2:
                viewAllExpenses(expenses, count);
                break;
            case 3:
                filterExpensesByCategory(expenses, count);
                break;
            case 4:
                filterExpensesByDate(expenses, count);
                break;
            case 5:
                deleteExpense(expenses, &count);
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}