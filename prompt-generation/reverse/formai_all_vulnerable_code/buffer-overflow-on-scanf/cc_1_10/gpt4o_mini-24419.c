//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 100

typedef struct {
    char bidderName[50];
    float bidAmount;
} Bid;

typedef struct {
    Bid bids[MAX_BIDS];
    int bidCount;
} Auction;

// Function prototypes
void startAuction(Auction *auction);
void placeBid(Auction *auction, float currentHighestBid);
void declareWinner(Auction *auction);

int main() {
    Auction auction;
    auction.bidCount = 0;
    startAuction(&auction);
    return 0;
}

void startAuction(Auction *auction) {
    time_t startTime = time(NULL);
    time_t duration = 30; // Auction lasts for 30 seconds
    printf("Auction started! You have %ld seconds to place your bids.\n", duration);
    placeBid(auction, 0.0); // Start the recursive bidding process
    time_t endTime = time(NULL);

    if (difftime(endTime, startTime) >= duration) {
        printf("Auction time is over!\n");
        declareWinner(auction);
    }
}

void placeBid(Auction *auction, float currentHighestBid) {
    if (auction->bidCount >= MAX_BIDS) {
        printf("Maximum number of bids reached!\n");
        return;
    }

    char name[50];
    float bidAmount;

    printf("Current highest bid: $%.2f\n", currentHighestBid);
    printf("Enter your name (or type 'exit' to finish): ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Strip newline character

    if (strcmp(name, "exit") == 0) {
        return; // Exit the bidding
    }

    printf("Enter your bid amount: $");
    scanf("%f", &bidAmount);
    getchar(); // Clear newline from buffer

    if (bidAmount <= currentHighestBid) {
        printf("Your bid must be higher than the current highest bid!\n");
    } else {
        strcpy(auction->bids[auction->bidCount].bidderName, name);
        auction->bids[auction->bidCount].bidAmount = bidAmount;
        auction->bidCount++;
        printf("Bid recorded: %s bids $%.2f\n", name, bidAmount);
    }

    // Recursive call to allow for next bid
    placeBid(auction, (auction->bidCount > 0) ? auction->bids[auction->bidCount - 1].bidAmount : 0.0);
}

void declareWinner(Auction *auction) {
    if (auction->bidCount == 0) {
        printf("No bids were placed. No winner!\n");
        return;
    }
    
    Bid highestBid = auction->bids[0];
    for (int i = 1; i < auction->bidCount; i++) {
        if (auction->bids[i].bidAmount > highestBid.bidAmount) {
            highestBid = auction->bids[i];
        }
    }

    printf("The auction is over! The winner is %s with a bid of $%.2f!\n", highestBid.bidderName, highestBid.bidAmount);
}