//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>

#define MAX_ITEMS 5

// Menu items
const char* items[MAX_ITEMS] = {
    "1. Coffee ($2.50)",
    "2. Tea ($1.75)",
    "3. Sandwich ($5.00)",
    "4. Cake ($3.00)",
    "5. Juice ($2.00)"
};

// Prices of the menu items
const float prices[MAX_ITEMS] = {2.50, 1.75, 5.00, 3.00, 2.00};

// Function to display menu
void display_menu() {
    printf("\nWelcome to the Happy Cafe!\n");
    printf("Here are the delicious items we have for you:\n");
    for(int i = 0; i < MAX_ITEMS; i++) {
        printf("%s\n", items[i]);
    }
    printf("*********************************\n");
}

// Function to take the order
void take_order(int* order, int* quantity) {
    int item;
    do {
        printf("Please enter the item number you would like to order (1-%d or 0 to finish): ", MAX_ITEMS);
        scanf("%d", &item);
        
        if (item >= 1 && item <= MAX_ITEMS) {
            printf("How many would you like? ");
            scanf("%d", &quantity[item - 1]);
            order[item - 1] = item;
            printf("Great choice! You've selected item %d.\n", item);
        } else if (item != 0) {
            printf("Oops! Invalid item number. Please try again!\n");
        }
    } while (item != 0);
}

// Function to calculate total
float calculate_total(int* order, int* quantity) {
    float total = 0.0;
    printf("\nYour order:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (order[i] != 0) {
            float item_total = prices[i] * quantity[i];
            total += item_total;
            printf("%s x %d = $%.2f\n", items[i], quantity[i], item_total);
        }
    }
    return total;
}

// Function to print the receipt
void print_receipt(float total) {
    printf("*********************************\n");
    printf("Your total amount due: $%.2f\n", total);
    printf("Thank you for visiting Happy Cafe! Enjoy your meal!\n");
    printf("*********************************\n");
}

int main() {
    int order[MAX_ITEMS] = {0}; // Array to store ordered items
    int quantity[MAX_ITEMS] = {0}; // Quantity for each item

    display_menu();
    take_order(order, quantity);
    float total = calculate_total(order, quantity);
    
    if (total > 0) {
        print_receipt(total);
    } else {
        printf("You didn't order anything! Come back soon!\n");
    }

    return 0;
}