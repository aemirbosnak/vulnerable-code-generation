//FormAI DATASET v1.0 Category: Digital Auction System ; Style: statistical
/*
 * This program simulates a digital auction system where bidders can participate and bid on items.
 * The program generates a random item and starts the auction. Each bidder is assigned a random budget 
 * and can make bids on the item until the auction ends.
 * At the end of the auction, the winner is determined based on the highest bid.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BIDDERS 5 // number of bidders participating in the auction
#define MAX_BUDGET 1000 // maximum budget for each bidder
#define AUCTION_LENGTH 30 // length of the auction in seconds

int main(void) {
    srand(time(NULL)); // seed the random number generator

    // Generate a random item
    char *items[] = {"Smartphone", "Laptop", "Camera", "TV", "Headphones", "Tablet", "Smartwatch"};
    int num_items = sizeof(items) / sizeof(char*);
    int random_item_index = rand() % num_items;
    char *random_item = items[random_item_index];

    // Print the item that is being auctioned
    printf("Item: %s\n", random_item);

    // Initialize bid data for each bidder
    int bids[NUM_BIDDERS] = {0};
    int budgets[NUM_BIDDERS] = {0};
    int bidder_ids[NUM_BIDDERS] = {0};
    for (int i = 0; i < NUM_BIDDERS; i++) {
        int random_budget = rand() % MAX_BUDGET + 1;
        budgets[i] = random_budget;
        bidder_ids[i] = i + 1;
    }

    // Start the auction
    for (int i = 0; i < AUCTION_LENGTH; i++) {
        printf("Time left: %d seconds\n", AUCTION_LENGTH - i);

        // Allow each bidder to make a bid
        for (int j = 0; j < NUM_BIDDERS; j++) {
            int random_bid = rand() % budgets[j] + 1;
            bids[j] += random_bid;
            budgets[j] -= random_bid;
            printf("Bidder %d bid %d. Budget remaining: %d\n", bidder_ids[j], bids[j], budgets[j]);
        }
        printf("\n");
    }

    // Determine the winner
    int max_bid = -1;
    int winner_id = -1;
    for (int i = 0; i < NUM_BIDDERS; i++) {
        if (bids[i] > max_bid) {
            max_bid = bids[i];
            winner_id = bidder_ids[i];
        }
    }

    // Print the winner and their bid
    printf("Auction Ended.\n");
    printf("Highest Bidder: %d\n", winner_id);
    printf("Winning Bid: $%d\n", max_bid);

    return 0; 
}