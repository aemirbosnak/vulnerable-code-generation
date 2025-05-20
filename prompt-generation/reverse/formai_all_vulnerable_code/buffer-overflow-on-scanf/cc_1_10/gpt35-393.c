//FormAI DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char item[20];
    double cost;
    Date date;
} Expense;

void addExpense(Expense expenses[], int *numExpenses);
void showExpenses(Expense expenses[], int numExpenses);
double totalExpense(Expense expenses[], int numExpenses);
void expenseReport(Expense expenses[], int numExpenses);

int main() {
    Expense expenses[100];
    int numExpenses = 0;
    int choice;

    while (1) {
        printf("Expense Tracker\n");
        printf("---------------\n");
        printf("1. Add expense\n");
        printf("2. Show all expenses\n");
        printf("3. Show total expense\n");
        printf("4. Generate expense report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                showExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Total expense: %.2lf\n\n", totalExpense(expenses, numExpenses));
                break;
            case 4:
                expenseReport(expenses, numExpenses);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n\n");
        }
    }

    return 0;
}

void addExpense(Expense expenses[], int *numExpenses) {
    printf("Enter item name: ");
    scanf("%s", expenses[*numExpenses].item);
    printf("Enter item cost: ");
    scanf("%lf", &expenses[*numExpenses].cost);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &expenses[*numExpenses].date.day,
                       &expenses[*numExpenses].date.month,
                       &expenses[*numExpenses].date.year);
    (*numExpenses)++;
    printf("Expense added.\n\n");
}

void showExpenses(Expense expenses[], int numExpenses) {
    printf("All Expenses\n");
    printf("------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d/%d/%d - %s - %.2lf\n", expenses[i].date.day,
                                          expenses[i].date.month,
                                          expenses[i].date.year,
                                          expenses[i].item,
                                          expenses[i].cost);
    }
    printf("\n");
}

double totalExpense(Expense expenses[], int numExpenses) {
    double total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].cost;
    }
    return total;
}

void expenseReport(Expense expenses[], int numExpenses) {
    FILE *fp;
    fp = fopen("expense_report.csv", "w");
    fprintf(fp, "Date,Item,Cost\n");
    for (int i = 0; i < numExpenses; i++) {
        fprintf(fp, "%d/%d/%d,%s,%.2lf\n", expenses[i].date.day,
                                           expenses[i].date.month,
                                           expenses[i].date.year,
                                           expenses[i].item,
                                           expenses[i].cost);
    }
    fclose(fp);
    printf("Expense report generated.\n\n");
}