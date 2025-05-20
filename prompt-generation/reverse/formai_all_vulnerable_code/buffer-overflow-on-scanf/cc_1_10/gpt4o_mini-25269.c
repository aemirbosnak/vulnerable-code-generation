//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define ITEM_NAME_LENGTH 50
#define USER_NAME_LENGTH 50

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    char highestBidder[USER_NAME_LENGTH];
    float highestBid;
} AuctionItem;

typedef struct {
    char username[USER_NAME_LENGTH];
    float bidAmount;
} Bid;

AuctionItem items[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Maximum item limit reached!\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[itemCount].itemName);
    items[itemCount].highestBid = 0.0;
    strcpy(items[itemCount].highestBidder, "None");
    itemCount++;
    printf("Item '%s' added to auction.\n", items[itemCount - 1].itemName);
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items available for auction.\n");
        return;
    }

    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s, Highest Bid: %.2f by %s\n", 
                i + 1, items[i].itemName, 
                items[i].highestBid, items[i].highestBidder);
    }
    printf("\n");
}

void placeBid() {
    int itemIndex;
    Bid bids[MAX_BIDS];
    int bidCount = 0;

    printf("Enter the item number you want to bid on: ");
    scanf("%d", &itemIndex);
    itemIndex--; // Adjust for array indexing

    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item number!\n");
        return;
    }

    char currentUser[USER_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", currentUser);

    float bidAmount;
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= items[itemIndex].highestBid) {
        printf("Bid should be higher than the current highest bid of %.2f\n", items[itemIndex].highestBid);
        return;
    }

    // Update highest bid and highest bidder
    items[itemIndex].highestBid = bidAmount;
    strcpy(items[itemIndex].highestBidder, currentUser);
    printf("Bid placed successfully! You are now the highest bidder for '%s'.\n", items[itemIndex].itemName);
}

void startAuction() {
    int choice;
    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Place Bid\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                printf("Exiting auction system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option! Please select again.\n");
                break;
        }
    }
}

int main() {
    startAuction();
    return 0;
}