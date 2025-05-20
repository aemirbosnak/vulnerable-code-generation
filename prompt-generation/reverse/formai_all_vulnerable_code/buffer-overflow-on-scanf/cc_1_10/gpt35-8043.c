//FormAI DATASET v1.0 Category: Digital Auction System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate random price bids for items
int generate_bid() {
    return rand() % 1000 + 100;
}

int main() {
    // Set up initial variables
    int num_items, num_bids;
    char item_name[20];
    time_t t;

    // Seed the random number generator
    srand((unsigned) time(&t));

    // Welcome message
    printf("Welcome to the Cheery Auction System!\n");

    // Get number of items to auction
    printf("How many items would you like to auction? ");
    scanf("%d", &num_items);

    // Create arrays to hold item information
    char item_names[num_items][20];
    int item_prices[num_items];

    // Loop through each item and get its name
    for (int i = 0; i < num_items; i++) {
        printf("What is the name of item #%d? ", i+1);
        scanf("%s", item_names[i]);
    }

    // Loop through each item and generate a starting bid
    for (int i = 0; i < num_items; i++) {
        item_prices[i] = generate_bid();
        printf("The starting bid for %s is $%d.\n", item_names[i], item_prices[i]);
    }

    // Get number of bids to make for each item
    printf("How many bids would you like to make for each item? ");
    scanf("%d", &num_bids);

    // Loop through each bid and randomly increase the price of each item
    for (int i = 0; i < num_bids; i++) {
        for (int j = 0; j < num_items; j++) {
            item_prices[j] += generate_bid();
            printf("The price of %s is now $%d.\n", item_names[j], item_prices[j]);
        }
    }

    // Display final prices for all items
    printf("\nFinal Item Prices:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: $%d\n", item_names[i], item_prices[i]);
    }

    printf("\nThank you for using the Cheery Auction System!");

    return 0;
}