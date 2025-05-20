//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char* name;
    float amount;
};

struct Budget {
    float income;
    struct Expense* expenses;
    int num_expenses;
};

struct Planner {
    struct Budget budget;
    int num_budgets;
};

struct Planner* create_planner(int num_budgets) {
    struct Planner* planner = malloc(sizeof(struct Planner));
    planner->num_budgets = num_budgets;
    planner->budget.expenses = malloc(sizeof(struct Expense) * num_budgets);
    return planner;
}

void add_budget(struct Planner* planner, float income, struct Expense* expenses, int num_expenses) {
    planner->budget.income = income;
    planner->budget.expenses = expenses;
    planner->budget.num_expenses = num_expenses;
    planner->num_budgets++;
}

void calculate_balance(struct Planner* planner) {
    float balance = planner->budget.income;
    for (int i = 0; i < planner->budget.num_expenses; i++) {
        balance -= planner->budget.expenses[i].amount;
    }
    printf("Balance: %f\n", balance);
}

int main() {
    struct Planner* planner = create_planner(3);
    add_budget(planner, 5000, NULL, 0);
    add_budget(planner, 4000, NULL, 0);
    add_budget(planner, 3000, NULL, 0);
    calculate_balance(planner);
    free(planner);
    return 0;
}