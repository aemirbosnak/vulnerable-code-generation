//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_AUCTIONS 50
#define MAX_BID_HISTORY 100

typedef struct {
    char name[50];
    char email[50];
    int id;
} User;

typedef struct {
    char itemName[50];
    float startingBid;
    float currentBid;
    int auctionId;
    int creatorId;
    time_t endTime;
    int active;
} Auction;

typedef struct {
    int auctionId;
    int userId;
    float bidAmount;
    time_t bidTime;
} BidHistory;

User users[MAX_USERS];
Auction auctions[MAX_AUCTIONS];
BidHistory bidHistories[MAX_BID_HISTORY];
int userCount = 0;
int auctionCount = 0;
int bidHistoryCount = 0;

void displayMenu() {
    printf("\nDigital Auction System\n");
    printf("1. Register User\n");
    printf("2. Create Auction\n");
    printf("3. Place Bid\n");
    printf("4. View Auctions\n");
    printf("5. View Bid History\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached! Cannot register more users.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", users[userCount].name);
    printf("Enter email: ");
    scanf("%s", users[userCount].email);
    users[userCount].id = userCount + 1;
    printf("User registered successfully! User ID: %d\n", users[userCount].id);
    userCount++;
}

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Auction limit reached! Cannot create more auctions.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", auctions[auctionCount].itemName);
    printf("Enter starting bid: ");
    scanf("%f", &auctions[auctionCount].startingBid);
    auctions[auctionCount].currentBid = auctions[auctionCount].startingBid;
    auctions[auctionCount].auctionId = auctionCount + 1;
    auctions[auctionCount].creatorId = users[userCount - 1].id; // assign to last registered user
    auctions[auctionCount].active = 1;
    auctions[auctionCount].endTime = time(NULL) + 3600; // auction ends in 1 hour
    printf("Auction created successfully! Auction ID: %d\n", auctions[auctionCount].auctionId);
    auctionCount++;
}

void placeBid() {
    int auctionId, userId;
    float bidAmount;
    printf("Enter Auction ID to bid on: ");
    scanf("%d", &auctionId);
    
    if (auctionId <= 0 || auctionId > auctionCount || !auctions[auctionId - 1].active) {
        printf("Invalid Auction ID or auction not active.\n");
        return;
    }
    
    printf("Enter your User ID: ");
    scanf("%d", &userId);
    
    if (userId <= 0 || userId > userCount) {
        printf("Invalid User ID.\n");
        return;
    }
    
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    
    if (bidAmount <= auctions[auctionId - 1].currentBid) {
        printf("Bid amount must be higher than the current bid (%f).\n", auctions[auctionId - 1].currentBid);
        return;
    }

    // Record the bid
    bidHistories[bidHistoryCount].auctionId = auctionId;
    bidHistories[bidHistoryCount].userId = userId;
    bidHistories[bidHistoryCount].bidAmount = bidAmount;
    bidHistories[bidHistoryCount].bidTime = time(NULL);
    bidHistoryCount++;

    auctions[auctionId - 1].currentBid = bidAmount; // Update current bid
    printf("Bid placed successfully! Current Bid: %f\n", auctions[auctionId - 1].currentBid);
}

void viewAuctions() {
    printf("\nActive Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        if (auctions[i].active) {
            printf("Auction ID: %d, Item: %s, Starting Bid: %f, Current Bid: %f, Ends in: %ld seconds\n",
                   auctions[i].auctionId, auctions[i].itemName,
                   auctions[i].startingBid,
                   auctions[i].currentBid,
                   (long)(auctions[i].endTime - time(NULL)));
        }
    }
}

void viewBidHistory() {
    printf("\nBid History:\n");
    for (int i = 0; i < bidHistoryCount; i++) {
        printf("Auction ID: %d, User ID: %d, Bid Amount: %f, Time: %s",
               bidHistories[i].auctionId,
               bidHistories[i].userId,
               bidHistories[i].bidAmount,
               ctime(&bidHistories[i].bidTime));
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
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
                viewAuctions();
                break;
            case 5:
                viewBidHistory();
                break;
            case 6:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}