//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOME 10

typedef struct {
    char name[50];
    float amount;
} Expense;

typedef struct {
    char name[50];
    float amount;
} Income;

void addExpense(Expense expenses[], int numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[numExpenses].amount);
    numExpenses++;
}

void addIncome(Income incomes[], int numIncomes) {
    printf("Enter income name: ");
    scanf("%s", incomes[numIncomes].name);
    printf("Enter income amount: ");
    scanf("%f", &incomes[numIncomes].amount);
    numIncomes++;
}

void displayExpenses(Expense expenses[], int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void displayIncomes(Income incomes[], int numIncomes) {
    printf("Incomes:\n");
    for (int i = 0; i < numIncomes; i++) {
        printf("%s: $%.2f\n", incomes[i].name, incomes[i].amount);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    Income incomes[MAX_INCOME];
    int numIncomes = 0;

    addExpense(expenses, numExpenses);
    addExpense(expenses, numExpenses);
    addExpense(expenses, numExpenses);

    addIncome(incomes, numIncomes);
    addIncome(incomes, numIncomes);

    displayExpenses(expenses, numExpenses);
    displayIncomes(incomes, numIncomes);

    return 0;
}