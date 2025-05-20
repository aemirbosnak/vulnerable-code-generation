//FormAI DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float bid;
} Bid;

typedef struct {
    char itemName[50];
    float startingPrice;
    Bid* highestBid;
} AuctionItem;

void displayAuctionItems(AuctionItem* items, int numItems);
void bidOnItem(AuctionItem* item, Bid* bid);

int main() {
    int numItems;
    printf("Enter the number of items to be auctioned: ");
    scanf("%d", &numItems);
    
    AuctionItem* items = (AuctionItem*) malloc(numItems*sizeof(AuctionItem));
    
    for (int i = 0; i < numItems; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].itemName);
        printf("Enter the starting price of item %d: ", i+1);
        scanf("%f", &items[i].startingPrice);
        
        // Initialize highestBid to NULL
        items[i].highestBid = NULL;
    }
    
    displayAuctionItems(items, numItems);
    
    // Bid on an item
    int itemNum, bidderNum;
    float bidAmount;
    printf("\nEnter the item number you want to bid on: ");
    scanf("%d", &itemNum);
    while (itemNum < 1 || itemNum > numItems) {
        printf("Invalid item number. Please enter a number between 1 and %d: ", numItems);
        scanf("%d", &itemNum);
    }
    printf("Enter your name: ");
    Bid* bidder = (Bid*) malloc(sizeof(Bid));
    scanf("%s", bidder->name);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    bidder->bid = bidAmount;
    bidOnItem(&items[itemNum-1], bidder);
    
    // Display updated highest bid for item
    printf("\nUpdated highest bid for item %d: %s - %.2f", itemNum, items[itemNum-1].highestBid->name, items[itemNum-1].highestBid->bid);
    
    free(items);
    free(bidder);
}

void displayAuctionItems(AuctionItem* items, int numItems) {
    printf("\nItems in the auction:");
    for (int i = 0; i < numItems; i++) {
        printf("\n%d. %s - %.2f", i+1, items[i].itemName, items[i].startingPrice);
        if (items[i].highestBid != NULL) {
            printf(" (Highest Bid: %s - %.2f)", items[i].highestBid->name, items[i].highestBid->bid);
        }
    }
}

void bidOnItem(AuctionItem* item, Bid* bid) {
    if (item->highestBid == NULL) {
        item->highestBid = bid;
    } else if (bid->bid > item->highestBid->bid) {
        item->highestBid = bid;
    } else {
        printf("\nYour bid of %.2f on item %s did not exceed the current highest bid of %.2f by %s.\n", bid->bid, item->itemName, item->highestBid->bid, item->highestBid->name);
    }
}