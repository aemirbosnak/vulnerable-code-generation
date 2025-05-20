//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUDGET_ITEMS 100

typedef struct {
    char name[100];
    double amount;
    int frequency;
} budget_item_t;

budget_item_t budget[MAX_BUDGET_ITEMS];
int num_budget_items = 0;

void add_budget_item() {
    if (num_budget_items >= MAX_BUDGET_ITEMS) {
        printf("Cannot add more budget items. Maximum limit reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", budget[num_budget_items].name);

    printf("Enter amount: ");
    scanf("%lf", &budget[num_budget_items].amount);

    printf("Enter frequency (monthly, weekly, daily): ");
    scanf("%s", budget[num_budget_items].frequency);

    num_budget_items++;
}

void print_budget() {
    printf("\nBudget:\n");
    for (int i = 0; i < num_budget_items; i++) {
        double monthly_amount = budget[i].amount / (double)atoi(budget[i].frequency);
        printf("%s - %.2f %s - %.2f per month\n", budget[i].name, budget[i].amount, budget[i].frequency, monthly_amount);
    }
}

void main() {
    int choice;
    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add budget item\n");
        printf("2. Print budget\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_budget_item();
            break;
        case 2:
            print_budget();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}