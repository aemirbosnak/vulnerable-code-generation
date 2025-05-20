//FormAI DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EXPENSES 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    double amount;
    Date date;
} Expense;

Expense expenses[MAX_EXPENSES];
int totalExpenses = 0;

void addExpense(char *name, double amount, int day, int month, int year) {
    Expense expense;
    strcpy(expense.name, name);
    expense.amount = amount;
    expense.date.day = day;
    expense.date.month = month;
    expense.date.year = year;
    expenses[totalExpenses++] = expense;
    printf("Expense added!\n");
}

void printExpenses() {
    if(totalExpenses == 0) {
        printf("No expenses yet!\n");
        return;
    }
    printf("Name\tAmount\t\tDate\n");
    for(int i = 0; i < totalExpenses; i++) {
        printf("%s\t%0.2f\t\t%02d/%02d/%d\n", expenses[i].name, expenses[i].amount, expenses[i].date.day, expenses[i].date.month, expenses[i].date.year);
    }
}

void printOptions() {
    printf("\n1. Add Expense\n");
    printf("2. Print Expenses\n");
    printf("3. Exit\n");
}

int main() {
    int choice = 0;
    do {
        printOptions();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                char name[50];
                double amount;
                int day, month, year;
                printf("Enter name of expense: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%lf", &amount);
                printf("Enter date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                addExpense(name, amount, day, month, year);
                break;
            }
            case 2: {
                printExpenses();
                break;
            }
            case 3: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while (choice != 3);
    return 0;
}