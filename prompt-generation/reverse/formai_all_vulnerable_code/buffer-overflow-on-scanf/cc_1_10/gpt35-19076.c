//FormAI DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // to generate random numbers

    int max_bidder_id = 0, max_bidder_bid = 0; // variables to store the max bidder details
    int min_bidder_id = 0, min_bidder_bid = 0; // variables to store the min bidder details
    int num_bidders = 0, bid_amount = 0, bidder_id = 0; // variables to get input from user
    int total_bids = 0, total_amount = 0, average_bid = 0; // variables to calculate statistics

    printf("Welcome to the Digital Auction System!\n");
    printf("Please enter the number of bidders: ");
    scanf("%d", &num_bidders);

    // loop over bidders to get their bids
    for (int i = 0; i < num_bidders; i++)
    {
        printf("Enter bid amount for bidder %d: ", i+1);
        scanf("%d", &bid_amount);

        // check if the current bid is the highest so far
        if (bid_amount > max_bidder_bid) 
        {
            max_bidder_bid = bid_amount;
            max_bidder_id = i+1;
        }

        // check if the current bid is the lowest so far
        if (i == 0 || bid_amount < min_bidder_bid) 
        {
            min_bidder_bid = bid_amount;
            min_bidder_id = i+1;
        }

        total_amount += bid_amount; // add current bid to total amount
        total_bids++; // increment the total number of bids
    }

    // calculate the average bid
    average_bid = total_amount / total_bids;

    // print out the statistics of the auction
    printf("\nThank you for participating in the Digital Auction System!\n");
    printf("\nNumber of bidders: %d\n", num_bidders);
    printf("Total bids: %d\n", total_bids);
    printf("Total amount: $%d\n", total_amount);
    printf("Average bid: $%d\n", average_bid);
    printf("Highest bidder: bidder #%d ($%d)\n", max_bidder_id, max_bidder_bid);
    printf("Lowest bidder: bidder #%d ($%d)\n", min_bidder_id, min_bidder_bid);

    return 0;
}