//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 100
#define NAME_LENGTH 100

typedef struct {
    char bidderName[NAME_LENGTH];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[NAME_LENGTH];
    float startingPrice;
    float currentPrice;
    int numberOfBids;
    Bid bids[MAX_BIDS];
} Auction;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached.\n");
        return;
    }

    Auction newAuction;
    printf("Enter item name: ");
    scanf("%s", newAuction.itemName);
    printf("Enter starting price: ");
    scanf("%f", &newAuction.startingPrice);
    
    newAuction.currentPrice = newAuction.startingPrice;
    newAuction.numberOfBids = 0;
    auctions[auctionCount] = newAuction;
    auctionCount++;
    
    printf("Auction for '%s' created with starting price of %.2f\n", newAuction.itemName, newAuction.startingPrice);
}

void placeBid() {
    if (auctionCount == 0) {
        printf("No auctions available.\n");
        return;
    }

    int auctionIndex;
    printf("Available Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        printf("%d. %s | Current Price: %.2f\n", i + 1, auctions[i].itemName, auctions[i].currentPrice);
    }

    printf("Select auction number to place a bid: ");
    scanf("%d", &auctionIndex);
    auctionIndex--; // Convert to zero-based index

    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Invalid auction number.\n");
        return;
    }

    float bidAmount;
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    
    if (bidAmount <= auctions[auctionIndex].currentPrice) {
        printf("Bid must be higher than the current price of %.2f.\n", auctions[auctionIndex].currentPrice);
        return;
    }
    
    Bid newBid;
    printf("Enter your name: ");
    scanf("%s", newBid.bidderName);
    newBid.bidAmount = bidAmount;

    auctions[auctionIndex].bids[auctions[auctionIndex].numberOfBids] = newBid;
    auctions[auctionIndex].numberOfBids++;
    auctions[auctionIndex].currentPrice = bidAmount;

    printf("Bid placed by %s: %.2f for '%s'\n", newBid.bidderName, bidAmount, auctions[auctionIndex].itemName);
}

void viewAuctionDetails() {
    if (auctionCount == 0) {
        printf("No auctions available.\n");
        return;
    }

    int auctionIndex;
    printf("Available Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        printf("%d. %s\n", i + 1, auctions[i].itemName);
    }

    printf("Select auction number to view details: ");
    scanf("%d", &auctionIndex);
    auctionIndex--; // Convert to zero-based index

    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Invalid auction number.\n");
        return;
    }

    Auction selectedAuction = auctions[auctionIndex];
    printf("Auction Details for '%s'\n", selectedAuction.itemName);
    printf("Starting Price: %.2f\n", selectedAuction.startingPrice);
    printf("Current Price: %.2f\n", selectedAuction.currentPrice);
    printf("Number of Bids: %d\n", selectedAuction.numberOfBids);
    
    if (selectedAuction.numberOfBids > 0) {
        printf("Bids:\n");
        for (int i = 0; i < selectedAuction.numberOfBids; i++) {
            printf(" - %s: %.2f\n", selectedAuction.bids[i].bidderName, selectedAuction.bids[i].bidAmount);
        }
    } else {
        printf("No bids placed yet.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. View Auction Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAuction();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                viewAuctionDetails();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}