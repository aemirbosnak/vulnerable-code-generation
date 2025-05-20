//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char bidderName[MAX_NAME_LENGTH];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    float startingPrice;
    int numberOfBids;
    Bid bids[MAX_BIDS];
} AuctionItem;

void addBid(AuctionItem* item) {
    if (item->numberOfBids >= MAX_BIDS) {
        printf("Maximum bids reached for item: %s\n", item->itemName);
        return;
    }

    Bid newBid;
    printf("Enter bidder name: ");
    scanf("%s", newBid.bidderName);
    printf("Enter bid amount: ");
    scanf("%f", &newBid.bidAmount);

    // Validate bid
    if (newBid.bidAmount <= item->startingPrice) {
        printf("Bid must be higher than starting price (%.2f)\n", item->startingPrice);
        return;
    }
    
    item->bids[item->numberOfBids] = newBid;
    item->numberOfBids++;
}

void displayBids(const AuctionItem* item) {
    printf("Bids for item: %s\n", item->itemName);
    if (item->numberOfBids == 0) {
        printf("No bids placed yet.\n");
        return;
    }
    for (int i = 0; i < item->numberOfBids; i++) {
        printf("%s bid %.2f\n", item->bids[i].bidderName, item->bids[i].bidAmount);
    }
}

void displayWinningBid(const AuctionItem* item) {
    if (item->numberOfBids == 0) {
        printf("No bids placed for item: %s\n", item->itemName);
        return;
    }
    
    Bid highestBid = item->bids[0];
    for (int i = 1; i < item->numberOfBids; i++) {
        if (item->bids[i].bidAmount > highestBid.bidAmount) {
            highestBid = item->bids[i];
        }
    }

    printf("Winning bid for item: %s is %.2f by %s\n", item->itemName, highestBid.bidAmount, highestBid.bidderName);
}

int main() {
    AuctionItem item;

    printf("Enter auction item name: ");
    scanf("%s", item.itemName);
    printf("Enter starting price: ");
    scanf("%f", &item.startingPrice);
    item.numberOfBids = 0;

    int choice;
    do {
        printf("\nAuction Menu:\n");
        printf("1. Place a bid\n");
        printf("2. View bids\n");
        printf("3. View winning bid\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBid(&item);
                break;
            case 2:
                displayBids(&item);
                break;
            case 3:
                displayWinningBid(&item);
                break;
            case 4:
                printf("Exiting auction.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}