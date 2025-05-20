//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    int itemId;
    char itemName[50];
    float startingPrice;
    float currentPrice;
    int highestBidderId;
    int bidsCount;
} Item;

typedef struct {
    int bidderId;
    char bidderName[50];
    float bidAmount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int itemCount = 0;
int bidCount = 0;

void addItem(int id, const char* name, float startingPrice) {
    if (itemCount < MAX_ITEMS) {
        items[itemCount].itemId = id;
        strcpy(items[itemCount].itemName, name);
        items[itemCount].startingPrice = startingPrice;
        items[itemCount].currentPrice = startingPrice;
        items[itemCount].highestBidderId = -1;
        items[itemCount].bidsCount = 0;
        itemCount++;
        printf("Item added: %s with starting price: %.2f\n", name, startingPrice);
    } else {
        printf("Item limit reached, cannot add more items.\n");
    }
}

void placeBid(int itemId, int bidderId, const char* bidderName, float bidAmount) {
    if (bidCount < MAX_BIDS) {
        for (int i = 0; i < itemCount; i++) {
            if (items[i].itemId == itemId) {
                if (bidAmount > items[i].currentPrice) {
                    items[i].currentPrice = bidAmount;
                    items[i].highestBidderId = bidderId;
                    bids[bidCount].bidderId = bidderId;
                    strcpy(bids[bidCount].bidderName, bidderName);
                    bids[bidCount].bidAmount = bidAmount;
                    items[i].bidsCount++;
                    bidCount++;
                    printf("Bid placed by %s (ID: %d) for item %s (ID: %d) with amount: %.2f\n",
                           bidderName, bidderId, items[i].itemName, itemId, bidAmount);
                } else {
                    printf("Bid amount must be higher than current price: %.2f\n", items[i].currentPrice);
                }
                return;
            }
        }
        printf("Item with ID %d not found.\n", itemId);
    } else {
        printf("Bid limit reached, cannot place more bids.\n");
    }
}

void displayItems() {
    printf("\nAvailable items for auction:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s, Starting Price: %.2f, Current Price: %.2f, Highest Bidder ID: %d\n",
               items[i].itemId, items[i].itemName, items[i].startingPrice, items[i].currentPrice, items[i].highestBidderId);
    }
}

void displayBids() {
    printf("\nBids placed in the auction:\n");
    for (int i = 0; i < bidCount; i++) {
        printf("Bidder: %s (ID: %d) placed a bid of %.2f\n",
               bids[i].bidderName, bids[i].bidderId, bids[i].bidAmount);
    }
}

int main() {
    int choice, id, bidderId;
    char name[50];
    float price;

    while (1) {
        printf("\nDigital Auction System Menu:\n");
        printf("1. Add Item\n");
        printf("2. Place Bid\n");
        printf("3. Display Items\n");
        printf("4. Display Bids\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter starting price: ");
                scanf("%f", &price);
                addItem(id, name, price);
                break;
            case 2:
                printf("Enter item ID to bid on: ");
                scanf("%d", &id);
                printf("Enter your ID: ");
                scanf("%d", &bidderId);
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your bid amount: ");
                scanf("%f", &price);
                placeBid(id, bidderId, name, price);
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
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}