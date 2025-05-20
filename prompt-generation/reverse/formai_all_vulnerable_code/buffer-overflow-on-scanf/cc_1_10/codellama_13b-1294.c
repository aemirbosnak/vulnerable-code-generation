//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: lively
/*
*  Expense Tracker in C
*  Created by [Your Name]
*  Date: [Date]
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to store expense details
struct expense {
    char category[50];
    char description[100];
    float amount;
};

// Function to add an expense
void add_expense(struct expense *expense) {
    printf("Enter the category: ");
    scanf("%s", expense->category);
    printf("Enter the description: ");
    scanf("%s", expense->description);
    printf("Enter the amount: ");
    scanf("%f", &expense->amount);
}

// Function to display all expenses
void display_expenses(struct expense *expense, int n) {
    int i;
    printf("All Expenses:\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s - %s - %f\n", i + 1, expense[i].category, expense[i].description, expense[i].amount);
    }
}

// Function to display total expenses
void display_total_expenses(struct expense *expense, int n) {
    int i;
    float total = 0;
    for (i = 0; i < n; i++) {
        total += expense[i].amount;
    }
    printf("Total Expenses: %f\n", total);
}

// Function to display average expense
void display_average_expense(struct expense *expense, int n) {
    int i;
    float total = 0;
    for (i = 0; i < n; i++) {
        total += expense[i].amount;
    }
    printf("Average Expense: %f\n", total / n);
}

int main() {
    struct expense expenses[10];
    int n, i;
    printf("Enter the number of expenses: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        add_expense(&expenses[i]);
    }
    display_expenses(expenses, n);
    display_total_expenses(expenses, n);
    display_average_expense(expenses, n);
    return 0;
}