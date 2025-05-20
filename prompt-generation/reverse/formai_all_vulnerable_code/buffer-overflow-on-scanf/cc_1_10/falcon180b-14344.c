//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

// Structure to store item information
typedef struct {
    char name[MAX_NAME_LEN];
    double price;
    int quantity;
} item_t;

// Function to initialize an item
void init_item(item_t* item) {
    strcpy(item->name, "");
    item->price = 0.0;
    item->quantity = 0;
}

// Function to add an item to the list
void add_item(item_t* items, int num_items, item_t* new_item) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    strcpy(items[num_items].name, new_item->name);
    items[num_items].price = new_item->price;
    items[num_items].quantity = new_item->quantity;

    num_items++;
}

// Function to calculate the total cost of items in the list
double calculate_total_cost(item_t* items, int num_items) {
    double total_cost = 0.0;

    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].price * items[i].quantity;
    }

    return total_cost;
}

// Function to print the list of items
void print_items(item_t* items, int num_items) {
    printf("Item Name\tPrice\tQuantity\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    init_item(&items[0]);
    add_item(items, num_items, &items[0]);

    printf("Enter item name: ");
    scanf("%s", items[0].name);
    printf("Enter item price: ");
    scanf("%lf", &items[0].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[0].quantity);

    printf("Item added successfully.\n");

    return 0;
}