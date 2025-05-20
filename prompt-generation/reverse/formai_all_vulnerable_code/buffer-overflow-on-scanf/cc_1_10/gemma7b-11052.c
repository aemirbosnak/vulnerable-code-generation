//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store information about each item in the database
typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

// Define an array of items in the database
Item items[] = {
    {"Water", 10, 1.50},
    {"Food", 5, 2.00},
    {"Weapons", 2, 3.00},
    {"Armor", 3, 4.00},
    {"Medical supplies", 4, 5.00}
};

// Function to search for an item in the database
Item* searchItem(char* name) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return &items[i];
        }
    }

    return NULL;
}

int main() {

    // Get the item name from the user
    char itemName[20];
    printf("Enter the name of the item you want to find: ");
    scanf("%s", itemName);

    // Search for the item in the database
    Item* item = searchItem(itemName);

    // If the item was found, display its information
    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
    } else {
        // If the item was not found, display an error message
        printf("Item not found.\n");
    }

    return 0;
}