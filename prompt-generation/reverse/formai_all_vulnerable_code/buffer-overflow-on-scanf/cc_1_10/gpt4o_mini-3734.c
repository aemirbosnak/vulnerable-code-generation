//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    char name[50];
    double startingPrice;
    double highestBid;
    char highestBidder[50];
} Item;

typedef struct {
    char bidderName[50];
    double amount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int itemCount = 0;
int bidCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Item limit reached!\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", items[itemCount].name);
    printf("Enter starting price: ");
    scanf("%lf", &items[itemCount].startingPrice);
    items[itemCount].highestBid = items[itemCount].startingPrice;
    strcpy(items[itemCount].highestBidder, "None");
    itemCount++;
    printf("Item added successfully!\n");
}

void placeBid() {
    char bidderName[50];
    printf("Enter your name: ");
    scanf("%s", bidderName);

    int itemIndex;
    printf("Enter item index to bid on (0 to %d): ", itemCount - 1);
    scanf("%d", &itemIndex);

    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid item index!\n");
        return;
    }

    double bidAmount;
    printf("Enter your bid amount: ");
    scanf("%lf", &bidAmount);

    if (bidAmount <= items[itemIndex].highestBid) {
        printf("Bid must be higher than the current highest bid of %.2lf\n", items[itemIndex].highestBid);
        return;
    }

    items[itemIndex].highestBid = bidAmount;
    strcpy(items[itemIndex].highestBidder, bidderName);

    bids[bidCount].amount = bidAmount;
    strcpy(bids[bidCount].bidderName, bidderName);
    bidCount++;

    printf("Bid placed successfully!\n");
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items available for auction.\n");
        return;
    }

    printf("---- Auction Items ----\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s\n", i, items[i].name);
        printf("Starting Price: %.2lf\n", items[i].startingPrice);
        printf("Highest Bid: %.2lf (by %s)\n", items[i].highestBid, items[i].highestBidder);
        printf("-----------------------\n");
    }
}

void displayBids() {
    if (bidCount == 0) {
        printf("No bids placed yet.\n");
        return;
    }

    printf("---- Bids Information ----\n");
    for (int i = 0; i < bidCount; i++) {
        printf("Bidder: %s - Amount: %.2lf\n", bids[i].bidderName, bids[i].amount);
    }
    printf("---------------------------\n");
}

int main() {
    int choice;
    do {
        printf("---- Digital Auction System ----\n");
        printf("1. Add Item\n");
        printf("2. Place Bid\n");
        printf("3. Display Items\n");
        printf("4. Display Bids\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                displayBids();
                break;
            case 5:
                printf("Exiting the auction system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}