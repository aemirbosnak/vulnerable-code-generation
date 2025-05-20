//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the number of items
#define NUM_ITEMS 5

// Define the item structure
typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

// Create an array of items
Item items[NUM_ITEMS] = {
    {"Coffee", 50.0, 10},
    {"Tea", 40.0, 8},
    {"Juice", 30.0, 6},
    {"Smoothie", 20.0, 4},
    {"Water", 10.0, 2}
};

// Function to calculate the total cost
float calculateTotalCost(int itemsQuantity, Item items[]) {
    float totalCost = 0.0;
    for (int i = 0; i < itemsQuantity; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

// Function to print the bill
void printBill(float totalCost, int itemsQuantity, Item items[]) {
    printf("--------------------------------------------------------\n");
    printf("**Coffee Shop Bill**\n");
    printf("--------------------------------------------------------\n");
    printf("Items:\n");
    for (int i = 0; i < itemsQuantity; i++) {
        printf("%s - %d units @ %.2f each = %.2f\n", items[i].name, items[i].quantity, items[i].price, items[i].price * items[i].quantity);
    }
    printf("\nTotal Cost: %.2f\n", totalCost);
    printf("\nThank you for your visit! Come again soon!\n");
    printf("--------------------------------------------------------\n");
}

int main() {
    int itemsQuantity = 0;
    float totalCost = 0.0;

    // Get the number of items
    printf("Enter the number of items: ");
    scanf("%d", &itemsQuantity);

    // Calculate the total cost
    totalCost = calculateTotalCost(itemsQuantity, items);

    // Print the bill
    printBill(totalCost, itemsQuantity, items);

    return 0;
}