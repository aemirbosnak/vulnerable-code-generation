//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct item {
    char name[20];
    int price;
    int quantity;
} item_t;

// Create an array of items
item_t items[] = {
    {"Coffee", 50, 10},
    {"Tea", 40, 5},
    {"Juice", 30, 7},
    {"Smoothie", 60, 3}
};

// Function to calculate the total cost of an order
int calculate_total_cost(item_t *items, int num_items) {
    int total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].price * items[i].quantity;
    }
    return total_cost;
}

// Function to display the menu
void display_menu() {
    printf("*** Coffee Shop Menu ***\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: $%d, Quantity: %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

// Function to take an order
void take_order() {
    char item_name[20];
    int quantity;

    printf("Enter item name:");
    scanf("%s", item_name);

    printf("Enter quantity:");
    scanf("%d", &quantity);

    for (int i = 0; i < 4; i++) {
        if (strcmp(item_name, items[i].name) == 0) {
            items[i].quantity += quantity;
            break;
        }
    }

    printf("Order placed!\n");
}

int main() {
    int choice;

    // Display menu
    display_menu();

    // Take an order
    take_order();

    // Calculate total cost
    int total_cost = calculate_total_cost(items, 4);

    // Display total cost
    printf("Total cost: $%d\n", total_cost);

    return 0;
}