//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_BUDGET_NAME_LENGTH 50

typedef struct {
    char name[MAX_BUDGET_NAME_LENGTH];
    double amount;
} budget_item_t;

budget_item_t budget_items[MAX_BUDGET_ITEMS];

int num_budget_items = 0;

void add_budget_item() {
    if (num_budget_items >= MAX_BUDGET_ITEMS) {
        printf("Error: Maximum number of budget items reached.\n");
        return;
    }

    printf("Enter budget item name: ");
    fgets(budget_items[num_budget_items].name, MAX_BUDGET_NAME_LENGTH, stdin);
    budget_items[num_budget_items].name[strcspn(budget_items[num_budget_items].name, "\n")] = '\0';

    printf("Enter budget item amount: $");
    scanf("%lf", &budget_items[num_budget_items].amount);

    num_budget_items++;
}

void print_budget_items() {
    printf("Budget items:\n");
    for (int i = 0; i < num_budget_items; i++) {
        printf("%s: $%.2f\n", budget_items[i].name, budget_items[i].amount);
    }
}

void calculate_total_expenses() {
    double total_expenses = 0.0;

    for (int i = 0; i < num_budget_items; i++) {
        total_expenses += budget_items[i].amount;
    }

    printf("Total expenses: $%.2f\n", total_expenses);
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n\n");

    while (1) {
        printf("\n1. Add budget item\n2. Print budget items\n3. Calculate total expenses\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_budget_item();
            break;
        case 2:
            print_budget_items();
            break;
        case 3:
            calculate_total_expenses();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}