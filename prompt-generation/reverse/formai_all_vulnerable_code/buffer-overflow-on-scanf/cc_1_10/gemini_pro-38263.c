//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Item structure represents an item in the auction
typedef struct Item {
    int id;
    char *name;
    float reserve_price;
    float current_bid;
    bool is_sold;
} Item;

// Bid structure represents a bid on an item
typedef struct Bid {
    int item_id;
    float amount;
    char *bidder_name;
} Bid;

// Auction structure represents the entire auction system
typedef struct Auction {
    Item *items;
    int num_items;
    Bid *bids;
    int num_bids;
} Auction;

// Function to create a new auction
Auction *create_auction() {
    Auction *auction = malloc(sizeof(Auction));
    auction->items = NULL;
    auction->num_items = 0;
    auction->bids = NULL;
    auction->num_bids = 0;
    return auction;
}

// Function to add an item to the auction
void add_item(Auction *auction, Item *item) {
    auction->items = realloc(auction->items, sizeof(Item) * (auction->num_items + 1));
    auction->items[auction->num_items] = *item;
    auction->num_items++;
}

// Function to add a bid to the auction
void add_bid(Auction *auction, Bid *bid) {
    auction->bids = realloc(auction->bids, sizeof(Bid) * (auction->num_bids + 1));
    auction->bids[auction->num_bids] = *bid;
    auction->num_bids++;
}

// Function to print the auction details
void print_auction(Auction *auction) {
    printf("Auction Details:\n");
    printf("Number of Items: %d\n", auction->num_items);
    for (int i = 0; i < auction->num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", auction->items[i].name);
        printf("Reserve Price: %f\n", auction->items[i].reserve_price);
        if (auction->items[i].is_sold) {
            printf("Status: Sold\n");
        } else {
            printf("Status: Available\n");
        }
        printf("\n");
    }
    printf("Number of Bids: %d\n", auction->num_bids);
    for (int i = 0; i < auction->num_bids; i++) {
        printf("Bid %d:\n", i + 1);
        printf("Item ID: %d\n", auction->bids[i].item_id);
        printf("Amount: %f\n", auction->bids[i].amount);
        printf("Bidder Name: %s\n", auction->bids[i].bidder_name);
        printf("\n");
    }
}

// Function to start the auction
void start_auction(Auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        Item *item = &auction->items[i];
        printf("Item %d: %s\n", item->id, item->name);
        printf("Reserve Price: %f\n", item->reserve_price);
        printf("Current Bid: %f\n", item->current_bid);
        printf("Enter a bid amount (0 to skip): ");
        float bid_amount;
        scanf("%f", &bid_amount);
        if (bid_amount > 0) {
            Bid bid;
            bid.item_id = item->id;
            bid.amount = bid_amount;
            printf("Enter your name: ");
            char bidder_name[256];
            scanf("%s", bidder_name);
            bid.bidder_name = malloc(strlen(bidder_name) + 1);
            strcpy(bid.bidder_name, bidder_name);
            add_bid(auction, &bid);
            item->current_bid = bid_amount;
        }
    }
}

// Function to end the auction
void end_auction(Auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        Item *item = &auction->items[i];
        if (item->current_bid >= item->reserve_price) {
            item->is_sold = true;
        }
    }
}

// Function to print the results of the auction
void print_results(Auction *auction) {
    printf("Auction Results:\n");
    for (int i = 0; i < auction->num_items; i++) {
        Item *item = &auction->items[i];
        if (item->is_sold) {
            printf("Item %d: %s\n", item->id, item->name);
            printf("Winning Bid: %f\n", item->current_bid);
            printf("Winning Bidder: %s\n", auction->bids[i].bidder_name);
            printf("\n");
        }
    }
}

// Main function
int main() {
    Auction *auction = create_auction();

    // Add some items to the auction
    Item item1 = {1, "Painting", 100.0, 0.0, false};
    Item item2 = {2, "Sculpture", 200.0, 0.0, false};
    Item item3 = {3, "Vase", 50.0, 0.0, false};
    add_item(auction, &item1);
    add_item(auction, &item2);
    add_item(auction, &item3);

    // Start the auction
    start_auction(auction);

    // End the auction
    end_auction(auction);

    // Print the results of the auction
    print_results(auction);

    return 0;
}