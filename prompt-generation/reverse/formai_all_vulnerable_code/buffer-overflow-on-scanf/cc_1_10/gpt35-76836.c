//FormAI DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 50

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    Date date;
    float amount;
    char details[MAX_CHAR];
} Expense;

void addExpense(Expense *expenses, int *numExpenses) {
    Expense newExpense;
    printf("Enter the date of the expense (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &newExpense.date.day, &newExpense.date.month, &newExpense.date.year);
    printf("Enter the amount of the expense: ");
    scanf("%f", &newExpense.amount);
    printf("Enter a brief description of the expense: ");
    scanf(" %[^\n]s", newExpense.details);
    expenses[*numExpenses] = newExpense;
    *numExpenses += 1;
}

void printExpenses(Expense *expenses, int numExpenses) {
    printf("Date\t\tAmount\tDetails\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%02d/%02d/%04d\t%.2f\t%s\n", expenses[i].date.day, expenses[i].date.month, expenses[i].date.year, expenses[i].amount, expenses[i].details);
    }
    printf("\n");
}

float getTotalExpenses(Expense *expenses, int numExpenses) {
    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    Expense expenses[100];
    int numExpenses = 0;
    int choice;
    do {
        printf("Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. View Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense(&expenses[numExpenses], &numExpenses);
                break;
            case 2:
                printExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Total Expenses: %.2f\n", getTotalExpenses(expenses, numExpenses));
                break;
            case 4:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid Choice, Try Again.\n");
        }
    } while (choice != 4);
    
    return 0;
}