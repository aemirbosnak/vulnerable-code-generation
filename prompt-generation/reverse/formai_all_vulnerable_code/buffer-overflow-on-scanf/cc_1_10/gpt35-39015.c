//FormAI DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum capacity of the inventory
#define MAX_CAPACITY 100

// Define the structure for each item in the inventory
struct Item {
    char name[50];
    int quantity;
    float price;
};

// Define the inventory array
struct Item inventory[MAX_CAPACITY];

// Define the current size of the inventory
int size = 0;

// Define the function to add a new item to the inventory
void addItem() {
    // Check if the inventory is already full
    if (size == MAX_CAPACITY) {
        printf("Error: Inventory is already full!\n");
        return;
    }

    // Prompt for the item details
    printf("Enter the name of the item: ");
    char name[50];
    scanf("%s", name);
    printf("Enter the quantity of the item: ");
    int quantity;
    scanf("%d", &quantity);
    printf("Enter the price of the item: ");
    float price;
    scanf("%f", &price);

    // Create a new item and add it to the inventory
    struct Item newItem;
    strcpy(newItem.name, name);
    newItem.quantity = quantity;
    newItem.price = price;
    inventory[size] = newItem;
    size++;

    printf("Item added to the inventory successfully!\n");
}

// Define the function to remove an item from the inventory
void removeItem() {
    // Check if the inventory is empty
    if (size == 0) {
        printf("Error: Inventory is already empty!\n");
        return;
    }

    // Prompt for the name of the item to remove
    printf("Enter the name of the item to remove: ");
    char name[50];
    scanf("%s", name);

    // Search for the item in the inventory
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Item not found in the inventory!\n");
        return;
    }

    // Shift the remaining items to fill the gap
    for (int i = index; i < size - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    size--;

    printf("Item removed from the inventory successfully!\n");
}

// Define the function to print all the items in the inventory
void printInventory() {
    // Check if the inventory is empty
    if (size == 0) {
        printf("Error: Inventory is empty!\n");
        return;
    }

    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    // Print the welcome message
    printf("Welcome to the Medieval Product Inventory System!\n");

    while (1) {
        // Prompt for the user's choice
        printf("\nChoose an option:\n");
        printf("1. Add an item\n");
        printf("2. Remove an item\n");
        printf("3. Print the inventory\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                printInventory();
                break;
            case 4:
                printf("Thank you for using the Medieval Product Inventory System!\n");
                exit(0);
            default:
                printf("Error: Invalid choice; please choose again!\n");
                break;
        }
    }

    return 0;
}