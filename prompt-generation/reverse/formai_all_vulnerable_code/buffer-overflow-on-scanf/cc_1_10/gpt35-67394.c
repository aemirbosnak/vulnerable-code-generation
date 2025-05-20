//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 100
#define MAX_BIDDERS 50
#define MAX_NAME_LENGTH 20

// Structure for bidders
struct Bidder {
    char name[MAX_NAME_LENGTH];
    float maxBid;
    float currentBid;
};

// Structure for auctions
struct Auction {
    char item[MAX_NAME_LENGTH];
    float startingBid;
    struct Bidder bidders[MAX_BIDDERS];
    int numBidders;
    int winnerIndex;
    int isActive;
};

struct Auction auctions[MAX_AUCTIONS];
int numAuctions = 0;

// Forward declarations
void createAuction();
void joinAuction();
void showAuctions();
void showBidders(int index);
void startAuction(int index);
void endAuction(int index);

// Entry point
int main() {
    int choice;
    do {
        printf("Welcome to the Cyberpunk Digital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Join Auction\n");
        printf("3. Show Active Auctions\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAuction();
                break;
            case 2:
                joinAuction();
                break;
            case 3:
                showAuctions();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}

// Create a new auction
void createAuction() {
    if (numAuctions >= MAX_AUCTIONS) {
        printf("Error: Maximum auctions reached.\n");
        return;
    }
    struct Auction auction;
    printf("Enter item name: ");
    scanf("%s", &auction.item);
    printf("Enter starting bid: ");
    scanf("%f", &auction.startingBid);
    auction.numBidders = 0;
    auction.winnerIndex = -1;
    auction.isActive = 0;
    auctions[numAuctions++] = auction;
    printf("Auction created with ID %d.\n", numAuctions);
}

// Join an existing auction
void joinAuction() {
    int index;
    printf("Enter auction ID to join: ");
    scanf("%d", &index);
    if (index < 1 || index > numAuctions) {
        printf("Error: Invalid auction ID.\n");
        return;
    }
    struct Auction* auction = &auctions[index-1];
    if (auction->isActive) {
        printf("Error: Auction is already active.\n");
        return;
    }
    if (auction->numBidders >= MAX_BIDDERS) {
        printf("Error: Maximum bidders reached.\n");
        return;
    }
    struct Bidder bidder;
    printf("Enter your name: ");
    scanf("%s", &bidder.name);
    printf("Enter your maximum bid: ");
    scanf("%f", &bidder.maxBid);
    bidder.currentBid = auction->startingBid;
    auction->bidders[auction->numBidders++] = bidder;
    printf("You have joined the auction.\n");
}

// Show all active auctions
void showAuctions() {
    if (numAuctions == 0) {
        printf("No auctions available.\n");
        return;
    }
    printf("Active Auctions:\n");
    for (int i = 0; i < numAuctions; i++) {
        struct Auction auction = auctions[i];
        if (auction.isActive) {
            printf("%d. %s\n", i+1, auction.item);
        }
    }
    if (numAuctions > 0) {
        int index;
        printf("Enter auction ID to view bidders (or 0 to cancel): ");
        scanf("%d", &index);
        if (index > 0 && index <= numAuctions) {
            showBidders(index-1);
        }
    }
}

// Show bidders for an auction
void showBidders(int index) {
    struct Auction auction = auctions[index];
    printf("Bidders for %s:\n", auction.item);
    for (int i = 0; i < auction.numBidders; i++) {
        struct Bidder bidder = auction.bidders[i];
        printf("%d. %s\n", i+1, bidder.name);
    }
}

// Start an auction
void startAuction(int index) {
    struct Auction* auction = &auctions[index];
    auction->isActive = 1;
    printf("Auction started for %s!\n", auction->item);
    // Simulate bidding process
    srand(time(NULL));
    float currentBid = auction->startingBid;
    int numBidders = auction->numBidders;
    while (numBidders > 0) {
        for (int i = 0; i < auction->numBidders; i++) {
            struct Bidder* bidder = &auction->bidders[i];
            if (bidder->currentBid >= currentBid) {
                float increment = (float)(rand() % 5 + 1) / 10.0;
                bidder->currentBid += increment;
                printf("%s bids %f for %s!\n", bidder->name, bidder->currentBid, auction->item);
            }
            else {
                numBidders--;
            }
        }
        currentBid += (float)(rand() % 5 + 1) / 10.0;
    }
    // Determine winner
    float maxBid = auction->startingBid;
    int winnerIndex = -1;
    for (int i = 0; i < auction->numBidders; i++) {
        struct Bidder* bidder = &auction->bidders[i];
        if (bidder->currentBid > maxBid) {
            maxBid = bidder->currentBid;
            winnerIndex = i;
        }
    }
    if (winnerIndex >= 0) {
        printf("Sold to %s for %f!\n", auction->bidders[winnerIndex].name, maxBid);
        auction->winnerIndex = winnerIndex;
    }
    else {
        printf("No bids made. Auction cancelled.\n");
    }
}

// End an auction
void endAuction(int index) {
    struct Auction* auction = &auctions[index];
    if (!auction->isActive) {
        printf("Error: Auction is not active.\n");
        return;
    }
    auction->isActive = 0;
    printf("Auction ended for %s!\n", auction->item);
}