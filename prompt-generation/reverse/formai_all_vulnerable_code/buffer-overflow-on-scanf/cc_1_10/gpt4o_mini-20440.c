//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 50
#define NAME_LEN 50

typedef struct {
    char itemName[NAME_LEN];
    float cost;
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ENTRIES];
    int totalItems;
    float totalCost;
} Budget;

void initializeBudget(Budget *budget) {
    budget->totalItems = 0;
    budget->totalCost = 0.0f;
}

void addItem(Budget *budget) {
    if (budget->totalItems >= MAX_ENTRIES) {
        printf("Cannot add more items. The budget is full!\n");
        return;
    }
    Item newItem;
    
    printf("Enter the name of the item: ");
    scanf("%s", newItem.itemName);
    
    printf("Enter the cost of %s: ", newItem.itemName);
    scanf("%f", &newItem.cost);
    
    printf("Enter the quantity of %s: ", newItem.itemName);
    scanf("%d", &newItem.quantity);
    
    budget->items[budget->totalItems++] = newItem;
    budget->totalCost += newItem.cost * newItem.quantity;

    printf("Item added: %s, Cost: %.2f, Quantity: %d\n", newItem.itemName, newItem.cost, newItem.quantity);
}

void displayBudget(const Budget *budget) {
    if (budget->totalItems == 0) {
        printf("The budget is empty.\n");
        return;
    }

    printf("\n===== Current Budget =====\n");
    for (int i = 0; i < budget->totalItems; i++) {
        printf("Item %d: %s, Cost: %.2f, Quantity: %d\n", 
               i + 1, budget->items[i].itemName, budget->items[i].cost, budget->items[i].quantity);
    }
    printf("Total Budget Cost: %.2f\n", budget->totalCost);
    printf("=========================\n");
}

void removeItem(Budget *budget) {
    if (budget->totalItems == 0) {
        printf("No items to remove from the budget.\n");
        return;
    }
    
    int index;
    displayBudget(budget);

    printf("Enter the item number to remove: ");
    scanf("%d", &index);
    
    if (index < 1 || index > budget->totalItems) {
        printf("Invalid item number!\n");
        return;
    }

    index -= 1; // Adjust for 0-based indexing
    budget->totalCost -= budget->items[index].cost * budget->items[index].quantity;

    for (int i = index; i < budget->totalItems - 1; i++) {
        budget->items[i] = budget->items[i + 1];
    }

    budget->totalItems--;
    printf("Item removed. Updated budget:\n");
    displayBudget(budget);
}

void saveBudget(const Budget *budget) {
    FILE *file = fopen("post_apocalyptic_budget.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < budget->totalItems; i++) {
        fprintf(file, "%s %.2f %d\n", budget->items[i].itemName, budget->items[i].cost, budget->items[i].quantity);
    }
    fprintf(file, "Total Cost: %.2f\n", budget->totalCost);
    fclose(file);
    printf("Budget saved to post_apocalyptic_budget.txt\n");
}

void loadBudget(Budget *budget) {
    FILE *file = fopen("post_apocalyptic_budget.txt", "r");
    if (!file) {
        printf("No saved budget file found. Starting fresh.\n");
        return;
    }

    printf("Loading budget...\n");
    initializeBudget(budget);
    while (fscanf(file, "%s %f %d", budget->items[budget->totalItems].itemName, 
                  &budget->items[budget->totalItems].cost, 
                  &budget->items[budget->totalItems].quantity) != EOF) {
        budget->totalCost += budget->items[budget->totalItems].cost * budget->items[budget->totalItems].quantity;
        budget->totalItems++;
    }
    fclose(file);
    printf("Budget loaded. Total items: %d\n", budget->totalItems);
}

int main() {
    Budget myBudget;
    int choice;

    initializeBudget(&myBudget);
    loadBudget(&myBudget);

    do {
        printf("\n===== Post-Apocalyptic Personal Finance Planner =====\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Budget\n");
        printf("4. Save Budget\n");
        printf("5. Exit\n");
        printf("Choose an action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&myBudget);
                break;
            case 2:
                removeItem(&myBudget);
                break;
            case 3:
                displayBudget(&myBudget);
                break;
            case 4:
                saveBudget(&myBudget);
                break;
            case 5:
                saveBudget(&myBudget);
                printf("Exiting the planner. Stay safe in the wasteland!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}