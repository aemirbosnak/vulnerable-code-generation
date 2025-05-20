//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the menu items
#define COFFEE 1
#define TEA 2
#define CAKE 3

// Define the prices
#define COFFEE_PRICE 1.99
#define TEA_PRICE 1.50
#define CAKE_PRICE 2.99

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the maximum number of characters in an item name
#define MAX_ITEM_NAME_LENGTH 20

// Define the data structure for an order item
typedef struct {
    int item_id;
    char item_name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    float price;
} order_item;

// Define the data structure for an order
typedef struct {
    int num_items;
    order_item items[MAX_ITEMS];
    float total_price;
} order;

// Function to print the menu
void print_menu() {
    printf("Welcome to the Cafe! Here's our menu:\n");
    printf("1. Coffee - $1.99\n");
    printf("2. Tea - $1.50\n");
    printf("3. Cake - $2.99\n");
}

// Function to get the user's order
void get_order(order *o) {
    int num_items;
    printf("How many items would you like to order? ");
    scanf("%d", &num_items);

    o->num_items = num_items;

    for (int i = 0; i < num_items; i++) {
        int item_id;
        printf("Enter the item ID of item %d: ", i + 1);
        scanf("%d", &item_id);

        char item_name[MAX_ITEM_NAME_LENGTH];
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", item_name);

        int quantity;
        printf("Enter the quantity of item %d: ", i + 1);
        scanf("%d", &quantity);

        float price;
        switch (item_id) {
            case COFFEE:
                price = COFFEE_PRICE;
                break;
            case TEA:
                price = TEA_PRICE;
                break;
            case CAKE:
                price = CAKE_PRICE;
                break;
            default:
                printf("Invalid item ID. Please enter a valid item ID.\n");
                i--;
                continue;
        }

        o->items[i].item_id = item_id;
        strcpy(o->items[i].item_name, item_name);
        o->items[i].quantity = quantity;
        o->items[i].price = price;
    }
}

// Function to calculate the total price of the order
void calculate_total_price(order *o) {
    o->total_price = 0;
    for (int i = 0; i < o->num_items; i++) {
        o->total_price += o->items[i].price * o->items[i].quantity;
    }
}

// Function to print the order
void print_order(order *o) {
    printf("Your order summary:\n");
    for (int i = 0; i < o->num_items; i++) {
        printf("%d %s x %d = $%.2f\n", o->items[i].item_id, o->items[i].item_name, o->items[i].quantity, o->items[i].price * o->items[i].quantity);
    }
    printf("Total price: $%.2f\n", o->total_price);
}

// Main function
int main() {
    // Print the menu
    print_menu();

    // Get the user's order
    order o;
    get_order(&o);

    // Calculate the total price of the order
    calculate_total_price(&o);

    // Print the order
    print_order(&o);

    return 0;
}