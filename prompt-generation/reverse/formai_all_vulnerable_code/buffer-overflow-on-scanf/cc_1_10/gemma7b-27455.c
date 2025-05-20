//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 10, 5.0},
    {"Tea", 8, 4.0},
    {"Juice", 6, 3.0},
    {"Smoothie", 5, 6.0},
    {"Biscuits", 7, 2.0},
    {"Cookies", 9, 2.5},
    {"Scones", 6, 3.5},
    {"Pancakes", 8, 4.5},
    {"Waffles", 10, 5.5},
    {"Muesli", 4, 3.2}
};

int main() {
    int numItems = 10;
    int itemIndex;
    char itemName[20];
    int itemQuantity;
    float itemPrice;
    float totalAmount = 0.0;

    printf("Welcome to The Coffee Bean!\n");
    printf("Please select an item: ");

    // Get the item name
    scanf("%s", itemName);

    // Find the item index
    for (itemIndex = 0; itemIndex < numItems; itemIndex++) {
        if (strcmp(itemName, items[itemIndex].name) == 0) {
            break;
        }
    }

    // If the item is found, get the item quantity and price
    if (itemIndex != numItems) {
        printf("Enter the quantity of the item: ");
        scanf("%d", &itemQuantity);

        itemPrice = items[itemIndex].price * itemQuantity;
        totalAmount += itemPrice;

        printf("Your order: %s (%d) for %.2f\n", items[itemIndex].name, itemQuantity, itemPrice);
    } else {
        printf("Item not found.\n");
    }

    // Calculate the total amount
    printf("Total amount: %.2f\n", totalAmount);

    // Prompt the customer to pay
    printf("Please pay the amount: ");

    // Get the payment
    float payment;

    scanf("%f", &payment);

    // Calculate the change
    float change = payment - totalAmount;

    // Print the change
    printf("Change: %.2f\n", change);

    return 0;
}