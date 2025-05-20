//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define NAME_LENGTH 50

typedef struct {
    char itemName[NAME_LENGTH];
    float startingPrice;
    int auctionDuration; // in seconds
    time_t endTime;
    int bidsCount;
    float highestBid;
    char highestBidder[NAME_LENGTH];
} AuctionItem;

typedef struct {
    char bidderName[NAME_LENGTH];
    float bidAmount;
} Bid;

AuctionItem auctionItems[MAX_ITEMS];
Bid bids[MAX_BIDS];
int itemCount = 0;

void addAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Cannot add more auction items.\n");
        return;
    }

    AuctionItem newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.itemName);
    printf("Enter starting price: ");
    scanf("%f", &newItem.startingPrice);
    printf("Enter auction duration (in seconds): ");
    scanf("%d", &newItem.auctionDuration);

    newItem.endTime = time(NULL) + newItem.auctionDuration;
    newItem.bidsCount = 0;
    newItem.highestBid = newItem.startingPrice;
    strcpy(newItem.highestBidder, "None");

    auctionItems[itemCount++] = newItem;
    printf("Auction item added successfully.\n");
}

void placeBid() {
    char bidder[NAME_LENGTH];
    float bidAmount;
    int itemIndex;

    printf("Enter your name: ");
    scanf("%s", bidder);
    
    printf("Enter item index to bid on (0 to %d): ", itemCount - 1);
    scanf("%d", &itemIndex);

    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item index selected.\n");
        return;
    }

    AuctionItem *item = &auctionItems[itemIndex];

    if (time(NULL) > item->endTime) {
        printf("This auction has already ended.\n");
        return;
    }

    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= item->highestBid) {
        printf("Bid must be higher than the current highest bid of %.2f.\n", item->highestBid);
        return;
    }

    item->highestBid = bidAmount;
    strcpy(item->highestBidder, bidder);
    item->bidsCount++;

    printf("Bid placed successfully! Current highest bid: %.2f by %s.\n", item->highestBid, item->highestBidder);
}

void displayAuctionItems() {
    printf("\nAvailable Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        AuctionItem *item = &auctionItems[i];
        printf("Item %d: %s | Starting Price: %.2f | Highest Bid: %.2f | Highest Bidder: %s | Ends in: %ld seconds\n",
            i, item->itemName, item->startingPrice, item->highestBid, item->highestBidder, (item->endTime - time(NULL)));
    }
}

void endAuction() {
    int itemIndex;
    printf("Enter item index to end auction (0 to %d): ", itemCount - 1);
    scanf("%d", &itemIndex);

    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item index selected.\n");
        return;
    }

    AuctionItem *item = &auctionItems[itemIndex];
    printf("Ending auction for item: %s\n", item->itemName);
    
    if (item->bidsCount > 0) {
        printf("Auction ended. Highest bid: %.2f by %s.\n", item->highestBid, item->highestBidder);
    } else {
        printf("Auction ended with no bids.\n");
    }

    // Optionally remove the item from the list or keep it
    // Here, we just reset it
    auctionItems[itemIndex] = auctionItems[--itemCount]; // Swap with last and decrement count.
}

int main() {
    int choice;

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Add Auction Item\n");
        printf("2. Place a Bid\n");
        printf("3. Display Available Auction Items\n");
        printf("4. End Auction\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAuctionItem();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                displayAuctionItems();
                break;
            case 4:
                endAuction();
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}