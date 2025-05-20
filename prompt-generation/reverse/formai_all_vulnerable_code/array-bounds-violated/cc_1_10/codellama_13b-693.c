//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
/*
 * A C Cafe Billing System in the style of Sherlock Holmes
 *
 * This program will simulate a billing system for a coffee shop,
 * where the user will be asked to enter the items they wish to order
 * and the system will calculate the total cost.
 *
 * The program will be designed in the style of Sherlock Holmes,
 * with a focus on using deductive reasoning to solve problems.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the items available for purchase
#define COFFEE 1
#define ESPRESSO 2
#define LATTE 3
#define CAPPUCCINO 4
#define MUFFIN 5
#define DONUT 6
#define BAGEL 7
#define MORNING_BREW 8

// Define the prices for each item
int prices[] = {
    25, // COFFEE
    35, // ESPRESSO
    50, // LATTE
    65, // CAPPUCCINO
    10, // MUFFIN
    15, // DONUT
    10, // BAGEL
    50  // MORNING_BREW
};

// Define the total number of items available for purchase
#define NUM_ITEMS 8

// Define the maximum number of items a customer can order
#define MAX_ORDER_SIZE 5

// Define the maximum total cost a customer can spend
#define MAX_TOTAL_COST 100

// Define the welcome message
const char *WELCOME_MSG = "Welcome to the Coffee Cafe! What would you like to order today?\n";

// Define the prompt for the user to enter their order
const char *PROMPT_MSG = "Enter the number of each item you would like to order, separated by spaces: ";

// Define the message for the total cost
const char *TOTAL_COST_MSG = "The total cost of your order is: ";

// Define the message for the order confirmation
const char *ORDER_CONFIRM_MSG = "Thank you for your order! Please pay the total of: ";

// Define the message for the order rejection
const char *ORDER_REJECT_MSG = "Sorry, your order has been rejected. Please try again.";

// Define the message for the order completion
const char *ORDER_COMPLETE_MSG = "Thank you for choosing the Coffee Cafe! Enjoy your beverage!";

// Define the function to calculate the total cost of an order
int calculate_total_cost(int *items, int num_items) {
    int total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        total_cost += prices[items[i] - 1];
    }
    return total_cost;
}

// Define the function to check if an order is valid
int is_valid_order(int *items, int num_items) {
    // Check if the number of items is valid
    if (num_items > MAX_ORDER_SIZE) {
        return 0;
    }

    // Check if the total cost is valid
    int total_cost = calculate_total_cost(items, num_items);
    if (total_cost > MAX_TOTAL_COST) {
        return 0;
    }

    // Check if the items are valid
    for (int i = 0; i < num_items; i++) {
        if (items[i] < 1 || items[i] > NUM_ITEMS) {
            return 0;
        }
    }

    return 1;
}

// Define the function to display the order confirmation
void display_order_confirmation(int *items, int num_items) {
    int total_cost = calculate_total_cost(items, num_items);
    printf(ORDER_CONFIRM_MSG);
    printf("%d\n", total_cost);
}

// Define the function to display the order rejection
void display_order_rejection() {
    printf(ORDER_REJECT_MSG);
}

// Define the function to display the order completion
void display_order_completion() {
    printf(ORDER_COMPLETE_MSG);
}

// Define the main function
int main() {
    // Initialize the items for the order
    int items[MAX_ORDER_SIZE];
    int num_items = 0;

    // Display the welcome message
    printf(WELCOME_MSG);

    // Prompt the user to enter their order
    printf(PROMPT_MSG);

    // Read the user's order
    char input[256];
    fgets(input, 256, stdin);

    // Parse the user's order
    char *token = strtok(input, " ");
    while (token != NULL) {
        items[num_items++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Check if the order is valid
    if (is_valid_order(items, num_items)) {
        // Display the order confirmation
        display_order_confirmation(items, num_items);

        // Display the order completion
        display_order_completion();
    } else {
        // Display the order rejection
        display_order_rejection();
    }

    return 0;
}