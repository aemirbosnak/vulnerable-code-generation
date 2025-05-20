//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char name[20];
    int start_price;
    int current_price;
    int num_bids;
    time_t start_time;
    time_t end_time;
} Auction;

void create_auction(Auction *auction) {
    printf("Enter the name of the auction: ");
    scanf("%s", auction->name);

    printf("Enter the starting price: ");
    scanf("%d", &auction->start_price);

    auction->current_price = auction->start_price;
    auction->num_bids = 0;

    time_t t = time(NULL);
    auction->start_time = t;
    auction->end_time = t + 600;
}

void place_bid(Auction *auction) {
    int bid_price;

    printf("Enter your bid price: ");
    scanf("%d", &bid_price);

    if (bid_price > auction->current_price) {
        auction->current_price = bid_price;
        auction->num_bids++;
    } else {
        printf("Your bid is not higher than the current price.\n");
    }
}

void print_auction(Auction *auction) {
    printf("Name: %s\n", auction->name);
    printf("Start Price: %d\n", auction->start_price);
    printf("Current Price: %d\n", auction->current_price);
    printf("Number of Bids: %d\n", auction->num_bids);
    printf("Start Time: %s\n",ctime(auction->start_time));
    printf("End Time: %s\n",ctime(auction->end_time));
}

int main() {
    Auction auctions[MAX_AUCTIONS];

    for (int i = 0; i < MAX_AUCTIONS; i++) {
        create_auction(&auctions[i]);
    }

    for (int i = 0; i < MAX_AUCTIONS; i++) {
        place_bid(&auctions[i]);
    }

    for (int i = 0; i < MAX_AUCTIONS; i++) {
        print_auction(&auctions[i]);
    }

    return 0;
}