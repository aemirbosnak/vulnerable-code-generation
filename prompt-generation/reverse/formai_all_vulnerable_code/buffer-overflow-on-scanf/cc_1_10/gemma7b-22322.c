//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct Item {
    char name[20];
    int quantity;
    double price;
};

struct Item items[] = {
    {"Banana", 10, 1.20},
    {"Apple", 15, 1.50},
    {"Orange", 20, 1.70},
    {"Mango", 12, 1.90}
};

int main() {
    int i, total_items = 4;
    char item_name[20];
    int item_quantity;
    double item_price;

    printf("Welcome to the Quirky C Product Inventory System!\n");

    // Display list of items
    printf("Items:\n");
    for (i = 0; i < total_items; i++) {
        printf("%s - %d - %.2lf\n", items[i].name, items[i].quantity, items[i].price);
    }

    // Get item name and quantity
    printf("Enter item name:");
    scanf("%s", item_name);

    printf("Enter item quantity:");
    scanf("%d", &item_quantity);

    // Find item and update quantity
    for (i = 0; i < total_items; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            items[i].quantity += item_quantity;
            break;
        }
    }

    // Display updated item list
    printf("Updated Items:\n");
    for (i = 0; i < total_items; i++) {
        printf("%s - %d - %.2lf\n", items[i].name, items[i].quantity, items[i].price);
    }

    return 0;
}