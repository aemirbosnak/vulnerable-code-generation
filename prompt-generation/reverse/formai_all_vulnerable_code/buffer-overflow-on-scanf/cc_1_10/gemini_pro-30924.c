//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10
#define MAX_BIDDERS 10

struct Bid {
    char *name;
    int amount;
};

struct Auction {
    char *item;
    int starting_price;
    struct Bid bids[MAX_BIDS];
    int num_bids;
};

void print_auction(struct Auction *auction) {
    printf("Item: %s\n", auction->item);
    printf("Starting price: %d\n", auction->starting_price);
    printf("Bids:\n");
    for (int i = 0; i < auction->num_bids; i++) {
        printf("  %s: %d\n", auction->bids[i].name, auction->bids[i].amount);
    }
}

int main() {
    struct Auction auction;
    auction.item = "A pair of star-crossed lovers";
    auction.starting_price = 100;
    auction.num_bids = 0;

    // Romeo and Juliet enter the auction
    struct Bid romeo_bid;
    romeo_bid.name = "Romeo";
    romeo_bid.amount = 150;
    auction.bids[auction.num_bids++] = romeo_bid;

    struct Bid juliet_bid;
    juliet_bid.name = "Juliet";
    juliet_bid.amount = 200;
    auction.bids[auction.num_bids++] = juliet_bid;

    // Print the current state of the auction
    print_auction(&auction);

    // The auctioneer starts the bidding
    int highest_bid = auction.starting_price;
    char *highest_bidder = NULL;
    while (1) {
        // Get the next bid
        char name[MAX_BIDDERS];
        int amount;
        printf("Enter the name of the next bidder: ");
        scanf("%s", name);
        printf("Enter the amount of the bid: ");
        scanf("%d", &amount);

        // Check if the bid is valid
        if (amount < highest_bid) {
            printf("The bid must be higher than the current highest bid.\n");
            continue;
        }

        // Update the highest bid
        highest_bid = amount;
        highest_bidder = name;

        // Add the bid to the auction
        struct Bid bid;
        bid.name = name;
        bid.amount = amount;
        auction.bids[auction.num_bids++] = bid;

        // Print the current state of the auction
        print_auction(&auction);

        // Check if the bidding is over
        char answer;
        printf("Do you want to continue bidding (y/n)? ");
        scanf(" %c", &answer);
        if (answer == 'n') {
            break;
        }
    }

    // Print the winner of the auction
    printf("The winner of the auction is %s with a bid of %d.\n", highest_bidder, highest_bid);

    return 0;
}