//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

/* Struct to hold item information */
typedef struct {
    char name[20];
    float price;
    int quantity;
} Item;

/* Function declarations */
void addItem(Item items[MAX_ITEMS], int *numItems);
void removeItem(Item items[MAX_ITEMS], int *numItems);
void listItems(Item items[MAX_ITEMS], int numItems);
void searchItem(Item items[MAX_ITEMS], int numItems);

int main() {

    Item items[MAX_ITEMS];
    int numItems = 0;
    int choice;

    do {
        /* Display menu */
        printf("Warehouse Management System:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. List Items\n");
        printf("4. Search Item\n");
        printf("5. Exit\n");

        /* Get user choice */
        printf("Enter choice: ");
        scanf("%d", &choice);

        /* Handle choice */
        switch (choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                removeItem(items, &numItems);
                break;
            case 3:
                listItems(items, numItems);
                break;
            case 4:
                searchItem(items, numItems);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

/* Function to add an item to the warehouse */
void addItem(Item items[MAX_ITEMS], int *numItems) {
    /* Check if max number of items has been reached */
    if (*numItems >= MAX_ITEMS) {
        printf("Maximum number of items reached! Cannot add more items.\n");
        return;
    }

    /* Get item information */
    Item newItem;
    printf("Enter name of item: ");
    scanf("%s", newItem.name);
    printf("Enter price of item: ");
    scanf("%f", &newItem.price);
    printf("Enter quantity of item: ");
    scanf("%d", &newItem.quantity);

    /* Add item to list */
    items[*numItems] = newItem;
    (*numItems)++;

    printf("Item added successfully!\n");
}

/* Function to remove an item from the warehouse */
void removeItem(Item items[MAX_ITEMS], int *numItems) {
    /* Check if any items are in the warehouse */
    if (*numItems == 0) {
        printf("No items in the warehouse! Cannot remove any items.\n");
        return;
    }

    /* Get item name */
    char itemName[20];
    printf("Enter name of item to remove: ");
    scanf("%s", itemName);

    /* Search for item in list */
    int index = -1;
    for (int i = 0; i < *numItems; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            index = i;
            break;
        }
    }

    /* Check if item was found */
    if (index == -1) {
        printf("Item not found in the warehouse! Cannot remove item.\n");
        return;
    }

    /* Remove item from list */
    for (int i = index; i < *numItems - 1; i++) {
        items[i] = items[i + 1];
    }
    (*numItems)--;

    printf("Item removed successfully!\n");
}

/* Function to list all items in the warehouse */
void listItems(Item items[MAX_ITEMS], int numItems) {
    /* Check if any items are in the warehouse */
    if (numItems == 0) {
        printf("No items in the warehouse!\n");
        return;
    }

    /* Print header */
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Quantity");
    printf("-----------------------------------------\n");

    /* Print items */
    for (int i = 0; i < numItems; i++) {
        printf("%-20s %-10.2f %-10d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

/* Function to search for an item in the warehouse */
void searchItem(Item items[MAX_ITEMS], int numItems) {
    /* Check if any items are in the warehouse */
    if (numItems == 0) {
        printf("No items in the warehouse! Cannot search for any items.\n");
        return;
    }

    /* Get item name */
    char itemName[20];
    printf("Enter name of item to search: ");
    scanf("%s", itemName);

    /* Search for item in list */
    int index = -1;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            index = i;
            break;
        }
    }

    /* Check if item was found */
    if (index == -1) {
        printf("Item not found in the warehouse!\n");
        return;
    }

    /* Print item information */
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Quantity");
    printf("-----------------------------------------\n");
    printf("%-20s %-10.2f %-10d\n", items[index].name, items[index].price, items[index].quantity);
}