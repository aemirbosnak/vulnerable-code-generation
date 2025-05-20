//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 50
#define NAME_LEN 50
#define ITEM_DESC_LEN 200

typedef struct {
    char itemName[NAME_LEN];
    char itemDescription[ITEM_DESC_LEN];
    float startPrice;
    float highestBid;
    int bidCount;
    char highestBidder[NAME_LEN];
    time_t endTime;
} AuctionItem;

typedef struct {
    char bidderName[NAME_LEN];
    float bidAmount;
} Bid;

AuctionItem items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int totalItems = 0;

void createAuctionItem() {
    if (totalItems >= MAX_ITEMS) {
        printf("Maximum item limit reached!\n");
        return;
    }

    AuctionItem newItem;
    printf("Enter item name: ");
    scanf(" %[^\n]%*c", newItem.itemName);
    printf("Enter item description: ");
    scanf(" %[^\n]%*c", newItem.itemDescription);
    printf("Enter starting price: ");
    scanf("%f", &newItem.startPrice);
    newItem.highestBid = newItem.startPrice;
    newItem.bidCount = 0;
    printf("Enter auction end time in seconds from now: ");
    int endTimeInSec;
    scanf("%d", &endTimeInSec);
    newItem.endTime = time(NULL) + endTimeInSec;

    items[totalItems++] = newItem;
    printf("Auction item created successfully!\n");
}

void placeBid() {
    char bidder[NAME_LEN];
    printf("Enter your name: ");
    scanf(" %[^\n]%*c", bidder);

    int itemIndex;
    printf("Enter the auction item index (0 to %d): ", totalItems - 1);
    scanf("%d", &itemIndex);

    if (itemIndex < 0 || itemIndex >= totalItems) {
        printf("Invalid item index!\n");
        return;
    }

    AuctionItem* item = &items[itemIndex];

    if (time(NULL) > item->endTime) {
        printf("Auction has ended for this item!\n");
        return;
    }

    float bidAmount;
    printf("Enter your bid amount (current highest bid is %.2f): ", item->highestBid);
    scanf("%f", &bidAmount);

    if (bidAmount <= item->highestBid) {
        printf("Bid must be higher than the current highest bid!\n");
        return;
    }

    strcpy(item->highestBidder, bidder);
    item->highestBid = bidAmount;
    item->bidCount++;

    printf("Bid placed successfully! Current highest bid is now %.2f by %s.\n", item->highestBid, item->highestBidder);
}

void displayItems() {
    printf("\nAuction Items:\n");
    for (int i = 0; i < totalItems; i++) {
        AuctionItem item = items[i];
        printf("Item %d: %s\n", i, item.itemName);
        printf("Description: %s\n", item.itemDescription);
        printf("Starting Price: %.2f\n", item.startPrice);
        printf("Current Highest Bid: %.2f by %s\n", item.highestBid, item.highestBidder);
        printf("Auction Ends In: %ld seconds\n", item.endTime - time(NULL));
        printf("-------------------\n");
    }
}

void endAuction() {
    printf("\nEnding all auctions...\n");
    for (int i = 0; i < totalItems; i++) {
        AuctionItem item = items[i];
        if (time(NULL) > item.endTime) {
            if (item.bidCount > 0) {
                printf("Auction for %s ended. Winning Bid: %.2f by %s\n", item.itemName, item.highestBid, item.highestBidder);
            } else {
                printf("Auction for %s ended. No bids placed.\n", item.itemName);
            }
        }
    }
}

int main() {
    int option;
    
    do {
        printf("\nDigital Auction System\n");
        printf("1. Create Auction Item\n");
        printf("2. Place Bid\n");
        printf("3. Display All Items\n");
        printf("4. End Auctions\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                createAuctionItem();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                endAuction();
                break;
            case 5:
                printf("Exiting the auction system.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);
    
    return 0;
}