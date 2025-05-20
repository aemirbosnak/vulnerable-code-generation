//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

void addExpense(Expense* expenses, int numExpenses, char* name, float amount, char* category) {
    if (numExpenses < MAX_EXPENSES) {
        strcpy(expenses[numExpenses].name, name);
        expenses[numExpenses].amount = amount;
        strcpy(expenses[numExpenses].category, category);
        numExpenses++;
    } else {
        printf("Error: Expense limit reached.\n");
    }
}

void displayExpenses(Expense* expenses, int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char input[100];

    while (1) {
        printf("Enter expense (name amount category): ");
        scanf("%s", input);

        char* name = strtok(input, " ");
        float amount = atof(strtok(NULL, " "));
        char* category = strtok(NULL, " ");

        addExpense(expenses, numExpenses, name, amount, category);

        if (numExpenses > 0) {
            displayExpenses(expenses, numExpenses);
        }
    }

    return 0;
}