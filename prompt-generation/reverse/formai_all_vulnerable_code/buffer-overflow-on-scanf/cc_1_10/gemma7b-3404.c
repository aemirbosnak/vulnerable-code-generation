//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store items
typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

// Define a function to add an item to the store
void addItem(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter item price: ");
    scanf("%f", &item->price);
}

// Define a function to display all items in the store
void displayItems(Item *items, int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Define a function to search for an item in the store
void searchItem(Item *items, int numItems) {
    char searchName[20];
    printf("Enter item name: ");
    scanf("%s", searchName);

    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            printf("Item name: %s\n", items[i].name);
            printf("Item quantity: %d\n", items[i].quantity);
            printf("Item price: %.2f\n", items[i].price);
        }
    }
}

int main() {
    // Create an array of items
    Item items[] = {{"Paracetamol", 100, 5.0}, {"Ibuprofen", 50, 6.0}, {"Crocin", 20, 7.0}, {"Tefagen", 30, 4.0}, {"Pepsin", 40, 3.0}};

    // Number of items in the store
    int numItems = 5;

    // Display all items in the store
    displayItems(items, numItems);

    // Search for an item in the store
    searchItem(items, numItems);

    return 0;
}