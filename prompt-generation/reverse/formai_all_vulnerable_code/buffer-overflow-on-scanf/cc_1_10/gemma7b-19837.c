//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct Item {
    char name[50];
    int quantity;
    float price;
};

int main() {
    struct Item items[] = {
        {"Coffee", 10, 50.0},
        {"Tea", 8, 40.0},
        {"Juice", 12, 30.0},
        {"Smoothie", 6, 45.0}
    };

    int numItems = sizeof(items) / sizeof(struct Item);

    // Customer's order
    char itemName[50];
    int itemQuantity;

    printf("Welcome to the C Cafe!\n");

    // Get the customer's order
    printf("Please enter the name of the item you want: ");
    scanf("%s", itemName);

    // Find the item in the menu
    int itemIndex = -1;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            itemIndex = i;
            break;
        }
    }

    // If the item is not found, display an error message
    if (itemIndex == -1) {
        printf("Error: item not found.\n");
        return 1;
    }

    // Get the item quantity
    printf("Please enter the quantity of the item you want: ");
    scanf("%d", &itemQuantity);

    // Calculate the total cost of the item
    float totalCost = items[itemIndex].price * itemQuantity;

    // Display the total cost of the item
    printf("The total cost of your item is: $%.2f\n", totalCost);

    return 0;
}