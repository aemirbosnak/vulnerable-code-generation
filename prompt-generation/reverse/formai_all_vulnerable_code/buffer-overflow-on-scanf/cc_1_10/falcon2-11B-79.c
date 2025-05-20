//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10

typedef struct {
    char name[50];
    double amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void addExpense(const char* name, double amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Expenses list is full.\n");
        return;
    }

    if (num_expenses == 0) {
        strcpy(expenses[num_expenses].name, name);
        expenses[num_expenses].amount = amount;
    } else {
        int i;
        for (i = 0; i < num_expenses; i++) {
            if (strcmp(expenses[i].name, name) == 0) {
                expenses[i].amount += amount;
                break;
            }
        }

        if (i == num_expenses) {
            strcpy(expenses[num_expenses].name, name);
            expenses[num_expenses].amount = amount;
        }
    }

    num_expenses++;
}

double getTotalExpenses() {
    double total = 0;
    int i;

    for (i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    return total;
}

int main() {
    char name[50];
    double amount;

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter expense amount: ");
    scanf("%lf", &amount);

    addExpense(name, amount);

    printf("Total expenses: %.2lf\n", getTotalExpenses());

    return 0;
}