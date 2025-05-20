//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char name[50];
    float price;
};

struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Soda", 1.50},
    {"Water", 1.00},
    {"Sandwich", 5.00},
    {"Salad", 4.00},
    {"Soup", 3.00},
    {"Pastry", 2.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order
struct Order {
    struct MenuItem item;
    int quantity;
};

// Get the user's input
void getInput(struct Order *order, int *numItems) {
    int i;

    printf("Welcome to the Cafe Billing System!\n");
    printf("----------------------------------\n");

    // Get the number of items ordered
    printf("How many items would you like to order? ");
    scanf("%d", numItems);

    // Get the details of each item ordered
    for (i = 0; i < *numItems; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", order[i].item.name);

        printf("Enter the quantity of item %d: ", i + 1);
        scanf("%d", &order[i].quantity);
    }
}

// Calculate the total cost of the order
float calculateTotal(struct Order *order, int numItems) {
    int i;
    float total = 0.0;

    for (i = 0; i < numItems; i++) {
        total += order[i].item.price * order[i].quantity;
    }

    return total;
}

// Print the receipt
void printReceipt(struct Order *order, int numItems, float total) {
    int i;

    printf("\nHere is your receipt:\n");
    printf("----------------------\n");

    for (i = 0; i < numItems; i++) {
        printf("%s x %d = $%.2f\n", order[i].item.name, order[i].quantity, order[i].item.price * order[i].quantity);
    }

    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    struct Order order[MAX_ITEMS];
    int numItems;
    float total;

    getInput(order, &numItems);
    total = calculateTotal(order, numItems);
    printReceipt(order, numItems, total);

    return 0;
}