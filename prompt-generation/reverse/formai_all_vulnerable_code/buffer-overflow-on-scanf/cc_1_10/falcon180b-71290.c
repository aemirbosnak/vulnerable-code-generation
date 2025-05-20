//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

void addExpense(Expense *expenses, int *numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", (*expenses).name);
    printf("Enter expense amount: ");
    scanf("%f", &(*expenses).amount);
    printf("Enter expense category: ");
    scanf("%s", (*expenses).category);

    (*numExpenses)++;
    expenses = realloc(expenses, sizeof(Expense) * (*numExpenses));
}

void viewExpenses(Expense *expenses, int numExpenses) {
    printf("\nExpense Tracker\n");
    printf("---------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d. %s - %.2f - %s\n", i+1, expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void searchExpense(Expense *expenses, int numExpenses, char *query) {
    int found = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].name, query) == 0 || strcmp(expenses[i].category, query) == 0) {
            printf("\nExpense found:\n");
            printf("---------------------\n");
            printf("%s - %.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No expense found.\n");
    }
}

int main() {
    Expense *expenses = NULL;
    int numExpenses = 0;

    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);

    viewExpenses(expenses, numExpenses);

    char query[50];
    printf("Enter search query: ");
    scanf("%s", query);
    searchExpense(expenses, numExpenses, query);

    free(expenses);
    return 0;
}