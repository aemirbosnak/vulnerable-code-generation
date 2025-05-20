//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUDGET_ITEMS 100

// Budget item structure
typedef struct {
    char name[50];
    float amount;
    int frequency;
    int frequency_type;
} BudgetItem;

void createBudgetItem(BudgetItem *item) {
    printf("Enter budget item name: ");
    scanf("%s", item->name);
    printf("Enter budget amount: ");
    scanf("%f", &item->amount);
    printf("Enter frequency (in months): ");
    scanf("%d", &item->frequency);
    printf("Enter frequency type (1: monthly, 2: bi-monthly): ");
    scanf("%d", &item->frequency_type);
}

void displayBudgetItem(BudgetItem item) {
    printf("Name: %s\n", item.name);
    printf("Amount: $%.2f\n", item.amount);
    printf("Frequency: %d months\n", item.frequency);
    if (item.frequency_type == 1) {
        printf("Frequency type: Monthly\n");
    } else {
        printf("Frequency type: Bi-monthly\n");
    }
}

void calculateTotalBudget(BudgetItem *items, int num_items) {
    float total_budget = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_budget += items[i].amount * (12 / items[i].frequency);
    }
    printf("Total budget: $%.2f\n", total_budget);
}

int main() {
    srand(time(NULL));
    int num_items;
    printf("Enter number of budget items: ");
    scanf("%d", &num_items);
    BudgetItem items[MAX_BUDGET_ITEMS];
    for (int i = 0; i < num_items; i++) {
        createBudgetItem(&items[i]);
    }
    calculateTotalBudget(items, num_items);
    return 0;
}