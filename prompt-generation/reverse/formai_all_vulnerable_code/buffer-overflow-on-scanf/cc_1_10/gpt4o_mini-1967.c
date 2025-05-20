//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 100
#define MAX_AUCTIONS 10
#define NAME_LEN 50

typedef struct {
    char itemName[NAME_LEN];
    double startingPrice;
    double currentHighestBid;
    char highestBidder[NAME_LEN];
} Auction;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum auction limit reached!\n");
        return;
    }
    
    Auction newAuction;
    printf("Enter item name: ");
    scanf(" %[^\n]", newAuction.itemName);
    printf("Enter starting price: ");
    scanf("%lf", &newAuction.startingPrice);
    
    newAuction.currentHighestBid = newAuction.startingPrice;
    strcpy(newAuction.highestBidder, "No bids yet");

    auctions[auctionCount++] = newAuction;
    printf("Auction for '%s' created successfully!\n", newAuction.itemName);
}

void placeBid() {
    char bidderName[NAME_LEN];
    int auctionIndex;

    printf("Enter bidder name: ");
    scanf(" %[^\n]", bidderName);
    
    printf("Select auction index (0 to %d): ", auctionCount - 1);
    scanf("%d", &auctionIndex);
    
    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Invalid auction index!\n");
        return;
    }

    double bidAmount;
    printf("Enter bid amount: ");
    scanf("%lf", &bidAmount);
    
    if (bidAmount > auctions[auctionIndex].currentHighestBid) {
        auctions[auctionIndex].currentHighestBid = bidAmount;
        strcpy(auctions[auctionIndex].highestBidder, bidderName);
        printf("Bid placed successfully!\n");
    } else {
        printf("Bid amount must be higher than the current highest bid of %.2lf!\n", auctions[auctionIndex].currentHighestBid);
    }
}

void displayAuctions() {
    if (auctionCount == 0) {
        printf("No auctions available!\n");
        return;
    }
    
    for (int i = 0; i < auctionCount; i++) {
        Auction auction = auctions[i];
        printf("Auction #%d: Item: %s, Starting Price: %.2lf, Current Highest Bid: %.2lf, Highest Bidder: %s\n",
               i, auction.itemName, auction.startingPrice, auction.currentHighestBid, auction.highestBidder);
    }
}

void menu() {
    int choice;

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. Display Auctions\n");
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
                displayAuctions();
                break;
            case 4:
                printf("Exiting the auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}