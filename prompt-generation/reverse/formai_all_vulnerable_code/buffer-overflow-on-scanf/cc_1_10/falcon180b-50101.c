//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUDGET_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} budgetItem;

void addBudgetItem(budgetItem *budget, int numItems, budgetItem newItem) {
    if (numItems < MAX_BUDGET_ITEMS) {
        budget[numItems] = newItem;
        numItems++;
    } else {
        printf("Sorry, you have reached the maximum number of budget items!\n");
    }
}

void displayBudget(budgetItem budget[], int numItems) {
    printf("Budget:\n");
    printf("======\n");
    for (int i = 0; i < numItems; i++) {
        printf("%-20s $%.2f %s\n", budget[i].name, budget[i].amount, budget[i].category);
    }
}

int main() {
    budgetItem budget[MAX_BUDGET_ITEMS];
    int numItems = 0;
    char choice;

    do {
        printf("Personal Finance Planner\n");
        printf("======================\n");
        printf("1. Add budget item\n");
        printf("2. Display budget\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name of budget item: ");
                scanf("%s", budget[numItems].name);
                printf("Enter amount of budget item: $");
                scanf("%f", &budget[numItems].amount);
                printf("Enter category of budget item: ");
                scanf("%s", budget[numItems].category);
                numItems++;
                break;
            case '2':
                displayBudget(budget, numItems);
                break;
            case '3':
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}