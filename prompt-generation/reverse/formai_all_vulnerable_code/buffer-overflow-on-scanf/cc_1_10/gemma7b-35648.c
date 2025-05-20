//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
struct item {
    char name[20];
    int price;
    int quantity;
};

// Create an array of items
struct item items[] = {
    {"Coffee", 50, 10},
    {"Tea", 40, 5},
    {"Juice", 30, 7},
    {"Smoothie", 60, 2}
};

// Function to calculate the total cost of an item
int calculateTotalCost(struct item item) {
    return item.price * item.quantity;
}

// Function to display the items
void displayItems() {
    for (int i = 0; i < 4; i++) {
        printf("%s - $%d, Quantity: %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

// Function to take an order
void takeOrder() {
    char itemName[20];
    int itemQuantity;

    printf("Enter item name: ");
    scanf("%s", itemName);

    for (int i = 0; i < 4; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            printf("Enter item quantity: ");
            scanf("%d", &itemQuantity);

            items[i].quantity -= itemQuantity;

            int totalCost = calculateTotalCost(items[i]);
            printf("Total cost: $%d\n", totalCost);
        }
    }
}

int main() {
    displayItems();
    takeOrder();

    return 0;
}