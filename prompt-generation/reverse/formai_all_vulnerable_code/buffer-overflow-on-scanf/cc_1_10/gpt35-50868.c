//FormAI DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000 // Maximum bidding amount
#define MIN_BID 100 // Minimum bidding amount
#define AUCTION_PERIOD 60 // Length of auction (in seconds)

int main()
{
    srand(time(NULL)); // Initialize the random generator

    int starting_bid = rand() % (MAX_BID - MIN_BID + 1) + MIN_BID; // Generate a random starting bid
    int current_bid = starting_bid; // Set the current bid to be the starting bid
    int highest_bidder_id = -1; // Initialize the highest bidder ID to -1 (no one has bid yet)
    int remaining_time = AUCTION_PERIOD; // Initialize the remaining time to the length of the auction

    printf("Welcome to the digital auction system!\n");
    printf("Starting bid: $%d\n", starting_bid);
    printf("Auction period: %d seconds\n", AUCTION_PERIOD);

    while (remaining_time > 0) {
        printf("\nTime remaining: %d seconds\n", remaining_time);
        printf("Current bid: $%d\n", current_bid);
        printf("Enter your bidder ID and bid amount: ");

        int bidder_id, bid_amount;
        scanf("%d %d", &bidder_id, &bid_amount);

        if (bid_amount > current_bid && bid_amount <= MAX_BID) {
            printf("Bid accepted.\n");
            highest_bidder_id = bidder_id;
            current_bid = bid_amount;
        } else if (bid_amount > MAX_BID) {
            printf("Bid amount exceeds maximum allowed.\n");
        } else {
            printf("Bid not accepted.\n");
        }

        remaining_time--;
    }

    printf("\nAuction over.\n\n");

    if (highest_bidder_id == -1) {
        printf("No bids were placed.\n");
    } else {
        printf("The winner is bidder %d with a bid of $%d.\n", highest_bidder_id, current_bid);
    }

    return 0;
}