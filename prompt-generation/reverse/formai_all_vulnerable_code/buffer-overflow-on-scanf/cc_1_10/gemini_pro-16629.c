//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Structure to store medicine details
struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function to add a new medicine to the inventory
void add_medicine(struct Medicine *inventory, int *count) {
    // Get the medicine details from the user
    printf("Enter medicine ID: ");
    scanf("%d", &inventory[*count].id);

    printf("Enter medicine name: ");
    scanf("%s", inventory[*count].name);

    printf("Enter medicine price: ");
    scanf("%f", &inventory[*count].price);

    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[*count].quantity);

    // Increment the count of medicines in the inventory
    (*count)++;
}

// Function to search for a medicine by ID
struct Medicine *search_medicine_by_id(struct Medicine *inventory, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            return &inventory[i];
        }
    }

    return NULL;
}

// Function to sell a medicine
void sell_medicine(struct Medicine *inventory, int *count, int id, int quantity) {
    // Find the medicine by ID
    struct Medicine *medicine = search_medicine_by_id(inventory, *count, id);

    if (medicine == NULL) {
        printf("Medicine not found.\n");
        return;
    }

    // Check if the quantity to be sold is available
    if (medicine->quantity < quantity) {
        printf("Insufficient quantity.\n");
        return;
    }

    // Deduct the sold quantity from the inventory
    medicine->quantity -= quantity;

    // Calculate the total price of the sold medicines
    float total_price = medicine->price * quantity;

    // Print the receipt
    printf("------------------------------------\n");
    printf("Medicine Name: %s\n", medicine->name);
    printf("Quantity Sold: %d\n", quantity);
    printf("Total Price: %.2f\n", total_price);
    printf("------------------------------------\n");
}

// Function to print the inventory
void print_inventory(struct Medicine *inventory, int count) {
    printf("------------------------------------\n");
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f %-10d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("------------------------------------\n");
}

// Main function
int main() {
    // Initialize the medicine inventory
    struct Medicine inventory[100];
    int count = 0;

    // Add some initial medicines to the inventory
    add_medicine(inventory, &count);
    add_medicine(inventory, &count);
    add_medicine(inventory, &count);

    // Print the inventory
    print_inventory(inventory, count);

    // Search for a medicine by ID
    int id;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);
    struct Medicine *medicine = search_medicine_by_id(inventory, count, id);
    if (medicine == NULL) {
        printf("Medicine not found.\n");
    } else {
        printf("Medicine found:\n");
        printf("ID: %d\n", medicine->id);
        printf("Name: %s\n", medicine->name);
        printf("Price: %.2f\n", medicine->price);
        printf("Quantity: %d\n", medicine->quantity);
    }

    // Sell a medicine
    int quantity;
    printf("Enter medicine ID to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    sell_medicine(inventory, &count, id, quantity);

    // Print the inventory
    print_inventory(inventory, count);

    return 0;
}