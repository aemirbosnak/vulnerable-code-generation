//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUDGET_ITEMS 100

typedef struct {
    char name[50];
    double amount;
    time_t due_date;
} BudgetItem;

void add_budget_item(BudgetItem* budget, int size, const char* name, double amount, time_t due_date) {
    if (size >= MAX_BUDGET_ITEMS) {
        printf("Sorry, your budget is full. Please remove an item to add a new one.\n");
        return;
    }

    strcpy(budget[size].name, name);
    budget[size].amount = amount;
    budget[size].due_date = due_date;

    printf("Item added to budget:\n");
    printf("Name: %s\n", budget[size].name);
    printf("Amount: $%.2f\n", budget[size].amount);
    printf("Due date: %s\n", ctime(&budget[size].due_date));

    size++;
}

void remove_budget_item(BudgetItem* budget, int size) {
    if (size <= 0) {
        printf("Your budget is empty.\n");
        return;
    }

    printf("Item removed from budget:\n");
    printf("Name: %s\n", budget[size - 1].name);
    printf("Amount: $%.2f\n", budget[size - 1].amount);

    size--;
}

void display_budget(BudgetItem* budget, int size) {
    if (size <= 0) {
        printf("Your budget is empty.\n");
        return;
    }

    printf("Budget:\n");
    for (int i = 0; i < size; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", budget[i].name);
        printf("Amount: $%.2f\n", budget[i].amount);
        printf("Due date: %s\n", ctime(&budget[i].due_date));
        printf("\n");
    }
}

int main() {
    BudgetItem budget[MAX_BUDGET_ITEMS];
    int size = 0;

    srand(time(NULL));

    add_budget_item(budget, size, "Rent", 1000, time(NULL) + 60 * 60 * 24 * 30);
    add_budget_item(budget, size, "Groceries", 200, time(NULL) + 60 * 60 * 24 * 7);
    add_budget_item(budget, size, "Utilities", 150, time(NULL) + 60 * 60 * 24 * 15);

    display_budget(budget, size);

    remove_budget_item(budget, size);

    display_budget(budget, size);

    return 0;
}