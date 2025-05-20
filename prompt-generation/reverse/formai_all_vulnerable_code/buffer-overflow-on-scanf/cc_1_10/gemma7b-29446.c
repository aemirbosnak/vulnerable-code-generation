//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 10
#define MAX_BID 1000

struct Auction {
    char name[20];
    int startPrice;
    int reservePrice;
    int currentBid;
    int numBids;
    time_t endTime;
};

struct Bid {
    char bidderName[20];
    int bidAmount;
    time_t bidTime;
};

void createAuction(struct Auction *auction) {
    printf("Enter auction name: ");
    scanf("%s", auction->name);

    printf("Enter starting price: ");
    scanf("%d", &auction->startPrice);

    printf("Enter reserve price: ");
    scanf("%d", &auction->reservePrice);

    auction->currentBid = 0;
    auction->numBids = 0;
    auction->endTime = time(NULL) + 60 * 5;
}

void placeBid(struct Auction *auction, struct Bid *bid) {
    printf("Enter your name: ");
    scanf("%s", bid->bidderName);

    printf("Enter your bid amount: ");
    scanf("%d", &bid->bidAmount);

    bid->bidTime = time(NULL);

    if (bid->bidAmount > auction->currentBid) {
        auction->currentBid = bid->bidAmount;
        auction->numBids++;
    } else {
        printf("Your bid is not higher than the current bid.\n");
    }
}

void checkAuctionStatus(struct Auction *auction) {
    if (time(NULL) >= auction->endTime) {
        printf("Auction ended.\n");
        printf("The winning bid is: $%d\n", auction->currentBid);
    } else {
        printf("Auction is still ongoing.\n");
        printf("Current highest bid: $%d\n", auction->currentBid);
    }
}

int main() {
    struct Auction auctions[MAX_AUCTIONS];
    struct Bid bids[MAX_BID];

    for (int i = 0; i < MAX_AUCTIONS; i++) {
        createAuction(&auctions[i]);
    }

    for (int i = 0; i < MAX_BID; i++) {
        placeBid(&auctions[0], &bids[i]);
    }

    checkAuctionStatus(&auctions[0]);

    return 0;
}