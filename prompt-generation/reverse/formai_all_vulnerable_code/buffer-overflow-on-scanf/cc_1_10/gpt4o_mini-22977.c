//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    float startingPrice;
    float highestBid;
    char highestBidder[MAX_NAME_LENGTH];
    time_t endTime;
} AuctionItem;

typedef struct {
    char bidderName[MAX_NAME_LENGTH];
    float bidAmount;
} Bid;

AuctionItem auctionItems[MAX_ITEMS];
int itemCount = 0;

void createAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Maximum auction items reached!\n");
        return;
    }
    
    AuctionItem item;
    printf("Enter item name: ");
    scanf(" %[^\n]", item.itemName);
    
    printf("Enter starting price: ");
    scanf("%f", &item.startingPrice);
    
    item.highestBid = item.startingPrice;
    strcpy(item.highestBidder, "No bids yet");
    
    printf("Enter auction duration in seconds: ");
    int duration;
    scanf("%d", &duration);
    
    item.endTime = time(NULL) + duration;
    
    auctionItems[itemCount++] = item;
    printf("Auction created successfully for item: %s\n", item.itemName);
}

void placeBid() {
    char bidderName[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf(" %[^\n]", bidderName);
    
    int itemIndex;
    printf("Enter auction item number (0 to %d): ", itemCount - 1);
    scanf("%d", &itemIndex);
    
    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid auction item number!\n");
        return;
    }
    
    AuctionItem *item = &auctionItems[itemIndex];
    
    if (time(NULL) > item->endTime) {
        printf("Auction for %s has ended!\n", item->itemName);
        return;
    }
    
    float bidAmount;
    printf("Enter your bid amount (must be higher than %.2f): ", item->highestBid);
    scanf("%f", &bidAmount);

    if (bidAmount <= item->highestBid) {
        printf("Bid must be higher than current highest bid!\n");
        return;
    }

    item->highestBid = bidAmount;
    strcpy(item->highestBidder, bidderName);
    printf("Bid of %.2f placed by %s successfully!\n", bidAmount, bidderName);
}

void viewAuctionResults() {
    for (int i = 0; i < itemCount; i++) {
        AuctionItem item = auctionItems[i];
        printf("Auction Item %d: %s\n", i, item.itemName);
        printf("Starting Price: %.2f\n", item.startingPrice);
        printf("Highest Bid: %.2f by %s\n", item.highestBid, item.highestBidder);
        printf("Auction Ended? %s\n\n", (time(NULL) > item.endTime) ? "Yes" : "No");
    }
}

int main() {
    int choice;
    
    do {
        printf("Digital Auction System\n");
        printf("1. Create Auction Item\n");
        printf("2. Place Bid\n");
        printf("3. View Auction Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAuctionItem();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                viewAuctionResults();
                break;
            case 4:
                printf("Exiting the Auction System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}