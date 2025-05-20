//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 5

typedef struct {
    char name[30];
    int bid;
} Bidder;

typedef struct {
    char itemName[50];
    int currentBid;
    Bidder highestBidder;
} AuctionItem;

void initializeAuctionItems(AuctionItem items[], int count) {
    for(int i = 0; i < count; i++) {
        snprintf(items[i].itemName, sizeof(items[i].itemName), "Mystery Item %d", i + 1);
        items[i].currentBid = 0;
        strcpy(items[i].highestBidder.name, "No one yet!");
        items[i].highestBidder.bid = 0;
    }
}

void displayItems(const AuctionItem items[], int count) {
    printf("\nCurrent Auction Items:\n");
    for(int i = 0; i < count; i++) {
        printf("Item: %s | Current Bid: $%d | Highest Bidder: %s ($%d)\n",
               items[i].itemName,
               items[i].currentBid,
               items[i].highestBidder.name,
               items[i].highestBidder.bid);
    }
}

int placeBid(AuctionItem *item, Bidder *bidder) {
    if(bidder->bid > item->currentBid) {
        item->currentBid = bidder->bid;
        item->highestBidder = *bidder;
        printf("%s has successfully placed a bid of $%d on %s!\n", bidder->name, bidder->bid, item->itemName);
        return 1;
    } else {
        printf("Bid from %s of $%d on %s was too low! Try again, big spender!\n", bidder->name, bidder->bid, item->itemName);
        return 0;
    }
}

void countdownTimer() {
    for(int i = 10; i > 0; i--) {
        printf("The auction ends in %d seconds...\n", i);
        sleep(1);
    }
}

int main() {
    AuctionItem items[MAX_ITEMS];
    Bidder bidders[MAX_BIDDERS];
    int numBidders;

    printf("Welcome to the Digital Auction System!\n");
    printf("Where items are mysterious, and bids are questionable!\n");

    // Initialize auction items
    initializeAuctionItems(items, MAX_ITEMS);
    
    printf("\nHow many bidders are ready to take the plunge? (Max: %d)\n", MAX_BIDDERS);
    scanf("%d", &numBidders);
    
    if(numBidders > MAX_BIDDERS) {
        printf("Whoa there! You can't have more than %d bidders! Adjusting for you!\n", MAX_BIDDERS);
        numBidders = MAX_BIDDERS;
    }

    // Gather bidder information
    for(int i = 0; i < numBidders; i++) {
        printf("Enter name for Bidder %d: ", i + 1);
        scanf("%s", bidders[i].name);
        bidders[i].bid = rand() % 100; // Random bid for fun!
        printf("%s is ready to bid $%d on something! Fabulous!\n", bidders[i].name, bidders[i].bid);
    }

    countdownTimer();
    printf("Time's up! Let's review the final bids!\n");
    displayItems(items, MAX_ITEMS);

    // Place bids
    for(int i = 0; i < numBidders; i++) {
        for(int j = 0; j < MAX_ITEMS; j++) {
            bidders[i].bid = rand() % 150; // Generate a new random bid for excitement!
            placeBid(&items[j], &bidders[i]);
        }
    }

    printf("\nThe auction is now closed, let's find out who won what!\n");
    displayItems(items, MAX_ITEMS);

    printf("Thanks for participating! Remember, you may not have won, but you certainly had a blast!\n");
    return 0;
}