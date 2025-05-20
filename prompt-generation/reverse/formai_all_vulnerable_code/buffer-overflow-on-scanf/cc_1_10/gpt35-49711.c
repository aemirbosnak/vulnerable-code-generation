//FormAI DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_BIDS 10
#define MAX_ITEM_LEN 20
#define MAX_BID_AMOUNT 1000

// Define struct for auction item
typedef struct {
    char name[MAX_ITEM_LEN];
    int current_bid;
    int bids[MAX_BIDS];
    int num_bids;
} AuctionItem;

// Declare functions
AuctionItem createAuctionItem(char name[]);
void printAuctionItem(AuctionItem item);
void makeBid(AuctionItem *item, int bid);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create new auction item
    AuctionItem painting = createAuctionItem("Landscape painting");

    // Print auction item details
    printf("Auction item: %s\n", painting.name);
    printf("Current bid: $%d\n", painting.current_bid);

    // Prompt user to make a bid
    int bid;
    printf("Enter your bid (up to $%d): $", MAX_BID_AMOUNT);
    scanf("%d", &bid);
    if (bid > MAX_BID_AMOUNT) {
        printf("Sorry, that bid is too high.\n");
    } else {
        makeBid(&painting, bid);
        printf("Thanks for your bid of $%d!\n", bid);
    }

    // Print updated auction item details
    printf("Auction item: %s\n", painting.name);
    printf("Current bid: $%d\n", painting.current_bid);

    return 0;
}

// Function to create a new auction item
AuctionItem createAuctionItem(char name[]) {
    AuctionItem item;
    strcpy(item.name, name);
    item.current_bid = rand() % MAX_BID_AMOUNT + 1;
    item.num_bids = 1;
    item.bids[0] = item.current_bid;
    return item;
}

// Function to print auction item details
void printAuctionItem(AuctionItem item) {
    printf("Auction item: %s\n", item.name);
    printf("Current bid: $%d\n", item.current_bid);
    printf("Number of bids: %d\n", item.num_bids);
    printf("Bid history: ");
    for (int i = 0; i < item.num_bids; i++) {
        printf("$%d ", item.bids[i]);
    }
    printf("\n");
}

// Function to make a bid on an auction item
void makeBid(AuctionItem *item, int bid) {
    if (bid <= item->current_bid) {
        printf("Sorry, your bid must be higher than the current bid of $%d.\n", item->current_bid);
    } else if (item->num_bids >= MAX_BIDS) {
        printf("Sorry, the maximum number of bids has been reached.\n");
    } else {
        item->bids[item->num_bids] = bid;
        item->num_bids++;
        item->current_bid = bid;
    }
}