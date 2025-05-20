//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    double bidAmount;
} Bid;

typedef struct {
    char itemName[MAX_LENGTH];
    double reservePrice;
    double highestBid;
    Bid bids[MAX_BIDS];
    int bidCount;
    time_t auctionEndTime;
} AuctionItem;

void initializeAuction(AuctionItem *item, const char *name, double price, int duration) {
    strcpy(item->itemName, name);
    item->reservePrice = price;
    item->highestBid = 0;
    item->bidCount = 0;
    item->auctionEndTime = time(NULL) + duration;
}

void placeBid(AuctionItem *item) {
    if (time(NULL) > item->auctionEndTime) {
        printf("The auction has ended for %s. Cannot place a bid.\n", item->itemName);
        return;
    }
    
    if (item->bidCount >= MAX_BIDS) {
        printf("The maximum number of bids has been reached for %s.\n", item->itemName);
        return;
    }
    
    char username[MAX_LENGTH];
    double bidAmount;

    printf("Enter your username: ");
    scanf("%s", username);
    
    printf("Enter your bid amount: ");
    scanf("%lf", &bidAmount);

    if (bidAmount <= item->highestBid) {
        printf("Your bid must be higher than the current highest bid of %.2f\n", item->highestBid);
        return;
    }

    item->bids[item->bidCount].bidAmount = bidAmount;
    strcpy(item->bids[item->bidCount].username, username);
    item->highestBid = bidAmount;
    item->bidCount++;

    printf("Bid placed successfully by %s for %.2f on %s\n", username, bidAmount, item->itemName);
}

void displayAuctionDetails(AuctionItem *item) {
    printf("\n-- Auction Details --\n");
    printf("Item: %s\n", item->itemName);
    printf("Reserve Price: %.2f\n", item->reservePrice);
    printf("Highest Bid: %.2f\n", item->highestBid);
    printf("Number of Bids: %d\n", item->bidCount);
    printf("Bids:\n");
    for (int i = 0; i < item->bidCount; i++) {
        printf("  Username: %s, Bid Amount: %.2f\n", item->bids[i].username, item->bids[i].bidAmount);
    }
    printf("----------------------\n");
}

void auctionStatus(AuctionItem *item) {
    if (time(NULL) > item->auctionEndTime) {
        printf("Auction for %s has ended!\n", item->itemName);
    } else {
        printf("Auction for %s is ongoing! Ends in %ld seconds.\n", item->itemName, item->auctionEndTime - time(NULL));
    }
}

int main() {
    AuctionItem auction;
    int duration;

    printf("Enter auction item name: ");
    scanf("%s", auction.itemName);
    
    printf("Enter reserve price: ");
    scanf("%lf", &auction.reservePrice);

    printf("Enter auction duration in seconds: ");
    scanf("%d", &duration);

    initializeAuction(&auction, auction.itemName, auction.reservePrice, duration);

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Place a Bid\n");
        printf("2. Display Auction Details\n");
        printf("3. Check Auction Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                placeBid(&auction);
                break;
            case 2:
                displayAuctionDetails(&auction);
                break;
            case 3:
                auctionStatus(&auction);
                break;
            case 4:
                printf("Exiting the auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        };
    }

    return 0;
}