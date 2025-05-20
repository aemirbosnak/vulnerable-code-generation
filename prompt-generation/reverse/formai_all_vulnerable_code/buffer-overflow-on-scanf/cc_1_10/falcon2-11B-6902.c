//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int bid;
    int bidder;
    int current_bid;
    char bidder_name[50];
} Bidder;

void display_bids(Bidder bids[], int num_bids) {
    for (int i = 0; i < num_bids; i++) {
        printf("Bidder %d: %d\n", bids[i].bidder, bids[i].bid);
    }
}

void add_bid(Bidder bids[], int num_bids, int bidder, int bid) {
    if (num_bids == 0) {
        bids[0].bidder = bidder;
        bids[0].bid = bid;
        bids[0].current_bid = bid;
        return;
    }
    if (bid > bids[num_bids-1].current_bid) {
        bids[num_bids-1].current_bid = bid;
        strcpy(bids[num_bids-1].bidder_name, "Bidder ");
        sprintf(bids[num_bids-1].bidder_name + strlen("Bidder "), "%d", bidder);
        return;
    }
    add_bid(bids, num_bids, bidder, bid);
}

void run_auction(Bidder bids[], int num_bids) {
    int bidder, bid, highest_bid = bids[0].current_bid;
    char bidder_name[50];

    for (int i = 0; i < num_bids; i++) {
        printf("Current bid: %d\n", bids[i].current_bid);
        printf("Bidder %d: %s\n", bids[i].bidder, bids[i].bidder_name);
    }
    printf("Enter your bid: ");
    scanf("%d", &bid);
    if (bid > highest_bid) {
        highest_bid = bid;
        strcpy(bidder_name, "Bidder ");
        sprintf(bidder_name + strlen("Bidder "), "%d", bidder);
        add_bid(bids, num_bids, bidder, bid);
    }
    printf("Thank you for your bid. The highest bid is %d.\n", highest_bid);
    printf("The winner is %s.\n", bidder_name);
}

int main() {
    Bidder bids[100];
    int num_bids = 0;
    int bidder, bid, highest_bid = 0;
    char bidder_name[50];

    printf("Welcome to the Digital Auction System!\n");
    printf("Please enter the initial bid: ");
    scanf("%d", &bid);
    add_bid(bids, num_bids, 0, bid);
    run_auction(bids, num_bids);
    return 0;
}