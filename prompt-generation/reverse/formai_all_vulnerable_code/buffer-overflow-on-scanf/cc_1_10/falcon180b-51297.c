//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float cost;
    int quantity;
} Item;

void addItem(Item items[], int numItems, char name[], float cost, int quantity) {
    if (numItems >= MAX_ITEMS) {
        printf("Sorry, you can only add up to %d items.\n", MAX_ITEMS);
        return;
    }

    strcpy(items[numItems].name, name);
    items[numItems].cost = cost;
    items[numItems].quantity = quantity;

    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItems:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%-30s $%.2f  %d\n", items[i].name, items[i].cost, items[i].quantity);
    }
}

void calculateTotal(Item items[], int numItems, float *totalCost) {
    for (int i = 0; i < numItems; i++) {
        *totalCost += items[i].cost * items[i].quantity;
    }
}

int main() {
    int numItems = 0;
    Item items[MAX_ITEMS];

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\n1. Add an item\n2. Display items\n3. Calculate total cost\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char name[50];
            float cost;
            int quantity;

            printf("Enter the name of the item: ");
            scanf("%s", name);

            printf("Enter the cost of the item: $");
            scanf("%f", &cost);

            printf("Enter the quantity of the item: ");
            scanf("%d", &quantity);

            addItem(items, numItems, name, cost, quantity);
            break;
        }

        case 2: {
            if (numItems == 0) {
                printf("No items have been added yet.\n");
            } else {
                displayItems(items, numItems);
            }
            break;
        }

        case 3: {
            float totalCost = 0.0;
            calculateTotal(items, numItems, &totalCost);

            printf("\nTotal cost: $%.2f\n", totalCost);
            break;
        }

        case 4: {
            printf("Thank you for using the Expense Tracker! Goodbye!\n");
            return 0;
        }

        default: {
            printf("Invalid choice. Please try again.\n");
        }
        }
    }

    return 0;
}