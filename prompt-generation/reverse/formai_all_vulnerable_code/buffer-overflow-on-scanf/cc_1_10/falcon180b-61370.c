//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

void addExpense(Expense expenses[], int numExpenses) {
    char input[50];
    printf("Enter expense name: ");
    scanf("%s", input);
    strcpy(expenses[numExpenses].name, input);

    printf("Enter expense amount: $");
    scanf("%f", &expenses[numExpenses].amount);

    printf("Enter expense category: ");
    scanf("%s", input);
    strcpy(expenses[numExpenses].category, input);

    numExpenses++;
}

void displayExpenses(Expense expenses[], int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\nAmount: $%.2f\nCategory: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void searchExpense(Expense expenses[], int numExpenses, char searchTerm[]) {
    int found = 0;
    printf("\nSearch results:\n");
    for (int i = 0; i < numExpenses; i++) {
        if (strstr(expenses[i].name, searchTerm) || strstr(expenses[i].category, searchTerm)) {
            printf("Name: %s\nAmount: $%.2f\nCategory: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
            found = 1;
        }
    }
    if (!found) {
        printf("No results found.\n");
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    addExpense(expenses, numExpenses);
    addExpense(expenses, numExpenses);
    addExpense(expenses, numExpenses);

    printf("\nExpenses:\n");
    displayExpenses(expenses, numExpenses);

    char searchTerm[50];
    printf("\nEnter search term: ");
    scanf("%s", searchTerm);
    searchExpense(expenses, numExpenses, searchTerm);

    return 0;
}