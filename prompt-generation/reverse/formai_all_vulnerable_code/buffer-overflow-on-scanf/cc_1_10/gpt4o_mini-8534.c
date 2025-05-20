//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 100
#define ITEM_NAME_LEN 50
#define BIDDER_NAME_LEN 50

struct Item {
    char name[ITEM_NAME_LEN];
    int id;
    float startingPrice;
    float highestBid;
    char highestBidder[BIDDER_NAME_LEN];
    int isActive; // 1 for active, 0 for expired
};

struct Bidder {
    char name[BIDDER_NAME_LEN];
    int id;
    int totalBids;
};

struct Item items[MAX_ITEMS];
struct Bidder bidders[MAX_BIDDERS];
int itemCount = 0;
int bidderCount = 0;

void addItem(char *name, float startingPrice) {
    if(itemCount < MAX_ITEMS) {
        struct Item newItem;
        strncpy(newItem.name, name, ITEM_NAME_LEN);
        newItem.startingPrice = startingPrice;
        newItem.highestBid = startingPrice;
        newItem.isActive = 1; // Active by default
        newItem.id = itemCount;
        items[itemCount++] = newItem; 
        printf("Item '%s' added with ID %d at starting price %.2f\n", name, newItem.id, startingPrice);
    } else {
        printf("Item list is full!\n");
    }
}

void registerBidder(char *name) {
    if(bidderCount < MAX_BIDDERS) {
        struct Bidder newBidder;
        strncpy(newBidder.name, name, BIDDER_NAME_LEN);
        newBidder.id = bidderCount;
        newBidder.totalBids = 0;
        bidders[bidderCount++] = newBidder;
        printf("Bidder '%s' registered with ID %d\n", name, newBidder.id);
    } else {
        printf("Bidder list is full!\n");
    }
}

void placeBid(int itemId, int bidderId, float bidAmount) {
    if(itemId >= 0 && itemId < itemCount && bidderId >= 0 && bidderId < bidderCount) {
        struct Item *item = &items[itemId];
        struct Bidder *bidder = &bidders[bidderId];

        if(item->isActive) {
            if(bidAmount > item->highestBid) {
                item->highestBid = bidAmount;
                strncpy(item->highestBidder, bidder->name, BIDDER_NAME_LEN);
                bidder->totalBids++;
                printf("Bid of %.2f placed by '%s' on item '%s'\n", bidAmount, bidder->name, item->name);
            } else {
                printf("Bid of %.2f is not higher than current highest bid of %.2f on item '%s'\n", bidAmount, item->highestBid, item->name);
            }
        } else {
            printf("Cannot place bid. Item '%s' is no longer active.\n", item->name);
        }
    } else {
        printf("Invalid item or bidder ID.\n");
    }
}

void endAuction(int itemId) {
    if(itemId >= 0 && itemId < itemCount) {
        items[itemId].isActive = 0;
        printf("Auction for item '%s' has ended. Highest bid: %.2f by '%s'\n", 
               items[itemId].name, items[itemId].highestBid, items[itemId].highestBidder);
    } else {
        printf("Invalid item ID.\n");
    }
}

void showActiveItems() {
    printf("\nActive Items:\n");
    for(int i = 0; i < itemCount; ++i) {
        if(items[i].isActive) {
            printf("ID: %d, Name: '%s', Current Highest Bid: %.2f\n", 
                   items[i].id, items[i].name, items[i].highestBid);
        }
    }
}

void showBidders() {
    printf("\nRegistered Bidders:\n");
    for(int i = 0; i < bidderCount; ++i) {
        printf("ID: %d, Name: '%s', Total Bids: %d\n", 
               bidders[i].id, bidders[i].name, bidders[i].totalBids);
    }
}

int main() {
    int choice, itemId, bidderId;
    float bidAmount;
    char name[BIDDER_NAME_LEN];

    while(1) {
        printf("\n1. Add Item\n2. Register Bidder\n3. Place Bid\n4. End Auction\n5. Show Active Items\n6. Show Bidders\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter starting price: ");
                scanf("%f", &bidAmount);
                addItem(name, bidAmount);
                break;
            case 2:
                printf("Enter bidder name: ");
                scanf("%s", name);
                registerBidder(name);
                break;
            case 3:
                printf("Enter item ID: ");
                scanf("%d", &itemId);
                printf("Enter bidder ID: ");
                scanf("%d", &bidderId);
                printf("Enter bid amount: ");
                scanf("%f", &bidAmount);
                placeBid(itemId, bidderId, bidAmount);
                break;
            case 4:
                printf("Enter item ID to end auction: ");
                scanf("%d", &itemId);
                endAuction(itemId);
                break;
            case 5:
                showActiveItems();
                break;
            case 6:
                showBidders();
                break;
            case 7:
                printf("Exiting the auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}