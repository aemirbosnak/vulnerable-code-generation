//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store warehouse item information
typedef struct Item {
    char item_name[20];
    int quantity;
    float price;
} Item;

// Define a function to add an item to the warehouse
void add_item(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->item_name);

    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter item price: ");
    scanf("%f", &item->price);
}

// Define a function to list all items in the warehouse
void list_items(Item *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d, $%.2f\n", items[i].item_name, items[i].quantity, items[i].price);
    }
}

// Define a function to search for an item in the warehouse
void search_item(Item *items, int num_items) {
    char item_name[20];

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].item_name, item_name) == 0) {
            printf("%s: %d, $%.2f\n", items[i].item_name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    // Create an array of items in the warehouse
    Item items[] = {
        {"Apple", 100, 1.20},
        {"Banana", 50, 0.80},
        {"Orange", 75, 1.00}
    };

    // Number of items in the warehouse
    int num_items = 3;

    // Menu options
    int menu_choice;

    // Display menu options
    printf("1. Add Item\n");
    printf("2. List Items\n");
    printf("3. Search Item\n");

    // Get user input
    printf("Enter your choice: ");
    scanf("%d", &menu_choice);

    // Switch case to handle user input
    switch (menu_choice) {
        case 1:
            add_item(&items[num_items++]);
            break;
        case 2:
            list_items(items, num_items);
            break;
        case 3:
            search_item(items, num_items);
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}