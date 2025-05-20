//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store item details
typedef struct Item {
    int id;
    char name[50];
    float reserve_price;
    float current_bid;
    int highest_bidder_id;
    time_t end_time;
} Item;

// Structure to store bidder details
typedef struct Bidder {
    int id;
    char name[50];
    float balance;
} Bidder;

// Array to store items
Item items[100];

// Array to store bidders
Bidder bidders[100];

// Number of items
int num_items = 0;

// Number of bidders
int num_bidders = 0;

// Current time
time_t current_time;

// Function to add an item to the auction
void add_item(char *name, float reserve_price, time_t end_time) {
    // Check if the auction has started
    if (current_time > end_time) {
        printf("Error: Auction has already started.\n");
        return;
    }

    // Create a new item
    Item item;
    item.id = num_items++;
    strcpy(item.name, name);
    item.reserve_price = reserve_price;
    item.current_bid = 0;
    item.highest_bidder_id = -1;
    item.end_time = end_time;

    // Add the item to the array
    items[num_items - 1] = item;
}

// Function to add a bidder to the auction
void add_bidder(char *name, float balance) {
    // Create a new bidder
    Bidder bidder;
    bidder.id = num_bidders++;
    strcpy(bidder.name, name);
    bidder.balance = balance;

    // Add the bidder to the array
    bidders[num_bidders - 1] = bidder;
}

// Function to place a bid on an item
void place_bid(int item_id, int bidder_id, float bid_amount) {
    // Check if the auction has started
    if (current_time <= items[item_id].end_time) {
        printf("Error: Auction has not started yet.\n");
        return;
    }

    // Check if the auction has ended
    if (current_time > items[item_id].end_time) {
        printf("Error: Auction has already ended.\n");
        return;
    }

    // Check if the bid amount is valid
    if (bid_amount <= items[item_id].current_bid) {
        printf("Error: Bid amount must be greater than the current bid.\n");
        return;
    }

    // Check if the bidder has enough balance
    if (bid_amount > bidders[bidder_id].balance) {
        printf("Error: Bidder does not have enough balance.\n");
        return;
    }

    // Place the bid
    items[item_id].current_bid = bid_amount;
    items[item_id].highest_bidder_id = bidder_id;
    bidders[bidder_id].balance -= bid_amount;
}

// Function to end an auction
void end_auction(int item_id) {
    // Check if the auction has already ended
    if (current_time > items[item_id].end_time) {
        printf("Error: Auction has already ended.\n");
        return;
    }

    // End the auction
    items[item_id].end_time = current_time;

    // Print the winner
    if (items[item_id].current_bid >= items[item_id].reserve_price) {
        printf("Item %s sold to bidder %s for %.2f.\n", items[item_id].name, bidders[items[item_id].highest_bidder_id].name, items[item_id].current_bid);
    } else {
        printf("Item %s did not meet its reserve price.\n", items[item_id].name);
    }
}

// Main function
int main() {
    // Get the current time
    time(&current_time);

    // Add some items to the auction
    add_item("Painting", 1000, current_time + 3600);
    add_item("Sculpture", 2000, current_time + 7200);
    add_item("Vase", 500, current_time + 10800);

    // Add some bidders to the auction
    add_bidder("Alice", 1000);
    add_bidder("Bob", 2000);
    add_bidder("Carol", 3000);

    // Place some bids
    place_bid(0, 1, 1100);
    place_bid(0, 2, 1200);
    place_bid(1, 0, 2100);
    place_bid(1, 1, 2200);
    place_bid(2, 2, 550);
    place_bid(2, 0, 600);

    // End the auction
    end_auction(0);
    end_auction(1);
    end_auction(2);

    return 0;
}