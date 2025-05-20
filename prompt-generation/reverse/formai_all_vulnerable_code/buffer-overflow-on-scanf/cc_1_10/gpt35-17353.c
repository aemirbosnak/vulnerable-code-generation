//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 10
#define BID_INCREMENT 5

struct item {
    char name[20];
    int current_bid;
    int bidder_id;
};

int main() {
    struct item items[NUM_ITEMS];
    srand(time(NULL));

    // Initialize items
    for (int i = 0; i < NUM_ITEMS; i++) {
        sprintf(items[i].name, "Item %d", i+1);
        items[i].current_bid = rand() % 100 + 1;
        items[i].bidder_id = 0;
    }

    // Display items with their current bids
    printf("Current Items for Auction:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%s\tCurrent Bid: $%d\n", items[i].name, items[i].current_bid);
    }

    // Auction process
    int item_index = 0;
    while (item_index < NUM_ITEMS) {
        printf("\nBidding on %s\n", items[item_index].name);
        int bidder_id = rand() % 1000 + 1;
        int bid_amount = items[item_index].current_bid + BID_INCREMENT;
        printf("Current highest bid: $%d\n", items[item_index].current_bid);

        int continue_bidding = 1;
        while (continue_bidding) {
            printf("Bid $%d by bidder %d? (y/n) ", bid_amount, bidder_id);
            char input;
            scanf(" %c", &input);

            if (input == 'y') {
                items[item_index].current_bid = bid_amount;
                items[item_index].bidder_id = bidder_id;
                printf("Bid accepted!\n");
                continue_bidding = 0;
            } else if (input == 'n') {
                printf("Bid not accepted.\n");
                continue_bidding = 0;
            } else {
                printf("Invalid input.\n");
            }
        }

        item_index++;
    }

    // Display winners of each item
    printf("\nWinners:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%s\tWinner: Bidder %d\n", items[i].name, items[i].bidder_id);
    }

    return 0;
}