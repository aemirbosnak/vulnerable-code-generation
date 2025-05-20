//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: retro
// Retro Cafe Billing System in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define menu items and prices
char menu[][50] = {
    "Coffee",
    "Tea",
    "Milk",
    "Cake",
    "Ice Cream"
};
float prices[] = {
    1.50,
    1.20,
    2.00,
    3.00,
    3.50
};

// Define struct for order
typedef struct {
    char name[50];
    int quantity;
    float total;
} order_t;

// Define struct for table
typedef struct {
    int number;
    order_t order;
} table_t;

// Function to calculate total price
float calculate_total(int quantity, float price) {
    return quantity * price;
}

// Function to display menu
void display_menu() {
    printf("Welcome to our cafe!\n");
    printf("Here is our menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i], prices[i]);
    }
}

// Function to place order
void place_order(table_t* table) {
    // Ask for order
    printf("What would you like to order?\n");
    printf("1. %s\n", menu[0]);
    printf("2. %s\n", menu[1]);
    printf("3. %s\n", menu[2]);
    printf("4. %s\n", menu[3]);
    printf("5. %s\n", menu[4]);
    printf("Choose a number: ");
    scanf("%d", &table->order.quantity);
    // Calculate total price
    table->order.total = calculate_total(table->order.quantity, prices[table->order.quantity - 1]);
    // Ask for name
    printf("What is your name?\n");
    scanf("%s", &table->order.name);
}

// Function to display order
void display_order(order_t order) {
    printf("Order: %s - %d x $%.2f = $%.2f\n", order.name, order.quantity, prices[order.quantity - 1], order.total);
}

// Function to display table number
void display_table_number(table_t table) {
    printf("Table %d: ", table.number);
    display_order(table.order);
}

// Function to display all orders
void display_all_orders(table_t* tables, int num_tables) {
    for (int i = 0; i < num_tables; i++) {
        display_table_number(tables[i]);
    }
}

int main() {
    // Define number of tables
    int num_tables = 5;
    // Create array of tables
    table_t tables[num_tables];
    // Initialize table numbers
    for (int i = 0; i < num_tables; i++) {
        tables[i].number = i + 1;
    }
    // Place orders
    for (int i = 0; i < num_tables; i++) {
        place_order(&tables[i]);
    }
    // Display all orders
    display_all_orders(tables, num_tables);
    return 0;
}