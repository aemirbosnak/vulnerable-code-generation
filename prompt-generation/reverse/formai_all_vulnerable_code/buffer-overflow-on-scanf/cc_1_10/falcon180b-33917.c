//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure for each item in the inventory
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Function to add an item to the inventory
void addItem(Item inventory[], int *size) {
    printf("Enter the name of the item: ");
    scanf("%s", &inventory[*size].name);

    printf("Enter the quantity of the item: ");
    scanf("%d", &inventory[*size].quantity);

    printf("Enter the price of the item: ");
    scanf("%f", &inventory[*size].price);

    (*size)++;
}

// Function to display the entire inventory
void displayInventory(Item inventory[], int size) {
    printf("\nInventory:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to search for an item in the inventory
int searchInventory(Item inventory[], int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Item not found
}

// Function to update the quantity of an item in the inventory
void updateQuantity(Item inventory[], int size, char *name, int quantity) {
    int index = searchInventory(inventory, size, name);

    if (index!= -1) {
        inventory[index].quantity += quantity;
    } else {
        printf("Item not found.\n");
    }
}

// Function to calculate the total value of the inventory
float calculateTotalValue(Item inventory[], int size) {
    float totalValue = 0;

    for (int i = 0; i < size; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }

    return totalValue;
}

int main() {
    Item inventory[MAX_ITEMS];
    int size = 0;

    // Add some items to the inventory
    addItem(inventory, &size);
    addItem(inventory, &size);
    addItem(inventory, &size);

    // Display the inventory
    displayInventory(inventory, size);

    // Update the quantity of an item
    updateQuantity(inventory, size, "Sword", 5);

    // Display the updated inventory
    displayInventory(inventory, size);

    // Calculate the total value of the inventory
    float totalValue = calculateTotalValue(inventory, size);
    printf("\nTotal value of the inventory: $%.2f\n", totalValue);

    return 0;
}