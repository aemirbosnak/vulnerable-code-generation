//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_AUCTIONS 50
#define MAX_BIDS 100

typedef struct {
    char name[50];
    float amount;
} Bid;

typedef struct {
    char itemName[50];
    char owner[50];
    float startingBid;
    float currentBid;
    Bid bids[MAX_BIDS];
    int bidCount;
} Auction;

typedef struct {
    char username[50];
} User;

User users[MAX_USERS];
Auction auctions[MAX_AUCTIONS];
int userCount = 0;
int auctionCount = 0;

void addUser(char *username) {
    strcpy(users[userCount++].username, username);
    printf("Welcome, %s! You are successfully registered in our system!\n", username);
}

void createAuction(char *itemName, char *owner, float startingBid) {
    Auction newAuction;
    strcpy(newAuction.itemName, itemName);
    strcpy(newAuction.owner, owner);
    newAuction.startingBid = startingBid;
    newAuction.currentBid = startingBid;
    newAuction.bidCount = 0;
    
    auctions[auctionCount++] = newAuction;
    printf("Hooray! Auction for '%s' has been created by %s with a starting bid of $%.2f!\n", itemName, owner, startingBid);
}

void placeBid(char *username, int auctionIndex, float bidAmount) {
    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Oops! This auction doesn't exist.\n");
        return;
    }
    
    if (bidAmount <= auctions[auctionIndex].currentBid) {
        printf("Oh no! Your bid must be higher than the current bid of $%.2f.\n", auctions[auctionIndex].currentBid);
        return;
    }

    Bid newBid;
    strcpy(newBid.name, username);
    newBid.amount = bidAmount;
    
    auctions[auctionIndex].bids[auctions[auctionIndex].bidCount++] = newBid;
    auctions[auctionIndex].currentBid = bidAmount;
    
    printf("Congratulations, %s! You've placed a bid of $%.2f on '%s'!\n", username, bidAmount, auctions[auctionIndex].itemName);
}

void viewAuctions() {
    printf("\n====== Current Auctions ======\n");
    for (int i = 0; i < auctionCount; i++) {
        printf("Auction #%d: Item: '%s', Owned by: %s, Current Bid: $%.2f\n",
               i, auctions[i].itemName, auctions[i].owner, auctions[i].currentBid);
    }
    printf("==============================\n");
}

void viewBids(int auctionIndex) {
    if (auctionIndex < 0 || auctionIndex >= auctionCount) {
        printf("Oops! This auction doesn't exist.\n");
        return;
    }
    
    printf("\nBids for '%s':\n", auctions[auctionIndex].itemName);
    for (int i = 0; i < auctions[auctionIndex].bidCount; i++) {
        printf("Bidder: %s, Amount: $%.2f\n", auctions[auctionIndex].bids[i].name, auctions[auctionIndex].bids[i].amount);
    }
}

int main() {
    char command[50];
    printf("Welcome to the Happy Digital Auction System! Let’s have some fun!\n");
    
    while (1) {
        printf("Choose an action: [register, create, bid, view_auctions, view_bids, exit] ");
        scanf("%s", command);
        
        if (strcmp(command, "register") == 0) {
            char username[50];
            printf("Enter your username: ");
            scanf("%s", username);
            addUser(username);
        } else if (strcmp(command, "create") == 0) {
            char itemName[50], owner[50];
            float startingBid;

            printf("Enter item name: ");
            scanf("%s", itemName);
            printf("Enter your username (owner): ");
            scanf("%s", owner);
            printf("Enter starting bid: ");
            scanf("%f", &startingBid);

            createAuction(itemName, owner, startingBid);
        } else if (strcmp(command, "bid") == 0) {
            char username[50];
            int auctionIndex;
            float bidAmount;

            printf("Enter your username: ");
            scanf("%s", username);
            printf("Enter auction number: ");
            scanf("%d", &auctionIndex);
            printf("Enter your bid amount: ");
            scanf("%f", &bidAmount);

            placeBid(username, auctionIndex, bidAmount);
        } else if (strcmp(command, "view_auctions") == 0) {
            viewAuctions();
        } else if (strcmp(command, "view_bids") == 0) {
            int auctionIndex;
            printf("Enter auction number to view bids: ");
            scanf("%d", &auctionIndex);
            viewBids(auctionIndex);
        } else if (strcmp(command, "exit") == 0) {
            printf("Thank you for participating in our Happy Digital Auction System! See you next time!\n");
            exit(0);
        } else {
            printf("Hmm... That command isn't valid. Let's keep it cheerful and try again!\n");
        }
    }

    return 0;
}