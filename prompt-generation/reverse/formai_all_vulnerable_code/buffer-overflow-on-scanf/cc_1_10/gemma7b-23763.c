//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char item_name[20];
    int starting_bid;
    int current_bid;
    char bidder_name[20];
} Auction;

void create_auction(Auction *auction) {
    printf("Enter the item name: ");
    scanf("%s", auction->item_name);

    printf("Enter the starting bid: ");
    scanf("%d", &auction->starting_bid);

    auction->current_bid = auction->starting_bid;
    auction->bidder_name[0] = '\0';
}

void place_bid(Auction *auction) {
    printf("Enter your name: ");
    scanf("%s", auction->bidder_name);

    printf("Enter your bid: ");
    scanf("%d", &auction->current_bid);

    if (auction->current_bid > auction->starting_bid) {
        auction->current_bid = auction->starting_bid;
        printf("Error: Your bid must be greater than the starting bid.\n");
    } else if (auction->current_bid < auction->starting_bid) {
        auction->current_bid = auction->starting_bid;
        printf("Error: Your bid must be greater than the starting bid.\n");
    } else {
        printf("Your bid has been placed.\n");
    }
}

void print_auction(Auction *auction) {
    printf("Item name: %s\n", auction->item_name);
    printf("Starting bid: %d\n", auction->starting_bid);
    printf("Current bid: %d\n", auction->current_bid);
    printf("Bidder name: %s\n", auction->bidder_name);
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