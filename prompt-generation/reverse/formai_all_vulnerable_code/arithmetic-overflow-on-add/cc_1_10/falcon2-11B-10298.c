//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>

// Global variables
int current_bid = 0;
int highest_bid = 0;
int bidder_id = 0;
int auction_start_time = 0;
int auction_end_time = 0;
char auction_item[100];

// Function prototypes
void print_bid(int bid_id, int bid_value);
void increment_bid(int bid_id, int bid_value);
void decrement_bid(int bid_id, int bid_value);
void display_auction_info();
void start_auction();
void end_auction();
void process_bid();

// Main program
int main() {
    // Initialize global variables
    auction_start_time = time(NULL);
    auction_end_time = auction_start_time + 60; // Auction ends after 60 seconds

    // Print initial auction information
    printf("Welcome to the Digital Auction System!\n");
    printf("Current bid: %d\n", current_bid);
    printf("Highest bid: %d\n", highest_bid);
    printf("Bidder ID: %d\n", bidder_id);
    printf("Auction item: %s\n", auction_item);

    // Start the auction
    start_auction();

    // End the auction after 60 seconds
    while (time(NULL) <= auction_end_time) {
        // Process bid
        process_bid();
    }

    // End the auction
    end_auction();

    return 0;
}

// Function to print bid information
void print_bid(int bid_id, int bid_value) {
    printf("Bid ID: %d\n", bid_id);
    printf("Bid value: %d\n", bid_value);
}

// Function to increment bid
void increment_bid(int bid_id, int bid_value) {
    if (bid_id == bidder_id) {
        current_bid += bid_value;
        printf("You have successfully increased your bid to %d.\n", current_bid);
    } else {
        printf("Invalid bid ID.\n");
    }
}

// Function to decrement bid
void decrement_bid(int bid_id, int bid_value) {
    if (bid_id == bidder_id) {
        current_bid -= bid_value;
        printf("You have successfully decreased your bid to %d.\n", current_bid);
    } else {
        printf("Invalid bid ID.\n");
    }
}

// Function to display auction information
void display_auction_info() {
    printf("Current bid: %d\n", current_bid);
    printf("Highest bid: %d\n", highest_bid);
    printf("Bidder ID: %d\n", bidder_id);
    printf("Auction item: %s\n", auction_item);
}

// Function to start the auction
void start_auction() {
    printf("The auction has started.\n");
}

// Function to end the auction
void end_auction() {
    printf("The auction has ended.\n");
}

// Function to process bid
void process_bid() {
    int bid_value;
    printf("Enter bid value: ");
    scanf("%d", &bid_value);

    int bid_id;
    printf("Enter bid ID: ");
    scanf("%d", &bid_id);

    if (bid_id!= 0) {
        if (bid_id == bidder_id) {
            increment_bid(bid_id, bid_value);
        } else {
            decrement_bid(bid_id, bid_value);
        }
    } else {
        printf("Invalid bid ID.\n");
    }
}