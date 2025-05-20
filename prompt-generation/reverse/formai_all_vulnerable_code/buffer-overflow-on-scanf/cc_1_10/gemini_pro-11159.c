//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Structure to store item details
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Function to calculate total cost of each item
float calculateItemCost(Item item) {
    return item.quantity * item.price;
}

// Function to calculate total cost of all items
float calculateTotalCost(Item items[], int numItems) {
    float totalCost = 0;
    for (int i = 0; i < numItems; i++) {
        totalCost += calculateItemCost(items[i]);
    }
    return totalCost;
}

// Function to print bill
void printBill(Item items[], int numItems, float totalCost) {
    printf("Cafe Billing System\n");
    printf("--------------------\n");
    printf("Item Name\tQuantity\tPrice\tCost\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%d\t\t%.2f\t%.2f\n", items[i].name, items[i].quantity, items[i].price, calculateItemCost(items[i]));
    }
    printf("--------------------\n");
    printf("Total Cost: %.2f\n", totalCost);
}

int main() {

    // Get number of items from user
    int numItems;
    printf("Enter number of items: ");
    scanf("%d", &numItems);

    // Get item details from user
    Item items[numItems];
    for (int i = 0; i < numItems; i++) {
        printf("Enter item name: ");
        scanf("%s", items[i].name);
        printf("Enter quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Enter price: ");
        scanf("%f", &items[i].price);
    }

    // Calculate total cost
    float totalCost = calculateTotalCost(items, numItems);

    // Print bill
    printBill(items, numItems, totalCost);

    return 0;
}