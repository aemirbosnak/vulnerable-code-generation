//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
/*
 * Digital Auction System Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int rand_between_1_and_100() {
    return rand() % 100 + 1;
}

// Function to display the current highest bidder and their bid amount
void display_bid(int bidder_id, int bid_amount) {
    printf("Current highest bidder: %d\n", bidder_id);
    printf("Current highest bid: %d\n", bid_amount);
}

int main() {
    // Initialize the bidding system
    int bidder_id = 0;
    int bid_amount = 0;
    int highest_bidder_id = 0;
    int highest_bid = 0;

    // Generate a random number between 1 and 100 for the starting bid
    int starting_bid = rand_between_1_and_100();

    // Display the starting bid
    printf("Starting bid: %d\n", starting_bid);

    // Loop until the bidding is complete
    while (bid_amount < starting_bid) {
        // Display the current highest bidder and their bid amount
        display_bid(highest_bidder_id, highest_bid);

        // Prompt the user for a bid
        printf("Enter your bid: ");
        scanf("%d", &bid_amount);

        // Check if the bid is higher than the current highest bid
        if (bid_amount > highest_bid) {
            // Update the highest bidder and their bid amount
            highest_bidder_id = bidder_id;
            highest_bid = bid_amount;
        }

        // Increment the bidder ID
        bidder_id++;
    }

    // Display the final bid and winner
    display_bid(highest_bidder_id, highest_bid);
    printf("Winner: %d\n", highest_bidder_id);

    return 0;
}