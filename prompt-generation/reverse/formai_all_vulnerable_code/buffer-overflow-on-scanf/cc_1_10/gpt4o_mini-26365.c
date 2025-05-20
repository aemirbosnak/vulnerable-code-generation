//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_BIDS 10
#define ITEM_NAME_LENGTH 50
#define USER_NAME_LENGTH 50

typedef struct {
    char bidder[USER_NAME_LENGTH];
    float amount;
} Bid;

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    float startingPrice;
    Bid bids[MAX_BIDS];
    int bidCount;
} AuctionItem;

AuctionItem items[MAX_ITEMS];
int itemCount = 0;

void createAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Maximum item limit reached!\n");
        return;
    }

    AuctionItem newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.itemName);
    printf("Enter starting price: ");
    scanf("%f", &newItem.startingPrice);
    newItem.bidCount = 0;
    
    items[itemCount++] = newItem;
    printf("Auction item created successfully!\n");
}

void placeBid() {
    char itemName[ITEM_NAME_LENGTH];
    float bidAmount;

    printf("Enter the item name you want to bid on: ");
    scanf("%s", itemName);

    AuctionItem *item = NULL;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].itemName, itemName) == 0) {
            item = &items[i];
            break;
        }
    }

    if (item == NULL) {
        printf("Item not found!\n");
        return;
    }

    if (item->bidCount >= MAX_BIDS) {
        printf("Maximum bid limit reached for this item!\n");
        return;
    }

    printf("Enter your name: ");
    char bidder[USER_NAME_LENGTH];
    scanf("%s", bidder);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= item->startingPrice) {
        printf("Bid must be greater than starting price (%f)!\n", item->startingPrice);
        return;
    }

    // Check if the bid is higher than previous bids
    for (int i = 0; i < item->bidCount; i++) {
        if (item->bids[i].amount >= bidAmount) {
            printf("Your bid must be higher than the current highest bid: %f\n", item->bids[i].amount);
            return;
        }
    }

    strcpy(item->bids[item->bidCount].bidder, bidder);
    item->bids[item->bidCount].amount = bidAmount;
    item->bidCount++;
    printf("Bid placed successfully!\n");
}

void displayAuctionItems() {
    if (itemCount == 0) {
        printf("No auction items available!\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s, Starting Price: %.2f, Total Bids: %d\n",
               items[i].itemName, items[i].startingPrice, items[i].bidCount);
        
        for (int j = 0; j < items[i].bidCount; j++) {
            printf("\tBidder: %s, Bid Amount: %.2f\n", items[i].bids[j].bidder, items[i].bids[j].amount);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nDigital Auction System Menu:\n");
        printf("1. Create Auction Item\n");
        printf("2. Place a Bid\n");
        printf("3. Display Auction Items\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAuctionItem();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                displayAuctionItems();
                break;
            case 4:
                printf("Exiting the Auction System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}