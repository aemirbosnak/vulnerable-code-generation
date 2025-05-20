//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the auction item structure
typedef struct {
    char name[50];
    int starting_bid;
    int current_bid;
    int highest_bidder;
} AuctionItem;

// Function to initialize the auction item
void init_auction_item(AuctionItem* item) {
    strcpy(item->name, "");
    item->starting_bid = 0;
    item->current_bid = 0;
    item->highest_bidder = 0;
}

// Function to display the auction item details
void display_auction_item(AuctionItem* item) {
    printf("Name: %s\n", item->name);
    printf("Starting Bid: $%d\n", item->starting_bid);
    printf("Current Bid: $%d\n", item->current_bid);
    printf("Highest Bidder: %d\n", item->highest_bidder);
}

// Function to place a bid on the auction item
void place_bid(AuctionItem* item, int bidder, int bid) {
    if (item->current_bid < item->starting_bid) {
        item->current_bid = item->starting_bid;
    } else if (bid > item->current_bid) {
        item->current_bid = bid;
        item->highest_bidder = bidder;
    }
}

// Function to start the auction
void start_auction(AuctionItem* item) {
    int i, max_bid = 0;
    char name[50];

    // Initialize the auction item
    init_auction_item(item);

    // Start the bidding
    for (i = 1; i <= 5; i++) {
        printf("Round %d:\n", i);
        printf("Enter your name: ");
        scanf("%s", name);
        printf("Enter your bid: ");
        scanf("%d", &item->current_bid);
        printf("Bid placed by %s: $%d\n\n", name, item->current_bid);

        if (item->current_bid > max_bid) {
            max_bid = item->current_bid;
        }
    }

    // Display the winner
    if (item->current_bid > 0) {
        printf("The auction item is sold to %d for $%d\n", item->highest_bidder, item->current_bid);
    } else {
        printf("The auction item is not sold.\n");
    }
}

// Function to run the digital auction system
void digital_auction_system() {
    AuctionItem item;
    int choice;

    // Initialize the auction item
    init_auction_item(&item);

    // Display the main menu
    printf("Digital Auction System\n");
    printf("1. Start Auction\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Start the auction
    if (choice == 1) {
        start_auction(&item);
    }

    // Exit the program
    printf("Exiting the program...\n");
}

// Main function
int main() {
    srand(time(NULL));
    digital_auction_system();
    return 0;
}