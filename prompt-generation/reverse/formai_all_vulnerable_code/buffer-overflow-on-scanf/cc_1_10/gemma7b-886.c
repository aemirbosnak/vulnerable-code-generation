//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store item information
typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

// Create an array of items
Item items[] = {
    {"Coffee", 5.0, 10},
    {"Tea", 4.0, 8},
    {"Juice", 3.0, 12},
    {"Smoothie", 6.0, 9}
};

// Define a function to calculate the total cost of an order
float calculateTotalCost(int numItems, Item items[]) {
    float totalCost = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

// Define a function to print the bill
void printBill(int numItems, Item items[], float totalCost) {
    printf("------------------------------------------------\n");
    printf("C Cafe Billing System\n");
    printf("------------------------------------------------\n");
    printf("Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: %d @ $%.2f = $%.2f\n", items[i].name, items[i].quantity, items[i].price, items[i].price * items[i].quantity);
    }
    printf("Total Cost: $%.2f\n", totalCost);
    printf("------------------------------------------------\n");
}

int main() {
    int numItems = 0;
    float totalCost = 0.0;
    Item items[100];

    // Get the number of items in the order
    printf("Enter the number of items you want to order: ");
    scanf("%d", &numItems);

    // Create the items in the order
    for (int i = 0; i < numItems; i++) {
        items[i].name[0] = '\0';
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i].name);

        printf("Enter the price of item %d: ", i + 1);
        scanf("%f", &items[i].price);

        printf("Enter the quantity of item %d: ", i + 1);
        scanf("%d", &items[i].quantity);
    }

    // Calculate the total cost of the order
    totalCost = calculateTotalCost(numItems, items);

    // Print the bill
    printBill(numItems, items, totalCost);

    return 0;
}