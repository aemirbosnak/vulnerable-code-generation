//FormAI DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char category[30];
    double cost;
    char date[20];
};

typedef struct expense Expense;

int main() {
    int size = 10;
    int count = 0;
    Expense* expenses = malloc(size * sizeof(Expense));

    // loop to add expenses
    char input[10];
    while(1) {
        printf("Do you want to add an expense? Type 'yes' to continue or 'no' to exit: ");
        scanf("%s", input);
        if (strcmp(input, "no") == 0) {
            break;
        }
        if (count >= size) {
            size *= 2;
            expenses = realloc(expenses, size * sizeof(Expense));
        }
        printf("Category: ");
        scanf("%s", expenses[count].category);
        printf("Cost: $");
        scanf("%lf", &expenses[count].cost);
        printf("Date (MM/DD/YYYY): ");
        scanf("%s", expenses[count].date);
        count++;
    }

    // print all expenses
    printf("\nExpenses:\n");
    printf("%-15s%-10s%s\n", "Category", "Cost", "Date");
    for (int i = 0; i < count; i++) {
        printf("%-15s$%-10.2lf%s\n", expenses[i].category, expenses[i].cost, expenses[i].date);
    }

    // calculate total cost
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].cost;
    }
    printf("\nTotal Cost: $%.2lf\n", total);

    free(expenses);
    return 0;
}