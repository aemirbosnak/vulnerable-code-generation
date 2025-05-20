//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    double price;
};

struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Muffin", 3.00},
    {"Scone", 2.00},
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Get the number of items ordered
int getNumItems() {
    int numItems;
    printf("How many items would you like to order? ");
    scanf("%d", &numItems);
    return numItems;
}

// Get the items ordered
int getItems(struct MenuItem *items) {
    int numItems = getNumItems();
    for (int i = 0; i < numItems; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf(" %s", items[i].name);
        printf("Enter the price of item %d: ", i + 1);
        scanf(" %lf", &items[i].price);
    }
    return numItems;
}

// Calculate the total price of the order
double calculateTotal(struct MenuItem *items, int numItems) {
    double total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price;
    }
    return total;
}

// Print the receipt
void printReceipt(struct MenuItem *items, int numItems, double total) {
    printf("Here is your receipt:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: $%.2f\n", items[i].name, items[i].price);
    }
    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    // Get the items ordered
    struct MenuItem items[MAX_ITEMS];
    int numItems = getItems(items);

    // Calculate the total price of the order
    double total = calculateTotal(items, numItems);

    // Print the receipt
    printReceipt(items, numItems, total);

    return 0;
}