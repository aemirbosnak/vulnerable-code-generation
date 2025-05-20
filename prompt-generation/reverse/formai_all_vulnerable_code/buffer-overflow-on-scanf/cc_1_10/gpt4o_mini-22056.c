//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float startingPrice;
    float currentPrice;
    char highestBidder[NAME_LENGTH];
    int bidsCount;
    time_t endTime;
} AuctionItem;

typedef struct {
    char bidderName[NAME_LENGTH];
    float bidAmount;
} Bid;

AuctionItem items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int itemCount = 0;

void displayMenu() {
    printf("\n** Digital Auction System **\n");
    printf("1. Add Auction Item\n");
    printf("2. List Auction Items\n");
    printf("3. Place Bid\n");
    printf("4. View Highest Bids\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached!\n");
        return;
    }
    AuctionItem newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter starting price: ");
    scanf("%f", &newItem.startingPrice);
    
    newItem.currentPrice = newItem.startingPrice;
    strcpy(newItem.highestBidder, "None");
    newItem.bidsCount = 0;
    newItem.endTime = time(NULL) + 3600; // Auction ends in 1 hour

    items[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void listAuctionItems() {
    printf("\n** Auction Items **\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s | Current Price: %.2f | Highest Bidder: %s\n", 
            i + 1, items[i].name, items[i].currentPrice, items[i].highestBidder);
    }
}

void placeBid() {
    int itemIndex;
    float bidAmount;

    printf("Enter item index to bid on: ");
    scanf("%d", &itemIndex);
    itemIndex--;

    if (itemIndex < 0 || itemIndex >= itemCount || time(NULL) > items[itemIndex].endTime) {
        printf("Invalid item or auction has ended!\n");
        return;
    }

    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= items[itemIndex].currentPrice) {
        printf("Bid must be higher than the current price!\n");
        return;
    }

    items[itemIndex].currentPrice = bidAmount;
    printf("Enter your name: ");
    scanf("%s", items[itemIndex].highestBidder);

    items[itemIndex].bidsCount++;
    printf("Bid placed successfully!\n");
}

void viewHighestBids() {
    printf("\n** Highest Bids for Each Item **\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s | Highest Bid: %.2f | Highest Bidder: %s\n",
            items[i].name, items[i].currentPrice, items[i].highestBidder);
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAuctionItem();
                break;
            case 2:
                listAuctionItems();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                viewHighestBids();
                break;
            case 5:
                printf("Exiting the auction system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}