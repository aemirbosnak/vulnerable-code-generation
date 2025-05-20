//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
    float budget;
} GroceryList;

void initGroceryList(GroceryList *groceryList, float budget) {
    groceryList->count = 0;
    groceryList->budget = budget;
}

void addItem(GroceryList *groceryList) {
    if (groceryList->count >= MAX_ITEMS) {
        printf("Grocery list is full. Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    printf("Enter the price of the item: ");
    scanf("%f", &newItem.price);

    float totalCost = 0;
    for (int i = 0; i < groceryList->count; i++) {
        totalCost += groceryList->items[i].price;
    }
    totalCost += newItem.price;

    if (totalCost > groceryList->budget) {
        printf("Cannot add %s. Total cost exceeds budget of %.2f.\n", newItem.name, groceryList->budget);
        return;
    }

    groceryList->items[groceryList->count] = newItem;
    groceryList->count++;
    printf("Added %s with price %.2f to the grocery list.\n", newItem.name, newItem.price);
}

void removeItem(GroceryList *groceryList) {
    if (groceryList->count == 0) {
        printf("The grocery list is empty. Nothing to remove.\n");
        return;
    }

    char itemName[ITEM_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    scanf("%s", itemName);

    for (int i = 0; i < groceryList->count; i++) {
        if (strcmp(groceryList->items[i].name, itemName) == 0) {
            printf("Removing %s from the grocery list.\n", groceryList->items[i].name);
            for (int j = i; j < groceryList->count - 1; j++) {
                groceryList->items[j] = groceryList->items[j + 1];
            }
            groceryList->count--;
            return;
        }
    }

    printf("Item %s not found in the grocery list.\n", itemName);
}

void viewList(GroceryList *groceryList) {
    if (groceryList->count == 0) {
        printf("The grocery list is empty.\n");
        return;
    }

    printf("Grocery List:\n");
    for (int i = 0; i < groceryList->count; i++) {
        printf("%d. %s - %.2f\n", i + 1, groceryList->items[i].name, groceryList->items[i].price);
    }
}

void checkout(GroceryList *groceryList) {
    if (groceryList->count == 0) {
        printf("The grocery list is empty. Cannot checkout.\n");
        return;
    }

    float totalCost = 0;
    for (int i = 0; i < groceryList->count; i++) {
        totalCost += groceryList->items[i].price;
    }

    printf("Total cost for checkout: %.2f\n", totalCost);
    groceryList->count = 0;  // Clear the list after checkout
    printf("Checkout complete.\n");
}

int main() {
    GroceryList groceryList;
    float budget;

    printf("Welcome to Grocery Guru!\n");
    printf("Set your budget for shopping: ");
    scanf("%f", &budget);
    initGroceryList(&groceryList, budget);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View List\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&groceryList);
                break;
            case 2:
                removeItem(&groceryList);
                break;
            case 3:
                viewList(&groceryList);
                break;
            case 4:
                checkout(&groceryList);
                break;
            case 5:
                printf("Exiting the program. Thank you for using Grocery Guru!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}