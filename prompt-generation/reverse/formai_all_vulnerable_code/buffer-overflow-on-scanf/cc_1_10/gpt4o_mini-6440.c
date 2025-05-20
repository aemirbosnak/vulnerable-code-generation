//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_ITEMS 100
#define MAX_BIDS 500

typedef struct {
    char username[50];
} User;

typedef struct {
    char itemName[50];
    float startingPrice;
    float highestBid;
    User highestBidder;
    time_t auctionEndTime;
    bool isActive;
} AuctionItem;

typedef struct {
    char itemName[50];
    float bidAmount;
    User bidder;
} Bid;

User users[MAX_USERS];
AuctionItem items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int userCount = 0, itemCount = 0, bidCount = 0;

// Function declarations
void registerUser(char *username);
void createAuction(char *itemName, float startingPrice, int auctionDuration);
void placeBid(char *itemName, char *username, float bidAmount);
void listActiveAuctions();
void endAuction(char *itemName);

int main() {
    int choice;
    char username[50], itemName[50];
    float startingPrice, bidAmount;
    int auctionDuration;

    while (true) {
        printf("\nDigital Auction System\n");
        printf("1. Register User\n");
        printf("2. Create Auction\n");
        printf("3. Place Bid\n");
        printf("4. List Active Auctions\n");
        printf("5. End Auction\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0;  // Remove newline
                registerUser(username);
                break;
            case 2:
                printf("Enter item name: ");
                fgets(itemName, sizeof(itemName), stdin);
                itemName[strcspn(itemName, "\n")] = 0; 
                printf("Enter starting price: ");
                scanf("%f", &startingPrice);
                printf("Enter auction duration (in seconds): ");
                scanf("%d", &auctionDuration);
                createAuction(itemName, startingPrice, auctionDuration);
                break;
            case 3:
                printf("Enter item name: ");
                fgets(itemName, sizeof(itemName), stdin);
                itemName[strcspn(itemName, "\n")] = 0; 
                printf("Enter your username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; 
                printf("Enter bid amount: ");
                scanf("%f", &bidAmount);
                placeBid(itemName, username, bidAmount);
                break;
            case 4:
                listActiveAuctions();
                break;
            case 5:
                printf("Enter item name: ");
                fgets(itemName, sizeof(itemName), stdin);
                itemName[strcspn(itemName, "\n")] = 0; 
                endAuction(itemName);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void registerUser(char *username) {
    if (userCount < MAX_USERS) {
        strcpy(users[userCount].username, username);
        userCount++;
        printf("User '%s' registered successfully!\n", username);
    } else {
        printf("User registration limit reached!\n");
    }
}

void createAuction(char *itemName, float startingPrice, int auctionDuration) {
    if (itemCount < MAX_ITEMS) {
        AuctionItem item;
        strcpy(item.itemName, itemName);
        item.startingPrice = startingPrice;
        item.highestBid = startingPrice;
        item.isActive = true;
        item.auctionEndTime = time(NULL) + auctionDuration;
        items[itemCount++] = item;
        printf("Auction for '%s' created successfully!\n", itemName);
    } else {
        printf("Auction item limit reached!\n");
    }
}

void placeBid(char *itemName, char *username, float bidAmount) {
    for (int i = 0; i < itemCount; i++) {
        AuctionItem *item = &items[i];
        if (strcmp(item->itemName, itemName) == 0 && item->isActive) {
            if (time(NULL) >= item->auctionEndTime) {
                printf("Auction for '%s' has ended!\n", itemName);
                return;
            }
            if (bidAmount > item->highestBid) {
                item->highestBid = bidAmount;
                strcpy(item->highestBidder.username, username);
                printf("Bid of %.2f placed by '%s' on '%s'.\n", bidAmount, username, itemName);
                return;
            } else {
                printf("Bid must be higher than the current highest bid of %.2f.\n", item->highestBid);
                return;
            }
        }
    }
    printf("Auction for '%s' not found or is inactive.\n", itemName);
}

void listActiveAuctions() {
    printf("\nActive Auctions:\n");
    for (int i = 0; i < itemCount; i++) {
        AuctionItem *item = &items[i];
        if (item->isActive) {
            printf("Item: %s | Starting Price: %.2f | Current Highest Bid: %.2f | Ending Time: %s", 
                item->itemName, item->startingPrice, item->highestBid, 
                ctime(&item->auctionEndTime));
        }
    }
}

void endAuction(char *itemName) {
    for (int i = 0; i < itemCount; i++) {
        AuctionItem *item = &items[i];
        if (strcmp(item->itemName, itemName) == 0) {
            item->isActive = false;
            printf("Auction for '%s' has ended. Highest Bid: %.2f by %s\n", 
                item->itemName, item->highestBid, 
                item->highestBidder.username[0] ? item->highestBidder.username : "No bids placed");
            return;
        }
    }
    printf("Auction for '%s' not found.\n", itemName);
}