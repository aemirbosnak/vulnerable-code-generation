//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 100
#define BID_INCREMENT 1

typedef struct {
    char itemName[50];
    float startingPrice;
    float highestBid;
    char highestBidder[50];
    time_t endTime;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum auctions reached.\n");
        return;
    }

    Auction newAuction;
    printf("Enter the item name: ");
    scanf(" %[^\n]", newAuction.itemName);
    printf("Enter starting price: ");
    scanf("%f", &newAuction.startingPrice);
    newAuction.highestBid = newAuction.startingPrice;
    strcpy(newAuction.highestBidder, "None");
    newAuction.endTime = time(NULL) + 60; // Auction lasts for 60 seconds

    auctions[auctionCount] = newAuction;
    auctionCount++;
    printf("Auction created successfully for %s with starting price %.2f\n", newAuction.itemName, newAuction.startingPrice);
}

void placeBid() {
    char bidderName[50];
    printf("Enter your name: ");
    scanf(" %[^\n]", bidderName);

    int auctionIndex;
    printf("Enter auction number (0 to %d): ", auctionCount - 1);
    scanf("%d", &auctionIndex);
    
    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Invalid auction number.\n");
        return;
    }

    Auction *currentAuction = &auctions[auctionIndex];

    if (time(NULL) > currentAuction->endTime) {
        printf("The auction for %s has ended.\n", currentAuction->itemName);
        return;
    }

    float bidAmount;
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= currentAuction->highestBid) {
        printf("Your bid must be higher than the current highest bid of %.2f\n", currentAuction->highestBid);
        return;
    }

    currentAuction->highestBid = bidAmount;
    strcpy(currentAuction->highestBidder, bidderName);
    printf("Bid placed successfully! Current highest bid is %.2f by %s\n", currentAuction->highestBid, currentAuction->highestBidder);
}

void viewAuctions() {
    if (auctionCount == 0) {
        printf("No auctions available.\n");
        return;
    }

    for (int i = 0; i < auctionCount; i++) {
        Auction *a = &auctions[i];
        printf("Auction %d: Item: %s, Starting Price: %.2f, Highest Bid: %.2f by %s\n", 
            i, a->itemName, a->startingPrice, a->highestBid, a->highestBidder);
        if (time(NULL) > a->endTime) {
            printf("Status: This auction has ended.\n");
        } else {
            printf("Status: Ongoing\n");
        }
    }
}

void listMenu() {
    printf("\nDigital Auction System\n");
    printf("1. Create Auction\n");
    printf("2. Place Bid\n");
    printf("3. View Auctions\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    while (1) {
        listMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAuction();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                viewAuctions();
                break;
            case 4:
                printf("Exiting the auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}