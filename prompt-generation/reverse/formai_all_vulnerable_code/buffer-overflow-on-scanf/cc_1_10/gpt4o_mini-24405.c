//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BIDS 100
#define ITEM_NAME_LENGTH 100

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    char highestBidder[ITEM_NAME_LENGTH];
    float highestBid;
    int bidCount;
} Auction;

Auction auction;

void initializeAuction(char *item) {
    strcpy(auction.itemName, item);
    auction.highestBid = 0.0;
    auction.bidCount = 0;
    strcpy(auction.highestBidder, "No bids yet");
}

void placeBid(const char *bidderName, float bidAmount) {
    if (bidAmount > auction.highestBid) {
        auction.highestBid = bidAmount;
        strcpy(auction.highestBidder, bidderName);
        auction.bidCount++;
        printf("Bid accepted: %s bids %.2f.\n", bidderName, bidAmount);
    } else {
        printf("Bid rejected: %.2f is not higher than the current highest bid of %.2f.\n", bidAmount, auction.highestBid);
    }
}

void displayAuctionStatus() {
    printf("\n--- Auction Status ---\n");
    printf("Item: %s\n", auction.itemName);
    printf("Current Highest Bid: %.2f by %s\n", auction.highestBid, auction.highestBidder);
    printf("Number of Bids: %d\n", auction.bidCount);
    printf("----------------------\n\n");
}

void displayMenu() {
    printf("--- Digital Auction System ---\n");
    printf("1. Place a bid\n");
    printf("2. Display auction status\n");
    printf("3. Exit\n");
    printf("----------------------------\n");
}

int main() {
    char item[ITEM_NAME_LENGTH];
    char bidder[ITEM_NAME_LENGTH];
    float bidAmount;
    int choice;

    // Initiate auction
    printf("Enter the item for auction: ");
    fgets(item, ITEM_NAME_LENGTH, stdin);
    item[strcspn(item, "\n")] = 0; // Remove newline character
    initializeAuction(item);

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", bidder);
                printf("Enter your bid amount: ");
                scanf("%f", &bidAmount);
                placeBid(bidder, bidAmount);
                break;

            case 2:
                displayAuctionStatus();
                break;

            case 3:
                printf("Exiting auction system.\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
        sleep(1); // Pause for a moment before displaying the menu again
    }

    return 0;
}