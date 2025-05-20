//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the menu items
struct menu_item {
    char name[50];
    float price;
};

// Define the structure of the order
struct order {
    int num_items;
    struct menu_item items[10];
};

// Function to display the menu
void display_menu(struct menu_item menu[], int num_items) {
    printf("Cafe Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take the order
void take_order(struct order *order) {
    printf("Enter the number of items in your order:\n");
    scanf("%d", &order->num_items);

    printf("Enter the items you want to order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("Item %d:\n", i+1);
        scanf("%s", order->items[i].name);
        printf("Price of %s:\n", order->items[i].name);
        scanf("%f", &order->items[i].price);
    }
}

// Function to calculate the total cost of the order
float calculate_total(struct order order) {
    float total = 0;
    for (int i = 0; i < order.num_items; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to display the order
void display_order(struct order order) {
    printf("Order:\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total cost: $%.2f\n", calculate_total(order));
}

int main() {
    // Define the menu items
    struct menu_item menu[] = {{"Coffee", 2.50}, {"Tea", 1.50}, {"Cake", 3.50}};

    // Define the order
    struct order order;

    // Display the menu
    display_menu(menu, 3);

    // Take the order
    take_order(&order);

    // Display the order
    display_order(order);

    return 0;
}