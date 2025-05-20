//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
struct item {
    char name[20];
    int price;
    int quantity;
};

// Define a function to calculate the total cost of an item
int calculate_cost(struct item item) {
    return item.price * item.quantity;
}

// Define a function to display the billing summary
void display_summary(struct item items[], int num_items) {
    printf("------------------------------------------------------------------------\n");
    printf("Bill Summary:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d units x %d = %d\n", items[i].name, items[i].quantity, items[i].price, calculate_cost(items[i]));
    }
    printf("Total Cost: %d\n", calculate_total_cost(items, num_items));
    printf("------------------------------------------------------------------------\n");
}

// Define a function to calculate the total cost of all items
int calculate_total_cost(struct item items[], int num_items) {
    int total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        total_cost += calculate_cost(items[i]);
    }
    return total_cost;
}

int main() {
    // Create an array of items
    struct item items[] = {
        {"Coffee", 50, 2},
        {"Tea", 30, 3},
        {"Juice", 20, 1}
    };

    // Calculate the total cost of all items
    int total_cost = calculate_total_cost(items, 3);

    // Display the billing summary
    display_summary(items, 3);

    // Print the total cost
    printf("Total Cost: %d\n", total_cost);

    return 0;
}