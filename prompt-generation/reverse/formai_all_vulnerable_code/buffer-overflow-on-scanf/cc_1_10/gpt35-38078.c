//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

/* Declare the maximum size of the warehouse inventory */
#define MAX_SIZE 1000

/* Define the Item struct representing an inventory item*/
struct Item {
    char name[25];
    int quantity;
};

/* Declare the warehouse_inventory array initialized with default values*/
struct Item warehouse_inventory[MAX_SIZE] = {
    {"apple", 10},
    {"orange", 20},
    {"banana", 15},
    {"grape", 30},
    {"watermelon", 5},
};

/* Prototype functions */
void displayWarehouseInventory(struct Item*, int);
void addItem(struct Item*, char*, int, int*);
void removeItem(struct Item*, char*, int, int*);
void searchItem(struct Item*, char*, int, int*);

int main() {
    /* Declare variables */
    int option;
    int count = 5;
    char name[25];
    int quantity;
    int index = -1;

    /* Display a welcome message */
    printf("Welcome to the Warehouse Management System \n\n");

    /* Display the main menu options */
    printf("Main Menu: \n\n");
    printf("1. Display Warehouse Inventory\n");
    printf("2. Add Item to Inventory\n");
    printf("3. Remove Item from Inventory\n");
    printf("4. Search for Item in Inventory\n");
    printf("5. Quit\n\n");

    /* Loop continually until the user quits */
    while (1) {
        /* Get user input */
        printf("Enter option: ");
        scanf("%d", &option);

        /* Process user input */
        switch(option) {
            case 1:
                /* Display the current warehouse inventory */
                displayWarehouseInventory(warehouse_inventory, count);
                break;
            case 2:
                /* Add an item to the warehouse inventory*/
                printf("Enter item name: ");
                scanf("%s", name);

                printf("Enter item quantity: ");
                scanf("%d", &quantity);

                addItem(warehouse_inventory, name, quantity, &count);
                printf("Item successfully added to warehouse inventory.\n");
                break;
            case 3:
                /* Remove an item from the warehouse inventory */
                printf("Enter item name: ");
                scanf("%s", name);

                removeItem(warehouse_inventory, name, count, &index);

                if (index == -1) {
                    printf("Item not found in warehouse inventory.\n");
                } else {
                    printf("Item successfully removed from warehouse inventory.\n");
                    count--;
                }
                break;
            case 4:
                /* Search for an item in the warehouse inventory */
                printf("Enter item name: ");
                scanf("%s", name);

                searchItem(warehouse_inventory, name, count, &index);

                if (index == -1) {
                    printf("Item not found in warehouse inventory.\n");
                } else {
                    printf("%s: %d\n", warehouse_inventory[index].name, warehouse_inventory[index].quantity);
                }
                break;
            case 5:
                /* Quit the program */
                printf("Quitting Warehouse Management System. Goodbye.\n");
                exit(0);
            default:
                /* Invalid input. Display error message */
                printf("Invalid option entered. Please try again.\n");
                break;
        }

        /* Display the main menu options */
        printf("\nMain Menu: \n\n");
        printf("1. Display Warehouse Inventory\n");
        printf("2. Add Item to Inventory\n");
        printf("3. Remove Item from Inventory\n");
        printf("4. Search for Item in Inventory\n");
        printf("5. Quit\n\n");
    }

    return 0;
}

/* Function to display the current warehouse inventory */
void displayWarehouseInventory(struct Item* inventory, int count) {
    printf("Warehouse Inventory: \n\n");

    /* Loop through all inventory items and display them */
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

/* Function to add an item to the warehouse inventory */
void addItem(struct Item* inventory, char* name, int quantity, int* count) {
    /* Check if the inventory is full */
    if (*count == MAX_SIZE) {
        printf("Warehouse inventory is full. Cannot add item.\n");
        return;
    }

    /* Find the index to insert the new item */
    int i = 0;

    while (i < *count && strcmp(inventory[i].name, name) < 0) {
        i++;
    }

    /* Check if the item already exists in the inventory */
    if (i < *count && strcmp(inventory[i].name, name) == 0) {
        inventory[i].quantity += quantity;
    } else {
        /* Shift elements in the inventory to make space for the new item */
        for (int j = *count - 1; j >= i; j--) {
            inventory[j+1] = inventory[j];
        }

        /* Add the new item to the inventory */
        strcpy(inventory[i].name, name);
        inventory[i].quantity = quantity;

        /* Increment the count of items in the inventory */
        (*count)++;
    }
}

/* Function to remove an item from the warehouse inventory */
void removeItem(struct Item* inventory, char* name, int count, int* index) {
    /* Loop through all inventory items to find the item name */
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            /* Item found. Set the index and exit the function */
            *index = i;
            return;
        }
    }

    /* Item not found. Set the index to -1 */
    *index = -1;
}

/* Function to search for an item in the warehouse inventory */
void searchItem(struct Item* inventory, char* name, int count, int* index) {
    /* Loop through all inventory items to find the item name */
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            /* Item found. Set the index and exit the function */
            *index = i;
            return;
        }
    }

    /* Item not found. Set the index to -1 */
    *index = -1;
}