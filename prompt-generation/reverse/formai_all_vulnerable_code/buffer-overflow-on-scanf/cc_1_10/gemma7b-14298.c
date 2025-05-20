//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 20

struct Auction {
    char name[20];
    int startPrice;
    int currentBid;
    int numBids;
    struct Bid *bids;
};

struct Bid {
    char bidderName[20];
    int bidAmount;
    struct Bid *nextBid;
};

void createAuction(struct Auction *auction) {
    printf("Enter the name of the auction: ");
    scanf("%s", auction->name);

    printf("Enter the starting price of the auction: ");
    scanf("%d", &auction->startPrice);

    auction->currentBid = auction->startPrice;
    auction->numBids = 0;
    auction->bids = NULL;
}

void placeBid(struct Auction *auction) {
    struct Bid *newBid = malloc(sizeof(struct Bid));

    printf("Enter your name: ");
    scanf("%s", newBid->bidderName);

    printf("Enter your bid amount: ");
    scanf("%d", &newBid->bidAmount);

    newBid->nextBid = auction->bids;
    auction->bids = newBid;
    auction->numBids++;

    auction->currentBid = fmax(auction->currentBid, newBid->bidAmount);
}

void viewBids(struct Auction *auction) {
    printf("The bids for this auction are:\n");

    for (struct Bid *bid = auction->bids; bid; bid = bid->nextBid) {
        printf("%s: %d\n", bid->bidderName, bid->bidAmount);
    }
}

int main() {
    struct Auction auctions[MAX_AUCTIONS];

    for (int i = 0; i < MAX_AUCTIONS; i++) {
        createAuction(&auctions[i]);
    }

    for (int i = 0; i < MAX_AUCTIONS; i++) {
        viewBids(&auctions[i]);
    }

    return 0;
}