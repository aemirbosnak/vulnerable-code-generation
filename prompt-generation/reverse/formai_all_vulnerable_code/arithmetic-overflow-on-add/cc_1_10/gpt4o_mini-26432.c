//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 10
#define MAX_BIDDERS 5
#define MAX_NAME_LENGTH 30

typedef struct {
    int id;
    char item[MAX_NAME_LENGTH];
    float startingPrice;
    float currentPrice;
    int bids;
    int active;
    time_t endTime;
} Auction;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float bidAmount;
} Bidder;

Auction auctions[MAX_AUCTIONS];
Bidder bidders[MAX_BIDDERS];

void initializeAuctions() {
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        auctions[i].id = 0;
        auctions[i].active = 0;
        auctions[i].bids = 0;
    }
}

void createAuction(int id, const char* item, float startingPrice, int duration) {
    if (id <1 || id > MAX_AUCTIONS) {
        printf("Invalid auction ID. Please choose a number between 1 and %d\n", MAX_AUCTIONS);
        return;
    }
    if (auctions[id - 1].active) {
        printf("Auction %d is already active!\n", id);
        return;
    }
    auctions[id - 1].id = id;
    strncpy(auctions[id - 1].item, item, MAX_NAME_LENGTH);
    auctions[id - 1].startingPrice = startingPrice;
    auctions[id - 1].currentPrice = startingPrice;
    auctions[id - 1].endTime = time(NULL) + duration;
    auctions[id - 1].active = 1;
    auctions[id - 1].bids = 0;

    printf("Auction %d for item '%s' has been created with starting price %.2f\n", 
           id, item, startingPrice);
}

void placeBid(int auctionId, const char* bidderName, float bidAmount) {
    if (auctionId < 1 || auctionId > MAX_AUCTIONS) {
        printf("Invalid auction ID.\n");
        return;
    }
    Auction* auction = &auctions[auctionId - 1];

    if (!auction->active) {
        printf("Auction %d is not active.\n", auctionId);
        return;
    }
    
    if (bidAmount <= auction->currentPrice) {
        printf("Bid must be higher than the current price of %.2f.\n", 
               auction->currentPrice);
        return;
    }

    if (time(NULL) >= auction->endTime) {
        printf("Auction %d has already ended.\n", auctionId);
        return;
    }

    auction->currentPrice = bidAmount;
    auction->bids++;
    printf("%s placed a bid of %.2f on auction %d for item '%s'.\n",
           bidderName, bidAmount, auctionId, auction->item);
}

void endAuction(int auctionId) {
    if (auctionId < 1 || auctionId > MAX_AUCTIONS) {
        printf("Invalid auction ID.\n");
        return;
    }
    Auction* auction = &auctions[auctionId - 1];

    if (!auction->active) {
        printf("Auction %d is not active.\n", auctionId);
        return;
    }

    if (time(NULL) < auction->endTime) {
        printf("Auction %d has not yet ended.\n", auctionId);
        return;
    }

    auction->active = 0;
    printf("Auction %d for item '%s' has ended with final price of %.2f from %d bids.\n",
           auctionId, auction->item, auction->currentPrice, auction->bids);
}

void displayActiveAuctions() {
    printf("Active Auctions:\n");
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        if (auctions[i].active) {
            printf("Auction ID: %d\nItem: %s\nCurrent Price: %.2f\n",
                   auctions[i].id, auctions[i].item, auctions[i].currentPrice);
        }
    }
}

int main() {
    initializeAuctions();
    
    createAuction(1, "Antique Vase", 100.0, 30);
    createAuction(2, "Vintage Watch", 150.0, 45);
    
    displayActiveAuctions();
    
    placeBid(1, "Alice", 120.0);
    placeBid(1, "Bob", 130.0);
    placeBid(2, "Charlie", 160.0);
    
    sleep(31); // Wait for auction to expire (in seconds)
    
    endAuction(1);
    endAuction(2);
    
    return 0;
}