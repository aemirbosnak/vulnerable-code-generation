//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

/*
Expense Tracker program in Ken Thompson style.
*/

struct Expense {
    char name[30];
    float amount;
    int day;
    int month;
    int year;
};

void addExpense(struct Expense expenses[], int *size);
void showExpenses(struct Expense expenses[], int size);
void filterExpenses(struct Expense expenses[], int size, int month, int year);

int main() {
    char choice = ' ';
    struct Expense expenses[100];
    int size = 0;

    while (choice != 'Q') {
        printf("Expense Tracker\n");
        printf("A - Add an expense\n");
        printf("S - Show all expenses\n");
        printf("F - Filter expenses by month and year\n");
        printf("Q - Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                addExpense(expenses, &size);
                break;
            case 'S':
                showExpenses(expenses, size);
                break;
            case 'F':
                printf("Enter month (1-12): ");
                int month;
                scanf("%d", &month);
                printf("Enter year: ");
                int year;
                scanf("%d", &year);
                filterExpenses(expenses, size, month, year);
                break;
            case 'Q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void addExpense(struct Expense expenses[], int *size) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*size].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*size].amount);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &expenses[*size].day, &expenses[*size].month, &expenses[*size].year);
    (*size)++;
}

void showExpenses(struct Expense expenses[], int size) {
    if (size == 0) {
        printf("No expenses added\n");
        return;
    }

    printf("All expenses:\n");
    for (int i = 0; i < size; i++) {
        printf("%d/%d/%d - $%.2f - %s\n", expenses[i].day, expenses[i].month, expenses[i].year, expenses[i].amount, expenses[i].name);
    }
}

void filterExpenses(struct Expense expenses[], int size, int month, int year) {
    if (size == 0) {
        printf("No expenses added\n");
        return;
    }

    printf("Expenses in %d/%d:\n", month, year);
    for (int i = 0; i < size; i++) {
        if (expenses[i].month == month && expenses[i].year == year) {
            printf("%d/%d/%d - $%.2f - %s\n", expenses[i].day, expenses[i].month, expenses[i].year, expenses[i].amount, expenses[i].name);
        }
    }
}