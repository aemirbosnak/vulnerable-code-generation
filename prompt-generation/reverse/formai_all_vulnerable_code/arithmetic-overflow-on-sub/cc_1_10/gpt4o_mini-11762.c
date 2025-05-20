//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_AUCTIONS 100
#define MAX_BIDS 100
#define MAX_LEN 100

typedef struct {
    char itemName[MAX_LEN];
    float startingBid;
    float currentBid;
    char highestBidder[MAX_LEN];
    int active;
} Auction;

typedef struct {
    char bidderName[MAX_LEN];
    float bidAmount;
} Bid;

Auction auctions[MAX_AUCTIONS];
Bid bids[MAX_BIDS];
int auctionCount = 0;
int bidCount = 0;

void displayAuctions() {
    printf("\nActive Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        if (auctions[i].active) {
            printf("Auction #%d\n", i + 1);
            printf("Item: %s\n", auctions[i].itemName);
            printf("Current Bid: %.2f by %s\n", auctions[i].currentBid, auctions[i].highestBidder);
            printf("Starting Bid: %.2f\n", auctions[i].startingBid);
            printf("Status: Active\n\n");
        }
    }
}

void createAuction(char *itemName, float startingBid) {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum auctions reached.\n");
        return;
    }
    
    Auction newAuction;
    strcpy(newAuction.itemName, itemName);
    newAuction.startingBid = startingBid;
    newAuction.currentBid = startingBid;
    strcpy(newAuction.highestBidder, "None");
    newAuction.active = 1;

    auctions[auctionCount++] = newAuction;
    printf("Auction created for item: %s with starting bid %.2f\n", itemName, startingBid);
}

void placeBid(int auctionIndex, char *bidderName, float bidAmount) {
    if (auctionIndex < 0 || auctionIndex >= auctionCount || !auctions[auctionIndex].active) {
        printf("Invalid auction index.\n");
        return;
    }

    if (bidAmount <= auctions[auctionIndex].currentBid) {
        printf("Bid must be higher than the current bid of %.2f.\n", auctions[auctionIndex].currentBid);
        return;
    }

    // Record the bid
    if (bidCount < MAX_BIDS) {
        Bid newBid;
        strcpy(newBid.bidderName, bidderName);
        newBid.bidAmount = bidAmount;
        bids[bidCount++] = newBid;

        // Update auction details
        auctions[auctionIndex].currentBid = bidAmount;
        strcpy(auctions[auctionIndex].highestBidder, bidderName);
        
        printf("Bid placed successfully! New current bid: %.2f by %s\n", bidAmount, bidderName);
    } else {
        printf("Maximum bids reached.\n");
    }
}

void closeAuction(int auctionIndex) {
    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Invalid auction index.\n");
        return;
    }

    auctions[auctionIndex].active = 0;
    printf("Auction for item '%s' has been closed. Final bid was %.2f by %s.\n",
           auctions[auctionIndex].itemName, auctions[auctionIndex].currentBid, auctions[auctionIndex].highestBidder);
}

int main() {
    int choice;
    char itemName[MAX_LEN], bidderName[MAX_LEN];
    float startingBid, bidAmount;

    while (1) {
        printf("\nDigital Auction System Menu:\n");
        printf("1. Create Auction\n");
        printf("2. Display Auctions\n");
        printf("3. Place Bid\n");
        printf("4. Close Auction\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf(" %[^\n]", itemName);
                printf("Enter starting bid: ");
                scanf("%f", &startingBid);
                createAuction(itemName, startingBid);
                break;
            case 2:
                displayAuctions();
                break;
            case 3:
                printf("Enter auction index to bid on: ");
                scanf("%d", &choice);
                printf("Enter bidder name: ");
                scanf(" %[^\n]", bidderName);
                printf("Enter bid amount: ");
                scanf("%f", &bidAmount);
                placeBid(choice - 1, bidderName, bidAmount);
                break;
            case 4:
                printf("Enter auction index to close: ");
                scanf("%d", &choice);
                closeAuction(choice - 1);
                break;
            case 5:
                printf("Exiting the auction system.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}