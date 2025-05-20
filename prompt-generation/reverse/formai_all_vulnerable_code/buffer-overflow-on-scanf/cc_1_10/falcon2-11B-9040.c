//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
} Expense;

Expense expenses[100];
int num_expenses = 0;

void addExpense(const char* name, float amount) {
    Expense newExpense;
    strcpy(newExpense.name, name);
    newExpense.amount = amount;
    expenses[num_expenses] = newExpense;
    num_expenses++;
}

void viewExpenses() {
    int i;
    printf("Total expenses: $%0.2f\n", 0);
    for (i = 0; i < num_expenses; i++) {
        printf("%s - $%0.2f\n", expenses[i].name, expenses[i].amount);
        printf("---------------------\n");
    }
}

float calculateTotalExpenses() {
    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    char name[50];
    float amount;

    printf("Add an expense (Y/N)?: ");
    scanf("%c", &name[0]);
    while (name[0] == 'Y' || name[0] == 'y') {
        printf("Name: ");
        scanf("%s", name);
        printf("Amount: ");
        scanf("%f", &amount);
        addExpense(name, amount);
        printf("Add another expense (Y/N)?: ");
        scanf("%c", &name[0]);
    }

    viewExpenses();
    printf("Total expenses: $%0.2f\n", calculateTotalExpenses());

    return 0;
}