//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_AUCTIONS 10
#define ITEM_NAME_LEN 50
#define BIDDER_NAME_LEN 50

typedef struct {
    char itemName[ITEM_NAME_LEN];
    float startPrice;
    float currentPrice;
    char highestBidder[BIDDER_NAME_LEN];
} AuctionItem;

typedef struct {
    char name[BIDDER_NAME_LEN];
    float bidAmount;
} Bidder;

AuctionItem auctions[MAX_AUCTIONS];
Bidder bidders[MAX_BIDDERS];
int auctionCount = 0;
int bidderCount = 0;

void registerBidder() {
    if (bidderCount >= MAX_BIDDERS) {
        printf("Maximum bidder limit reached.\n");
        return;
    }
    printf("Enter bidder name: ");
    scanf("%s", bidders[bidderCount].name);
    bidders[bidderCount].bidAmount = 0.0;
    bidderCount++;
    printf("Bidder %s registered successfully!\n", bidders[bidderCount - 1].name);
}

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum auction limit reached.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", auctions[auctionCount].itemName);
    printf("Enter starting price: ");
    scanf("%f", &auctions[auctionCount].startPrice);
    auctions[auctionCount].currentPrice = auctions[auctionCount].startPrice;
    strcpy(auctions[auctionCount].highestBidder, "None");
    auctionCount++;
    printf("Auction for %s created with starting price $%.2f!\n", 
           auctions[auctionCount - 1].itemName, auctions[auctionCount - 1].startPrice);
}

void placeBid() {
    char bidderName[BIDDER_NAME_LEN];
    float bidAmount;
    
    printf("Enter your name: ");
    scanf("%s", bidderName);
    
    printf("Enter bid amount: ");
    scanf("%f", &bidAmount);
    
    for (int i = 0; i < auctionCount; i++) {
        printf("Bidding for %s (Current Price: $%.2f)\n", auctions[i].itemName, auctions[i].currentPrice);
        if (bidAmount > auctions[i].currentPrice) {
            auctions[i].currentPrice = bidAmount;
            strcpy(auctions[i].highestBidder, bidderName);
            printf("Bid accepted! You are now the highest bidder for %s with a bid of $%.2f!\n", 
                   auctions[i].itemName, bidAmount);
            return;
        }
    }
    
    printf("Bid rejected! The bid must be higher than the current price.\n");
}

void viewAuctions() {
    printf("\nCurrent Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        printf("Item: %s, Current Price: $%.2f, Highest Bidder: %s\n", 
               auctions[i].itemName, auctions[i].currentPrice, auctions[i].highestBidder);
    }
}

void digitalAuctionSystem() {
    int choice;
    
    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Register Bidder\n");
        printf("2. Create Auction\n");
        printf("3. Place Bid\n");
        printf("4. View Auctions\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerBidder();
                break;
            case 2:
                createAuction();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                viewAuctions();
                break;
            case 5:
                printf("Exiting the Auction System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
}

int main() {
    digitalAuctionSystem();
    return 0;
}