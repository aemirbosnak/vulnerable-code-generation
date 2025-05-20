//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_AUCTIONS 50
#define MAX_NAME_LEN 50
#define MAX_ITEM_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    float currentBid;
} Bidder;

typedef struct {
    char item[MAX_ITEM_LEN];
    float startingPrice;
    Bidder *highestBidder;
} Auction;

Bidder bidders[MAX_BIDDERS];
Auction auctions[MAX_AUCTIONS];
int bidderCount = 0;
int auctionCount = 0;

void registerBidder() {
    if (bidderCount >= MAX_BIDDERS) {
        printf("Maximum number of bidders reached.\n");
        return;
    }

    Bidder newBidder;
    printf("Enter your name: ");
    scanf("%s", newBidder.name);
    newBidder.currentBid = 0.0;

    bidders[bidderCount++] = newBidder;
    printf("Bidder %s registered successfully!\n", newBidder.name);
}

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached.\n");
        return;
    }

    Auction newAuction;
    printf("Enter item name for auction: ");
    scanf("%s", newAuction.item);
    printf("Enter starting price: ");
    scanf("%f", &newAuction.startingPrice);
    newAuction.highestBidder = NULL;

    auctions[auctionCount++] = newAuction;
    printf("Auction for %s created successfully starting at $%.2f!\n", newAuction.item, newAuction.startingPrice);
}

void placeBid() {
    char bidderName[MAX_NAME_LEN];
    char item[MAX_ITEM_LEN];
    float bidAmount;

    printf("Enter your name: ");
    scanf("%s", bidderName);
    
    printf("Enter item name to bid on: ");
    scanf("%s", item);
    
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].item, item) == 0) {
            if (bidAmount > auctions[i].startingPrice) {
                if (auctions[i].highestBidder == NULL || bidAmount > auctions[i].highestBidder->currentBid) {
                    for (int j = 0; j < bidderCount; j++) {
                        if (strcmp(bidders[j].name, bidderName) == 0) {
                            bidders[j].currentBid = bidAmount;
                            auctions[i].highestBidder = &bidders[j];
                            printf("Bid of $%.2f placed successfully!\n", bidAmount);
                            return;
                        }
                    }
                    printf("Bidder not found.\n");
                    return;
                } else {
                    printf("Your bid is lower than the current highest bid of $%.2f.\n", auctions[i].highestBidder->currentBid);
                    return;
                }
            } else {
                printf("Bid must be higher than the starting price of $%.2f.\n", auctions[i].startingPrice);
                return;
            }
        }
    }
    printf("Auction not found.\n");
}

void displayAuctions() {
    for (int i = 0; i < auctionCount; i++) {
        printf("Auction Item: %s\n", auctions[i].item);
        printf("Starting Price: $%.2f\n", auctions[i].startingPrice);
        if (auctions[i].highestBidder != NULL) {
            printf("Highest Bidder: %s with a bid of $%.2f\n", auctions[i].highestBidder->name, auctions[i].highestBidder->currentBid);
        } else {
            printf("No bids placed yet.\n");
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("Digital Auction System\n");
        printf("1. Register Bidder\n");
        printf("2. Create Auction\n");
        printf("3. Place Bid\n");
        printf("4. Display Auctions\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerBidder();
                break;
            case 2:
                createAuction();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                displayAuctions();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}