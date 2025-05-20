//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the menu items
#define ITEM_COFFEE 1
#define ITEM_TEA 2
#define ITEM_CAKE 3
#define ITEM_SANDWICH 4
#define ITEM_EXIT 5

// Define the prices of the menu items
#define PRICE_COFFEE 2.50
#define PRICE_TEA 2.00
#define PRICE_CAKE 3.00
#define PRICE_SANDWICH 4.00

// Function to display the menu
void display_menu() {
    printf("Welcome to the Cafe Billing System!\n");
    printf("---------------------------------\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $2.00\n");
    printf("3. Cake - $3.00\n");
    printf("4. Sandwich - $4.00\n");
    printf("5. Exit\n");
}

// Function to get the user's choice
int get_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to calculate the total bill
float calculate_bill(int items[], int quantities[]) {
    float total = 0.0;
    for (int i = 0; i < 5; i++) {
        total += items[i] * quantities[i];
    }
    return total;
}

// Function to print the receipt
void print_receipt(int items[], int quantities[], float total) {
    printf("---------------------------------\n");
    printf("Receipt\n");
    printf("---------------------------------\n");
    for (int i = 0; i < 5; i++) {
        if (items[i] > 0) {
            printf("%d x %s - $%.2f\n", quantities[i], (i == ITEM_COFFEE) ? "Coffee" : (i == ITEM_TEA) ? "Tea" : (i == ITEM_CAKE) ? "Cake" : (i == ITEM_SANDWICH) ? "Sandwich" : "", quantities[i] * ((i == ITEM_COFFEE) ? PRICE_COFFEE : (i == ITEM_TEA) ? PRICE_TEA : (i == ITEM_CAKE) ? PRICE_CAKE : (i == ITEM_SANDWICH) ? PRICE_SANDWICH : 0.0));
        }
    }
    printf("Total: $%.2f\n", total);
    printf("---------------------------------\n");
}

// Main function
int main() {
    // Initialize the variables
    int items[5] = {0};
    int quantities[5] = {0};
    float total = 0.0;

    // Display the menu
    display_menu();

    // Get the user's choice
    int choice = get_choice();

    // Loop until the user chooses to exit
    while (choice != ITEM_EXIT) {
        // Get the quantity of the item
        printf("Enter the quantity: ");
        int quantity;
        scanf("%d", &quantity);

        // Store the item and quantity in the arrays
        items[choice - 1] = choice;
        quantities[choice - 1] = quantity;

        // Display the menu again
        display_menu();

        // Get the user's choice
        choice = get_choice();
    }

    // Calculate the total bill
    total = calculate_bill(items, quantities);

    // Print the receipt
    print_receipt(items, quantities, total);

    return 0;
}