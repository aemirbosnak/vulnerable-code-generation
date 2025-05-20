//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int bidder_id;
    int bid_amount;
    int num_bids;
    char bidder_name[50];
} Bidder;

typedef struct {
    int auction_id;
    int start_time;
    int end_time;
    int bid_amount;
    Bidder* bidders;
    int num_bidders;
} Auction;

void create_auction(Auction* auction) {
    srand(time(NULL));
    auction->auction_id = rand() % 1000;
    auction->start_time = time(NULL);
    auction->end_time = auction->start_time + 60;
    auction->bid_amount = rand() % 1000;
    auction->bidders = malloc(sizeof(Bidder));
    auction->num_bidders = 0;
}

void add_bidder(Auction* auction, int bidder_id, char bidder_name[50]) {
    if (auction->num_bidders >= 10) {
        printf("No more bidders allowed.\n");
        return;
    }
    auction->bidders[auction->num_bidders].bidder_id = bidder_id;
    strcpy(auction->bidders[auction->num_bidders].bidder_name, bidder_name);
    auction->num_bidders++;
}

void place_bid(Auction* auction, int bidder_id, int bid_amount) {
    if (auction->end_time <= time(NULL)) {
        printf("Auction is over.\n");
        return;
    }
    for (int i = 0; i < auction->num_bidders; i++) {
        if (auction->bidders[i].bidder_id == bidder_id) {
            if (bid_amount > auction->bidders[i].bid_amount) {
                auction->bidders[i].bid_amount = bid_amount;
                auction->bidders[i].num_bids++;
                printf("Bidder %d's new bid amount is %d.\n", bidder_id, bid_amount);
                return;
            } else {
                printf("Bidder %d's bid amount is already %d.\n", bidder_id, auction->bidders[i].bid_amount);
                return;
            }
        }
    }
    printf("Bidder %d is not registered for this auction.\n", bidder_id);
}

void show_bids(Auction* auction) {
    printf("Auction ID: %d\n", auction->auction_id);
    printf("Start time: %s\n", ctime(&auction->start_time));
    printf("End time: %s\n", ctime(&auction->end_time));
    printf("Bid amount: %d\n", auction->bid_amount);
    printf("Bidders:\n");
    for (int i = 0; i < auction->num_bidders; i++) {
        printf("Bidder %d: %s\n", auction->bidders[i].bidder_id, auction->bidders[i].bidder_name);
    }
}

int main() {
    Auction* auction = malloc(sizeof(Auction));
    create_auction(auction);
    add_bidder(auction, 1, "Alice");
    add_bidder(auction, 2, "Bob");
    add_bidder(auction, 3, "Charlie");
    place_bid(auction, 1, 1000);
    place_bid(auction, 2, 2000);
    place_bid(auction, 3, 3000);
    show_bids(auction);
    free(auction->bidders);
    free(auction);
    return 0;
}