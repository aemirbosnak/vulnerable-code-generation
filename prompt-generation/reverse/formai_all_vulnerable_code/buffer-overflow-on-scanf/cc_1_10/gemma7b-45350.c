//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 10, 2.50},
    {"Tea", 8, 2.20},
    {"Juice", 6, 2.00},
    {"Smoothie", 4, 2.75},
    {"Biscuits", 12, 1.50},
    {"Cookies", 14, 1.25},
    {"Scones", 9, 1.75},
    {"Muffins", 5, 1.80},
    {"Pancakes", 3, 2.05},
    {"Waffles", 7, 1.90}
};

int main() {
    int i, item_no, total_items = 0, total_price = 0;
    char item_name[20];

    printf("Welcome to the C Cafe Billing System!\n");

    // Loop to get the item name and quantity
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("Enter item name: ");
        scanf("%s", item_name);

        for (item_no = 0; item_no < total_items; item_no++) {
            if (strcmp(item_name, items[item_no].name) == 0) {
                printf("Enter quantity: ");
                scanf("%d", &items[item_no].quantity);
                break;
            }
        }

        if (item_no == total_items) {
            // Add new item to the list
            items[total_items].name[0] = '\0';
            strcpy(items[total_items].name, item_name);
            items[total_items].quantity = 1;
            items[total_items].price = 0.0;
            total_items++;
        }
    }

    // Calculate the total price
    for (i = 0; i < total_items; i++) {
        total_price += items[i].quantity * items[i].price;
    }

    // Print the total price
    printf("Total items: %d\n", total_items);
    printf("Total price: $%.2lf\n", total_price);

    return 0;
}