//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: careful
/*
 * C Cafe Billing System
 *
 * This program is an example of a simple cafe billing system written in C.
 * It allows customers to select their desired beverages and prints a receipt
 * with the total cost.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the different types of drinks
typedef enum {
    COFFEE,
    TEA,
    HOT_CHOCOLATE,
    COLD_CHOCOLATE
} DrinkType;

// Define the different drink prices
const float DRINK_PRICES[4] = {
    [COFFEE] = 3.00,
    [TEA] = 2.50,
    [HOT_CHOCOLATE] = 4.00,
    [COLD_CHOCOLATE] = 3.50
};

// Define the different drink sizes
typedef enum {
    SMALL,
    MEDIUM,
    LARGE
} DrinkSize;

// Define the structure for a drink
typedef struct {
    DrinkType type;
    DrinkSize size;
    int quantity;
} Drink;

// Define the structure for a receipt
typedef struct {
    Drink drink;
    float total_cost;
} Receipt;

// Print a receipt
void print_receipt(Receipt receipt) {
    printf("--- Receipt ---\n");
    printf("Drink: %s\n", DRINK_PRICES[receipt.drink.type]);
    printf("Size: %s\n", (receipt.drink.size == SMALL) ? "Small" : "Large");
    printf("Quantity: %d\n", receipt.drink.quantity);
    printf("Total cost: $%.2f\n", receipt.total_cost);
}

int main() {
    // Declare variables
    Drink drink;
    Receipt receipt;
    int quantity;

    // Get the drink type
    printf("Enter the type of drink (1=Coffee, 2=Tea, 3=Hot Chocolate, 4=Cold Chocolate): ");
    scanf("%d", &drink.type);

    // Get the drink size
    printf("Enter the size of the drink (1=Small, 2=Medium, 3=Large): ");
    scanf("%d", &drink.size);

    // Get the drink quantity
    printf("Enter the quantity of the drink: ");
    scanf("%d", &drink.quantity);

    // Calculate the total cost
    receipt.total_cost = DRINK_PRICES[drink.type] * drink.quantity;

    // Print the receipt
    print_receipt(receipt);

    return 0;
}