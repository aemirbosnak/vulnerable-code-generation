//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 100
#define ITEM_NAME_LENGTH 50
#define BIDDER_NAME_LENGTH 50

typedef struct {
    char name[BIDDER_NAME_LENGTH];
    float amount;
} Bid;

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    float startingPrice;
    Bid bids[MAX_BIDS];
    int bidCount;
} Auction;

// Function prototypes
void initializeAuction(Auction* auction, const char* itemName, float startingPrice);
void placeBid(Auction* auction, const char* bidderName, float bidAmount);
void displayCurrentBid(const Auction* auction);
void declareWinner(const Auction* auction);

int main() {
    Auction auction;
    char itemName[ITEM_NAME_LENGTH];
    float startingPrice;

    // Step 1: Initialize the auction
    printf("Welcome to the Digital Auction System!\n");
    printf("Enter the name of the item for auction: ");
    fgets(itemName, ITEM_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline character

    printf("Enter the starting price: ");
    scanf("%f", &startingPrice);

    initializeAuction(&auction, itemName, startingPrice);

    // Step 2: Bidding process
    while (1) {
        char bidderName[BIDDER_NAME_LENGTH];
        float bidAmount;

        displayCurrentBid(&auction);

        printf("Enter your name to place a bid (or type 'exit' to finish): ");
        getchar(); // Consume newline left by previous input
        fgets(bidderName, BIDDER_NAME_LENGTH, stdin);
        bidderName[strcspn(bidderName, "\n")] = 0; // Remove newline character

        if (strcmp(bidderName, "exit") == 0) {
            break; // Exit bidding loop
        }

        printf("Enter your bid amount: ");
        scanf("%f", &bidAmount);

        // Step 3: Place the bid
        placeBid(&auction, bidderName, bidAmount);
    }

    // Step 4: Declare the winner
    declareWinner(&auction);

    return 0;
}

void initializeAuction(Auction* auction, const char* itemName, float startingPrice) {
    strncpy(auction->itemName, itemName, ITEM_NAME_LENGTH);
    auction->startingPrice = startingPrice;
    auction->bidCount = 0;
    printf("Auction for \"%s\" has started with a starting price of %.2f!\n", auction->itemName, auction->startingPrice);
}

void placeBid(Auction* auction, const char* bidderName, float bidAmount) {
    if (auction->bidCount >= MAX_BIDS) {
        printf("Maximum number of bids reached!\n");
        return;
    }
    
    if (bidAmount <= auction->startingPrice) {
        printf("Bid must be higher than the starting price of %.2f!\n", auction->startingPrice);
        return;
    }

    for (int i = 0; i < auction->bidCount; i++) {
        if (strcmp(auction->bids[i].name, bidderName) == 0) {
            printf("You have already placed a bid!\n");
            return;
        }
    }

    auction->bids[auction->bidCount].amount = bidAmount;
    strncpy(auction->bids[auction->bidCount].name, bidderName, BIDDER_NAME_LENGTH);
    auction->bidCount++;
    printf("Bid of %.2f by %s has been placed successfully!\n", bidAmount, bidderName);
}

void displayCurrentBid(const Auction* auction) {
    if (auction->bidCount == 0) {
        printf("No bids have been placed yet. Current minimum price: %.2f\n", auction->startingPrice);
    } else {
        float highestBid = auction->bids[0].amount;
        for (int i = 1; i < auction->bidCount; i++) {
            if (auction->bids[i].amount > highestBid) {
                highestBid = auction->bids[i].amount;
            }
        }
        printf("Current highest bid: %.2f\n", highestBid);
    }
}

void declareWinner(const Auction* auction) {
    if (auction->bidCount == 0) {
        printf("No bids were placed. No winner for the auction of \"%s\".\n", auction->itemName);
        return;
    }

    float highestBid = auction->bids[0].amount;
    char winner[BIDDER_NAME_LENGTH];
    strncpy(winner, auction->bids[0].name, BIDDER_NAME_LENGTH);

    for (int i = 1; i < auction->bidCount; i++) {
        if (auction->bids[i].amount > highestBid) {
            highestBid = auction->bids[i].amount;
            strncpy(winner, auction->bids[i].name, BIDDER_NAME_LENGTH);
        }
    }
    printf("The auction has ended. The winner is %s with a bid of %.2f for \"%s\"!\n", winner, highestBid, auction->itemName);
}