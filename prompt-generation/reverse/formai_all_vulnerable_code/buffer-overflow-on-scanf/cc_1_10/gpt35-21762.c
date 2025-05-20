//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20 // Maximum number of items on menu
#define MAX_NAME 20 // Maximum length of item name

// Structure to hold menu items
struct MenuItem {
    char name[MAX_NAME];
    float price;
};

// Function to print menu items
void print_menu(struct MenuItem items[], int num_items) {
    printf("Menu:\n");
    printf("------------------------------\n");
    printf("| %-20s | %-10s |\n", "Item", "Price");
    printf("------------------------------\n");
    for(int i = 0; i < num_items; i++) {
        printf("| %-20s | $%-9.2f |\n", items[i].name, items[i].price);
    }
    printf("------------------------------\n");
}

// Function to calculate total price of order
float calculate_total(struct MenuItem items[], int quantities[], int num_items) {
    float total = 0;
    for(int i = 0; i < num_items; i++) {
        total += items[i].price * quantities[i];
    }
    return total;
}

int main() {
    // Create menu items
    struct MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50},
        {"Tea", 2.00},
        {"Espresso", 3.00},
        {"Latte", 3.50},
        {"Cappuccino", 3.50},
        {"Muffin", 2.00},
        {"Bagel", 2.50},
        {"Croissant", 2.75},
        {"Sandwich", 5.00},
        {"Salad", 6.00},
        {"Soup", 4.00},
        {"Cookie", 1.50},
        {"Brownie", 2.00},
        {"Cake", 3.50},
        {"Pie", 4.00},
        {"Scone", 2.25},
        {"Fruit Cup", 3.00},
        {"Yogurt Parfait", 3.50},
        {"Smoothie", 5.00},
        {"Iced Coffee", 3.00}
    };

    // Initialize quantities array to 0
    int quantities[MAX_ITEMS] = {0};

    printf("Welcome to the C Cafe!\n");

    while(1) {
        // Print menu and prompt for order
        print_menu(menu, MAX_ITEMS);
        printf("Enter the number of the item you would like to order or enter 0 to finish: ");
        int item_num;
        scanf("%d", &item_num);

        // Handle exit case
        if(item_num == 0) {
            printf("Your order is complete!\n");
            break;
        }

        // Handle invalid input
        if(item_num > MAX_ITEMS || item_num < 1) {
            printf("Invalid item number! Please enter a number between 1 and %d.\n", MAX_ITEMS);
            continue;
        }

        // Prompt for quantity
        printf("Enter the quantity: ");
        int quantity;
        scanf("%d", &quantity);

        // Add to quantities array
        quantities[item_num - 1] += quantity;

        printf("%d %s added to your order.\n\n", quantity, menu[item_num - 1].name);
    }

    // Print receipt with total
    printf("\nReceipt:\n");
    printf("------------------------------\n");
    printf("| %-20s | %-10s |\n", "Item", "Qty");
    printf("------------------------------\n");
    for(int i = 0; i < MAX_ITEMS; i++) {
        if(quantities[i] > 0) {
            printf("| %-20s | %-10d |\n", menu[i].name, quantities[i]);
        }
    }
    printf("------------------------------\n");
    printf("Total: $%.2f\n", calculate_total(menu, quantities, MAX_ITEMS));

    return 0;
}