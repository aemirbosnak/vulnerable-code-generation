//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and prices
char menu[10][50] = {"Cafe Latte", "Cappuccino", "Espresso", "Americano", "Mocha", "Chai Latte", "Hot Chocolate", "Tea", "Scone", "Muffin"};
double prices[10] = {3.50, 3.75, 3.00, 3.25, 4.00, 3.75, 3.50, 2.50, 2.00, 2.50};

// Define the order structure
typedef struct order {
    char item[50];
    int quantity;
    double price;
} order;

// Define the bill structure
typedef struct bill {
    order orders[10];
    int num_orders;
    double total_price;
} bill;

// Function to create a new order
order* create_order(char* item, int quantity, double price) {
    order* new_order = malloc(sizeof(order));
    strcpy(new_order->item, item);
    new_order->quantity = quantity;
    new_order->price = price;
    return new_order;
}

// Function to add an order to a bill
void add_order_to_bill(bill* b, order* o) {
    b->orders[b->num_orders] = *o;
    b->num_orders++;
    b->total_price += o->price * o->quantity;
}

// Function to print a bill
void print_bill(bill* b) {
    printf("\n\nYour bill:\n");
    for (int i = 0; i < b->num_orders; i++) {
        printf("%d %s x %d = %.2f\n", i+1, b->orders[i].item, b->orders[i].quantity, b->orders[i].price * b->orders[i].quantity);
    }
    printf("Total: %.2f\n", b->total_price);
}

// Function to get the user's input
void get_user_input(bill* b) {
    char input[50];
    int quantity;
    double price;

    printf("Welcome to the cafe! What would you like to order?\n");
    while (1) {
        printf("Enter the item you want to order: ");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }

        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        // Find the price of the item
        for (int i = 0; i < 10; i++) {
            if (strcmp(input, menu[i]) == 0) {
                price = prices[i];
            }
        }

        // Create a new order and add it to the bill
        order* new_order = create_order(input, quantity, price);
        add_order_to_bill(b, new_order);
    }
}

// Main function
int main() {
    bill b;
    b.num_orders = 0;
    b.total_price = 0.0;

    get_user_input(&b);
    print_bill(&b);

    return 0;
}