//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items
#define ALE   1
#define WINE  2
#define MEAD  3
#define FOOD  4

// Define the prices of the menu items
#define ALE_PRICE   2
#define WINE_PRICE  4
#define MEAD_PRICE  6
#define FOOD_PRICE  8

// Define the maximum number of items that can be ordered
#define MAX_ITEMS  10

// Declare the global variables
int num_items = 0;
float total_price = 0.0;

// Function to add an item to the order
void add_item(int item) {
    if (num_items < MAX_ITEMS) {
        switch (item) {
            case ALE:
                total_price += ALE_PRICE;
                break;
            case WINE:
                total_price += WINE_PRICE;
                break;
            case MEAD:
                total_price += MEAD_PRICE;
                break;
            case FOOD:
                total_price += FOOD_PRICE;
                break;
        }
        num_items++;
    } else {
        printf("Sorry, you cannot order more than %d items.\n", MAX_ITEMS);
    }
}

// Function to print the order
void print_order() {
    printf("Your order:\n");
    printf("  %d ale(s) @ %d silver each\n", num_items, ALE_PRICE);
    printf("  %d wine(s) @ %d silver each\n", num_items, WINE_PRICE);
    printf("  %d mead(s) @ %d silver each\n", num_items, MEAD_PRICE);
    printf("  %d food item(s) @ %d silver each\n", num_items, FOOD_PRICE);
    printf("Total: %0.2f silver\n", total_price);
}

// Function to take the order
void take_order() {
    int item;
    int res;

    do {
        printf("What wouldst thou like to order? (1 for ale, 2 for wine, 3 for mead, 4 for food, 0 to finish)\n");
        res = scanf("%d", &item);
        if (res == 1) {
            add_item(item);
        } else {
            printf("Invalid input. Please enter a number between 0 and 4.\n");
        }
    } while (item != 0);
}

// Function to main
int main() {
    take_order();
    print_order();
    return 0;
}