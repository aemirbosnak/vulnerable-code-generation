//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the inventory
void add_medicine(medicine *inventory, int *inventory_size) {
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*inventory_size].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*inventory_size].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*inventory_size].quantity);
    (*inventory_size)++;
}

// Function to search for a medicine in the inventory
int search_medicine(medicine *inventory, int inventory_size, char *name) {
    for (int i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to display the inventory
void display_inventory(medicine *inventory, int inventory_size) {
    printf("Medicine Inventory:\n");
    for (int i = 0; i < inventory_size; i++) {
        printf("%s\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to sell a medicine
void sell_medicine(medicine *inventory, int *inventory_size, char *name, int quantity) {
    int index = search_medicine(inventory, *inventory_size, name);
    if (index == -1) {
        printf("Medicine not found in inventory.\n");
    } else {
        if (inventory[index].quantity >= quantity) {
            inventory[index].quantity -= quantity;
            printf("Sold %d units of %s.\n", quantity, inventory[index].name);
        } else {
            printf("Insufficient quantity of %s in inventory.\n", inventory[index].name);
        }
    }
}

// Function to buy a medicine
void buy_medicine(medicine *inventory, int *inventory_size, char *name, int quantity) {
    int index = search_medicine(inventory, *inventory_size, name);
    if (index == -1) {
        // Add the medicine to the inventory
        add_medicine(inventory, inventory_size);
        index = *inventory_size - 1;
    }
    inventory[index].quantity += quantity;
    printf("Bought %d units of %s.\n", quantity, inventory[index].name);
}

// Main function
int main() {
    // Initialize the inventory
    medicine inventory[100];
    int inventory_size = 0;

    // Add some initial medicines to the inventory
    add_medicine(inventory, &inventory_size);
    add_medicine(inventory, &inventory_size);
    add_medicine(inventory, &inventory_size);

    // Display the inventory
    display_inventory(inventory, inventory_size);

    // Sell some medicine
    sell_medicine(inventory, &inventory_size, "Medicine 1", 10);
    sell_medicine(inventory, &inventory_size, "Medicine 2", 5);

    // Buy some medicine
    buy_medicine(inventory, &inventory_size, "Medicine 1", 15);
    buy_medicine(inventory, &inventory_size, "Medicine 3", 10);

    // Display the inventory
    display_inventory(inventory, inventory_size);

    return 0;
}