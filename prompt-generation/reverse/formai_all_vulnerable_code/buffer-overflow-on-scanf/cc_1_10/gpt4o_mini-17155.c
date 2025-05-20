//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 100
#define MAX_NAME_LENGTH 50
#define MAX_ITEM_LENGTH 100

typedef struct {
    char bidderName[MAX_NAME_LENGTH];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[MAX_ITEM_LENGTH];
    float startingPrice;
    Bid bids[MAX_BIDS];
    int bidCount;
} AuctionItem;

void initializeAuctionItem(AuctionItem *item, const char *name, float price) {
    strcpy(item->itemName, name);
    item->startingPrice = price;
    item->bidCount = 0;
    printf("Auction for '%s' starting at $%.2f is created!\n", item->itemName, item->startingPrice);
}

void placeBid(AuctionItem *item) {
    if (item->bidCount >= MAX_BIDS) {
        printf("Sorry! The maximum number of bids has been reached for %s.\n", item->itemName);
        return;
    }
    
    char name[MAX_NAME_LENGTH];
    float bidAmount;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount > item->startingPrice && (item->bidCount == 0 || bidAmount > item->bids[item->bidCount - 1].bidAmount)) {
        // Save the bid
        strcpy(item->bids[item->bidCount].bidderName, name);
        item->bids[item->bidCount].bidAmount = bidAmount;
        item->bidCount++;
        printf("Congratulations %s, your bid of $%.2f has been placed on %s!\n", name, bidAmount, item->itemName);
    } else {
        printf("Bid of $%.2f is not high enough. Please bid higher than the current bid!\n", bidAmount);
    }
}

void displayBids(const AuctionItem *item) {
    if (item->bidCount == 0) {
        printf("No bids placed for %s yet.\n", item->itemName);
        return;
    }
    
    printf("Bids for %s:\n", item->itemName);
    for (int i = 0; i < item->bidCount; i++) {
        printf("Bidder: %s, Amount: $%.2f\n", item->bids[i].bidderName, item->bids[i].bidAmount);
    }
}

void showHighestBid(const AuctionItem *item) {
    if (item->bidCount > 0) {
        printf("Highest bid on %s is $%.2f by %s.\n", item->itemName, item->bids[item->bidCount - 1].bidAmount, item->bids[item->bidCount - 1].bidderName);
    } else {
        printf("No bids placed on %s yet.\n", item->itemName);
    }
}

void auctionMenu(AuctionItem *item) {
    int choice;
    do {
        printf("\n--- Auction Menu for %s ---\n", item->itemName);
        printf("1. Place a Bid\n");
        printf("2. Show All Bids\n");
        printf("3. Show Highest Bid\n");
        printf("4. Exit Auction\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                placeBid(item);
                break;
            case 2:
                displayBids(item);
                break;
            case 3:
                showHighestBid(item);
                break;
            case 4:
                printf("Exiting auction for %s. Good luck bidders!\n", item->itemName);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    AuctionItem item;
    char itemName[MAX_ITEM_LENGTH];
    float startingPrice;

    printf("Welcome to the Digital Auction System!\n");
    printf("Enter the item name you want to auction: ");
    scanf("%s", itemName);
    printf("Enter the starting price for the item: ");
    scanf("%f", &startingPrice);
    
    initializeAuctionItem(&item, itemName, startingPrice);
    auctionMenu(&item);

    printf("Thank you for using the Digital Auction System!\n");
    return 0;
}