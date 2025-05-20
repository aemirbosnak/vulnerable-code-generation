//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Assuming a maximum of 100 items in the order
#define MAX_ITEMS 100

// Structure to store item details
struct Item {
    char name[50];
    float price;
    int quantity;
};

// Function to get user input for item details
void getItemDetails(struct Item *item, int itemIndex) {
    printf("Enter item %d details:\n", itemIndex + 1);
    printf("Name: ");
    scanf("%s", item->name);
    printf("Price: ");
    scanf("%f", &item->price);
    printf("Quantity: ");
    scanf("%d", &item->quantity);
}

// Function to calculate total bill amount
float calculateTotalBill(struct Item items[], int numItems) {
    float totalBill = 0;
    for (int i = 0; i < numItems; i++) {
        totalBill += items[i].price * items[i].quantity;
    }
    return totalBill;
}

// Function to print receipt
void printReceipt(struct Item items[], int numItems, float totalBill) {
    printf("\n\n======================== Receipt ========================\n");
    printf("Item\t\tPrice\t\tQuantity\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%.2f\t\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
    printf("\nTotal Bill: %.2f\n", totalBill);
    printf("=========================================================\n");
}

int main() {

    // Initialize variables
    int numItems;
    float totalBill;

    // Get number of items in the order
    printf("Enter the number of items in the order: ");
    scanf("%d", &numItems);

    // Check if number of items is within the limit
    if (numItems > MAX_ITEMS) {
        printf("Error: Maximum number of items allowed is %d\n", MAX_ITEMS);
        return 1;
    }

    // Declare array of items
    struct Item items[MAX_ITEMS];

    // Get item details for each item
    for (int i = 0; i < numItems; i++) {
        getItemDetails(&items[i], i);
    }

    // Calculate total bill amount
    totalBill = calculateTotalBill(items, numItems);

    // Print receipt
    printReceipt(items, numItems, totalBill);

    return 0;
}