//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS] = {
    {"Ale", 0, 2.50},
    {"Bread", 1, 1.25},
    {"Cheese", 0, 3.75},
    {"Fish", 2, 2.00},
    {"Honey", 1, 0.75},
    {"Juice", 0, 1.50},
    {"Mushrooms", 0, 3.25},
    {"Noodles", 1, 1.75},
    {"Pie", 0, 2.25},
    {"Soup", 0, 1.00}
};

int main() {
    int i, total_items = 0, total_price = 0;
    char item_name[20];
    int item_quantity;
    double item_price;

    // Print the menu
    printf("Welcome to The Rusty Dragon Inn!\n");
    printf("Please select an item from the menu:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - %d for %f\n", i + 1, items[i].name, items[i].quantity, items[i].price);
    }

    // Get the item name and quantity
    printf("Enter item name: ");
    scanf("%s", item_name);

    printf("Enter item quantity: ");
    scanf("%d", &item_quantity);

    // Find the item and update its quantity
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(item_name, items[i].name) == 0) {
            items[i].quantity += item_quantity;
        }
    }

    // Calculate the total items and price
    total_items = 0;
    total_price = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        total_items += items[i].quantity;
        total_price += items[i].quantity * items[i].price;
    }

    // Print the receipt
    printf("Your Order:\n");
    printf("Total items: %d\n", total_items);
    printf("Total price: %f\n", total_price);

    // Thank the customer
    printf("Thank you for your visit to The Rusty Dragon Inn!\n");

    return 0;
}