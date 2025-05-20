//FormAI DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Bid {
    char bidder_name[20];
    int bid_amount;
};

int main() {
    int num_bidders, i, j, current_bid;
    char item_name[30];
    struct Bid *bids;
    srand(time(0));

    printf("---Welcome to Futuristic Digital Auction System!---\n");
    printf("Enter the name of the item to be auctioned: ");
    gets(item_name);
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    // Allocate memory for all bids
    bids = (struct Bid*) malloc(num_bidders * sizeof(struct Bid));
    if (bids == NULL) {
        printf("Memory allocation error!");
        exit(1);
    }

    // Initialize all bid amounts to 0
    for (i = 0; i < num_bidders; i++) {
        bids[i].bid_amount = 0;
    }

    // Accept bids
    printf("\n---Bidding Begins---\n");
    for (i = 0; i < num_bidders; i++) {
        printf("Enter name of bidder %d: ", i+1);
        scanf("%s", bids[i].bidder_name);
        current_bid = (rand() % 10000) + 1; // Generate random bid amount
        bids[i].bid_amount = current_bid;
        printf("%s has placed a bid of %d on %s.\n", bids[i].bidder_name, current_bid, item_name);
    }
    printf("---Bidding Ends---\n\n");

    // Sort bids in descending order
    struct Bid temp;
    for (i = 0; i < num_bidders-1; i++) {
        for (j = i+1; j < num_bidders; j++) {
            if (bids[i].bid_amount < bids[j].bid_amount) {
                temp = bids[i];
                bids[i] = bids[j];
                bids[j] = temp;
            }
        }
    }

    // Display highest bidder and bid amount
    printf("Highest bidder on %s:\n", item_name);
    printf("%s with a bid of %d\n", bids[0].bidder_name, bids[0].bid_amount);

    // Free memory allocated for bids
    free(bids);

    return 0;
}