//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure for the items in the warehouse */
struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
};

/* Function to add an item to the warehouse */
void addItem(struct Item items[], int totalItems) {
    /* Declare variables to store input */
    int id;
    char name[50];
    float price;
    int quantity;

    /* Prompt user for input */
    printf("Enter item id: ");
    scanf("%d", &id);
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%f", &price);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    /* Add item to array */
    struct Item item = {id, name, price, quantity};
    items[totalItems] = item;

    /* Increment totalItems */
    totalItems++;

    /* Print success message */
    printf("Item added successfully!\n");
}

/* Function to remove an item from the warehouse */
void removeItem(struct Item items[], int totalItems) {
    /* Declare variable to store input */
    int id;

    /* Prompt user for input */
    printf("Enter item id: ");
    scanf("%d", &id);

    /* Loop through items array to find item with matching id */
    int i;
    int foundItem = 0;
    for (i = 0; i < totalItems; i++) {
        if (items[i].id == id) {
            /* Remove item from array */
            int j;
            for (j = i; j < totalItems - 1; j++) {
                items[j] = items[j + 1];
            }
            /* Decrement totalItems */
            totalItems--;
            /* Print success message */
            printf("Item removed successfully!\n");
            foundItem = 1;
            break;
        }
    }

    /* If item wasn't found, print error message */
    if (!foundItem) {
        printf("Item not found.\n");
    }
}

/* Function to update an item in the warehouse */
void updateItem(struct Item items[], int totalItems) {
    /* Declare variables to store input */
    int id;
    float price;
    int quantity;

    /* Prompt user for input */
    printf("Enter item id: ");
    scanf("%d", &id);
    printf("Enter new price: ");
    scanf("%f", &price);
    printf("Enter new quantity: ");
    scanf("%d", &quantity);

    /* Loop through items array to find item with matching id */
    int i;
    int foundItem = 0;
    for (i = 0; i < totalItems; i++) {
        if (items[i].id == id) {
            /* Update item in array */
            items[i].price = price;
            items[i].quantity = quantity;
            /* Print success message */
            printf("Item updated successfully!\n");
            foundItem = 1;
            break;
        }
    }

    /* If item wasn't found, print error message */
    if (!foundItem) {
        printf("Item not found.\n");
    }
}

/* Function to display all items in the warehouse */
void displayItems(struct Item items[], int totalItems) {
    /* Declare variable to store loop counter */
    int i;

    /* Print table heading */
    printf("%-10s%-30s%-10s%-10s\n", "ID", "Name", "Price", "Quantity");
    printf("--------------------------------------------------------\n");

    /* Loop through items array and print each item */
    for (i = 0; i < totalItems; i++) {
        printf("%-10d%-30s$%-9.2f%-10d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
    }
}

/* Main function */
int main() {
    /* Declare variables */
    int totalItems = 0;
    struct Item items[100];

    /* Main menu loop */
    int exitMenu = 0;
    while (!exitMenu) {
        /* Print main menu options */
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item\n");
        printf("4. Display Items\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");

        /* Get user choice */
        int choice;
        scanf("%d", &choice);

        /* Call appropriate function based on user choice */
        switch (choice) {
            case 1:
                addItem(items, totalItems);
                break;
            case 2:
                removeItem(items, totalItems);
                break;
            case 3:
                updateItem(items, totalItems);
                break;
            case 4:
                displayItems(items, totalItems);
                break;
            case 5:
                exitMenu = 1;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    /* Print exit message */
    printf("Thank you for using the Warehouse Management System!\n");

    /* End program */
    return 0;
}