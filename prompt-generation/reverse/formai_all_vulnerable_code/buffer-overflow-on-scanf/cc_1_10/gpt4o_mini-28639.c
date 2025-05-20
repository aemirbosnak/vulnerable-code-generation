//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 100
#define MAX_BIDS 100
#define TITLE_LENGTH 50
#define NAME_LENGTH 30

typedef struct {
    char bidder[NAME_LENGTH];
    float amount;
} Bid;

typedef struct {
    char title[TITLE_LENGTH];
    float startingPrice;
    float currentPrice;
    int bidCount;
    Bid bids[MAX_BIDS];
} Auction;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Auction limit reached! Cannot create more auctions.\n");
        return;
    }
    
    Auction newAuction;
    printf("Enter auction title: ");
    scanf("%s", newAuction.title);
    printf("Enter starting price: ");
    scanf("%f", &newAuction.startingPrice);
    
    newAuction.currentPrice = newAuction.startingPrice;
    newAuction.bidCount = 0;
    
    auctions[auctionCount++] = newAuction;
    printf("Auction created successfully!\n");
}

void placeBid() {
    char title[TITLE_LENGTH];
    printf("Enter auction title to bid on: ");
    scanf("%s", title);

    int index = -1;
    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Auction not found!\n");
        return;
    }

    Bid newBid;
    printf("Enter your name: ");
    scanf("%s", newBid.bidder);
    printf("Enter bid amount: ");
    scanf("%f", &newBid.amount);

    if (newBid.amount <= auctions[index].currentPrice) {
        printf("Bid amount must be higher than the current price of %.2f!\n", auctions[index].currentPrice);
        return;
    }

    auctions[index].bids[auctions[index].bidCount++] = newBid;
    auctions[index].currentPrice = newBid.amount;
    printf("Bid placed successfully! Current price updated to %.2f\n", auctions[index].currentPrice);
}

void viewAuction() {
    char title[TITLE_LENGTH];
    printf("Enter auction title to view details: ");
    scanf("%s", title);

    int index = -1;
    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Auction not found!\n");
        return;
    }

    printf("Auction Title: %s\n", auctions[index].title);
    printf("Starting Price: %.2f\n", auctions[index].startingPrice);
    printf("Current Price: %.2f\n", auctions[index].currentPrice);
    printf("Number of Bids: %d\n", auctions[index].bidCount);
    
    if (auctions[index].bidCount > 0) {
        printf("Bids:\n");
        for (int i = 0; i < auctions[index].bidCount; i++) {
            printf("  Bidder: %s, Amount: %.2f\n", auctions[index].bids[i].bidder, auctions[index].bids[i].amount);
        }
    } else {
        printf("No bids placed yet.\n");
    }
}

void displayMenu() {
    printf("Digital Auction System\n");
    printf("1. Create Auction\n");
    printf("2. Place Bid\n");
    printf("3. View Auction\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAuction();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                viewAuction();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}