//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Expense {
    char name[50];
    double amount;
    int date;
};

struct Expense expenses[100];
int numExpenses = 0;

void addExpense(char* name, double amount, int date) {
    struct Expense expense;
    strcpy(expense.name, name);
    expense.amount = amount;
    expense.date = date;

    expenses[numExpenses] = expense;
    numExpenses++;
}

void printExpenses() {
    for (int i = 0; i < numExpenses; i++) {
        struct Expense expense = expenses[i];
        printf("Name: %s\nAmount: %0.2f\nDate: %d\n\n", expense.name, expense.amount, expense.date);
    }
}

int main() {
    srand(time(0));

    char name[50];
    double amount;
    int date;

    printf("Welcome to the C Expense Tracker!\n");
    printf("Please enter the name of the expense:\n");
    scanf("%s", name);
    printf("Please enter the amount of the expense:\n");
    scanf("%lf", &amount);
    printf("Please enter the date of the expense (mm/dd/yyyy):\n");
    scanf("%d", &date);

    addExpense(name, amount, date);

    printf("Expense added successfully!\n");
    printf("Would you like to add another expense? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    while (choice!= 'n') {
        addExpense(name, amount, date);
        printf("Expense added successfully!\n");
        printf("Would you like to add another expense? (y/n): ");
        scanf(" %c", &choice);
    }

    printExpenses();

    return 0;
}