//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_AUCTIONS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float bidPrice;
} Bidder;

typedef struct {
    char itemName[NAME_LENGTH];
    float startingPrice;
    float currentPrice;
    Bidder highestBidder;
    int isActive;
    time_t endTime;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached!\n");
        return;
    }
    
    Auction newAuction;
    printf("Enter the item name for the auction: ");
    scanf("%s", newAuction.itemName);
    printf("Enter the starting price: ");
    scanf("%f", &newAuction.startingPrice);
    
    newAuction.currentPrice = newAuction.startingPrice;
    newAuction.isActive = 1;
    newAuction.highestBidder.bidPrice = 0;
    auctionCount++;
    
    // Set auction end time to 5 minutes from now
    newAuction.endTime = time(NULL) + 300;
    auctions[auctionCount - 1] = newAuction;
    
    printf("Auction for '%s' created with starting price %.2f.\n", 
           newAuction.itemName, newAuction.startingPrice);
}

void placeBid() {
    char bidderName[NAME_LENGTH];
    float bidAmount;
    
    printf("Enter your name: ");
    scanf("%s", bidderName);
    
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    
    for (int i = 0; i < auctionCount; i++) {
        Auction *auc = &auctions[i];
        if (auc->isActive) {
            if (time(NULL) < auc->endTime) {
                if (bidAmount > auc->currentPrice) {
                    strcpy(auc->highestBidder.name, bidderName);
                    auc->highestBidder.bidPrice = bidAmount;
                    auc->currentPrice = bidAmount;
                    printf("Bid of %.2f accepted for '%s' by %s!\n", 
                           bidAmount, auc->itemName, bidderName);
                } else {
                    printf("Bid must be higher than the current price (%.2f).\n", 
                           auc->currentPrice);
                }
            } else {
                auc->isActive = 0;
                printf("Auction for '%s' has ended.\n", auc->itemName);
            }
        }
    }
}

void displayAuctions() {
    printf("\nCurrent Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        Auction *auc = &auctions[i];
        if (auc->isActive) {
            printf("Item: %s | Current Price: %.2f | Highest Bidder: %s (%.2f)\n",
                   auc->itemName, auc->currentPrice, auc->highestBidder.name, 
                   auc->highestBidder.bidPrice);
        }
    }
}

void endAuctions() {
    for (int i = 0; i < auctionCount; i++) {
        Auction *auc = &auctions[i];
        if (time(NULL) >= auc->endTime && auc->isActive) {
            auc->isActive = 0;
            if (auc->highestBidder.bidPrice > 0) {
                printf("Auction for '%s' has ended. Highest bidder: %s for %.2f!\n",
                       auc->itemName, auc->highestBidder.name, 
                       auc->highestBidder.bidPrice);
            } else {
                printf("Auction for '%s' has ended. No bids were placed.\n", 
                       auc->itemName);
            }
        }
    }
}

int main() {
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
                endAuctions();
                displayAuctions();
                break;
            case 4:
                printf("Exiting the auction system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        endAuctions(); // Check if any auctions ended after each operation
    }

    return 0;
}