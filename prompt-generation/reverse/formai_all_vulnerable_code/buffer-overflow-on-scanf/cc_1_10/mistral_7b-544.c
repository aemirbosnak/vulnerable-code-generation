//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDDERS 10
#define MIN_BID 0
#define MAX_PRICE 1000

typedef struct {
    int bidder_id;
    int bid_amount;
} Bidder;

Bidder bidders[MAX_BIDDERS];
int num_bidders = 0;
int current_bid = MIN_BID;

void print_winner(int bidder_id) {
    printf("\nCongratulations Bidder %d, you have won the auction with a bid of %d!\n", bidder_id, bidders[bidder_id].bid_amount);
}

int find_highest_bidder() {
    int max_bid_index = -1;
    int max_bid = MIN_BID;

    for (int i = 0; i < num_bidders; i++) {
        if (bidders[i].bid_amount > max_bid) {
            max_bid = bidders[i].bid_amount;
            max_bid_index = i;
        }
    }

    return max_bid_index;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Digital Auction System!\n");
    printf("Please enter your maximum bid amount for the item: ");
    scanf("%d", &current_bid);

    for (int i = 0; i < MAX_BIDDERS; i++) {
        bidders[i].bidder_id = i + 1;
        bidders[i].bid_amount = rand() % (MAX_PRICE - MIN_BID + 1) + MIN_BID;

        if (bidders[i].bid_amount > current_bid) {
            num_bidders++;
        } else {
            printf("\nBidder %d has been skipped as their bid of %d is lower than the current highest bid of %d.\n", bidders[i].bidder_id, bidders[i].bid_amount, current_bid);
        }
    }

    int winner_index = find_highest_bidder();
    print_winner(winner_index);

    return 0;
}