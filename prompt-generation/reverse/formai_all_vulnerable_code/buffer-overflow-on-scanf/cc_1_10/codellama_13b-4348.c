//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
// Cafe Billing System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    int item_id;
    char item_name[50];
    int quantity;
    float price;
} item;

typedef struct {
    int table_number;
    item items[10];
    int num_items;
    float total_bill;
} order;

// Functions
void print_menu();
void place_order(order *o);
void print_order(order o);
void calculate_bill(order *o);

// Main Function
int main() {
    order o;
    int choice;
    char continue_order = 'y';

    // Print the menu
    print_menu();

    // Take order
    while (continue_order == 'y') {
        place_order(&o);
        print_order(o);
        calculate_bill(&o);

        // Ask for another order
        printf("Would you like to place another order? (y/n) ");
        scanf("%c", &continue_order);
    }

    return 0;
}

// Function Definitions
void print_menu() {
    printf("----------------------------------\n");
    printf("Coffee Menu\n");
    printf("----------------------------------\n");
    printf("1. Latte - $3.00\n");
    printf("2. Cappuccino - $4.00\n");
    printf("3. Mocha - $5.00\n");
    printf("----------------------------------\n");
    printf("Other Menu\n");
    printf("----------------------------------\n");
    printf("4. Sandwich - $7.00\n");
    printf("5. Salad - $8.00\n");
    printf("6. Soup - $6.00\n");
    printf("----------------------------------\n");
}

void place_order(order *o) {
    int i, item_id;
    char item_name[50];
    int quantity;

    // Take order
    printf("Enter table number: ");
    scanf("%d", &o->table_number);
    printf("Enter number of items: ");
    scanf("%d", &o->num_items);

    // Take order details
    for (i = 0; i < o->num_items; i++) {
        printf("Enter item id: ");
        scanf("%d", &item_id);
        printf("Enter item name: ");
        scanf("%s", item_name);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        o->items[i].item_id = item_id;
        strcpy(o->items[i].item_name, item_name);
        o->items[i].quantity = quantity;
    }
}

void print_order(order o) {
    int i;
    printf("Table Number: %d\n", o.table_number);
    printf("Number of Items: %d\n", o.num_items);
    for (i = 0; i < o.num_items; i++) {
        printf("Item %d: %s (%d)\n", i + 1, o.items[i].item_name, o.items[i].quantity);
    }
    printf("Total Bill: %f\n", o.total_bill);
}

void calculate_bill(order *o) {
    int i;
    float total_bill = 0;

    // Calculate total bill
    for (i = 0; i < o->num_items; i++) {
        total_bill += o->items[i].quantity * o->items[i].price;
    }
    o->total_bill = total_bill;
}