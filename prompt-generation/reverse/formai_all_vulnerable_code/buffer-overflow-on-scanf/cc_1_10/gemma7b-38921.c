//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 10

struct Auction {
    char name[50];
    int start_price;
    int current_price;
    int num_bids;
    time_t start_time;
    time_t end_time;
    char winner[50];
};

void create_auction(struct Auction *auction) {
    printf("Enter the name of the auction: ");
    scanf("%s", auction->name);

    printf("Enter the starting price: ");
    scanf("%d", &auction->start_price);

    auction->current_price = auction->start_price;
    auction->num_bids = 0;

    auction->start_time = time(NULL);
    auction->end_time = time(NULL) + 600;

    auction->winner[0] = '\0';
}

void place_bid(struct Auction *auction) {
    printf("Enter your bid: ");
    int bid = atoi(scanf("%d"));

    if (bid > auction->current_price) {
        auction->current_price = bid;
        auction->num_bids++;
        strcpy(auction->winner, "Not yet determined");
    } else {
        printf("Your bid is too low.\n");
    }
}

void check_auction_status(struct Auction *auction) {
    time_t current_time = time(NULL);

    if (current_time >= auction->end_time) {
        printf("The auction has ended.\n");
        printf("The winner is: %s\n", auction->winner);
    } else if (auction->num_bids > 0) {
        printf("The current price is: %d\n", auction->current_price);
        printf("Number of bids: %d\n", auction->num_bids);
    } else {
        printf("No bids have been placed yet.\n");
    }
}

int main() {
    struct Auction auctions[MAX_AUCTIONS];

    for (int i = 0; i < MAX_AUCTIONS; i++) {
        create_auction(&auctions[i]);
    }

    for (int i = 0; i < MAX_AUCTIONS; i++) {
        place_bid(&auctions[i]);
    }

    for (int i = 0; i < MAX_AUCTIONS; i++) {
        check_auction_status(&auctions[i]);
    }

    return 0;
}