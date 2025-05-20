//FormAI DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 1000

struct Expense {
    char date[11];
    char category[20];
    double amount;
};

void addExpense(struct Expense*, int*);
void viewExpenses(struct Expense*, int);
void exportExpenses(struct Expense*, int);

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;
    do {
        printf("Expense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Export Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                exportExpenses(expenses, numExpenses);
                break;
            case 4:
                printf("Bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}

void addExpense(struct Expense *expenses, int *numExpenses) {
    if(*numExpenses == MAX_EXPENSES) {
        printf("Expense limit reached.\n");
        return;
    }
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", expenses[*numExpenses].date);
    printf("Enter category: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Enter amount: ");
    scanf("%lf", &expenses[*numExpenses].amount);
    (*numExpenses)++;
    printf("Expense added successfully.\n");
}

void viewExpenses(struct Expense *expenses, int numExpenses) {
    if(numExpenses == 0) {
        printf("No expenses to display.\n");
        return;
    }
    double total = 0.0;
    printf("Date\t\tCategory\tAmount\n");
    for(int i = 0; i < numExpenses; i++) {
        printf("%s\t%s\t\t$%.2lf\n", expenses[i].date, expenses[i].category,expenses[i].amount);
        total += expenses[i].amount;
    }
    printf("Total Expenses: $%.2lf\n", total);
}

void exportExpenses(struct Expense *expenses, int numExpenses) {
    if(numExpenses == 0) {
        printf("No expenses to export.\n");
        return;
    }
    FILE *fp = fopen("expenses.txt", "w");
    if(fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(fp, "Date, Category, Amount\n");
    for(int i = 0; i < numExpenses; i++) {
        fprintf(fp, "%s, %s, %.2lf\n",expenses[i].date, expenses[i].category, expenses[i].amount);
    }
    fclose(fp);
    printf("Expenses exported successfully.\n");
}