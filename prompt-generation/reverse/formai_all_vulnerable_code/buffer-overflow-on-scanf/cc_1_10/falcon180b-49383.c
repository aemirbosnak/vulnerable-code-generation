//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_CATEGORY_LEN 20
#define MAX_PRICE 1000000
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char category[MAX_CATEGORY_LEN];
    float price;
    int quantity;
} Item;

int main() {
    Item inventory[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Happy Product Inventory System!\n");
    printf("Let's start by adding some items to the inventory.\n");

    while (1) {
        printf("Enter the name of the item (up to %d characters): ", MAX_NAME_LEN - 1);
        scanf("%s", inventory[num_items].name);

        printf("Enter the description of the item (up to %d characters): ", MAX_DESCRIPTION_LEN - 1);
        scanf("%s", inventory[num_items].description);

        printf("Enter the category of the item (up to %d characters): ", MAX_CATEGORY_LEN - 1);
        scanf("%s", inventory[num_items].category);

        printf("Enter the price of the item (up to %d): ", MAX_PRICE);
        scanf("%f", &inventory[num_items].price);

        printf("Enter the quantity of the item (up to %d): ", MAX_QUANTITY);
        scanf("%d", &inventory[num_items].quantity);

        num_items++;

        printf("\nItem added successfully!\n");

        printf("Do you want to add another item? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    printf("\nInventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Description: %s\n", inventory[i].description);
        printf("Category: %s\n", inventory[i].category);
        printf("Price: $%.2f\n", inventory[i].price);
        printf("Quantity: %d\n\n", inventory[i].quantity);
    }

    return 0;
}