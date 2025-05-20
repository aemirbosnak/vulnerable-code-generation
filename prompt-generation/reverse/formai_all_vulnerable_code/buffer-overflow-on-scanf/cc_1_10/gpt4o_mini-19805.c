//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 100
#define MAX_BIDS 100

typedef struct {
    char bidderName[50];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[100];
    float startingPrice;
    int bidCount;
    Bid* bids[MAX_BIDS];
} Auction;

Auction* auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached.\n");
        return;
    }

    Auction* newAuction = (Auction*)malloc(sizeof(Auction));
    printf("Enter item name: ");
    scanf(" %[^\n]", newAuction->itemName);
    printf("Enter starting price: ");
    scanf("%f", &newAuction->startingPrice);
    newAuction->bidCount = 0;

    auctions[auctionCount++] = newAuction;
    printf("Auction created for item: %s with starting price: %.2f\n", newAuction->itemName, newAuction->startingPrice);
}

void placeBid() {
    char itemName[100];
    printf("Enter the item name to bid on: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i]->itemName, itemName) == 0) {
            if (auctions[i]->bidCount >= MAX_BIDS) {
                printf("Maximum number of bids reached for this auction.\n");
                return;
            }

            Bid* newBid = (Bid*)malloc(sizeof(Bid));
            printf("Enter your name: ");
            scanf(" %[^\n]", newBid->bidderName);
            printf("Enter your bid amount: ");
            scanf("%f", &newBid->bidAmount);

            if (newBid->bidAmount > auctions[i]->startingPrice) {
                auctions[i]->bids[auctions[i]->bidCount++] = newBid;
                printf("Bid placed by %s for %.2f on auction of %s.\n", newBid->bidderName, newBid->bidAmount, itemName);
            } else {
                free(newBid);
                printf("Bid amount must be greater than the starting price of %.2f.\n", auctions[i]->startingPrice);
            }
            return;
        }
    }
    printf("Auction not found for item: %s\n", itemName);
}

void viewAuction() {
    char itemName[100];
    printf("Enter the item name to view auction: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i]->itemName, itemName) == 0) {
            printf("Auction for %s\n", auctions[i]->itemName);
            printf("Starting Price: %.2f\n", auctions[i]->startingPrice);
            printf("Number of bids: %d\n", auctions[i]->bidCount);
            if (auctions[i]->bidCount > 0) {
                printf("Current leading bid:\n");
                Bid* highestBid = auctions[i]->bids[0];
                for (int j = 1; j < auctions[i]->bidCount; j++) {
                    if (auctions[i]->bids[j]->bidAmount > highestBid->bidAmount) {
                        highestBid = auctions[i]->bids[j];
                    }
                }
                printf("Bidder: %s, Amount: %.2f\n", highestBid->bidderName, highestBid->bidAmount);
            } else {
                printf("No bids placed yet.\n");
            }
            return;
        }
    }
    printf("Auction not found for item: %s\n", itemName);
}

void freeAuctions() {
    for (int i = 0; i < auctionCount; i++) {
        for (int j = 0; j < auctions[i]->bidCount; j++) {
            free(auctions[i]->bids[j]);
        }
        free(auctions[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\nDigital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. View Auction\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAuction();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                viewAuction();
                break;
            case 4:
                freeAuctions();
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}