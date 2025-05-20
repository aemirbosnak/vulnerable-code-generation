//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <string.h>

/* Define the maximum storage capacity of the warehouse */
#define MAX_CAPACITY 100

/* Define the data structure for each item in the warehouse */
typedef struct {
    char name[20];
    int quantity;
} Item;

/* Define the array to store the items in the warehouse */
Item items[MAX_CAPACITY];

/* Define the number of items currently stored in the warehouse */
int numItems = 0;

/* Define a function to add an item to the warehouse */
void addItem(char* name, int quantity) {
    /* Check if the warehouse is already at maximum capacity */
    if (numItems >= MAX_CAPACITY) {
        printf("Warehouse is already at maximum capacity.\n");
        return;
    }

    /* Check if the item already exists in the warehouse */
    for (int i = 0; i < numItems; i++) {
        if (strcmp(name, items[i].name) == 0) {
            items[i].quantity += quantity;
            printf("%d units of %s added to warehouse.\n", quantity, name);
            return;
        }
    }

    /* Add the new item to the warehouse */
    strcpy(items[numItems].name, name);
    items[numItems].quantity = quantity;
    numItems++;
    printf("%d units of %s added to warehouse.\n", quantity, name);
}

/* Define a function to remove an item from the warehouse */
void removeItem(char* name, int quantity) {
    /* Check if the item exists in the warehouse */
    for (int i = 0; i < numItems; i++) {
        if (strcmp(name, items[i].name) == 0) {
            /* Check if there is enough quantity to remove */
            if (items[i].quantity >= quantity) {
                items[i].quantity -= quantity;
                printf("%d units of %s removed from warehouse.\n", quantity, name);
                return;
            } else {
                printf("Not enough %s in warehouse to remove %d units.\n", name, quantity);
                return;
            }
        }
    }

    /* If item is not found in the warehouse */
    printf("%s is not found in warehouse.\n", name);
}

/* Define a function to display the current status of the warehouse */
void displayStatus() {
    printf("Warehouse Status:\n");
    printf("------------------\n");

    /* Display item name and quantity for each item in warehouse */
    for (int i = 0; i < numItems; i++) {
        printf("%s: %d\n", items[i].name, items[i].quantity);
    }

    /* If warehouse is empty */
    if (numItems == 0) {
        printf("Empty.\n");
    }

    printf("------------------\n");
}

int main() {
    /* Menu-driven interface for warehouse management */
    char itemName[20];
    int itemQuantity;
    int choice;

    do {
        printf("Warehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter quantity: ");
                scanf("%d", &itemQuantity);
                addItem(itemName, itemQuantity);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter quantity: ");
                scanf("%d", &itemQuantity);
                removeItem(itemName, itemQuantity);
                break;
            case 3:
                displayStatus();
                break;
            case 4:
                printf("Exiting. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}