//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum bid amount
#define MAX_BID_AMOUNT 1000

struct Bid
{
    int bid_amount;
    char bidder_name[50];
};

// Function to simulate the bidding process
void bidding_process()
{
    struct Bid current_bid;
    struct Bid highest_bid;
    int bid_amount;

    // Initialize highest_bid and current_bid
    highest_bid.bid_amount = 0;
    highest_bid.bidder_name[0] = '\0';

    printf("Welcome to the digital auction system!\n");
    printf("The current item is up for auction.\n");

    while (1)
    {
        printf("Enter your bid amount: ");
        scanf("%d", &bid_amount);

        // Check if the bid amount is within the maximum bid amount
        if (bid_amount > MAX_BID_AMOUNT || bid_amount < 0)
        {
            printf("Invalid bid amount. Please enter a value between 0 and %d.\n", MAX_BID_AMOUNT);
            continue;
        }

        // Check if the bid is higher than the current highest bid
        if (bid_amount > highest_bid.bid_amount)
        {
            highest_bid.bid_amount = bid_amount;

            // Copy the bidder's name into highest_bid.bidder_name
            printf("Enter your name: ");
            fgets(highest_bid.bidder_name, sizeof(highest_bid.bidder_name), stdin);
        }

        // Print the current highest bid
        printf("Current highest bid: $%d by %s\n", highest_bid.bid_amount, highest_bid.bidder_name);

        // Check if all bids have been made
        if (strcmp(highest_bid.bidder_name, "end") == 0)
        {
            break;
        }

        // Reset current_bid
        current_bid.bid_amount = 0;
        current_bid.bidder_name[0] = '\0';
    }

    // Print the winner and their bid amount
    printf("Congratulations, %s! You won the auction with a bid of $%d.\n", highest_bid.bidder_name, highest_bid.bid_amount);
}

// Main function
int main()
{
    srand(time(NULL));

    // Simulate the bidding process
    bidding_process();

    return 0;
}