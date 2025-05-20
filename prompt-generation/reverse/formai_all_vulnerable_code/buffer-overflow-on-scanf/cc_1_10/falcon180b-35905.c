//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOME 10

typedef struct {
    char name[50];
    float amount;
    char category[50];
} expense;

typedef struct {
    char name[50];
    float amount;
    char category[50];
} income;

void addExpense(expense *expenses, int *numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses].category);
    (*numExpenses)++;
}

void addIncome(income *incomes, int *numIncomes) {
    printf("Enter income name: ");
    scanf("%s", incomes[*numIncomes].name);
    printf("Enter income amount: ");
    scanf("%f", &incomes[*numIncomes].amount);
    printf("Enter income category: ");
    scanf("%s", incomes[*numIncomes].category);
    (*numIncomes)++;
}

void displayExpenses(expense *expenses, int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void displayIncomes(income *incomes, int numIncomes) {
    printf("\nIncomes:\n");
    for (int i = 0; i < numIncomes; i++) {
        printf("%s - %.2f - %s\n", incomes[i].name, incomes[i].amount, incomes[i].category);
    }
}

void calculateTotalExpenses(expense *expenses, int numExpenses) {
    float totalExpenses = 0.0;
    for (int i = 0; i < numExpenses; i++) {
        totalExpenses += expenses[i].amount;
    }
    printf("\nTotal Expenses: %.2f\n", totalExpenses);
}

void calculateTotalIncomes(income *incomes, int numIncomes) {
    float totalIncomes = 0.0;
    for (int i = 0; i < numIncomes; i++) {
        totalIncomes += incomes[i].amount;
    }
    printf("\nTotal Incomes: %.2f\n", totalIncomes);
}

int main() {
    expense expenses[MAX_EXPENSES];
    income incomes[MAX_INCOME];
    int numExpenses = 0, numIncomes = 0;

    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);

    addIncome(incomes, &numIncomes);
    addIncome(incomes, &numIncomes);

    displayExpenses(expenses, numExpenses);
    displayIncomes(incomes, numIncomes);

    calculateTotalExpenses(expenses, numExpenses);
    calculateTotalIncomes(incomes, numIncomes);

    return 0;
}