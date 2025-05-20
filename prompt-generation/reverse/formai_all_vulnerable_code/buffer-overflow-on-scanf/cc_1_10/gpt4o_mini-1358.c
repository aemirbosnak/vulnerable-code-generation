//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 10
#define MAX_USERS 100
#define ITEM_NAME_LEN 50
#define USERNAME_LEN 30

typedef struct {
    char username[USERNAME_LEN];
    int bidAmount;
} Bid;

typedef struct {
    char itemName[ITEM_NAME_LEN];
    char auctioneer[USERNAME_LEN];
    Bid bids[MAX_BIDS];
    int bidCount;
} Auction;

typedef struct {
    char username[USERNAME_LEN];
} User;

Auction auctions[MAX_AUCTIONS];
User users[MAX_USERS];
int auctionCount = 0;
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached, cannot register more users.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    userCount++;
    printf("User %s registered successfully!\n", users[userCount - 1].username);
}

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Auction limit reached, cannot create more auctions.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", auctions[auctionCount].itemName);
    printf("Enter your username: ");
    scanf("%s", auctions[auctionCount].auctioneer);
    auctions[auctionCount].bidCount = 0;
    auctionCount++;
    printf("Auction for %s created successfully!\n", auctions[auctionCount - 1].itemName);
}

void placeBid() {
    char username[USERNAME_LEN];
    char itemName[ITEM_NAME_LEN];
    int bidAmount;
    
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter item name you want to bid on: ");
    scanf("%s", itemName);
    printf("Enter your bid amount: ");
    scanf("%d", &bidAmount);
    
    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].itemName, itemName) == 0) {
            if (auctions[i].bidCount >= MAX_BIDS) {
                printf("Bid limit reached for this auction.\n");
                return;
            }
            strcpy(auctions[i].bids[auctions[i].bidCount].username, username);
            auctions[i].bids[auctions[i].bidCount].bidAmount = bidAmount;
            auctions[i].bidCount++;
            printf("Bid of %d placed by %s on %s.\n", bidAmount, username, itemName);
            return;
        }
    }
    printf("Auction for %s not found.\n", itemName);
}

void viewAuctions() {
    if (auctionCount == 0) {
        printf("No active auctions.\n");
        return;
    }
    for (int i = 0; i < auctionCount; i++) {
        printf("Auction #%d\n", i + 1);
        printf("Item: %s, Auctioneer: %s\n", auctions[i].itemName, auctions[i].auctioneer);
        if (auctions[i].bidCount == 0) {
            printf("No bids placed yet.\n");
        } else {
            for (int j = 0; j < auctions[i].bidCount; j++) {
                printf("Bidder: %s, Amount: %d\n", auctions[i].bids[j].username, auctions[i].bids[j].bidAmount);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("Digital Auction System\n");
        printf("1. Register User\n");
        printf("2. Create Auction\n");
        printf("3. Place Bid\n");
        printf("4. View Auctions\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
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
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}