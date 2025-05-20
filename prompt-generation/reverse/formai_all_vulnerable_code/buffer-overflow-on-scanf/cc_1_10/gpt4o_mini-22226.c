//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 5

// Fun item names
const char *menu_items[MAX_ITEMS] = {
    "1. Coffee (5 beans)",
    "2. Tea (3 leaves)",
    "3. Pastry (2 crumbs)",
    "4. Sandwich (4 layers)",
    "5. Water (1 drop)"
};

// Fun prices
const float menu_prices[MAX_ITEMS] = {
    2.50, // Coffee
    1.75, // Tea
    3.00, // Pastry
    4.50, // Sandwich
    0.50  // Water
};

void display_menu() {
    printf("\nWelcome to the Silly Cafe!\n");
    printf("Here's our ridiculous menu:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%s - $%.2f\n", menu_items[i], menu_prices[i]);
    }
}

float calculate_bill(int ordered_items[]) {
    float total = 0.0;
    printf("\nHere's your order summary:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (ordered_items[i] > 0) {
            printf("%s x%d\n", menu_items[i], ordered_items[i]);
            total += ordered_items[i] * menu_prices[i];
        }
    }
    return total;
}

void take_order() {
    int ordered_items[MAX_ITEMS] = {0}; // Initialize order array to zero
    char choice[100];
    
    while (1) {
        printf("\nWhat would you like to order? (Type 'done' when finished)\n");
        display_menu();
        
        printf("Enter the item number (1-%d): ", MAX_ITEMS);
        scanf("%s", choice);

        if (strcmp(choice, "done") == 0) {
            break; // Exit the loop and finish ordering
        }

        int item_number = atoi(choice); // Convert string to int
        if (item_number >= 1 && item_number <= MAX_ITEMS) {
            ordered_items[item_number - 1]++; // Increment quantity for the ordered item
            printf("You ordered a %s!\n", menu_items[item_number - 1]);
        } else {
            printf("Oops! That's not a valid item. Try again, you'd know not to mess with the cafe's order system!\n");
        }
    }

    float total_cost = calculate_bill(ordered_items);
    printf("Your total bill is: $%.2f\n", total_cost);
    printf("Thank you for ordering from the Silly Cafe! Enjoy your food and do forget to leave us a tip or else...\n");
}

int main() {
    printf("Welcome to the Silly Cafe Billing System!\n");
    printf("We serve the best laughs along with food!\n");

    take_order();

    printf("Goodbye! Remember, calories don't count here!\n");
    return 0;
}