//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

// Define a function to calculate the total cost of an item
float calculate_cost(Item item) {
    return item.quantity * item.price;
}

// Define a function to calculate the total bill
float calculate_bill(Item items[], int num_items) {
    float total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        total_cost += calculate_cost(items[i]);
    }
    return total_cost;
}

// Define a function to print the bill
void print_bill(Item items[], int num_items, float total_cost) {
    printf("-------------------------------------------------------\n");
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %d @ %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("\nTotal Cost: %.2f\n", total_cost);
    printf("-------------------------------------------------------\n");
}

int main() {
    // Create an array of items
    Item items[] = {
        {"Coffee", 5, 2.50},
        {"Tea", 3, 1.50},
        {"Juice", 2, 1.20}
    };

    // Calculate the total bill
    float total_cost = calculate_bill(items, 3);

    // Print the bill
    print_bill(items, 3, total_cost);

    return 0;
}