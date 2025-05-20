//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    float startingPrice;
    float highestBid;
    char highestBidder[MAX_NAME_LEN];
    time_t endTime; // Time when the auction ends
} AuctionItem;

int itemCount = 0;
AuctionItem items[MAX_ITEMS];

void addAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Cannot add more auction items!\n");
        return;
    }

    AuctionItem newItem;
    newItem.id = itemCount + 1;

    printf("Enter item name: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter starting price: ");
    scanf("%f", &newItem.startingPrice);
    newItem.highestBid = newItem.startingPrice;
    strcpy(newItem.highestBidder, "None");

    printf("Enter auction duration in seconds: ");
    int duration;
    scanf("%d", &duration);
    newItem.endTime = time(NULL) + duration;

    items[itemCount] = newItem;
    itemCount++;
    printf("Auction item added successfully!\n");
}

void placeBid() {
    int id;
    printf("Enter item ID to bid on: ");
    scanf("%d", &id);

    if (id < 1 || id > itemCount) {
        printf("Invalid item ID!\n");
        return;
    }

    AuctionItem *item = &items[id - 1];
    if (time(NULL) > item->endTime) {
        printf("The auction for this item has ended!\n");
        return;
    }

    char bidderName[MAX_NAME_LEN];
    float bidAmount;

    printf("Enter your name: ");
    scanf(" %[^\n]", bidderName);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount > item->highestBid) {
        item->highestBid = bidAmount;
        strcpy(item->highestBidder, bidderName);
        printf("Bid placed successfully!\n");
    } else {
        printf("Your bid must be higher than the current highest bid!\n");
    }
}

void showAuctionItems() {
    printf("--------------------------------------------------\n");
    printf("ID\tName\t\tStarting Price\tHighest Bid\tHighest Bidder\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        AuctionItem item = items[i];
        printf("%d\t%s\t\t%.2f\t\t%.2f\t%s\n", 
               item.id, item.name, item.startingPrice, item.highestBid, item.highestBidder);
    }
    printf("--------------------------------------------------\n");
}

void closeAuction() {
    int id;
    printf("Enter item ID to close auction: ");
    scanf("%d", &id);

    if (id < 1 || id > itemCount) {
        printf("Invalid item ID!\n");
        return;
    }

    AuctionItem item = items[id - 1];
    if (time(NULL) <= item.endTime) {
        printf("This auction is still ongoing!\n");
        return;
    }

    printf("Auction closed for item: %s\n", item.name);
    printf("Highest Bid: %.2f by %s\n", item.highestBid, item.highestBidder);
}

int main() {
    int choice;

    do {
        printf("Digital Auction System\n");
        printf("1. Add Auction Item\n");
        printf("2. Place Bid\n");
        printf("3. Show Auction Items\n");
        printf("4. Close Auction\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addAuctionItem();
                break;
            case 2: 
                placeBid();
                break;
            case 3: 
                showAuctionItems();
                break;
            case 4: 
                closeAuction();
                break;
            case 5: 
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}