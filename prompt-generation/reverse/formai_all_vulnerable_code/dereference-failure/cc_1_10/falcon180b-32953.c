//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float amount;
} Expense;

typedef struct {
    char name[50];
    float amount;
} Income;

void addExpense(Expense expenses[], int *size, char name[], float amount) {
    if (*size == 0) {
        *size = 1;
        expenses = (Expense *)malloc(sizeof(Expense));
    } else {
        *size += 1;
        expenses = (Expense *)realloc(expenses, sizeof(Expense) * (*size));
    }
    strcpy(expenses[*size - 1].name, name);
    expenses[*size - 1].amount = amount;
}

void addIncome(Income incomes[], int *size, char name[], float amount) {
    if (*size == 0) {
        *size = 1;
        incomes = (Income *)malloc(sizeof(Income));
    } else {
        *size += 1;
        incomes = (Income *)realloc(incomes, sizeof(Income) * (*size));
    }
    strcpy(incomes[*size - 1].name, name);
    incomes[*size - 1].amount = amount;
}

void displayExpenses(Expense expenses[], int size) {
    printf("Expenses:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void displayIncomes(Income incomes[], int size) {
    printf("Incomes:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: $%.2f\n", incomes[i].name, incomes[i].amount);
    }
}

void main() {
    int size = 0;
    Expense expenses[100];
    Income incomes[100];
    char name[50];
    float amount;

    while (1) {
        printf("Enter 1 to add an expense, 2 to add an income, or 0 to exit:\n");
        scanf("%d", &amount);

        if (amount == 0) {
            break;
        }

        printf("Enter name of expense/income:\n");
        scanf("%s", name);

        if (amount == 1) {
            printf("Enter amount of expense:\n");
            scanf("%f", &amount);
            addExpense(expenses, &size, name, amount);
        } else if (amount == 2) {
            printf("Enter amount of income:\n");
            scanf("%f", &amount);
            addIncome(incomes, &size, name, amount);
        }
    }

    displayExpenses(expenses, size);
    displayIncomes(incomes, size);
}