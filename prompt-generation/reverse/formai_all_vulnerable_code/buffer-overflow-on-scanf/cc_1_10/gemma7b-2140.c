//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 5.0, 10},
    {"Tea", 3.0, 5},
    {"Juice", 4.0, 7},
    {"Smoothie", 6.0, 8},
    {"Soda", 2.0, 9},
    {"Water", 1.0, 12},
    {"Juice Lemon", 3.5, 6},
    {"Mango Juice", 4.5, 4},
    {"Fruit Juice", 3.0, 3},
    {"Iced Tea", 2.5, 2}
};

int main() {
    int item_num, quantity, total_items = 0;
    float total_price = 0.0;

    printf("Welcome to Cafe ABC!\n");

    // Display menu
    printf("Items:\n");
    for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++) {
        printf("%s - $%.2f, Quantity: %d\n", items[item_num].name, items[item_num].price, items[item_num].quantity);
    }

    // Get item and quantity
    printf("Enter item name: ");
    char item_name[20];
    scanf("%s", item_name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Find item and update quantity
    for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++) {
        if (strcmp(items[item_num].name, item_name) == 0) {
            items[item_num].quantity -= quantity;
            total_items++;
            total_price += items[item_num].price * quantity;
        }
    }

    // Calculate total price
    total_price = total_price * total_items;

    // Print receipt
    printf("\nThank you for your order, %s!\n", item_name);
    printf("Total items: %d\n", total_items);
    printf("Total price: $%.2f\n", total_price);

    return 0;
}