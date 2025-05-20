//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 5, 2.50},
    {"Tea", 3, 2.00},
    {"Juice", 2, 1.50},
    {"Soda", 4, 1.75},
    {"Water", 6, 1.25},
    {"Smoothie", 1, 3.00},
    {"Chocolate", 2, 2.25},
    {"Biscuits", 3, 1.00},
    {"Cookies", 4, 1.25},
    {"Scones", 2, 1.50}
};

int main() {
    int numItems = 10;
    int itemIndex = -1;
    float totalCost = 0.0;
    char itemName[20];

    printf("Welcome to the C Cafe Billing System!\n");
    printf("Please select an item: ");

    scanf("%s", itemName);

    for (int i = 0; i < numItems; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            itemIndex = i;
            break;
        }
    }

    if (itemIndex == -1) {
        printf("Item not found.\n");
    } else {
        printf("Quantity: %d\n", items[itemIndex].quantity);
        printf("Price: %.2f\n", items[itemIndex].price);
        printf("Total cost: %.2f\n", items[itemIndex].quantity * items[itemIndex].price);
        totalCost += items[itemIndex].quantity * items[itemIndex].price;
    }

    printf("Total cost: %.2f\n", totalCost);
    printf("Thank you for your order!\n");

    return 0;
}