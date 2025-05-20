//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

// Define a function to calculate total cost
float calculateTotalCost(Item item, int quantity) {
    return item.price * quantity;
}

// Define a function to display invoice
void displayInvoice(Item item, int quantity, float totalCost) {
    printf("Item: %s\n", item.name);
    printf("Quantity: %d\n", quantity);
    printf("Price: %.2f\n", item.price);
    printf("Total Cost: %.2f\n", totalCost);
    printf("\n");
}

int main() {
    // Create an array of items
    Item items[] = {
        {"Coffee", 2.50, 10},
        {"Tea", 3.00, 8},
        {"Juice", 2.00, 12}
    };

    // Get the item name and quantity from the user
    char itemName[50];
    int quantity;
    printf("Enter item name: ");
    scanf("%s", itemName);

    // Find the item in the array
    Item item = items[0];
    for (int i = 0; i < 3; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            item = items[i];
            break;
        }
    }

    // Calculate the total cost
    float totalCost = calculateTotalCost(item, quantity);

    // Display the invoice
    displayInvoice(item, quantity, totalCost);

    // Print the total cost
    printf("Total Cost: %.2f\n", totalCost);

    return 0;
}