//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 50
#define ITEM_NAME_LENGTH 50
#define BIDDER_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float basePrice;
    float currentPrice;
    int highestBidder;
    int auctionActive;
    time_t auctionEndTime;
} Item;

typedef struct {
    char name[BIDDER_NAME_LENGTH];
    float currentBid;
} Bidder;

Item auctionItems[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int itemCount = 0;
int bidderCount = 0;

// Function prototypes
void addAuctionItem(char *name, float basePrice);
void registerBidder(char *name);
void placeBid(int itemIndex, int bidderIndex, float bidAmount);
void displayItems();
void displayBidders();
void checkAuctionStatus();

int main() {
    int choice, itemIndex, bidderIndex;
    float bidAmount;
    char name[ITEM_NAME_LENGTH];

    printf("Welcome to the Digital Auction System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Auction Item\n");
        printf("2. Register Bidder\n");
        printf("3. Place Bid\n");
        printf("4. Display Auction Items\n");
        printf("5. Display Bidders\n");
        printf("6. Check Auction Status\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Item Name: ");
                scanf(" %49[^\n]", name);
                printf("Enter Base Price: ");
                float basePrice;
                scanf("%f", &basePrice);
                addAuctionItem(name, basePrice);
                break;
            case 2:
                printf("Enter Bidder Name: ");
                scanf(" %49[^\n]", name);
                registerBidder(name);
                break;
            case 3:
                displayItems();
                printf("Select item index to bid on: ");
                scanf("%d", &itemIndex);
                displayBidders();
                printf("Select bidder index to place bid: ");
                scanf("%d", &bidderIndex);
                printf("Enter Bid Amount: ");
                scanf("%f", &bidAmount);
                placeBid(itemIndex, bidderIndex, bidAmount);
                break;
            case 4:
                displayItems();
                break;
            case 5:
                displayBidders();
                break;
            case 6:
                checkAuctionStatus();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addAuctionItem(char *name, float basePrice) {
    if (itemCount >= MAX_ITEMS) {
        printf("Error: Maximum number of auction items reached.\n");
        return;
    }
    strcpy(auctionItems[itemCount].name, name);
    auctionItems[itemCount].basePrice = basePrice;
    auctionItems[itemCount].currentPrice = basePrice;
    auctionItems[itemCount].highestBidder = -1;
    auctionItems[itemCount].auctionActive = 1;

    // Set auction duration
    auctionItems[itemCount].auctionEndTime = time(NULL) + 3600; // 1 hour auction

    printf("Auction item '%s' added with base price %.2f.\n", name, basePrice);
    itemCount++;
}

void registerBidder(char *name) {
    if (bidderCount >= MAX_BIDDERS) {
        printf("Error: Maximum number of bidders reached.\n");
        return;
    }
    strcpy(bidders[bidderCount].name, name);
    bidders[bidderCount].currentBid = 0;

    printf("Bidder '%s' registered successfully.\n", name);
    bidderCount++;
}

void placeBid(int itemIndex, int bidderIndex, float bidAmount) {
    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item index.\n");
        return;
    }
    if (bidderIndex < 0 || bidderIndex >= bidderCount) {
        printf("Invalid bidder index.\n");
        return;
    }

    Item *item = &auctionItems[itemIndex];
    if (!item->auctionActive) {
        printf("Error: Auction for this item is closed.\n");
        return;
    }
    if (bidAmount <= item->currentPrice) {
        printf("Error: Bid must be higher than the current price (%.2f).\n", item->currentPrice);
        return;
    }

    // Accept the bid
    item->currentPrice = bidAmount;
    item->highestBidder = bidderIndex;
    printf("Bid of %.2f placed successfully by bidder '%s' on item '%s'.\n",
            bidAmount, bidders[bidderIndex].name, item->name);
}

void displayItems() {
    printf("\nAuction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        Item *item = &auctionItems[i];
        printf("Index: %d, Name: %s, Base Price: %.2f, Current Price: %.2f, Highest Bidder: %s\n",
                i, item->name, item->basePrice, item->currentPrice,
                item->highestBidder >= 0 ? bidders[item->highestBidder].name : "None");
        if (item->auctionActive) {
            printf("Auction ends in %ld seconds.\n", item->auctionEndTime - time(NULL));
        } else {
            printf("Auction closed.\n");
        }
    }
}

void displayBidders() {
    printf("\nBidders:\n");
    for (int i = 0; i < bidderCount; i++) {
        printf("Index: %d, Name: %s, Current Bid: %.2f\n",
               i, bidders[i].name, bidders[i].currentBid);
    }
}

void checkAuctionStatus() {
    time_t currentTime = time(NULL);
    for (int i = 0; i < itemCount; i++) {
        Item *item = &auctionItems[i];
        if (item->auctionActive && currentTime >= item->auctionEndTime) {
            item->auctionActive = 0;
            printf("Auction for item '%s' has ended. Final Price: %.2f, Highest Bidder: %s\n",
                   item->name, item->currentPrice,
                   item->highestBidder >= 0 ? bidders[item->highestBidder].name : "None");
        }
    }
}