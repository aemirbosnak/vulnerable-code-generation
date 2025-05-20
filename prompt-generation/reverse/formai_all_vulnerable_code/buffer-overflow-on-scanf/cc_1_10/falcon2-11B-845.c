//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include <stdio.h>

#define MAX_BIDS 100
#define MAX_BIDDERS 20

int highest_bid = 0;
char bidder_name[MAX_BIDDERS][50];
int bid_amount[MAX_BIDS];

int main() {
    int num_bids = 0;
    int num_bidders = 0;
    int bid;

    printf("Welcome to the Digital Auction System!\n");

    // Allow users to place bids
    printf("Enter a bid (or -1 to end the auction): ");
    scanf("%d", &bid);

    while (bid!= -1) {
        // Check if bid is greater than highest bid
        if (bid > highest_bid) {
            highest_bid = bid;
            num_bids++;

            // Update bidder name
            if (num_bidders < MAX_BIDDERS) {
                sprintf(bidder_name[num_bidders], "%s", "Anonymous");
            } else {
                sprintf(bidder_name[num_bidders], "%s", "Bidder %d", num_bidders);
            }

            // Print bid details
            printf("New bid placed: %d by %s\n", highest_bid, bidder_name[num_bidders]);
        }

        // Check if all bids have been placed
        if (num_bids == MAX_BIDS) {
            printf("All bids have been placed!\n");
            break;
        }

        printf("Enter a bid (or -1 to end the auction): ");
        scanf("%d", &bid);
    }

    // End auction
    printf("The highest bid is %d\n", highest_bid);
    printf("The winner is %s\n", bidder_name[0]);

    return 0;
}