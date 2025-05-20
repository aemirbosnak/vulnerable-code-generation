//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define ITEM_NAME_LENGTH 50
#define USER_NAME_LENGTH 50

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    double startingPrice;
    double currentHighestBid;
    char highestBidder[USER_NAME_LENGTH];
    time_t endTime;
    int bidsCount;
} Item;

typedef struct {
    char bidderName[USER_NAME_LENGTH];
    double bidAmount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int itemCount = 0;

void addItem(char* name, double price, int duration) {
    if (itemCount >= MAX_ITEMS) {
        printf("Cannot add more items. Maximum item limit reached.\n");
        return;
    }
    strcpy(items[itemCount].itemName, name);
    items[itemCount].startingPrice = price;
    items[itemCount].currentHighestBid = price;
    strcpy(items[itemCount].highestBidder, "None");
    items[itemCount].endTime = time(NULL) + duration;
    items[itemCount].bidsCount = 0;
    itemCount++;
    printf("Item \"%s\" added with a starting price of $%.2f.\n", name, price);
}

void displayItems() {
    printf("\nAvailable Items for Auction:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s\n", i + 1, items[i].itemName);
        printf("  Starting Price: $%.2f\n", items[i].startingPrice);
        printf("  Current Highest Bid: $%.2f by %s\n", 
            items[i].currentHighestBid, items[i].highestBidder);
        printf("  Auction ends in: %ld seconds\n", (long)(items[i].endTime - time(NULL)));
    }
}

int placeBid(int itemIndex, char* bidder, double amount) {
    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item index.\n");
        return -1;
    }

    if (time(NULL) > items[itemIndex].endTime) {
        printf("Auction for %s has already ended.\n", items[itemIndex].itemName);
        return -1;
    }

    if (amount <= items[itemIndex].currentHighestBid) {
        printf("Bid amount must be higher than the current highest bid.\n");
        return -1;
    }

    strcpy(bids[items[itemIndex].bidsCount].bidderName, bidder);
    bids[items[itemIndex].bidsCount].bidAmount = amount;
    
    items[itemIndex].currentHighestBid = amount;
    strcpy(items[itemIndex].highestBidder, bidder);
    items[itemIndex].bidsCount++;
    
    printf("Bid placed successfully by %s for item %s: $%.2f\n", bidder, 
        items[itemIndex].itemName, amount);
    return 0;
}

void closeAuction() {
    for (int i = 0; i < itemCount; i++) {
        if (time(NULL) > items[i].endTime) {
            printf("Auction for %s has ended.\n", items[i].itemName);
            if (strcmp(items[i].highestBidder, "None") == 0) {
                printf("No bids placed.\n");
            } else {
                printf("Winner: %s with a bid of $%.2f\n",
                    items[i].highestBidder, items[i].currentHighestBid);
            }
        }
    }
}

int main() {
    int choice;
    char itemName[ITEM_NAME_LENGTH];
    double startingPrice;
    int auctionDuration;
    
    while (1) {
        printf("\nDigital Auction System Menu:\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Place Bid\n");
        printf("4. Close Auction\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf(" %[^\n]", itemName);
                printf("Enter starting price: ");
                scanf("%lf", &startingPrice);
                printf("Enter auction duration (in seconds): ");
                scanf("%d", &auctionDuration);
                addItem(itemName, startingPrice, auctionDuration);
                break;
            case 2:
                displayItems();
                break;
            case 3: {
                int itemIndex;
                char bidder[USER_NAME_LENGTH];
                double bidAmount;
                printf("Enter item index to bid on: ");
                scanf("%d", &itemIndex);
                itemIndex--; // converting to 0-based index
                printf("Enter your name: ");
                scanf(" %[^\n]", bidder);
                printf("Enter your bid amount: ");
                scanf("%lf", &bidAmount);
                placeBid(itemIndex, bidder, bidAmount);
                break;
            }
            case 4:
                closeAuction();
                break;
            case 5:
                printf("Exiting the auction system.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}