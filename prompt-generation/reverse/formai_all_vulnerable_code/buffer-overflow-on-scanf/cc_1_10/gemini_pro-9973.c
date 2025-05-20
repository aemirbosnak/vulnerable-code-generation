//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Structure to store item details
typedef struct item {
    char name[50];
    int quantity;
    float price;
} Item;

// Function to calculate total price of an item
float calculateTotalPrice(Item item) {
    return item.quantity * item.price;
}

// Function to print item details
void printItemDetails(Item item) {
    printf("%-20s  %-10d  %-10.2f\n", item.name, item.quantity, item.price);
}

// Function to print bill header
void printBillHeader() {
    printf("=====================================================================\n");
    printf("                            Cafe Billing System                      \n");
    printf("=====================================================================\n");
    printf("Item Name              Quantity   Price\n");
    printf("---------------------------------------------------------------------\n");
}

// Function to print bill footer
void printBillFooter(float totalAmount) {
    printf("---------------------------------------------------------------------\n");
    printf("Total Amount:                              %.2f\n", totalAmount);
    printf("=====================================================================\n");
}

// Main function
int main() {
    // Array to store item details
    Item items[50];

    // Variable to store number of items
    int numItems;

    // Get number of items from user
    printf("Enter number of items: ");
    scanf("%d", &numItems);

    // Get item details from user
    for (int i = 0; i < numItems; i++) {
        printf("Enter item name: ");
        scanf("%s", items[i].name);
        printf("Enter quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Enter price: ");
        scanf("%f", &items[i].price);
    }

    // Calculate total price of each item
    float totalAmount = 0;
    for (int i = 0; i < numItems; i++) {
        totalAmount += calculateTotalPrice(items[i]);
    }

    // Print bill header
    printBillHeader();

    // Print item details
    for (int i = 0; i < numItems; i++) {
        printItemDetails(items[i]);
    }

    // Print bill footer
    printBillFooter(totalAmount);

    return 0;
}