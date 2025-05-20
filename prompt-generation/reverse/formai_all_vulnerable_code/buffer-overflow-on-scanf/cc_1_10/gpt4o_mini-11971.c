//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_AUCTIONS 50
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float currentBid;
    int bidderId;
} Bidder;

typedef struct {
    char itemName[NAME_LENGTH];
    float startingPrice;
    float currentBid;
    int highestBidderId;
    time_t endTime;
    int isActive;
} Auction;

Auction auctions[MAX_AUCTIONS];
Bidder bidders[MAX_BIDDERS];
int auctionCount = 0;
int bidderCount = 0;

void displayAuctions() {
    printf("\nCurrent Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        if (auctions[i].isActive) {
            printf("Auction #%d: %s, Starting Price: %.2f, Current Bid: %.2f, Ends in: %ld seconds\n",
                   i + 1, 
                   auctions[i].itemName,
                   auctions[i].startingPrice,
                   auctions[i].currentBid,
                   (long)(auctions[i].endTime - time(NULL)));
        }
    }
}

void placeBid(int auctionId, int bidderId, float bidAmount) {
    if (auctionId < 0 || auctionId >= auctionCount || !auctions[auctionId].isActive) {
        printf("Invalid auction ID.\n");
        return;
    }

    if (bidAmount <= auctions[auctionId].currentBid) {
        printf("Bid amount must be higher than the current bid of %.2f.\n", auctions[auctionId].currentBid);
        return;
    }

    auctions[auctionId].currentBid = bidAmount;
    auctions[auctionId].highestBidderId = bidderId;
    printf("Bid placed successfully. Current highest bid for %s is %.2f by bidder %s.\n",
           auctions[auctionId].itemName, bidAmount, bidders[bidderId].name);
}

void createAuction(const char *itemName, float startingPrice) {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached.\n");
        return;
    }

    strcpy(auctions[auctionCount].itemName, itemName);
    auctions[auctionCount].startingPrice = startingPrice;
    auctions[auctionCount].currentBid = startingPrice;
    auctions[auctionCount].highestBidderId = -1;
    auctions[auctionCount].endTime = time(NULL) + 3600; // 1 hour later
    auctions[auctionCount].isActive = 1;
    printf("Auction for '%s' created successfully.\n", itemName);
    auctionCount++;
}

void registerBidder(const char *name) {
    if (bidderCount >= MAX_BIDDERS) {
        printf("Maximum number of bidders reached.\n");
        return;
    }

    strcpy(bidders[bidderCount].name, name);
    bidders[bidderCount].currentBid = 0.0;
    bidders[bidderCount].bidderId = bidderCount;
    printf("Bidder '%s' registered successfully with ID %d.\n", name, bidderCount);
    bidderCount++;
}

void closeAuction(int auctionId) {
    if (auctionId < 0 || auctionId >= auctionCount) {
        printf("Invalid auction ID.\n");
        return;
    }

    auctions[auctionId].isActive = 0;
    if (auctions[auctionId].highestBidderId >= 0) {
        printf("Auction for '%s' closed. Winner: %s, Final Bid: %.2f\n",
               auctions[auctionId].itemName,
               bidders[auctions[auctionId].highestBidderId].name,
               auctions[auctionId].currentBid);
    } else {
        printf("Auction for '%s' closed with no bids.\n", auctions[auctionId].itemName);
    }
}

int main() {
    int choice, auctionId, bidderId;
    float bidAmount;
    char name[NAME_LENGTH], itemName[NAME_LENGTH];

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Register Bidder\n");
        printf("2. Create Auction\n");
        printf("3. Place Bid\n");
        printf("4. Display Auctions\n");
        printf("5. Close Auction\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter bidder name: ");
                scanf("%s", name);
                registerBidder(name);
                break;
            case 2:
                printf("Enter item name for auction: ");
                scanf("%s", itemName);
                printf("Enter starting price: ");
                scanf("%f", &bidAmount);
                createAuction(itemName, bidAmount);
                break;
            case 3:
                printf("Enter auction ID: ");
                scanf("%d", &auctionId);
                printf("Enter bidder ID: ");
                scanf("%d", &bidderId);
                printf("Enter bid amount: ");
                scanf("%f", &bidAmount);
                placeBid(auctionId - 1, bidderId, bidAmount);
                break;
            case 4:
                displayAuctions();
                break;
            case 5:
                printf("Enter auction ID to close: ");
                scanf("%d", &auctionId);
                closeAuction(auctionId - 1);
                break;
            case 6:
                printf("Exiting the auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}