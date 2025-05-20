//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

struct Item {
    char name[20];
    int quantity;
    double price;
};

struct CashRegister {
    double total_amount;
    int num_items;
    struct Item items[MAX_ITEMS];
};

int main() {
    struct CashRegister register1;
    register1.total_amount = 0;
    register1.num_items = 0;

    // Create a few items
    struct Item item1;
    strcpy(item1.name, "Panadol");
    item1.quantity = 10;
    item1.price = 5.0;
    struct Item item2;
    strcpy(item2.name, "Paracetamol");
    item2.quantity = 15;
    item2.price = 4.0;

    // Add items to the register
    register1.items[0] = item1;
    register1.items[1] = item2;
    register1.num_items++;

    // Simulate a customer purchase
    printf("Enter the name of the item you want to buy:");
    char item_name[20];
    scanf("%s", item_name);

    // Search for the item
    struct Item* item = NULL;
    for (int i = 0; i < register1.num_items; i++) {
        if (strcmp(item_name, register1.items[i].name) == 0) {
            item = &register1.items[i];
            break;
        }
    }

    // Check if the item was found
    if (item) {
        // Calculate the total cost of the item
        double total_cost = item->quantity * item->price;

        // Update the total amount in the register
        register1.total_amount += total_cost;

        // Print the total cost
        printf("The total cost of the item is: $%.2lf", total_cost);
    } else {
        // Item not found
        printf("Item not found");
    }

    // Print the total amount
    printf("\nThe total amount in the register is: $%.2lf", register1.total_amount);

    return 0;
}