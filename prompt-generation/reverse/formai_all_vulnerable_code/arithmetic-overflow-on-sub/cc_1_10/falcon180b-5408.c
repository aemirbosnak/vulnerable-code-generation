//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Define the structure for the menu items
struct menu_item {
    char name[50];
    float price;
};

// Define the structure for the customer order
struct order {
    int num_items;
    struct menu_item items[MAX_ITEMS];
};

// Function to print the menu
void print_menu(struct menu_item menu[], int num_items) {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to add an item to the customer order
void add_item(struct order *order, struct menu_item menu[], int num_items) {
    if (order->num_items >= MAX_ITEMS) {
        printf("Error: Maximum items reached.\n");
        return;
    }
    int choice;
    printf("Enter the number of the item you would like to order: ");
    scanf("%d", &choice);
    choice--;
    if (choice < 0 || choice >= num_items) {
        printf("Error: Invalid item.\n");
        return;
    }
    order->items[order->num_items] = menu[choice];
    order->num_items++;
}

// Function to calculate the total price of the customer order
float calculate_total(struct order order) {
    float total = 0;
    for (int i = 0; i < order.num_items; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to display the customer order
void display_order(struct order order) {
    printf("Customer Order:\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total: $%.2f\n", calculate_total(order));
}

int main() {
    // Define the menu items
    struct menu_item menu[] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Pastry", 3.00}};
    int num_items = sizeof(menu)/sizeof(menu[0]);

    // Define the customer order
    struct order order = {0};

    // Print the menu
    print_menu(menu, num_items);

    // Add items to the customer order
    add_item(&order, menu, num_items);
    add_item(&order, menu, num_items);

    // Display the customer order
    display_order(order);

    return 0;
}