//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store warehouse item information
typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

// Define a function to manage warehouse items
void manageItems(Item items[], int numItems) {
    // Display a list of items
    printf("Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    // Add a new item
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);
    numItems++;

    // Update item quantity
    printf("Enter item name: ");
    scanf("%s", items[numItems - 1].name);
    printf("Enter new item quantity: ");
    scanf("%d", &items[numItems - 1].quantity);

    // Delete item
    printf("Enter item name: ");
    scanf("%s", items[numItems - 1].name);
    numItems--;
}

int main() {
    // Create an array of items
    Item items[] = {
        {"Book", 10, 20.0},
        {"Pen", 20, 10.0},
        {"Pencil", 15, 8.0}
    };

    // Manage items
    manageItems(items, 3);

    return 0;
}