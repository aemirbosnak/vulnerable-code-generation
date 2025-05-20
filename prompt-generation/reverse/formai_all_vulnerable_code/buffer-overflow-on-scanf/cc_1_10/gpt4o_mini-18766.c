//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char bidderName[MAX_NAME_LENGTH];
    double bidAmount;
} Bid;

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    double startingPrice;
    double currentPrice;
    Bid bids[MAX_BIDS];
    int bidCount;
} Auction;

void initializeAuction(Auction *auction, const char *itemName, double startingPrice) {
    strcpy(auction->itemName, itemName);
    auction->startingPrice = startingPrice;
    auction->currentPrice = startingPrice;
    auction->bidCount = 0;
}

void placeBid(Auction *auction, const char *bidderName, double bidAmount) {
    if (auction->bidCount >= MAX_BIDS) {
        printf("Maximum bids reached for this auction.\n");
        return;
    }
    if (bidAmount <= auction->currentPrice) {
        printf("Bid must be higher than the current price.\n");
        return;
    }

    Bid newBid;
    strcpy(newBid.bidderName, bidderName);
    newBid.bidAmount = bidAmount;

    auction->bids[auction->bidCount] = newBid;
    auction->currentPrice = bidAmount;
    auction->bidCount++;
    printf("Bid placed by %s for %.2f\n", bidderName, bidAmount);
}

void displayBidHistory(const Auction *auction) {
    printf("Bid History for %s:\n", auction->itemName);
    for (int i = 0; i < auction->bidCount; i++) {
        printf("Bidder: %s, Amount: %.2f\n", auction->bids[i].bidderName, auction->bids[i].bidAmount);
    }
    if (auction->bidCount == 0) {
        printf("No bids placed yet.\n");
    }
}

void displayAuctionInfo(const Auction *auction) {
    printf("Auction Item: %s\n", auction->itemName);
    printf("Starting Price: %.2f\n", auction->startingPrice);
    printf("Current Price: %.2f\n", auction->currentPrice);
}

int main() {
    Auction auction;
    
    char itemName[MAX_NAME_LENGTH];
    double startingPrice;

    printf("Enter the auction item name: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline character

    printf("Enter the starting price: ");
    scanf("%lf", &startingPrice);

    initializeAuction(&auction, itemName, startingPrice);

    int choice;
    char bidderName[MAX_NAME_LENGTH];
    double bidAmount;

    do {
        printf("\nDigital Auction System\n");
        printf("1. Display Auction Info\n");
        printf("2. Place a Bid\n");
        printf("3. Display Bid History\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAuctionInfo(&auction);
                break;
            case 2:
                printf("Enter your name: ");
                scanf("%s", bidderName);
                printf("Enter your bid amount: ");
                scanf("%lf", &bidAmount);
                placeBid(&auction, bidderName, bidAmount);
                break;
            case 3:
                displayBidHistory(&auction);
                break;
            case 0:
                printf("Exiting the auction system.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}