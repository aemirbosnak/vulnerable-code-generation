//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Define the number of items in the menu
#define NUM_ITEMS 5

// Define the structure for each item in the menu
typedef struct {
    char name[50];
    float price;
} Item;

// Define the structure for the order
typedef struct {
    int num_items;
    Item items[NUM_ITEMS];
} Order;

// Function to print the menu
void print_menu(Item menu[NUM_ITEMS]) {
    printf("MENU\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take the order
void take_order(Order* order) {
    printf("Enter the number of items you want to order: ");
    scanf("%d", &order->num_items);
    for (int i = 0; i < order->num_items; i++) {
        printf("Enter the name of the item: ");
        scanf("%s", order->items[i].name);
        printf("Enter the price of the item: ");
        scanf("%f", &order->items[i].price);
    }
}

// Function to calculate the total cost of the order
float calculate_total(Order order) {
    float total = 0;
    for (int i = 0; i < order.num_items; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to print the order
void print_order(Order order) {
    printf("ORDER\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total cost: $%.2f\n", calculate_total(order));
}

// Function to print the bill
void print_bill(float total) {
    printf("BILL\n");
    printf("Total cost: $%.2f\n", total);
}

int main() {
    Item menu[NUM_ITEMS] = {{"Coffee", 2.50}, {"Tea", 1.50}, {"Cake", 3.50}, {"Sandwich", 4.50}, {"Soda", 1.75}};
    Order order;
    take_order(&order);
    print_order(order);
    float total = calculate_total(order);
    print_bill(total);
    return 0;
}