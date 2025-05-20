//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 100
#define MAX_BIDDERS 50
#define MAX_NAME_LENGTH 100

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    double startingBid;
    double highestBid;
    char highestBidder[MAX_NAME_LENGTH];
    int auctionActive;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount < MAX_AUCTIONS) {
        Auction newAuction;

        printf("Enter the item name for the auction: ");
        scanf(" %[^\n]s", newAuction.itemName);
        printf("Enter the starting bid: ");
        scanf("%lf", &newAuction.startingBid);
        
        newAuction.highestBid = newAuction.startingBid;
        strcpy(newAuction.highestBidder, "None");
        newAuction.auctionActive = 1;

        auctions[auctionCount++] = newAuction;
        printf("Auction for '%s' created successfully!\n", newAuction.itemName);
    } else {
        printf("Maximum auctions reached.\n");
    }
}

void placeBid() {
    int auctionId, validBid = 0;
    double bidAmount;
    char bidderName[MAX_NAME_LENGTH];

    printf("Enter auction ID (0 to %d): ", auctionCount - 1);
    scanf("%d", &auctionId);

    if (auctionId < 0 || auctionId >= auctionCount || !auctions[auctionId].auctionActive) {
        printf("Invalid auction ID or auction is not active.\n");
        return;
    }

    printf("Enter your name: ");
    scanf(" %[^\n]s", bidderName);
    printf("Enter your bid amount: ");
    scanf("%lf", &bidAmount);

    if (bidAmount > auctions[auctionId].highestBid) {
        auctions[auctionId].highestBid = bidAmount;
        strcpy(auctions[auctionId].highestBidder, bidderName);
        validBid = 1;
        printf("Bid placed successfully!\n");
    } else {
        printf("Your bid must be higher than the current highest bid of %.2f.\n", auctions[auctionId].highestBid);
    }

    if (validBid) {
        printf("Auction Status: Highest Bid: %.2f by %s\n", auctions[auctionId].highestBid, auctions[auctionId].highestBidder);
    }
}

void closeAuction() {
    int auctionId;
    
    printf("Enter auction ID to close (0 to %d): ", auctionCount - 1);
    scanf("%d", &auctionId);

    if (auctionId < 0 || auctionId >= auctionCount || !auctions[auctionId].auctionActive) {
        printf("Invalid auction ID or auction is already closed.\n");
        return;
    }

    auctions[auctionId].auctionActive = 0;
    printf("Auction for '%s' closed. Winner: %s with bid of %.2f\n", 
           auctions[auctionId].itemName, 
           auctions[auctionId].highestBidder, 
           auctions[auctionId].highestBid);
}

void displayAuctions() {
    for (int i = 0; i < auctionCount; i++) {
        printf("Auction ID: %d | Item: %s | Starting Bid: %.2f | Current Highest Bid: %.2f | Highest Bidder: %s | Status: %s\n",
               i, auctions[i].itemName, auctions[i].startingBid,
               auctions[i].highestBid, auctions[i].highestBidder,
               auctions[i].auctionActive ? "Active" : "Closed");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Digital Auction System ===\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. Close Auction\n");
        printf("4. Display Auctions\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAuction();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                closeAuction();
                break;
            case 4:
                displayAuctions();
                break;
            case 5:
                printf("Exiting the Auction System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}