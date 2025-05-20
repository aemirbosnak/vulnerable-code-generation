//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    auction->start_time = time(NULL);
    auction->end_time = time(NULL) + 60 * 5; // 5 minutes
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

void check_auction_status(Auction *auction) {
    time_t current_time = time(NULL);

    if (current_time >= auction->end_time) {
        printf("The auction has ended.\n");
        printf("The winner is: %s\n", auction->name);
        printf("The final price is: %d\n", auction->current_price);
    } else {
        printf("The auction is still ongoing.\n");
        printf("The current price is: %d\n", auction->current_price);
        printf("Number of bids: %d\n", auction->num_bids);
    }
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
        check_auction_status(&auctions[i]);
    }

    return 0;
}