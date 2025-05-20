//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_BUDGET_NAME_LENGTH 50

typedef struct {
    char name[MAX_BUDGET_NAME_LENGTH];
    double monthly_amount;
} BudgetItem;

BudgetItem budget[MAX_BUDGET_ITEMS];
int num_budget_items = 0;

void add_budget_item() {
    if (num_budget_items >= MAX_BUDGET_ITEMS) {
        printf("Sorry, you have reached the maximum number of budget items.\n");
        return;
    }

    printf("Enter the name of the budget item: ");
    scanf("%s", budget[num_budget_items].name);

    printf("Enter the monthly amount for this budget item: $");
    scanf("%lf", &budget[num_budget_items].monthly_amount);

    num_budget_items++;
}

void display_budget() {
    printf("\nBudget:\n");
    for (int i = 0; i < num_budget_items; i++) {
        printf("%s: $%.2f\n", budget[i].name, budget[i].monthly_amount);
    }
}

void main() {
    srand(time(NULL));

    int choice;
    char input[100];

    printf("Welcome to the Personal Finance Planner!\n\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a budget item\n");
        printf("2. Display budget\n");
        printf("3. Quit\n");
        printf("> ");
        scanf("%s", input);

        switch (atoi(input)) {
            case 1:
                add_budget_item();
                break;
            case 2:
                display_budget();
                break;
            case 3:
                printf("Thank you for using the Personal Finance Planner!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}