//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 100
#define MAX_BIDS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char bidderName[MAX_NAME_LENGTH];
    float bidAmount;
} Bid;

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    char itemDescription[MAX_DESCRIPTION_LENGTH];
    float startingBid;
    Bid bids[MAX_BIDS];
    int bidCount;
} Auction;

Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached!\n");
        return;
    }

    Auction newAuction;
    printf("Enter item name: ");
    scanf(" %[^\n]%*c", newAuction.itemName);
    printf("Enter item description: ");
    scanf(" %[^\n]%*c", newAuction.itemDescription);
    printf("Enter starting bid: ");
    scanf("%f", &newAuction.startingBid);
    
    newAuction.bidCount = 0;
    auctions[auctionCount++] = newAuction;

    printf("Auction created successfully!\n");
}

void placeBid() {
    char itemName[MAX_NAME_LENGTH];
    printf("Enter item name to bid on: ");
    scanf(" %[^\n]%*c", itemName);

    // Find the auction
    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].itemName, itemName) == 0) {
            float bidAmount;
            char bidderName[MAX_NAME_LENGTH];

            printf("Enter your name: ");
            scanf(" %[^\n]%*c", bidderName);
            printf("Enter bid amount: ");
            scanf("%f", &bidAmount);

            if (bidAmount >= auctions[i].startingBid) {
                int validBid = 1;
                for (int j = 0; j < auctions[i].bidCount; j++) {
                    if (auctions[i].bids[j].bidAmount >= bidAmount) {
                        validBid = 0;
                        break;
                    }
                }

                if (validBid) {
                    auctions[i].bids[auctions[i].bidCount].bidAmount = bidAmount;
                    strcpy(auctions[i].bids[auctions[i].bidCount].bidderName, bidderName);
                    auctions[i].bidCount++;
                    printf("Bid placed successfully!\n");
                } else {
                    printf("Bid amount must be higher than previous bids!\n");
                }
            } else {
                printf("Bid amount must be at least %.2f!\n", auctions[i].startingBid);
            }

            return;
        }
    }
    printf("Auction not found!\n");
}

void displayAuctions() {
    if (auctionCount == 0) {
        printf("No auctions available.\n");
        return;
    }

    printf("Current Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        printf("Auction %d: %s\n", i + 1, auctions[i].itemName);
        printf("Description: %s\n", auctions[i].itemDescription);
        printf("Starting Bid: %.2f\n", auctions[i].startingBid);
        if (auctions[i].bidCount > 0) {
            printf("Bids:\n");
            for (int j = 0; j < auctions[i].bidCount; j++) {
                printf("  Bidder: %s, Amount: %.2f\n", auctions[i].bids[j].bidderName, auctions[i].bids[j].bidAmount);
            }
        } else {
            printf("No bids yet.\n");
        }
        printf("----------\n");
    }
}

int main() {
    int choice;
    do {
        printf("Digital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. Display Auctions\n");
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
                displayAuctions();
                break;
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}