//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    int price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 50, 0},
    {"Tea", 40, 0},
    {"Juice", 30, 0},
    {"Water", 20, 0},
    {"Smoothie", 60, 0},
    {"Biscuits", 10, 0},
    {"Cookies", 12, 0},
    {"Scones", 15, 0},
    {"Muffins", 18, 0},
    {"Pancakes", 25, 0}
};

int main() {
    int numItems = 0;
    int itemIndex = -1;
    char itemName[20];
    int itemPrice = 0;
    int itemQuantity = 0;
    float totalAmount = 0.0f;

    // Display menu
    printf("Welcome to the Caffeinated Dream Cafe!\n\n");
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        printf("%d. %s - $%d\n", i + 1, items[i].name, items[i].price);
    }

    // Get item name
    printf("Please enter the name of the item you want to order: ");
    scanf("%s", itemName);

    // Find item index
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            itemIndex = i;
            break;
        }
    }

    // If item not found, display error message
    if (itemIndex == -1) {
        printf("Error: item not found.\n");
        return 1;
    }

    // Get item price and quantity
    printf("Please enter the price of the item: ");
    scanf("%d", &itemPrice);
    printf("Please enter the quantity of the item: ");
    scanf("%d", &itemQuantity);

    // Update item quantity
    items[itemIndex].quantity += itemQuantity;

    // Calculate total amount
    totalAmount = items[itemIndex].price * itemQuantity;

    // Display order confirmation
    printf("Your order has been confirmed!\n");
    printf("Item name: %s\n", items[itemIndex].name);
    printf("Quantity: %d\n", itemQuantity);
    printf("Total amount: $%.2f\n", totalAmount);

    return 0;
}