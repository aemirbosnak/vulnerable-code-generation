//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

// Create a function to calculate the total cost of an item
float calculateTotalCost(Item item) {
    return item.price * item.quantity;
}

// Create a function to display the bill
void displayBill(Item items[], int numItems) {
    printf("------------------------------------------------------------------------\n");
    printf("                           Romantic Cafe Billing System\n");
    printf("------------------------------------------------------------------------\n");
    printf("Item\t\t\tPrice\t\tQuantity\t\tTotal Cost\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%.2f\t\t%d\t\t%.2f\n", items[i].name, items[i].price, items[i].quantity, calculateTotalCost(items[i]));
    }

    printf("------------------------------------------------------------------------\n");
    printf("Total Cost:\t\t\t\t%.2f\n", calculateTotalCost(items[0]) + calculateTotalCost(items[1]));
    printf("Thank you for your visit to the Romantic Cafe!\n");
    printf("------------------------------------------------------------------------\n");
}

int main() {
    // Create an array of items
    Item items[] = {
        {"Coffee", 5.0, 2},
        {"Tea", 3.0, 1},
        {"Juice", 2.0, 3}
    };

    // Calculate the total cost of the items
    float totalCost = calculateTotalCost(items[0]) + calculateTotalCost(items[1]) + calculateTotalCost(items[2]);

    // Display the bill
    displayBill(items, 3);

    // Print the total cost
    printf("Total Cost:\t\t\t\t%.2f\n", totalCost);

    return 0;
}