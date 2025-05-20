//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 10

// Define the structure of an item
typedef struct {
    char name[50];
    float starting_price;
    float current_bid;
    char owner[50];
} item;

// Define the structure of the auction
typedef struct {
    item items[MAX_ITEMS];
    int num_items;
    int current_item;
} auction;

// Create a new auction
auction* create_auction() {
    auction* new_auction = malloc(sizeof(auction));
    new_auction->num_items = 0;
    new_auction->current_item = -1;
    return new_auction;
}

// Add an item to the auction
void add_item(auction* auction, item* item) {
    if (auction->num_items < MAX_ITEMS) {
        auction->items[auction->num_items++] = *item;
    } else {
        printf("Error: The auction is full.\n");
    }
}

// Start the auction
void start_auction(auction* auction) {
    auction->current_item = 0;
    while (auction->current_item < auction->num_items) {
        item* current_item = &auction->items[auction->current_item];
        printf("Current item: %s\n", current_item->name);
        printf("Starting price: %.2f\n", current_item->starting_price);
        printf("Current bid: %.2f\n", current_item->current_bid);
        printf("Owner: %s\n", current_item->owner);
        printf("\n");

        // Get the next bid
        float next_bid;
        printf("Enter your bid: ");
        scanf("%f", &next_bid);

        // Check if the bid is valid
        if (next_bid >= current_item->current_bid) {
            current_item->current_bid = next_bid;

            // Update the owner of the item
            strcpy(current_item->owner, "Current bidder");
        } else {
            printf("Error: Invalid bid.\n");
        }

        auction->current_item++;
    }
}

// End the auction
void end_auction(auction* auction) {
    printf("The auction has ended.\n");
    for (int i = 0; i < auction->num_items; i++) {
        item* item = &auction->items[i];
        printf("%s sold for %.2f to %s.\n", item->name, item->current_bid, item->owner);
    }
}

// Free the memory allocated for the auction
void free_auction(auction* auction) {
    free(auction);
}

// Main function
int main() {
    // Create a new auction
    auction* auction = create_auction();

    // Add some items to the auction
    item item1 = {"iPhone 13", 1000.00, 1000.00, "Apple"};
    item item2 = {"Samsung Galaxy S22", 800.00, 800.00, "Samsung"};
    item item3 = {"Google Pixel 6", 600.00, 600.00, "Google"};
    add_item(auction, &item1);
    add_item(auction, &item2);
    add_item(auction, &item3);

    // Start the auction
    start_auction(auction);

    // End the auction
    end_auction(auction);

    // Free the memory allocated for the auction
    free_auction(auction);

    return 0;
}