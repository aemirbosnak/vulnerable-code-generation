//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_CATEGORY_NAME 100
#define MAX_ITEM_NAME 100
#define MAX_DESCRIPTION 1000

// Structure for budget items
typedef struct {
    char category[MAX_CATEGORY_NAME];
    char item[MAX_ITEM_NAME];
    char description[MAX_DESCRIPTION];
    double amount;
} budget_item;

// Function to add a budget item
void add_item(budget_item* budget, int* num_items) {
    printf("Enter category: ");
    scanf("%s", budget[*num_items].category);
    printf("Enter item: ");
    scanf("%s", budget[*num_items].item);
    printf("Enter description: ");
    scanf("%s", budget[*num_items].description);
    printf("Enter amount: ");
    scanf("%lf", &budget[*num_items].amount);
    (*num_items)++;
}

// Function to display budget items
void display_items(budget_item* budget, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("%d. Category: %s\n", i+1, budget[i].category);
        printf("    Item: %s\n", budget[i].item);
        printf("    Description: %s\n", budget[i].description);
        printf("    Amount: $%.2lf\n\n", budget[i].amount);
    }
}

// Function to calculate total expenses
double calculate_total_expenses(budget_item* budget, int num_items) {
    double total_expenses = 0;
    for (int i = 0; i < num_items; i++) {
        total_expenses += budget[i].amount;
    }
    return total_expenses;
}

int main() {
    budget_item budget[MAX_BUDGET_ITEMS];
    int num_items = 0;

    add_item(budget, &num_items);
    add_item(budget, &num_items);
    add_item(budget, &num_items);

    display_items(budget, num_items);

    double total_expenses = calculate_total_expenses(budget, num_items);
    printf("Total expenses: $%.2lf\n", total_expenses);

    return 0;
}