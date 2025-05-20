//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a coffee item
typedef struct CoffeeItem {
    char name[20];
    float price;
    int quantity;
} CoffeeItem;

// Create an array of coffee items
CoffeeItem items[] = {
    {"Latte", 3.50, 0},
    {"Cappuccino", 4.00, 0},
    {"Americano", 2.00, 0},
    {"Mocha", 3.25, 0},
    {"Cappuccino Royale", 5.00, 0}
};

// Define a function to calculate the total cost of an order
float calculateTotalCost(CoffeeItem item, int quantity) {
    return item.price * quantity;
}

// Define a function to print the order receipt
void printOrderReceipt(CoffeeItem item, int quantity) {
    printf("Order:\n");
    printf("%s (%d) - $%.2f\n", item.name, quantity, calculateTotalCost(item, quantity));
    printf("Total Cost: $%.2f\n", calculateTotalCost(item, quantity));
}

int main() {
    // Get the user's order
    char itemName[20];
    int itemQuantity;
    printf("Enter the name of your coffee item: ");
    scanf("%s", itemName);
    printf("Enter the quantity of your coffee item: ");
    scanf("%d", &itemQuantity);

    // Find the coffee item in the array
    CoffeeItem item = items[0];
    for (int i = 0; i < 5; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            item = items[i];
            break;
        }
    }

    // Calculate the total cost of the order
    float totalCost = calculateTotalCost(item, itemQuantity);

    // Print the order receipt
    printOrderReceipt(item, itemQuantity);

    return 0;
}