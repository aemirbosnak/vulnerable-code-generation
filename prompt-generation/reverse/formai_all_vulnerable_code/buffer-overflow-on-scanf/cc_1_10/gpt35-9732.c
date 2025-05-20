//FormAI DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100 // Maximum number of expenses that can be tracked
#define MAX_DESC_LENGTH 30 // Maximum length of expense description
#define DATE_LENGTH 11 // Length of date string in format YYYY/MM/DD

typedef struct {
    char date[DATE_LENGTH];
    char description[MAX_DESC_LENGTH];
    double amount;
} Expense;

Expense expenses[MAX_EXPENSES]; // Array to store expenses
int num_expenses = 0; // Counter to keep track of number of expenses added

void print_menu() {
    printf("\nExpense Tracker\n\n");
    printf("Menu:\n");
    printf("1. Add expense\n");
    printf("2. View all expenses\n");
    printf("3. View expenses by date\n");
    printf("4. Exit\n");
}

void add_expense() {
    Expense expense;
    printf("\nEnter expense details:\n");
    printf("Date (YYYY/MM/DD): ");
    scanf("%s", expense.date);
    printf("Description: ");
    scanf("%s", expense.description);
    printf("Amount: ");
    scanf("%lf", &expense.amount);
    expenses[num_expenses] = expense;
    num_expenses++;
    printf("\nExpense added successfully!\n");
}

void view_all_expenses() {
    if (num_expenses == 0) {
        printf("\nNo expenses added yet!\n");
    } else {
        printf("\nAll Expenses:\n");
        for (int i = 0; i < num_expenses; i++) {
            printf("%s %s $%.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
        }
    }
}

void view_expenses_by_date() {
    char date[DATE_LENGTH];
    int count = 0;
    printf("\nEnter date (YYYY/MM/DD): ");
    scanf("%s", date);
    printf("\nExpenses on %s:\n", date);
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].date, date) == 0) {
            printf("%s %s $%.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
            count++;
        }
    }
    if (count == 0) {
        printf("No expenses on %s.\n", date);
    }
}

int main() {
    int choice = 0;
    while (choice != 4) {
        print_menu();
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_all_expenses();
                break;
            case 3:
                view_expenses_by_date();
                break;
            case 4:
                printf("\nThank you for using Expense Tracker!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
    return 0;
}