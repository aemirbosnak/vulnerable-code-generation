//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50
#define USER_NAME_LENGTH 50

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    char highestBidder[USER_NAME_LENGTH];
    float highestBid;
    int auctionActive;
} AuctionItem;

AuctionItem auctionItems[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Max items reached.\n");
        return;
    }

    AuctionItem newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.itemName);
    newItem.highestBidder[0] = '\0';
    newItem.highestBid = 0.0;
    newItem.auctionActive = 1; // Set auction as active

    auctionItems[itemCount++] = newItem;
    printf("Item '%s' added for auction.\n", newItem.itemName);
}

void bidOnItem() {
    char itemName[ITEM_NAME_LENGTH];
    float bidAmount;
    
    printf("Enter item name to bid on: ");
    scanf("%s", itemName);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(auctionItems[i].itemName, itemName) == 0) {
            if (!auctionItems[i].auctionActive) {
                printf("This auction has ended.\n");
                return;
            }
            if (bidAmount > auctionItems[i].highestBid) {
                printf("Congratulations! You are the highest bidder for '%s'.\n", auctionItems[i].itemName);
                auctionItems[i].highestBid = bidAmount;
                printf("Previous highest bid was %.2f by %s\n", auctionItems[i].highestBid, auctionItems[i].highestBidder);
                printf("Enter your name: ");
                scanf("%s", auctionItems[i].highestBidder);
            } else {
                printf("Your bid is too low. Current highest bid is %.2f by %s.\n", auctionItems[i].highestBid, auctionItems[i].highestBidder);
            }
            return;
        }
    }
    printf("Item '%s' not found.\n", itemName);
}

void viewItems() {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s\n", auctionItems[i].itemName);
        if (auctionItems[i].auctionActive) {
            printf("Current highest bid: %.2f by %s\n\n", auctionItems[i].highestBid, auctionItems[i].highestBidder[0] ? auctionItems[i].highestBidder : "None");
        } else {
            printf("Auction has ended. Highest bid: %.2f by %s\n\n", auctionItems[i].highestBid, auctionItems[i].highestBidder);
        }
    }
}

void endAuction() {
    char itemName[ITEM_NAME_LENGTH];
    printf("Enter item name to end auction: ");
    scanf("%s", itemName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(auctionItems[i].itemName, itemName) == 0) {
            auctionItems[i].auctionActive = 0; // Mark auction as inactive
            printf("Auction for '%s' has ended.\n", auctionItems[i].itemName);
            return;
        }
    }
    printf("Item '%s' not found.\n", itemName);
}

int main() {
    int choice;

    do {
        printf("\nDigital Auction System\n");
        printf("1. Add Item\n");
        printf("2. Bid on Item\n");
        printf("3. View Items\n");
        printf("4. End Auction\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: bidOnItem(); break;
            case 3: viewItems(); break;
            case 4: endAuction(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}