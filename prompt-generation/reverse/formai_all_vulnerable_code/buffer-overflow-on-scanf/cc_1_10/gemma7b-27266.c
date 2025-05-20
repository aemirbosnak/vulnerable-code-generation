//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct Item {
    char name[20];
    int price;
    int quantity;
} Item;

// Create an array of items
Item items[] = {
    {"Coffee", 50, 10},
    {"Tea", 30, 8},
    {"Juice", 20, 12},
    {"Smoothie", 40, 6}
};

// Define a function to calculate the total cost of an order
int calculateTotalCost(int numItems, Item items[]) {
    int totalCost = 0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

// Define a function to print the bill
void printBill(int totalCost, int numItems, Item items[]) {
    printf("\n--- C Cafe Billing System ---\n");
    printf("Total items: %d\n", numItems);
    for (int i = 0; i < numItems; i++) {
        printf("%s: %d x %d = %d\n", items[i].name, items[i].quantity, items[i].price, items[i].quantity * items[i].price);
    }
    printf("Total cost: %d\n", totalCost);
    printf("Thank you for your order!\n");
}

int main() {
    int numItems = 0;
    int totalCost = 0;
    Item items[] = {items, &items};

    // Get the number of items in the order
    printf("Enter the number of items in your order: ");
    scanf("%d", &numItems);

    // Calculate the total cost of the order
    totalCost = calculateTotalCost(numItems, items);

    // Print the bill
    printBill(totalCost, numItems, items);

    return 0;
}