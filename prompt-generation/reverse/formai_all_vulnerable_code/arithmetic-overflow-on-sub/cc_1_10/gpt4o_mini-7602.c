//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_AUCTIONS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float bid;
} Bidder;

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    float startingPrice;
    Bidder highestBidder;
    int totalBidders;
    time_t auctionEndTime;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void initializeAuction(Auction *auction, const char *itemName, float startingPrice) {
    strcpy(auction->itemName, itemName);
    auction->startingPrice = startingPrice;
    auction->highestBidder.bid = startingPrice;
    auction->highestBidder.name[0] = '\0'; // No bidder initially
    auction->totalBidders = 0;
}

void displayAuctions() {
    printf("\nCurrent Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        Auction *a = &auctions[i];
        printf("Auction %d: Item: %s, Starting Price: %.2f, Highest Bid: %.2f by %s\n", 
               i + 1, a->itemName, a->startingPrice, a->highestBidder.bid, a->highestBidder.name[0] ? a->highestBidder.name : "None");
    }
}

void placeBid(int auctionIndex) {
    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Invalid auction selected!\n");
        return;
    }

    Auction *auction = &auctions[auctionIndex];

    if (time(NULL) >= auction->auctionEndTime) {
        printf("The auction for %s has already ended.\n", auction->itemName);
        return;
    }

    Bidder bid;
    printf("Enter your name: ");
    scanf("%s", bid.name);
    printf("Enter your bid: ");
    scanf("%f", &bid.bid);

    if (bid.bid > auction->highestBidder.bid) {
        auction->highestBidder = bid;
        auction->totalBidders++;
        printf("Bid of %.2f from %s accepted!\n", bid.bid, bid.name);
    } else {
        printf("Bid of %.2f is not higher than the current highest bid of %.2f.\n", bid.bid, auction->highestBidder.bid);
    }
}

void startAuction(int auctionIndex, int duration) {
    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Invalid auction selected!\n");
        return;
    }

    Auction *auction = &auctions[auctionIndex];
    auction->auctionEndTime = time(NULL) + duration;
    printf("Auction for %s has started and will end in %d seconds.\n", auction->itemName, duration);
}

void showHighestBidder(int auctionIndex) {
    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Invalid auction selected!\n");
        return;
    }

    Auction *auction = &auctions[auctionIndex];
    if (auction->highestBidder.name[0] != '\0') {
        printf("Highest bidder for %s is %s with a bid of %.2f.\n", auction->itemName, auction->highestBidder.name, auction->highestBidder.bid);
    } else {
        printf("No bids placed for the auction of %s yet.\n", auction->itemName);
    }
}

int main() {
    while (1) {
        int choice;
        printf("\nWelcome to the Digital Auction System! Please select an option:\n");
        printf("1. Create Auction\n2. Display Auctions\n3. Place Bid\n4. Start Auction\n5. Show Highest Bidder\n6. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if (auctionCount < MAX_AUCTIONS) {
                char item[MAX_NAME_LENGTH];
                float startPrice;
                printf("Enter item name: ");
                scanf("%s", item);
                printf("Enter starting price: ");
                scanf("%f", &startPrice);
                initializeAuction(&auctions[auctionCount], item, startPrice);
                auctionCount++;
                printf("Auction created for %s with starting price %.2f.\n", item, startPrice);
            } else {
                printf("Cannot create more auctions. Maximum limit reached!\n");
            }
        } else if (choice == 2) {
            displayAuctions();
        } else if (choice == 3) {
            int auctionIndex;
            printf("Enter auction number to bid on: ");
            scanf("%d", &auctionIndex);
            placeBid(auctionIndex - 1); // Adjust for 0-based index
        } else if (choice == 4) {
            int auctionIndex, duration;
            printf("Enter auction number to start: ");
            scanf("%d", &auctionIndex);
            printf("Enter duration in seconds: ");
            scanf("%d", &duration);
            startAuction(auctionIndex - 1, duration); // Adjust for 0-based index
        } else if (choice == 5) {
            int auctionIndex;
            printf("Enter auction number to check highest bidder: ");
            scanf("%d", &auctionIndex);
            showHighestBidder(auctionIndex - 1); // Adjust for 0-based index
        } else if (choice == 6) {
            printf("Thank you for using the Digital Auction System. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}