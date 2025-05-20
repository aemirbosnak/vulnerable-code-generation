//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_BUDGET_NAME_LENGTH 50

typedef struct {
    char name[MAX_BUDGET_NAME_LENGTH];
    double budget;
} budget_item_t;

budget_item_t budget_items[MAX_BUDGET_ITEMS];
int num_budget_items = 0;

void add_budget_item(const char* name, double budget) {
    if (num_budget_items >= MAX_BUDGET_ITEMS) {
        printf("Error: Maximum number of budget items reached.\n");
        return;
    }

    strncpy(budget_items[num_budget_items].name, name, MAX_BUDGET_NAME_LENGTH);
    budget_items[num_budget_items].budget = budget;

    num_budget_items++;
}

void print_budget_items() {
    if (num_budget_items == 0) {
        printf("No budget items added.\n");
        return;
    }

    printf("Budget items:\n");
    for (int i = 0; i < num_budget_items; i++) {
        printf("%s: $%.2f\n", budget_items[i].name, budget_items[i].budget);
    }
}

void main() {
    printf("Personal Finance Planner\n");

    char choice;
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("A) Add budget item\n");
        printf("B) Print budget items\n");
        printf("C) Exit\n");
        printf("> ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter budget item name: ");
                char name[MAX_BUDGET_NAME_LENGTH];
                scanf("%s", name);
                printf("Enter budget: ");
                double budget;
                scanf("%lf", &budget);
                add_budget_item(name, budget);
                break;
            case 'B':
                print_budget_items();
                break;
            case 'C':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}