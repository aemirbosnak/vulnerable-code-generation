//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100 // Maximum number of items in the warehouse

/* Struct to hold item details */
typedef struct {
    int id;
    char name[20];
    int quantity;
} Item;

/* Prototype for the function to display the menu to the user */
void displayMenu();

/* Prototype for the function to add an item to the warehouse */
void addItem(Item items[], int *itemCounter);

/* Prototype for the function to remove an item from the warehouse */
void removeItem(Item items[], int *itemCounter);

/* Prototype for the function to display all the items in the warehouse */
void displayItems(Item items[], int itemCounter);

/* Main function */
int main() {
    /* Array to hold all the items */
    Item items[MAX_ITEMS];

    /* Counter to track the number of items in the warehouse */
    int itemCounter = 0;

    /* Flag to indicate if the user wants to exit the program */
    int exitFlag = 0;

    while (!exitFlag) {
        /* Display the menu to the user */
        displayMenu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                /* Add an item to the warehouse */
                addItem(items, &itemCounter);
                break;
            case 2:
                /* Remove an item from the warehouse */
                removeItem(items, &itemCounter);
                break;
            case 3:
                /* Display all the items in the warehouse */
                displayItems(items, itemCounter);
                break;
            case 4:
                /* Exit the program */
                exitFlag = 1;
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("Warehouse Management System\n");
    printf("----------------------------\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Items\n");
    printf("4. Exit\n");
}

void addItem(Item items[], int *itemCounter) {
    /* Check if the warehouse is full */
    if (*itemCounter == MAX_ITEMS) {
        printf("Error: Warehouse is full\n");
        return;
    }

    /* Get the details of the new item from the user */
    Item newItem;
    printf("Enter the ID of the item: ");
    scanf("%d", &newItem.id);
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem.quantity);

    /* Add the new item to the warehouse */
    items[*itemCounter] = newItem;

    /* Increment the counter */
    (*itemCounter)++;

    printf("Item added successfully\n");
}

void removeItem(Item items[], int *itemCounter) {
    /* Check if there are any items in the warehouse */
    if (*itemCounter == 0) {
        printf("Error: Warehouse is empty\n");
        return;
    }

    /* Get the ID of the item to be removed from the user */
    int idToRemove;
    printf("Enter the ID of the item to remove: ");
    scanf("%d", &idToRemove);

    /* Find the item with the specified ID */
    int itemIndex = -1;
    for (int i = 0; i < *itemCounter; i++) {
        if (items[i].id == idToRemove) {
            itemIndex = i;
            break;
        }
    }

    /* Check if the item was found */
    if (itemIndex == -1) {
        printf("Error: Item not found\n");
        return;
    }

    /* Remove the item from the warehouse */
    for (int i = itemIndex; i < *itemCounter - 1; i++) {
        items[i] = items[i+1];
    }

    /* Decrement the counter */
    (*itemCounter)--;

    printf("Item removed successfully\n");
}

void displayItems(Item items[], int itemCounter) {
    /* Check if there are any items in the warehouse */
    if (itemCounter == 0) {
        printf("Warehouse is empty\n");
        return;
    }

    /* Display all the items in the warehouse */
    printf("ID\tName\tQuantity\n");
    printf("------------------------\n");
    for (int i = 0; i < itemCounter; i++) {
        printf("%d\t%s\t%d\n", items[i].id, items[i].name, items[i].quantity);
    }
}