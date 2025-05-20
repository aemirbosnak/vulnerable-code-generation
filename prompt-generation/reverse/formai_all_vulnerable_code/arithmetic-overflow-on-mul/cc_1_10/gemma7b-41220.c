//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
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

// Define a function to display the bill
void display_bill(struct item items[], int num_items) {
    printf("------------------------------------------------------------------------\n");
    printf("                                 Cafe Bill\n");
    printf("------------------------------------------------------------------------\n");
    printf("Item\t\t\tPrice\t\tQuantity\t\tTotal Cost\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\n", items[i].name, items[i].price, items[i].quantity, calculate_cost(items[i]));
    }

    printf("------------------------------------------------------------------------\n");
    printf("Total Cost:\t\t\t\t\t\t%d\n", calculate_total_cost(items, num_items));
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
        {"Tea", 30, 1},
        {"Juice", 20, 3},
        {"Water", 10, 4}
    };

    // Calculate the total cost of all items
    int total_cost = calculate_total_cost(items, 4);

    // Display the bill
    display_bill(items, 4);

    // Print the total cost
    printf("Total Cost: $%d\n", total_cost);

    return 0;
}