//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char bidderName[MAX_NAME_LENGTH];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    char auctioneerName[MAX_NAME_LENGTH];
    float startingPrice;
    float currentPrice;
    int numberOfBids;
    Bid bids[MAX_BIDS];
} Auction;

void createAuction(Auction *auction) {
    printf("Enter item name: ");
    scanf("%s", auction->itemName);
    printf("Enter auctioneer name: ");
    scanf("%s", auction->auctioneerName);
    printf("Enter starting price: ");
    scanf("%f", &auction->startingPrice);
    auction->currentPrice = auction->startingPrice;
    auction->numberOfBids = 0;
}

void placeBid(Auction *auction) {
    if (auction->numberOfBids >= MAX_BIDS) {
        printf("Maximum number of bids reached.\n");
        return;
    }

    Bid newBid;
    printf("Enter your name: ");
    scanf("%s", newBid.bidderName);
    printf("Enter your bid amount: ");
    scanf("%f", &newBid.bidAmount);

    if (newBid.bidAmount <= auction->currentPrice) {
        printf("Bid amount must be higher than the current price.\n");
        return;
    }

    auction->bids[auction->numberOfBids] = newBid;
    auction->currentPrice = newBid.bidAmount;
    auction->numberOfBids++;

    printf("Bid placed successfully.\n");
}

void displayAuctionDetails(Auction *auction) {
    printf("\nAuction for: %s\n", auction->itemName);
    printf("Auctioneer: %s\n", auction->auctioneerName);
    printf("Starting Price: %.2f\n", auction->startingPrice);
    printf("Current Price: %.2f\n", auction->currentPrice);
    printf("Total Bids: %d\n", auction->numberOfBids);

    for (int i = 0; i < auction->numberOfBids; i++) {
        printf("Bid %d: %s bid %.2f\n", i + 1, auction->bids[i].bidderName, auction->bids[i].bidAmount);
    }
}

void listAuctions(Auction auctions[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d: %s (Auctioneer: %s) - Current Price: %.2f\n", i + 1, auctions[i].itemName, auctions[i].auctioneerName, auctions[i].currentPrice);
    }
}

int main() {
    Auction auctions[MAX_AUCTIONS];
    int auctionCount = 0;
    int choice;

    do {
        printf("\n--- Digital Auction System ---\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. Display Auction Details\n");
        printf("4. List All Auctions\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (auctionCount < MAX_AUCTIONS) {
                    createAuction(&auctions[auctionCount]);
                    auctionCount++;
                } else {
                    printf("Maximum number of auctions reached.\n");
                }
                break;
            case 2:
                if (auctionCount == 0) {
                    printf("No auctions available. Create an auction first.\n");
                } else {
                    int auctionIndex;
                    printf("Enter auction index to place a bid (1 to %d): ", auctionCount);
                    scanf("%d", &auctionIndex);
                    if (auctionIndex < 1 || auctionIndex > auctionCount) {
                        printf("Invalid auction index.\n");
                    } else {
                        placeBid(&auctions[auctionIndex - 1]);
                    }
                }
                break;
            case 3:
                if (auctionCount == 0) {
                    printf("No auctions available.\n");
                } else {
                    int auctionIndex;
                    printf("Enter auction index to display details (1 to %d): ", auctionCount);
                    scanf("%d", &auctionIndex);
                    if (auctionIndex < 1 || auctionIndex > auctionCount) {
                        printf("Invalid auction index.\n");
                    } else {
                        displayAuctionDetails(&auctions[auctionIndex - 1]);
                    }
                }
                break;
            case 4:
                if (auctionCount == 0) {
                    printf("No auctions available.\n");
                } else {
                    listAuctions(auctions, auctionCount);
                }
                break;
            case 5:
                printf("Exiting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}