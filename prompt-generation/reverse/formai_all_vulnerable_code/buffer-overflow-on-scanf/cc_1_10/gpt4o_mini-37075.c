//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 100
#define MAX_ITEMS 100
#define BUFFER_SIZE 256

typedef struct {
    char name[BUFFER_SIZE];
    int startingBid;
    int currentBid;
    char highestBidder[BUFFER_SIZE];
    int auctionEndTime;
    int isActive;
} AuctionItem;

typedef struct {
    char username[BUFFER_SIZE];
    int totalBids;
} User;

AuctionItem items[MAX_ITEMS];
User users[MAX_USERS];
int userCount = 0;
int itemCount = 0;

void addUser(const char* username) {
    if (userCount < MAX_USERS) {
        strcpy(users[userCount++].username, username);
        printf("User %s added successfully.\n", username);
    } else {
        printf("User limit reached!\n");
    }
}

void createAuctionItem(const char* name, int startingBid, int auctionDuration) {
    if (itemCount < MAX_ITEMS) {
        strcpy(items[itemCount].name, name);
        items[itemCount].startingBid = startingBid;
        items[itemCount].currentBid = startingBid;
        strcpy(items[itemCount].highestBidder, "None");
        items[itemCount].auctionEndTime = time(NULL) + auctionDuration;
        items[itemCount].isActive = 1;
        printf("Auction item %s created with starting bid %d.\n", name, startingBid);
        itemCount++;
    } else {
        printf("Item limit reached!\n");
    }
}

void displayActiveAuctions() {
    printf("\n--- Active Auctions ---\n");
    for (int i = 0; i < itemCount; i++) {
        if (items[i].isActive) {
            printf("Item: %s, Current Bid: %d, Highest Bidder: %s\n", 
                    items[i].name, items[i].currentBid, items[i].highestBidder);
        }
    }
}

void placeBid(const char* username, const char* itemName, int bidAmount) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0 && items[i].isActive) {
            if (bidAmount > items[i].currentBid) {
                if (time(NULL) < items[i].auctionEndTime) {
                    items[i].currentBid = bidAmount;
                    strcpy(items[i].highestBidder, username);
                    printf("Bid placed successfully!\n");
                } else {
                    printf("Auction for %s has ended!\n", itemName);
                }
            } else {
                printf("Bid must be higher than the current bid!\n");
            }
            return;
        }
    }
    printf("Item not found or inactive!\n");
}

void endAuction(const char* itemName) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            items[i].isActive = 0;
            printf("Auction for %s ended. Winner: %s at %d\n", 
                    items[i].name, items[i].highestBidder, items[i].currentBid);
            return;
        }
    }
    printf("Item not found!\n");
}

void showMenu() {
    printf("\n--- Digital Auction System ---\n");
    printf("1. Add User\n");
    printf("2. Create Auction Item\n");
    printf("3. Display Active Auctions\n");
    printf("4. Place Bid\n");
    printf("5. End Auction\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    char buffer[BUFFER_SIZE];

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf
        switch (choice) {
            case 1:
                printf("Enter username: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                addUser(buffer);
                break;
            case 2:
                printf("Enter item name: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                int startingBid, auctionDuration;
                printf("Enter starting bid: ");
                scanf("%d", &startingBid);
                printf("Enter auction duration (seconds): ");
                scanf("%d", &auctionDuration);
                createAuctionItem(buffer, startingBid, auctionDuration);
                break;
            case 3:
                displayActiveAuctions();
                break;
            case 4:
                printf("Enter username: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                char itemName[BUFFER_SIZE];
                int bidAmount;
                printf("Enter item name: ");
                fgets(itemName, BUFFER_SIZE, stdin);
                itemName[strcspn(itemName, "\n")] = 0; // Remove newline
                printf("Enter bid amount: ");
                scanf("%d", &bidAmount);
                placeBid(buffer, itemName, bidAmount);
                break;
            case 5:
                printf("Enter item name to end auction: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                endAuction(buffer);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}