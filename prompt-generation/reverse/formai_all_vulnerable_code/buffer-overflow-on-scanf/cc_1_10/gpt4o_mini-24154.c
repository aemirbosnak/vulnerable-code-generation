//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 100
#define NAME_LENGTH 50

typedef struct {
    char itemName[NAME_LENGTH];
    float startingPrice;
    float highestBid;
    char highestBidder[NAME_LENGTH];
    int numBids;
} AuctionItem;

AuctionItem auction;

void initializeAuction(const char *itemName, float startingPrice) {
    strncpy(auction.itemName, itemName, NAME_LENGTH);
    auction.startingPrice = startingPrice;
    auction.highestBid = startingPrice;
    auction.numBids = 0;
    memset(auction.highestBidder, 0, NAME_LENGTH);
}

void placeBid(const char *bidderName, float bidAmount) {
    if (bidAmount > auction.highestBid) {
        auction.highestBid = bidAmount;
        strncpy(auction.highestBidder, bidderName, NAME_LENGTH);
        auction.numBids++;
        printf("Bid placed successfully by %s: $%.2f\n", bidderName, bidAmount);
    } else {
        printf("Bid of $%.2f by %s is too low. Current highest bid is $%.2f\n", bidAmount, bidderName, auction.highestBid);
    }
}

void displayAuctionDetails() {
    printf("\nAuction Details:\n");
    printf("Item Name: %s\n", auction.itemName);
    printf("Starting Price: $%.2f\n", auction.startingPrice);
    printf("Current Highest Bid: $%.2f\n", auction.highestBid);
    printf("Highest Bidder: %s\n", auction.numBids == 0 ? "No bids yet" : auction.highestBidder);
    printf("Total Number of Bids: %d\n", auction.numBids);
}

int main() {
    char itemName[NAME_LENGTH];
    float startingPrice;
    char bidderName[NAME_LENGTH];
    float bidAmount;
    int choice;

    printf("Welcome to the Digital Auction System!\n");
    
    printf("Enter the name of the item to be auctioned: ");
    fgets(itemName, NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline character

    printf("Enter the starting price of the item: ");
    scanf("%f", &startingPrice);
    
    initializeAuction(itemName, startingPrice);

    do {
        printf("\nMenu: \n");
        printf("1. Place a Bid\n");
        printf("2. Display Auction Details\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", bidderName);
                printf("Enter your bid amount: ");
                scanf("%f", &bidAmount);
                placeBid(bidderName, bidAmount);
                break;
            case 2:
                displayAuctionDetails();
                break;
            case 3:
                printf("Exiting the auction system.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}