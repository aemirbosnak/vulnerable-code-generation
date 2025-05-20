//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int bid;
} Bidder;

Bidder bidders[100];
int num_bidders = 0;

int main() {
    // Initialize the auction system
    char item_name[50];
    int starting_bid;
    printf("Enter the name of the item being auctioned: ");
    scanf("%s", item_name);
    printf("Enter the starting bid: ");
    scanf("%d", &starting_bid);

    // Register bidders
    int num_bidders;
    printf("How many bidders will be participating? ");
    scanf("%d", &num_bidders);
    for (int i = 0; i < num_bidders; i++) {
        printf("Enter the name of bidder %d: ", i + 1);
        scanf("%s", bidders[i].name);
        bidders[i].bid = -1;  // Initialize bid to -1 to indicate no bid yet
    }

    // Start the auction
    int current_bid = starting_bid;
    int current_bidder = -1;  // Initialize to -1 to indicate no current bidder
    while (1) {
        // Display the current highest bid
        printf("\nCurrent highest bid: %d by %s\n", current_bid, bidders[current_bidder].name);

        // Get bids from all bidders
        for (int i = 0; i < num_bidders; i++) {
            if (bidders[i].bid == -1) {
                printf("%s, enter your bid: ", bidders[i].name);
                scanf("%d", &bidders[i].bid);
                if (bidders[i].bid > current_bid) {
                    current_bid = bidders[i].bid;
                    current_bidder = i;
                }
            }
        }

        // Check if all bidders have placed a bid
        int all_bids_placed = 1;
        for (int i = 0; i < num_bidders; i++) {
            if (bidders[i].bid == -1) {
                all_bids_placed = 0;
                break;
            }
        }

        // If all bids have been placed, end the auction
        if (all_bids_placed) {
            printf("\nAuction ended!\n");
            printf("The highest bid of %d was placed by %s.\n", current_bid, bidders[current_bidder].name);
            break;
        }
    }

    return 0;
}