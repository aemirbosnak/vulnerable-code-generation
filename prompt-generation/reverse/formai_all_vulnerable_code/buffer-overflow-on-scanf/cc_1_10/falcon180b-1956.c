//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define the structure of an item to be auctioned
typedef struct {
    char name[50];
    int starting_price;
    int current_price;
} item;

// Function to initialize an item with default values
void init_item(item* i) {
    strcpy(i->name, "No Name");
    i->starting_price = 0;
    i->current_price = 0;
}

// Function to print an item's details
void print_item(item i) {
    printf("Name: %s\nStarting Price: $%d\nCurrent Price: $%d\n", i.name, i.starting_price, i.current_price);
}

// Function to update an item's price based on bids received
void update_price(item* i, int bid) {
    if (bid >= i->current_price) {
        i->current_price = bid;
    }
}

// Function to place a bid on an item
void place_bid(item* i, int bid) {
    if (bid > i->current_price) {
        update_price(i, bid);
        printf("Bid placed successfully!\n");
    } else {
        printf("Bid not high enough.\n");
    }
}

// Function to start an auction for an item
void start_auction(item i) {
    int bid;
    printf("Auction started for %s with a starting price of $%d.\n", i.name, i.starting_price);
    while (1) {
        printf("Enter your bid (0 to stop): ");
        scanf("%d", &bid);
        if (bid == 0) {
            break;
        }
        place_bid(&i, bid);
        print_item(i);
    }
}

int main() {
    // Initialize items to be auctioned
    item item1, item2, item3;
    init_item(&item1);
    init_item(&item2);
    init_item(&item3);
    
    // Set starting prices for items
    item1.starting_price = 100;
    item2.starting_price = 200;
    item3.starting_price = 300;
    
    // Start auctions for each item
    start_auction(item1);
    start_auction(item2);
    start_auction(item3);
    
    return 0;
}