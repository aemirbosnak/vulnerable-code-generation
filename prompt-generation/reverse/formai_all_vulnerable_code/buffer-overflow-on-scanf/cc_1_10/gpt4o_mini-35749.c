//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    float bid;
} Bid;

typedef struct {
    char itemName[MAX_NAME];
    char description[255];
    float startingPrice;
    Bid bids[MAX_BIDS];
    int bidCount;
} AuctionItem;

AuctionItem auctionItems[MAX_ITEMS];
int itemCount = 0;

void addAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Maximum number of items reached.\n");
        return;
    }
    
    AuctionItem newItem;
    
    printf("Enter the item name: ");
    scanf("%s", newItem.itemName);
    printf("Enter the item description: ");
    scanf(" %[^\n]s", newItem.description); // Read with spaces
    printf("Enter the starting price: ");
    scanf("%f", &newItem.startingPrice);
    
    newItem.bidCount = 0; // Initialize bid count
    auctionItems[itemCount++] = newItem;

    printf("Item added successfully!\n");
}

void placeBid() {
    char itemName[MAX_NAME];
    printf("Enter the item name you want to bid on: ");
    scanf("%s", itemName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(auctionItems[i].itemName, itemName) == 0) {
            float bidAmount;
            printf("Enter your bid amount: ");
            scanf("%f", &bidAmount);
            
            if (auctionItems[i].bidCount < MAX_BIDS) {
                if (bidAmount > auctionItems[i].startingPrice) {
                    Bid newBid;
                    printf("Enter your name: ");
                    scanf("%s", newBid.name);
                    newBid.bid = bidAmount;
                    auctionItems[i].bids[auctionItems[i].bidCount++] = newBid;

                    // Update starting price to the latest bid
                    auctionItems[i].startingPrice = bidAmount;
                    printf("Bid placed successfully!\n");
                } else {
                    printf("Bid must be higher than the starting price of %.2f.\n", auctionItems[i].startingPrice);
                }
            } else {
                printf("Maximum bids reached for this item.\n");
            }
            return;
        }
    }
    printf("Item not found!\n");
}

void displayItems() {
    printf("\n--- Auction Items ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item Name: %s\n", auctionItems[i].itemName);
        printf("Description: %s\n", auctionItems[i].description);
        printf("Current Highest Bid: %.2f\n", auctionItems[i].startingPrice);
        printf("Number of Bids: %d\n\n", auctionItems[i].bidCount);
    }
}

void displayBids() {
    char itemName[MAX_NAME];
    printf("Enter the item name to view bids: ");
    scanf("%s", itemName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(auctionItems[i].itemName, itemName) == 0) {
            printf("\n--- Bids for %s ---\n", auctionItems[i].itemName);
            for (int j = 0; j < auctionItems[i].bidCount; j++) {
                printf("Bidder: %s, Bid Amount: %.2f\n", auctionItems[i].bids[j].name, auctionItems[i].bids[j].bid);
            }
            return;
        }
    }
    printf("Item not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Digital Auction System ---\n");
        printf("1. Add Auction Item\n");
        printf("2. Place Bid\n");
        printf("3. Display Items\n");
        printf("4. Display Bids\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAuctionItem();
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
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}