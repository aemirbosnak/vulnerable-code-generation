//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 100
#define MAX_BIDS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char bidderName[MAX_NAME_LENGTH];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    char auctioneerName[MAX_NAME_LENGTH];
    float startingPrice;
    float currentPrice;
    Bid bids[MAX_BIDS];
    int bidCount;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum auction limit reached.\n");
        return;
    }
    
    Auction newAuction;
    printf("Enter item name: ");
    scanf("%s", newAuction.itemName);
    printf("Enter auctioneer name: ");
    scanf("%s", newAuction.auctioneerName);
    printf("Enter starting price: ");
    scanf("%f", &newAuction.startingPrice);
    
    newAuction.currentPrice = newAuction.startingPrice;
    newAuction.bidCount = 0;
    
    auctions[auctionCount++] = newAuction;
    printf("Auction for %s created successfully!\n", newAuction.itemName);
}

void placeBid() {
    char itemName[MAX_NAME_LENGTH];
    printf("Enter item name to bid on: ");
    scanf("%s", itemName);
    
    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].itemName, itemName) == 0) {
            Bid newBid;
            printf("Enter your name: ");
            scanf("%s", newBid.bidderName);
            printf("Enter bid amount: ");
            scanf("%f", &newBid.bidAmount);
            
            if (newBid.bidAmount <= auctions[i].currentPrice) {
                printf("Bid amount must be higher than the current price: %.2f\n", auctions[i].currentPrice);
                return;
            }
            
            auctions[i].bids[auctions[i].bidCount++] = newBid;
            auctions[i].currentPrice = newBid.bidAmount;
            printf("Bid placed successfully! Current price is now: %.2f\n", auctions[i].currentPrice);
            return;
        }
    }
    printf("Auction for item %s not found.\n", itemName);
}

void viewAuctionDetails() {
    char itemName[MAX_NAME_LENGTH];
    printf("Enter item name to view details: ");
    scanf("%s", itemName);
    
    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].itemName, itemName) == 0) {
            printf("Item Name: %s\n", auctions[i].itemName);
            printf("Auctioneer: %s\n", auctions[i].auctioneerName);
            printf("Starting Price: %.2f\n", auctions[i].startingPrice);
            printf("Current Price: %.2f\n", auctions[i].currentPrice);
            printf("Number of Bids: %d\n", auctions[i].bidCount);
            for (int j = 0; j < auctions[i].bidCount; j++) {
                printf("Bidder: %s, Amount: %.2f\n", auctions[i].bids[j].bidderName, auctions[i].bids[j].bidAmount);
            }
            return;
        }
    }
    printf("Auction for item %s not found.\n", itemName);
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
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}