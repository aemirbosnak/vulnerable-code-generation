//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    double price;
} Item;

void print_item(Item item) {
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Quantity: %d\n", item.quantity);
    printf("Price: $%.2f\n\n", item.price);
}

int main() {
    Item inventory[MAX_ITEMS];
    int num_items = 0;

    printf("Product Inventory System\n\n");

    while (num_items < MAX_ITEMS) {
        printf("Enter product information (leave blank to finish):\n");
        printf("Name (max %d characters): ", MAX_NAME_LEN - 1);
        scanf("%s", inventory[num_items].name);

        if (strcmp(inventory[num_items].name, "") == 0) {
            break;
        }

        printf("Description (max %d characters): ", MAX_DESCRIPTION_LEN - 1);
        scanf("%s", inventory[num_items].description);

        printf("Quantity: ");
        scanf("%d", &inventory[num_items].quantity);

        printf("Price: ");
        scanf("%lf", &inventory[num_items].price);

        num_items++;
    }

    printf("\nInventory:\n");

    for (int i = 0; i < num_items; i++) {
        print_item(inventory[i]);
    }

    return 0;
}