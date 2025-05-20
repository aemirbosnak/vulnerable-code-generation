//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
// Cafe Billing System

#include <stdio.h>

// Define structure for Cafe Menu Items
struct menu_item {
    char name[20];
    float price;
};

// Define array of menu items
struct menu_item menu[] = {
    { "Coffee", 1.50 },
    { "Tea", 1.00 },
    { "Cake", 3.00 },
    { "Sandwich", 2.50 },
    { "Salad", 4.00 },
    { "Water", 1.00 },
    { "Juice", 2.00 }
};

// Define structure for Cafe Order
struct order {
    int item_count;
    struct menu_item items[5];
    float total;
};

// Define function to print menu
void print_menu() {
    for (int i = 0; i < 6; i++) {
        printf("%s: $%.2f\n", menu[i].name, menu[i].price);
    }
}

// Define function to calculate total
float calculate_total(struct order *o) {
    float total = 0;
    for (int i = 0; i < o->item_count; i++) {
        total += o->items[i].price;
    }
    return total;
}

// Define function to print order
void print_order(struct order *o) {
    printf("Order:\n");
    for (int i = 0; i < o->item_count; i++) {
        printf("%s: $%.2f\n", o->items[i].name, o->items[i].price);
    }
    printf("Total: $%.2f\n", o->total);
}

// Define main function
int main() {
    // Create order
    struct order o;
    o.item_count = 0;
    o.total = 0;

    // Print menu
    print_menu();

    // Take order
    printf("Enter the number of items you want to order: ");
    scanf("%d", &o.item_count);
    for (int i = 0; i < o.item_count; i++) {
        printf("Enter the name of the item you want to order: ");
        scanf("%s", o.items[i].name);
        printf("Enter the price of the item you want to order: ");
        scanf("%f", &o.items[i].price);
    }

    // Calculate total
    o.total = calculate_total(&o);

    // Print order
    print_order(&o);

    return 0;
}