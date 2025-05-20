//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_CATEGORY_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char category[MAX_CATEGORY_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
} Item;

void addItem(Item* inventory, int numItems) {
    printf("Enter the name of the item: ");
    scanf("%s", inventory[numItems].name);
    printf("Enter the description of the item: ");
    scanf("%s", inventory[numItems].description);
    printf("Enter the category of the item: ");
    scanf("%s", inventory[numItems].category);
    printf("Enter the price of the item: ");
    scanf("%s", inventory[numItems].price);
    printf("Enter the quantity of the item: ");
    scanf("%d", &inventory[numItems].quantity);
}

void displayItem(Item item) {
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Category: %s\n", item.category);
    printf("Price: %s\n", item.price);
    printf("Quantity: %d\n\n", item.quantity);
}

void displayInventory(Item* inventory, int numItems) {
    printf("Product Inventory:\n");
    for (int i = 0; i < numItems; i++) {
        displayItem(inventory[i]);
    }
}

int main() {
    Item inventory[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("Enter 1 to add an item, 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            addItem(inventory, numItems);
            numItems++;
        } else {
            break;
        }
    }

    displayInventory(inventory, numItems);

    return 0;
}