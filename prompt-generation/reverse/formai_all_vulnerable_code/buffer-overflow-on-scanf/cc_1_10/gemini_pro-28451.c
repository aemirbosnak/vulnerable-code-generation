//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bidder struct
typedef struct bidder {
    int id;
    char name[50];
    int bid;
} Bidder;

// Item struct
typedef struct item {
    int id;
    char name[50];
    float reserve_price;
    Bidder highest_bidder;
} Item;

// Auction struct
typedef struct auction {
    Item items[100];
    int num_items;
    int num_bidders;
    Bidder bidders[100];
} Auction;

// Create a new auction
Auction* create_auction() {
    Auction* auction = (Auction*)malloc(sizeof(Auction));
    auction->num_items = 0;
    auction->num_bidders = 0;
    return auction;
}

// Add an item to the auction
void add_item(Auction* auction, Item item) {
    auction->items[auction->num_items] = item;
    auction->num_items++;
}

// Add a bidder to the auction
void add_bidder(Auction* auction, Bidder bidder) {
    auction->bidders[auction->num_bidders] = bidder;
    auction->num_bidders++;
}

// Start the auction
void start_auction(Auction* auction) {
    printf("Welcome to the auction!\n");

    // Loop through each item
    for (int i = 0; i < auction->num_items; i++) {
        Item item = auction->items[i];

        // Print item details
        printf("Item %d: %s\n", item.id, item.name);
        printf("Reserve price: $%.2f\n", item.reserve_price);

        // Loop through each bidder
        for (int j = 0; j < auction->num_bidders; j++) {
            Bidder bidder = auction->bidders[j];

            // Get bidder's bid
            printf("Enter bid for %s (bidder %d): ", item.name, bidder.id);
            scanf("%d", &bidder.bid);

            // Check if bid is valid
            if (bidder.bid < item.reserve_price) {
                printf("Bid is too low! Please enter a higher bid.\n");
            } else {
                // Update highest bidder
                item.highest_bidder = bidder;
            }
        }

        // Print highest bid
        printf("Highest bid for %s: $%d (by bidder %d)\n", item.name, item.highest_bidder.bid, item.highest_bidder.id);
    }
}

// End the auction
void end_auction(Auction* auction) {
    printf("Thank you for participating in the auction!\n");

    // Loop through each item
    for (int i = 0; i < auction->num_items; i++) {
        Item item = auction->items[i];

        // Check if item sold
        if (item.highest_bidder.bid >= item.reserve_price) {
            printf("Item %d (%s) sold to bidder %d for $%d\n", item.id, item.name, item.highest_bidder.id, item.highest_bidder.bid);
        } else {
            printf("Item %d (%s) did not sell.\n", item.id, item.name);
        }
    }
}

// Main function
int main() {
    // Create a new auction
    Auction* auction = create_auction();

    // Add some items to the auction
    Item item1 = {1, "Painting", 100.0, {0, "", 0}};
    Item item2 = {2, "Sculpture", 200.0, {0, "", 0}};
    Item item3 = {3, "Vase", 50.0, {0, "", 0}};
    add_item(auction, item1);
    add_item(auction, item2);
    add_item(auction, item3);

    // Add some bidders to the auction
    Bidder bidder1 = {1, "John Doe", 0};
    Bidder bidder2 = {2, "Jane Smith", 0};
    Bidder bidder3 = {3, "Bob Johnson", 0};
    add_bidder(auction, bidder1);
    add_bidder(auction, bidder2);
    add_bidder(auction, bidder3);

    // Start the auction
    start_auction(auction);

    // End the auction
    end_auction(auction);

    return 0;
}