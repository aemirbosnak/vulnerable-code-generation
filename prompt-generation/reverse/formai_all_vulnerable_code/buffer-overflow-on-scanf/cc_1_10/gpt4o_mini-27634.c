//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 50
#define NAME_LENGTH 50
#define ITEM_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float bidAmount;
} Bidder;

typedef struct {
    char itemName[ITEM_LENGTH];
    float startingPrice;
    float currentBid;
    Bidder highestBidder;
} AuctionItem;

AuctionItem auctionItems[MAX_ITEMS];
int itemCount = 0;

void createAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Maximum number of auction items reached.\n");
        return;
    }

    AuctionItem newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.itemName);
    printf("Enter starting price: ");
    scanf("%f", &newItem.startingPrice);
    
    newItem.currentBid = newItem.startingPrice;
    newItem.highestBidder.bidAmount = 0.0;

    auctionItems[itemCount++] = newItem;
    printf("Auction item created successfully!\n");
}

void placeBid() {
    char itemName[ITEM_LENGTH];
    printf("Enter the item name to bid on: ");
    scanf("%s", itemName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(auctionItems[i].itemName, itemName) == 0) {
            float bidAmount;
            printf("Enter your bid amount: ");
            scanf("%f", &bidAmount);

            if (bidAmount > auctionItems[i].currentBid) {
                printf("Enter your name: ");
                scanf("%s", auctionItems[i].highestBidder.name);
                auctionItems[i].highestBidder.bidAmount = bidAmount;
                auctionItems[i].currentBid = bidAmount;
                printf("Bid placed successfully!\n");
            } else {
                printf("Bid must be higher than the current bid of %.2f\n", auctionItems[i].currentBid);
            }
            return;
        }
    }

    printf("Item not found.\n");
}

void viewAuctionItems() {
    if (itemCount == 0) {
        printf("No auction items available.\n");
        return;
    }

    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item Name: %s\n", auctionItems[i].itemName);
        printf("Starting Price: %.2f\n", auctionItems[i].startingPrice);
        printf("Current Bid: %.2f\n", auctionItems[i].currentBid);
        if (auctionItems[i].highestBidder.bidAmount > 0) {
            printf("Highest Bidder: %s with a bid of %.2f\n", auctionItems[i].highestBidder.name, auctionItems[i].highestBidder.bidAmount);
        } else {
            printf("No bids placed yet.\n");
        }
        printf("---------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("Digital Auction System\n");
        printf("1. Create Auction Item\n");
        printf("2. Place a Bid\n");
        printf("3. View Auction Items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAuctionItem();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                viewAuctionItems();
                break;
            case 4:
                printf("Exiting the auction system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}