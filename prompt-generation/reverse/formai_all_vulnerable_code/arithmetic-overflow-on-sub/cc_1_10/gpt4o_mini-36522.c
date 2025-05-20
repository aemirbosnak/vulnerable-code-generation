//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 100
#define NAME_LENGTH 50

typedef struct {
    char bidderName[NAME_LENGTH];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[NAME_LENGTH];
    float startingPrice;
    float currentBid;
    Bid bids[MAX_BIDS];
    int bidCount;
    time_t auctionEndTime;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached.\n");
        return;
    }

    Auction newAuction;
    printf("Enter item name: ");
    scanf(" %[^\n]s", newAuction.itemName);
    printf("Enter starting price: ");
    scanf("%f", &newAuction.startingPrice);
    
    newAuction.currentBid = newAuction.startingPrice;
    newAuction.bidCount = 0;

    // Set auction duration to 60 seconds
    newAuction.auctionEndTime = time(NULL) + 60;
    
    auctions[auctionCount++] = newAuction;
    printf("Auction created successfully!\n");
}

void placeBid(int auctionIndex) {
    if (auctionIndex >= auctionCount || auctionIndex < 0) {
        printf("Invalid auction index!\n");
        return;
    }

    Auction *auction = &auctions[auctionIndex];
    if (time(NULL) > auction->auctionEndTime) {
        printf("Auction has ended!\n");
        return;
    }
    
    Bid newBid;
    printf("Enter your name: ");
    scanf(" %[^\n]s", newBid.bidderName);
    printf("Enter your bid amount (must be higher than the current bid of %.2f): ", auction->currentBid);
    scanf("%f", &newBid.bidAmount);

    if (newBid.bidAmount <= auction->currentBid) {
        printf("Bid amount must be higher than the current bid!\n");
        return;
    }

    auction->bids[auction->bidCount++] = newBid;
    auction->currentBid = newBid.bidAmount;
    printf("Bid placed successfully by %s!\n", newBid.bidderName);
}

void endAuction(int auctionIndex) {
    if (auctionIndex >= auctionCount || auctionIndex < 0) {
        printf("Invalid auction index!\n");
        return;
    }

    Auction *auction = &auctions[auctionIndex];
    if (time(NULL) <= auction->auctionEndTime) {
        printf("Auction is still ongoing!\n");
        return;
    }

    printf("Auction for '%s' has ended.\n", auction->itemName);
    if (auction->bidCount == 0) {
        printf("No bids were placed.\n");
    } else {
        printf("Winning bidder: %s with a bid of %.2f\n", auction->bids[auction->bidCount - 1].bidderName, auction->currentBid);
    }
}

void displayAuctions() {
    if (auctionCount == 0) {
        printf("No auctions available.\n");
        return;
    }

    printf("Current Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        Auction *auction = &auctions[i];
        printf("Auction %d: %s, Starting Price: %.2f, Current Bid: %.2f\n", i + 1, auction->itemName, auction->startingPrice, auction->currentBid);
        printf("End Time: %s\n", ctime(&auction->auctionEndTime));
    }
}

void auctionMenu() {
    int choice, auctionIndex;

    do {
        printf("\nDigital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. End Auction\n");
        printf("4. Display Auctions\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAuction();
                break;
            case 2:
                printf("Enter auction index to bid on (1 to %d): ", auctionCount);
                scanf("%d", &auctionIndex);
                placeBid(auctionIndex - 1);
                break;
            case 3:
                printf("Enter auction index to end (1 to %d): ", auctionCount);
                scanf("%d", &auctionIndex);
                endAuction(auctionIndex - 1);
                break;
            case 4:
                displayAuctions();
                break;
            case 5:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    auctionMenu();
    return 0;
}