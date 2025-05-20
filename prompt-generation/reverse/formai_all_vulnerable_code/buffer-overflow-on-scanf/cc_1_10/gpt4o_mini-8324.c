//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 50
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float bidAmount;
} Bidder;

typedef struct {
    char itemName[NAME_LENGTH];
    float startingPrice;
    float highestBid;
    Bidder highestBidder;
    int isActive;
} AuctionItem;

AuctionItem auctionItems[MAX_ITEMS];
int auctionCount = 0;

// Function Prototypes
void registerAuctionItem();
void placeBid();
void checkHighestBid();
void pauseAuction();
void resumeAuction();
void endAuction();
void displayMenu();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: registerAuctionItem(); break;
            case 2: placeBid(); break;
            case 3: checkHighestBid(); break;
            case 4: pauseAuction(); break;
            case 5: resumeAuction(); break;
            case 6: endAuction(); break;
            case 0: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nDigital Auction System\n");
    printf("1. Register Auction Item\n");
    printf("2. Place Bid\n");
    printf("3. Check Highest Bid\n");
    printf("4. Pause Auction\n");
    printf("5. Resume Auction\n");
    printf("6. End Auction\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void registerAuctionItem() {
    if (auctionCount >= MAX_ITEMS) {
        printf("Maximum auction items reached.\n");
        return;
    }
    
    AuctionItem newItem;
    printf("Enter item name: ");
    fgets(newItem.itemName, NAME_LENGTH, stdin);
    newItem.itemName[strcspn(newItem.itemName, "\n")] = 0; // Remove newline character
    printf("Enter starting price: ");
    scanf("%f", &newItem.startingPrice);
    clearInputBuffer();

    newItem.highestBid = newItem.startingPrice;
    strcpy(newItem.highestBidder.name, "None");
    newItem.highestBidder.bidAmount = 0;
    newItem.isActive = 1;

    auctionItems[auctionCount++] = newItem;
    printf("Auction item '%s' registered successfully!\n", newItem.itemName);
}

void placeBid() {
    char bidderName[NAME_LENGTH];
    float bidAmount;
    int itemIndex;

    if (auctionCount == 0) {
        printf("No auction items available.\n");
        return;
    }

    printf("Enter your name: ");
    fgets(bidderName, NAME_LENGTH, stdin);
    bidderName[strcspn(bidderName, "\n")] = 0; // Remove newline character
    
    printf("Enter auction item index (0 to %d): ", auctionCount - 1);
    scanf("%d", &itemIndex);
    clearInputBuffer();

    if (itemIndex < 0 || itemIndex >= auctionCount) {
        printf("Invalid item index.\n");
        return;
    }

    AuctionItem *item = &auctionItems[itemIndex];

    if (!item->isActive) {
        printf("This auction item is not active.\n");
        return;
    }

    printf("Enter your bid amount (must be higher than %.2f): ", item->highestBid);
    scanf("%f", &bidAmount);
    clearInputBuffer();

    if (bidAmount <= item->highestBid) {
        printf("Bid rejected! Must be higher than the current highest bid.\n");
    } else {
        item->highestBid = bidAmount;
        strcpy(item->highestBidder.name, bidderName);
        item->highestBidder.bidAmount = bidAmount;
        printf("Bid of %.2f placed successfully by %s!\n", bidAmount, bidderName);
    }
}

void checkHighestBid() {
    int itemIndex;

    if (auctionCount == 0) {
        printf("No auction items available.\n");
        return;
    }

    printf("Enter auction item index (0 to %d): ", auctionCount - 1);
    scanf("%d", &itemIndex);
    clearInputBuffer();

    if (itemIndex < 0 || itemIndex >= auctionCount) {
        printf("Invalid item index.\n");
        return;
    }

    AuctionItem *item = &auctionItems[itemIndex];

    if (!item->isActive) {
        printf("This auction item is not active.\n");
    } else {
        printf("Highest bid for '%s' is %.2f by %s.\n", item->itemName, item->highestBid, item->highestBidder.name);
    }
}

void pauseAuction() {
    int itemIndex;

    if (auctionCount == 0) {
        printf("No auction items available.\n");
        return;
    }

    printf("Enter auction item index (0 to %d): ", auctionCount - 1);
    scanf("%d", &itemIndex);
    clearInputBuffer();

    if (itemIndex < 0 || itemIndex >= auctionCount) {
        printf("Invalid item index.\n");
    } else {
        AuctionItem *item = &auctionItems[itemIndex];
        item->isActive = 0;
        printf("Auction for '%s' has been paused.\n", item->itemName);
    }
}

void resumeAuction() {
    int itemIndex;

    if (auctionCount == 0) {
        printf("No auction items available.\n");
        return;
    }

    printf("Enter auction item index (0 to %d): ", auctionCount - 1);
    scanf("%d", &itemIndex);
    clearInputBuffer();

    if (itemIndex < 0 || itemIndex >= auctionCount) {
        printf("Invalid item index.\n");
    } else {
        AuctionItem *item = &auctionItems[itemIndex];
        item->isActive = 1;
        printf("Auction for '%s' has been resumed.\n", item->itemName);
    }
}

void endAuction() {
    int itemIndex;

    if (auctionCount == 0) {
        printf("No auction items available.\n");
        return;
    }

    printf("Enter auction item index (0 to %d): ", auctionCount - 1);
    scanf("%d", &itemIndex);
    clearInputBuffer();

    if (itemIndex < 0 || itemIndex >= auctionCount) {
        printf("Invalid item index.\n");
    } else {
        AuctionItem *item = &auctionItems[itemIndex];
        item->isActive = 0;
        printf("Auction for '%s' has ended. Final bid: %.2f by %s.\n", item->itemName, item->highestBid, 
               strcmp(item->highestBidder.name, "None") == 0 ? "No bids" : item->highestBidder.name);
    }
}