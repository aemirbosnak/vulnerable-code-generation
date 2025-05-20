//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct item {
    char name[20];
    int price;
    int quantity;
} item;

// Create a function to calculate the total cost of an item
int calculate_cost(item item1) {
    return item1.price * item1.quantity;
}

// Create a function to print the bill
void print_bill(item items[], int num_items) {
    printf("------------------------------------------------\n");
    printf("Welcome to the C Cafe!\n");
    printf("------------------------------------------------\n");
    printf("Item\t\tPrice\t\tQuantity\t\tTotal Cost\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\n", items[i].name, items[i].price, items[i].quantity, calculate_cost(items[i]));
    }

    printf("------------------------------------------------\n");
    printf("Total Cost: $%d\n", calculate_total_cost(items, num_items));
    printf("------------------------------------------------\n");
    printf("Thank you for your visit to the C Cafe!\n");
    printf("------------------------------------------------\n");
}

// Calculate the total cost of all items
int calculate_total_cost(item items[], int num_items) {
    int total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        total_cost += calculate_cost(items[i]);
    }
    return total_cost;
}

int main() {
    // Create an array of items
    item items[] = {
        {"Coffee", 5, 2},
        {"Tea", 3, 1},
        {"Juice", 4, 3},
        {"Smoothie", 6, 0}
    };

    // Calculate the total cost of all items
    int total_cost = calculate_total_cost(items, 4);

    // Print the bill
    print_bill(items, 4);

    // Print the total cost
    printf("Total Cost: $%d\n", total_cost);

    return 0;
}