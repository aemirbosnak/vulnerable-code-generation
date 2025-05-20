//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 100
#define MAX_BIDS 100

typedef struct {
    char bidderName[50];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[50];
    float startingPrice;
    float currentHighestBid;
    char highestBidder[50];
    int bidCount;
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
    
    newAuction.currentHighestBid = newAuction.startingPrice;
    strcpy(newAuction.highestBidder, "None");
    newAuction.bidCount = 0;
    
    auctions[auctionCount] = newAuction;
    auctionCount++;
    
    printf("Auction for '%s' created successfully!\n", newAuction.itemName);
}

void placeBid() {
    char itemName[50];
    printf("Enter item name to bid on: ");
    scanf("%s", itemName);
    int i;
    
    for (i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].itemName, itemName) == 0) {
            Bid newBid;
            printf("Enter bidder name: ");
            scanf("%s", newBid.bidderName);
            printf("Enter bid amount: ");
            scanf("%f", &newBid.bidAmount);
            
            if (newBid.bidAmount > auctions[i].currentHighestBid) {
                auctions[i].currentHighestBid = newBid.bidAmount;
                strcpy(auctions[i].highestBidder, newBid.bidderName);
                auctions[i].bids[auctions[i].bidCount] = newBid;
                auctions[i].bidCount++;
                printf("Bid placed successfully!\n");
            } else {
                printf("Bid amount must be higher than the current highest bid.\n");
            }
            return;
        }
    }
    printf("Auction for '%s' not found.\n", itemName);
}

void viewAuctionDetails() {
    char itemName[50];
    printf("Enter item name to view details: ");
    scanf("%s", itemName);
    
    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].itemName, itemName) == 0) {
            printf("Auction Details for '%s':\n", auctions[i].itemName);
            printf("Starting Price: %.2f\n", auctions[i].startingPrice);
            printf("Current Highest Bid: %.2f by %s\n", auctions[i].currentHighestBid, auctions[i].highestBidder);
            printf("Total Bids: %d\n", auctions[i].bidCount);
            for (int j = 0; j < auctions[i].bidCount; j++) {
                printf("Bid %d: %s - %.2f\n", j + 1, auctions[i].bids[j].bidderName, auctions[i].bids[j].bidAmount);
            }
            return;
        }
    }
    printf("Auction for '%s' not found.\n", itemName);
}

void displayMenu() {
    printf("Digital Auction System\n");
    printf("1. Create Auction\n");
    printf("2. Place Bid\n");
    printf("3. View Auction Details\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
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
                printf("Exiting the auction system.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}