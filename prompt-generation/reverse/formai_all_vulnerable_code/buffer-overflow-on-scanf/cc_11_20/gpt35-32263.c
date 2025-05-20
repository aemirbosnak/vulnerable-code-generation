//FormAI DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    int amount;
    Date date;
} Expense;

int main() {
    int choice;
    Expense expenses[1000];
    int numExpenses = 0;
    Date today;
    today.day = 27;
    today.month = 10;
    today.year = 2050;

    while (1) {
        printf("\nWelcome to the Expense Tracker Program of 2050!\n");
        printf("What would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. View expenses by date range\n");
        printf("3. View total expenses\n");
        printf("4. Exit program\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nAdding a new expense...\n");
            Expense expense;
            printf("Enter expense name: ");
            scanf("%s", expense.name);
            printf("Enter expense amount: ");
            scanf("%d", &expense.amount);
            printf("Enter expense date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &expense.date.day, &expense.date.month, &expense.date.year);
            expenses[numExpenses++] = expense;
            printf("\nExpense added successfully!\n");
        } else if (choice == 2) {
            printf("\nViewing expenses by date range...\n");
            Date startDate, endDate;
            printf("Enter start date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &startDate.day, &startDate.month, &startDate.year);
            printf("Enter end date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &endDate.day, &endDate.month, &endDate.year);
            int totalExpensesInRange = 0;
            for (int i = 0; i < numExpenses; i++) {
                Date expenseDate = expenses[i].date;
                if (expenseDate.year >= startDate.year && expenseDate.year <= endDate.year) {
                    if (expenseDate.month >= startDate.month && expenseDate.month <= endDate.month) {
                        if (expenseDate.day >= startDate.day && expenseDate.day <= endDate.day) {
                            printf("%s - %d\n", expenses[i].name, expenses[i].amount);
                            totalExpensesInRange += expenses[i].amount;
                        }
                    }
                }
            }
            printf("Total expenses in date range: %d\n", totalExpensesInRange);
        } else if (choice == 3) {
            printf("\nViewing total expenses...\n");
            int totalExpenses = 0;
            for (int i = 0; i < numExpenses; i++) {
                totalExpenses += expenses[i].amount;
            }
            printf("Total expenses: %d\n", totalExpenses);
        } else if (choice == 4) {
            printf("\nExiting program. Have a nice day!\n");
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}