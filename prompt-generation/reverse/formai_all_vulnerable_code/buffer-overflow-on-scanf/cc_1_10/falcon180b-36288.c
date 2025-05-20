//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUDGET_ITEMS 100

struct budget_item {
    char name[50];
    float amount;
    int category;
};

struct budget_item budget[MAX_BUDGET_ITEMS];
int budget_count = 0;

void add_budget_item() {
    budget_count++;
    printf("Enter budget item name: ");
    scanf("%s", budget[budget_count-1].name);
    printf("Enter budget item amount: ");
    scanf("%f", &budget[budget_count-1].amount);
    printf("Enter budget item category (1-10): ");
    scanf("%d", &budget[budget_count-1].category);
}

void display_budget() {
    printf("\nBudget:\n");
    for (int i = 0; i < budget_count; i++) {
        printf("%d. %s - $%.2f (Category: %d)\n", i+1, budget[i].name, budget[i].amount, budget[i].category);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    char repeat = 'y';

    while (repeat == 'y' || repeat == 'Y') {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add budget item\n");
        printf("2. Display budget\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_budget_item();
                break;
            case 2:
                display_budget();
                break;
            case 3:
                printf("Are you sure you want to exit? (y/n): ");
                scanf("%s", &repeat);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}