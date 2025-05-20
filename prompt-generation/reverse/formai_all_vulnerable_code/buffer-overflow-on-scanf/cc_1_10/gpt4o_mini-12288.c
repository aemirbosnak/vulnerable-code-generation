//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 10
#define MAX_BIDDERS 20
#define NAME_LENGTH 50
#define ITEM_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    float bid;
} Bidder;

typedef struct {
    char item[ITEM_LENGTH];
    float startingBid;
    float currentHighestBid;
    Bidder bidders[MAX_BIDDERS];
    int bidderCount;
    time_t auctionEndTime;
    int isActive;
} Auction;

void createAuction(Auction *auction, const char *item, float startingBid, int duration) {
    strncpy(auction->item, item, ITEM_LENGTH);
    auction->startingBid = startingBid;
    auction->currentHighestBid = startingBid;
    auction->bidderCount = 0;
    auction->isActive = 1;
    auction->auctionEndTime = time(NULL) + duration;
    printf("Auction for '%s' created with starting bid %.2f. Ends in %d seconds!\n", item, startingBid, duration);
}

void addBidder(Auction *auction, const char *name, float bid) {
    if (auction->bidderCount >= MAX_BIDDERS) {
        printf("Max bidders reached for auction '%s'. Can't add more!\n", auction->item);
        return;
    }
    if (bid <= auction->currentHighestBid) {
        printf("Bid of %.2f is too low for auction '%s'. Current highest bid is %.2f!\n", bid, auction->item, auction->currentHighestBid);
        return;
    }
    
    strcpy(auction->bidders[auction->bidderCount].name, name);
    auction->bidders[auction->bidderCount].bid = bid;
    auction->currentHighestBid = bid;
    auction->bidderCount++;
    printf("Bid of %.2f from '%s' accepted for auction '%s'!\n", bid, name, auction->item);
}

void displayAuction(const Auction *auction) {
    printf("\nAuction for '%s':\n", auction->item);
    printf("Starting Bid: %.2f\n", auction->startingBid);
    printf("Current Highest Bid: %.2f\n", auction->currentHighestBid);
    printf("Number of Bidders: %d\n", auction->bidderCount);
    printf("Bidders:\n");
    for (int i = 0; i < auction->bidderCount; i++) {
        printf("  %s: %.2f\n", auction->bidders[i].name, auction->bidders[i].bid);
    }
    printf("\n");
}

void endAuction(Auction *auction) {
    if (auction->isActive) {
        auction->isActive = 0;
        printf("Auction for '%s' has ended!\n", auction->item);
        if (auction->bidderCount > 0) {
            Bidder winner = auction->bidders[0];
            for (int i = 1; i < auction->bidderCount; i++) {
                if (auction->bidders[i].bid > winner.bid) {
                    winner = auction->bidders[i];
                }
            }
            printf("The winner is '%s' with a bid of %.2f!\n", winner.name, winner.bid);
        } else {
            printf("No bids were placed. The auction for '%s' has no winner!\n", auction->item);
        }
    } else {
        printf("Auction for '%s' is already ended!\n", auction->item);
    }
}

int main() {
    Auction auctions[MAX_AUCTIONS];
    int auctionCount = 0;
    
    while (1) {
        printf("Welcome to the Digital Auction System!\n");
        printf("1. Create Auction\n2. Place Bid\n3. View Auction\n4. End Auction\n5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            if (auctionCount >= MAX_AUCTIONS) {
                printf("Maximum number of auctions reached!\n");
                continue;
            }
            char item[ITEM_LENGTH];
            float startingBid;
            int duration;
            printf("Enter item name: ");
            scanf("%s", item);
            printf("Enter starting bid: ");
            scanf("%f", &startingBid);
            printf("Enter auction duration in seconds: ");
            scanf("%d", &duration);
            createAuction(&auctions[auctionCount++], item, startingBid, duration);
        } else if (choice == 2) {
            char name[NAME_LENGTH];
            float bid;
            printf("Enter auction index (0 to %d): ", auctionCount - 1);
            int auctionIndex;
            scanf("%d", &auctionIndex);
            if (auctionIndex < 0 || auctionIndex >= auctionCount) {
                printf("Invalid auction index!\n");
                continue;
            }
            printf("Enter bidder name: ");
            scanf("%s", name);
            printf("Enter your bid amount: ");
            scanf("%f", &bid);
            addBidder(&auctions[auctionIndex], name, bid);
        } else if (choice == 3) {
            int auctionIndex;
            printf("Enter auction index (0 to %d): ", auctionCount - 1);
            scanf("%d", &auctionIndex);
            if (auctionIndex < 0 || auctionIndex >= auctionCount) {
                printf("Invalid auction index!\n");
                continue;
            }
            displayAuction(&auctions[auctionIndex]);
        } else if (choice == 4) {
            int auctionIndex;
            printf("Enter auction index (0 to %d): ", auctionCount - 1);
            scanf("%d", &auctionIndex);
            if (auctionIndex < 0 || auctionIndex >= auctionCount) {
                printf("Invalid auction index!\n");
                continue;
            }
            endAuction(&auctions[auctionIndex]);
        } else if (choice == 5) {
            printf("Thank you for using the Digital Auction System!\n");
            break;
        } else {
            printf("Invalid choice! Please select again.\n");
        }
    }
    
    return 0;
}