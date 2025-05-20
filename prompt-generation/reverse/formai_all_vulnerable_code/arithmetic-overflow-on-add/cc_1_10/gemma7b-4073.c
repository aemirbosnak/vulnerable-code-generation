//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[] = {
    {"Coffee", 10, 5.0},
    {"Tea", 8, 3.5},
    {"Juice", 12, 4.0},
    {"Biscuits", 15, 2.0},
    {"Cookies", 18, 2.5}
};

int main() {
    int i, totalQuantity = 0, totalAmount = 0;
    char itemName[50];
    int itemQuantity;
    float itemPrice;

    // Display item list
    printf("Items:\n");
    for (i = 0; i < 5; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    // Get item name and quantity
    printf("Enter item name: ");
    scanf("%s", itemName);

    printf("Enter item quantity: ");
    scanf("%d", &itemQuantity);

    // Find item and update quantity
    for (i = 0; i < 5; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            items[i].quantity += itemQuantity;
            break;
        }
    }

    // Calculate total quantity and amount
    for (i = 0; i < 5; i++) {
        totalQuantity += items[i].quantity;
        totalAmount += items[i].quantity * items[i].price;
    }

    // Display total quantity and amount
    printf("Total quantity: %d\n", totalQuantity);
    printf("Total amount: %.2f\n", totalAmount);

    return 0;
}