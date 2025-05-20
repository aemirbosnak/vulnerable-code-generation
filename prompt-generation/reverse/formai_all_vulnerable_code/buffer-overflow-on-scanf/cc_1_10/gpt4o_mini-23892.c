//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 50
#define ITEM_NAME_LENGTH 30

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int currentBid;
    char highestBidder[ITEM_NAME_LENGTH];
} Item;

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int maximumBid;
} Bidder;

Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int itemCount = 0, bidderCount = 0;

void addItem(char *name) {
    if (itemCount < MAX_ITEMS) {
        strncpy(items[itemCount].name, name, ITEM_NAME_LENGTH);
        items[itemCount].currentBid = 0;
        strcpy(items[itemCount].highestBidder, "None");
        itemCount++;
        printf("Item '%s' has been added for bidding!\n", name);
    } else {
        printf("Error: Max item limit reached!\n");
    }
}

void registerBidder(char *name, int maxBid) {
    if (bidderCount < MAX_BIDDERS) {
        strncpy(bidders[bidderCount].name, name, ITEM_NAME_LENGTH);
        bidders[bidderCount].maximumBid = maxBid;
        bidderCount++;
        printf("Bidder '%s' has been registered with a maximum bid of %d!\n", name, maxBid);
    } else {
        printf("Error: Max bidder limit reached!\n");
    }
}

void placeBid(char *bidderName, char *itemName, int bidAmount) {
    int i;
    for (i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            if (bidAmount > items[i].currentBid && bidAmount <= getBidderMax(bidderName)) {
                items[i].currentBid = bidAmount;
                strncpy(items[i].highestBidder, bidderName, ITEM_NAME_LENGTH);
                printf("Bid of %d placed on item '%s' by bidder '%s'!\n", bidAmount, itemName, bidderName);
                return;
            } else {
                printf("Bid of %d is not valid for item '%s'. Current bid is %d and maximum bid is %d.\n", bidAmount, itemName, items[i].currentBid, getBidderMax(bidderName));
                return;
            }
        }
    }
    printf("Error: Item '%s' not found!\n", itemName);
}

int getBidderMax(char *bidderName) {
    for (int i = 0; i < bidderCount; i++) {
        if (strcmp(bidders[i].name, bidderName) == 0) {
            return bidders[i].maximumBid;
        }
    }
    return 0;
}

void displayItems() {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s | Current Bid: %d | Highest Bidder: %s\n", items[i].name, items[i].currentBid, items[i].highestBidder);
    }
}

void auctionMenu() {
    int choice;
    char name[ITEM_NAME_LENGTH], itemName[ITEM_NAME_LENGTH];
    int bidAmount;

    while (1) {
        printf("\n--- Digital Auction System ---\n");
        printf("1. Add Item\n2. Register Bidder\n3. Place Bid\n4. Display Items\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                addItem(name);
                break;
            case 2:
                printf("Enter bidder name: ");
                scanf("%s", name);
                printf("Enter maximum bid: ");
                scanf("%d", &bidAmount);
                registerBidder(name, bidAmount);
                break;
            case 3:
                printf("Enter bidder name: ");
                scanf("%s", name);
                printf("Enter item name for bidding: ");
                scanf("%s", itemName);
                printf("Enter bid amount: ");
                scanf("%d", &bidAmount);
                placeBid(name, itemName, bidAmount);
                break;
            case 4:
                displayItems();
                break;
            case 5:
                printf("Exiting the auction system. What a bidding experience!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again...\n");
                break;
        }
    }
}

int main() {
    auctionMenu();
    return 0;
}