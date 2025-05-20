//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEM_NAME_LENGTH 100
#define MAX_BIDDERS 10
#define MAX_BID_HISTORY 100

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    float startingPrice;
    float highestBid;
    char highestBidder[MAX_ITEM_NAME_LENGTH];
    time_t auctionEndTime;
    int bidCount;
} AuctionItem;

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    float bidAmount;
} Bid;

AuctionItem auctionItem;
Bid bidHistory[MAX_BID_HISTORY];
int bidHistoryIndex = 0;

void initializeAuctionItem(char *name, float startingPrice, int auctionDurationMinutes) {
    strcpy(auctionItem.name, name);
    auctionItem.startingPrice = startingPrice;
    auctionItem.highestBid = startingPrice;
    strcpy(auctionItem.highestBidder, "None");
    auctionItem.auctionEndTime = time(NULL) + (auctionDurationMinutes * 60);
    auctionItem.bidCount = 0;
}

void displayAuctionDetails() {
    printf("Auction Item: %s\n", auctionItem.name);
    printf("Starting Price: $%.2f\n", auctionItem.startingPrice);
    printf("Highest Bid: $%.2f by %s\n", auctionItem.highestBid, auctionItem.highestBidder);
    printf("Auction ends in: %ld seconds\n", auctionItem.auctionEndTime - time(NULL));
}

int isAuctionActive() {
    return time(NULL) < auctionItem.auctionEndTime;
}

void placeBid(char *bidderName, float bidAmount) {
    if (!isAuctionActive()) {
        printf("Auction has ended. You cannot place new bids.\n");
        return;
    }

    if (bidAmount <= auctionItem.highestBid) {
        printf("Bid of $%.2f is too low. Current highest bid is $%.2f.\n", bidAmount, auctionItem.highestBid);
        return;
    }

    auctionItem.highestBid = bidAmount;
    strcpy(auctionItem.highestBidder, bidderName);
    auctionItem.bidCount++;
    
    printf("%s placed a bid of $%.2f.\n", bidderName, bidAmount);

    // Store bid history
    if (bidHistoryIndex < MAX_BID_HISTORY) {
        strcpy(bidHistory[bidHistoryIndex].name, bidderName);
        bidHistory[bidHistoryIndex].bidAmount = bidAmount;
        bidHistoryIndex++;
    } else {
        printf("Bid history is full.\n");
    }
}

void displayBidHistory() {
    printf("Bid History:\n");
    for (int i = 0; i < bidHistoryIndex; i++) {
        printf("%s bid $%.2f\n", bidHistory[i].name, bidHistory[i].bidAmount);
    }
}

void finalizeAuction() {
    printf("Auction has ended...\n");
    printf("Final Highest Bid: $%.2f by %s.\n", auctionItem.highestBid, auctionItem.highestBidder);
}

int main() {
    char itemName[MAX_ITEM_NAME_LENGTH];
    float startingPrice;
    int auctionDurationMinutes;

    printf("Enter item name: ");
    fgets(itemName, MAX_ITEM_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline

    printf("Enter starting price (e.g., 100.00): ");
    scanf("%f", &startingPrice);

    printf("Enter auction duration (in minutes): ");
    scanf("%d", &auctionDurationMinutes);
    
    initializeAuctionItem(itemName, startingPrice, auctionDurationMinutes);

    while (isAuctionActive()) {
        displayAuctionDetails();
        
        char bidderName[MAX_ITEM_NAME_LENGTH];
        float bidAmount;

        printf("Enter your name: ");
        scanf("%s", bidderName);
        
        printf("Enter your bid amount: ");
        scanf("%f", &bidAmount);
        
        placeBid(bidderName, bidAmount);
    }

    finalizeAuction();
    displayBidHistory();

    return 0;
}