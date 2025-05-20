//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_AUCTIONS 50
#define MAX_BIDS 100

typedef struct {
    char username[50];
    int userId;
} User;

typedef struct {
    char itemName[50];
    float startingBid;
    float currentBid;
    int highestBidderId;
} Auction;

typedef struct {
    int auctionId;
    float bidAmount;
    int bidderId;
} Bid;

User users[MAX_USERS];
Auction auctions[MAX_AUCTIONS];
Bid bids[MAX_BIDS];

int userCount = 0, auctionCount = 0, bidCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    users[userCount].userId = userCount;
    printf("User %s registered successfully with ID %d\n", users[userCount].username, users[userCount].userId);
    userCount++;
}

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Auction limit reached\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", auctions[auctionCount].itemName);
    printf("Enter starting bid: ");
    scanf("%f", &auctions[auctionCount].startingBid);
    
    auctions[auctionCount].currentBid = auctions[auctionCount].startingBid;
    auctions[auctionCount].highestBidderId = -1; // No bids yet
    printf("Auction for %s created successfully with starting bid of %.2f\n", auctions[auctionCount].itemName, auctions[auctionCount].startingBid);
    auctionCount++;
}

void placeBid() {
    int auctionId, bidderId;
    float bidAmount;

    printf("Enter auction ID to bid on (0 to %d): ", auctionCount - 1);
    scanf("%d", &auctionId);
    if (auctionId < 0 || auctionId >= auctionCount) {
        printf("Invalid auction ID\n");
        return;
    }

    printf("Enter your user ID (0 to %d): ", userCount - 1);
    scanf("%d", &bidderId);
    if (bidderId < 0 || bidderId >= userCount) {
        printf("Invalid user ID\n");
        return;
    }

    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    if (bidAmount <= auctions[auctionId].currentBid) {
        printf("Bid must be higher than the current bid of %.2f\n", auctions[auctionId].currentBid);
        return;
    }

    bids[bidCount].auctionId = auctionId;
    bids[bidCount].bidAmount = bidAmount;
    bids[bidCount].bidderId = bidderId;
    bidCount++;

    auctions[auctionId].currentBid = bidAmount;
    auctions[auctionId].highestBidderId = bidderId;
    printf("Bid of %.2f placed successfully by user %s\n", bidAmount, users[bidderId].username);
}

void viewCurrentBids() {
    for (int i = 0; i < auctionCount; i++) {
        printf("Auction ID: %d, Item: %s, Current Bid: %.2f, Highest Bidder: %s\n", 
               i, auctions[i].itemName, auctions[i].currentBid, 
               auctions[i].highestBidderId != -1 ? users[auctions[i].highestBidderId].username : "No bids yet");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Register User\n");
        printf("2. Create Auction\n");
        printf("3. Place Bid\n");
        printf("4. View Current Bids\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                createAuction();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                viewCurrentBids();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}