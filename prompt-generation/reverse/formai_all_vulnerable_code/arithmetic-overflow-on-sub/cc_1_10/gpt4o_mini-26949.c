//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 50
#define MAX_BIDS 100
#define MAX_NAME_LEN 100

typedef struct {
    char itemName[MAX_NAME_LEN];
    int startingPrice;
    int currentHighestBid;
    char highestBidder[MAX_NAME_LEN];
    time_t endTime;
} Auction;

typedef struct {
    char name[MAX_NAME_LEN];
    int bidAmount;
} Bid;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum auction limit reached!\n");
        return;
    }

    Auction newAuction;
    printf("Enter item name for auction: ");
    scanf(" %[^\n]", newAuction.itemName);
    
    printf("Enter starting price: ");
    scanf("%d", &newAuction.startingPrice);
    
    newAuction.currentHighestBid = newAuction.startingPrice;
    strcpy(newAuction.highestBidder, "None");

    printf("Enter auction duration (in seconds): ");
    int duration;
    scanf("%d", &duration);
    newAuction.endTime = time(NULL) + duration;

    auctions[auctionCount] = newAuction;
    auctionCount++;

    printf("Auction for '%s' created successfully!\n", newAuction.itemName);
}

void makeBid() {
    char name[MAX_NAME_LEN];
    printf("Enter your name: ");
    scanf(" %[^\n]", name);

    printf("Available Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        printf("%d. %s (Current Bid: $%d)\n", i + 1, auctions[i].itemName, auctions[i].currentHighestBid);
    }

    int auctionIndex;
    printf("Select auction to bid on (1-%d): ", auctionCount);
    scanf("%d", &auctionIndex);
    auctionIndex--; // Adjust index to 0-based

    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Invalid auction selection!\n");
        return;
    }

    Auction *selectedAuction = &auctions[auctionIndex];
    if (time(NULL) > selectedAuction->endTime) {
        printf("Auction has already ended!\n");
        return;
    }

    int bidAmount;
    printf("Enter your bid amount (minimum $%d): ", selectedAuction->currentHighestBid + 1);
    scanf("%d", &bidAmount);

    if (bidAmount <= selectedAuction->currentHighestBid) {
        printf("Bid amount must be greater than the current highest bid!\n");
        return;
    }

    selectedAuction->currentHighestBid = bidAmount;
    strcpy(selectedAuction->highestBidder, name);
    printf("Bid of $%d placed successfully by '%s'!\n", bidAmount, name);
}

void checkAuctionStatus() {
    printf("Current Auction Status:\n");
    for (int i = 0; i < auctionCount; i++) {
        Auction *auc = &auctions[i];
        printf("%d. %s\n", i + 1, auc->itemName);
        printf("   Highest Bid: $%d by '%s'\n", auc->currentHighestBid, auc->highestBidder);
        if (time(NULL) > auc->endTime) {
            printf("   Status: Auction ended!\n");
        } else {
            printf("   Status: Ongoing...\n");
        }
    }
}

void endAuction() {
    printf("Ending Auction...\n");
    for (int i = 0; i < auctionCount; i++) {
        if (time(NULL) > auctions[i].endTime) {
            printf("Auction for '%s' has ended.\n", auctions[i].itemName);
            printf("Final bid was $%d by '%s'.\n\n", auctions[i].currentHighestBid, auctions[i].highestBidder);
            // Shift the remaining auctions to fill the gap
            for (int j = i; j < auctionCount - 1; j++) {
                auctions[j] = auctions[j + 1];
            }
            auctionCount--;
            i--; // Adjust index for the next iteration
        }
    }
}

int main() {
    int choice;
    
    do {
        printf("\nDigital Auction System\n");
        printf("-----------------------\n");
        printf("1. Create Auction\n");
        printf("2. Make Bid\n");
        printf("3. Check Auction Status\n");
        printf("4. End Auction\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAuction();
                break;
            case 2:
                makeBid();
                break;
            case 3:
                checkAuctionStatus();
                break;
            case 4:
                endAuction();
                break;
            case 0:
                printf("Exiting the auction system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}