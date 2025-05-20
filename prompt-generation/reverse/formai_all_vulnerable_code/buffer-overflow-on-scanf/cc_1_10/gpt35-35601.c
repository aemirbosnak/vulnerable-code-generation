//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bid {
    char bidder_name[50];
    int bid_amount;
};

struct Auction {
    char item_name[50];
    int current_bid;
    struct Bid highest_bid;
};

void printAuction(struct Auction *auction) {
    printf("Item Name: %s\n", auction->item_name);
    printf("Current Bid: $%d\n", auction->current_bid);
    if (auction->highest_bid.bid_amount > 0) {
        printf("Highest Bid: $%d by %s\n", 
            auction->highest_bid.bid_amount, auction->highest_bid.bidder_name);
    } else {
        printf("No Bids\n");
    }
    printf("\n");
}

void placeBid(struct Auction *auction, char *bidder_name, int bid_amount) {
    if (bid_amount > auction->current_bid) {
        auction->current_bid = bid_amount;
        strcpy(auction->highest_bid.bidder_name, bidder_name);
        auction->highest_bid.bid_amount = bid_amount;
        printf("%s has placed a bid of $%d on %s\n", bidder_name, bid_amount, auction->item_name);
    } else {
        printf("Bid not accepted. Current bid is $%d\n", auction->current_bid);
    }
}

int main() {

    struct Auction myAuction = {"Antique Desk", 100, {"", 0}};
    struct Auction yourAuction = {"Rare Stamp Collection", 500, {"", 0}};

    printf("Welcome to the Digital Auction System Prototype!\n");
    printf("Auction Items Available:\n");
    printAuction(&myAuction);
    printAuction(&yourAuction);

    printf("Please input your bid for the %s: ", myAuction.item_name);
    int bid;
    scanf("%d", &bid);
    placeBid(&myAuction, "John Doe", bid);

    printf("Please input your bid for the %s: ", yourAuction.item_name);
    scanf("%d", &bid);
    placeBid(&yourAuction, "Jane Smith", bid);

    printf("Auction Results:\n");
    printAuction(&myAuction);
    printAuction(&yourAuction);

    return 0;
}