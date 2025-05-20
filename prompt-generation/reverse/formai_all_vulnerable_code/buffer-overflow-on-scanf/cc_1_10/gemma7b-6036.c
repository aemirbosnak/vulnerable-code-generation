//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store item information
typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

// Define a function to calculate total cost
float calculateTotalCost(Item item) {
    return item.price * item.quantity;
}

// Define a function to print invoice
void printInvoice(Item item) {
    printf("----------------------------------------\n");
    printf("Item Name: %s\n", item.name);
    printf("Price: %.2f\n", item.price);
    printf("Quantity: %d\n", item.quantity);
    printf("Total Cost: %.2f\n", calculateTotalCost(item));
    printf("----------------------------------------\n");
}

int main() {
    // Create an item structure
    Item item;

    // Get item name, price, and quantity
    printf("Enter item name: ");
    scanf("%s", item.name);

    printf("Enter item price: ");
    scanf("%f", &item.price);

    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);

    // Calculate total cost
    float totalCost = calculateTotalCost(item);

    // Print invoice
    printInvoice(item);

    // Print total cost
    printf("Total Cost: %.2f\n", totalCost);

    return 0;
}