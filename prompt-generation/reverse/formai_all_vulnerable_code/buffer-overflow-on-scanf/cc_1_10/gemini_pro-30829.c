//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the inventory
void add_medicine(medicine *inventory, int *size) {
    // Get the details of the new medicine
    printf("Enter medicine ID: ");
    scanf("%d", &inventory[*size].id);

    printf("Enter medicine name: ");
    scanf(" %[^\n]s", inventory[*size].name);

    printf("Enter medicine manufacturer: ");
    scanf(" %[^\n]s", inventory[*size].manufacturer);

    printf("Enter medicine price: ");
    scanf("%f", &inventory[*size].price);

    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[*size].quantity);

    // Increment the size of the inventory
    (*size)++;
}

// Function to search for a medicine by ID
medicine* search_medicine_by_id(medicine *inventory, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            return &inventory[i];
        }
    }

    return NULL;
}

// Function to sell a medicine
void sell_medicine(medicine *inventory, int *size, int id, int quantity) {
    // Search for the medicine by ID
    medicine *medicine = search_medicine_by_id(inventory, *size, id);

    // Check if the medicine was found
    if (medicine == NULL) {
        printf("Medicine not found.\n");
        return;
    }

    // Check if the medicine has enough quantity
    if (medicine->quantity < quantity) {
        printf("Insufficient quantity.\n");
        return;
    }

    // Update the medicine quantity
    medicine->quantity -= quantity;

    // Calculate the total price
    float total_price = medicine->price * quantity;

    // Print the receipt
    printf("Medicine ID: %d\n", medicine->id);
    printf("Medicine name: %s\n", medicine->name);
    printf("Medicine quantity: %d\n", quantity);
    printf("Total price: %.2f\n", total_price);
}

// Function to print the inventory
void print_inventory(medicine *inventory, int size) {
    printf("Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("Medicine ID: %d\n", inventory[i].id);
        printf("Medicine name: %s\n", inventory[i].name);
        printf("Medicine manufacturer: %s\n", inventory[i].manufacturer);
        printf("Medicine price: %.2f\n", inventory[i].price);
        printf("Medicine quantity: %d\n\n");
    }
}

// Main function
int main() {
    // Initialize the inventory
    medicine inventory[100];
    int size = 0;

    // Add some sample medicines to the inventory
    add_medicine(inventory, &size);
    add_medicine(inventory, &size);
    add_medicine(inventory, &size);

    // Print the inventory
    print_inventory(inventory, size);

    // Search for a medicine by ID
    int id = 2;
    medicine *medicine = search_medicine_by_id(inventory, size, id);

    // Check if the medicine was found
    if (medicine == NULL) {
        printf("Medicine not found.\n");
    } else {
        printf("Medicine found:\n");
        printf("Medicine ID: %d\n", medicine->id);
        printf("Medicine name: %s\n", medicine->name);
        printf("Medicine manufacturer: %s\n", medicine->manufacturer);
        printf("Medicine price: %.2f\n", medicine->price);
        printf("Medicine quantity: %d\n", medicine->quantity);
    }

    // Sell a medicine
    int quantity = 2;
    sell_medicine(inventory, &size, id, quantity);

    // Print the updated inventory
    print_inventory(inventory, size);

    return 0;
}