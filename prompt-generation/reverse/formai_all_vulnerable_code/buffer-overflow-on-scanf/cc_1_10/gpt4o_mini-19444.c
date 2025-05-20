//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50
#define MAX_BID_LENGTH 15

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    double currentBid;
    char bidderName[MAX_NAME_LENGTH];
} AuctionItem;

AuctionItem auctionItems[MAX_ITEMS];
int itemCount = 0;

void displayItems() {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s | Current Bid: $%.2f | Bidder: %s\n", 
               i + 1, auctionItems[i].itemName, auctionItems[i].currentBid, auctionItems[i].bidderName);
    }
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Maximum item limit reached. Cannot add more items.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", auctionItems[itemCount].itemName);
    auctionItems[itemCount].currentBid = 0.0; // Initial bid
    strcpy(auctionItems[itemCount].bidderName, "No bids yet");
    itemCount++;
}

void placeBid() {
    displayItems();
    int itemNumber;
    printf("Select item number to bid on: ");
    scanf("%d", &itemNumber);

    if (itemNumber < 1 || itemNumber > itemCount) {
        printf("Invalid item number.\n");
        return;
    }

    double newBid;
    char bidder[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", bidder);
    printf("Enter your bid amount: ");
    scanf("%lf", &newBid);

    if (newBid > auctionItems[itemNumber - 1].currentBid) {
        auctionItems[itemNumber - 1].currentBid = newBid;
        strcpy(auctionItems[itemNumber - 1].bidderName, bidder);
        printf("Bid placed successfully!\n");
    } else {
        printf("Your bid must be higher than the current bid.\n");
    }
}

void endAuction() {
    printf("\nAuction Results:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s | Winning Bid: $%.2f | Winner: %s\n", 
               auctionItems[i].itemName, auctionItems[i].currentBid, auctionItems[i].bidderName);
    }
}

int main() {
    int choice;

    do {
        printf("\nDigital Auction System\n");
        printf("1. Add Item\n");
        printf("2. Place Bid\n");
        printf("3. Display Items\n");
        printf("4. End Auction\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
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
                endAuction();
                break;
            case 5:
                printf("Exiting the auction system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}