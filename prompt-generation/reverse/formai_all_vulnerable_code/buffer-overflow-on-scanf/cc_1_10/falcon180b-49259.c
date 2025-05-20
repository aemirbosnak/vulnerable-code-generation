//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the items in the medical store
struct item {
    char name[50];
    int quantity;
    float price;
};

// Function to add a new item to the store
void add_item(struct item* items, int num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", &items[num_items].name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &items[num_items].quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

// Function to display all items in the store
void display_items(struct item* items, int num_items) {
    printf("\nItems in the store:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %d units - %.2f each\n", i+1, items[i].name, items[i].quantity, items[i].price);
    }
}

// Function to search for an item in the store
int search_item(struct item* items, int num_items, char* name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to update the quantity of an item in the store
void update_quantity(struct item* items, int num_items, int index, int new_quantity) {
    items[index].quantity = new_quantity;
}

// Function to calculate the total cost of all items in the store
float calculate_total_cost(struct item* items, int num_items) {
    float total_cost = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].quantity * items[i].price;
    }
    return total_cost;
}

int main() {
    struct item items[100];
    int num_items = 0;

    // Initialize the store with some items
    add_item(items, num_items);
    add_item(items, num_items);
    add_item(items, num_items);

    // Display the items in the store
    display_items(items, num_items);

    // Update the quantity of an item
    int index = search_item(items, num_items, "Item 1");
    if (index!= -1) {
        printf("\nEnter the new quantity for %s:\n", items[index].name);
        scanf("%d", &items[index].quantity);
    }

    // Display the updated items in the store
    display_items(items, num_items);

    // Calculate the total cost of all items in the store
    float total_cost = calculate_total_cost(items, num_items);
    printf("\nThe total cost of all items in the store is: %.2f\n", total_cost);

    return 0;
}