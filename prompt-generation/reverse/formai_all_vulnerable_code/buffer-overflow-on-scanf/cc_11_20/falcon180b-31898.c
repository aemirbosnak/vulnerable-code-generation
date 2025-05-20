//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>

// Define the menu items and their prices
#define COFFEE 1
#define TEA 2
#define COKE 3
#define JUICE 4

#define COFFEE_PRICE 50
#define TEA_PRICE 30
#define COKE_PRICE 40
#define JUICE_PRICE 35

int main() {
    // Initialize variables
    int choice;
    int quantity;
    float total_price = 0.0;

    // Print the menu
    printf("Welcome to the Cafe!\n");
    printf("Please choose your order:\n");
    printf("1. Coffee - $0.50\n");
    printf("2. Tea - $0.30\n");
    printf("3. Coke - $0.40\n");
    printf("4. Juice - $0.35\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Get the quantity of the order
    printf("How many %s would you like to order? ", (choice == COFFEE)? "coffees" : (choice == TEA)? "teas" : (choice == COKE)? "cokes" : "juices");
    scanf("%d", &quantity);

    // Calculate the total price
    switch (choice) {
        case COFFEE:
            total_price = COFFEE_PRICE * quantity;
            break;
        case TEA:
            total_price = TEA_PRICE * quantity;
            break;
        case COKE:
            total_price = COKE_PRICE * quantity;
            break;
        case JUICE:
            total_price = JUICE_PRICE * quantity;
            break;
    }

    // Print the order and total price
    printf("\nYou ordered %d %s for a total price of $%.2f.\n", quantity, (choice == COFFEE)? "coffee" : (choice == TEA)? "tea" : (choice == COKE)? "coke" : "juice", total_price);

    return 0;
}