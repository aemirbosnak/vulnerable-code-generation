//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_BIDS 100
#define MAX_ITEMS 10
#define NAME_LENGTH 50
#define PASSWORD_LENGTH 20
#define ITEM_NAME_LENGTH 50

typedef struct {
    char username[NAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int userId;
} User;

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    int itemId;
    int currentBid;
    int highestBidderId; // userId of the highest bidder
    int isActive;
} AuctionItem;

typedef struct {
    int userId;
    int bidAmount;
} Bid;

User users[MAX_USERS];
int userCount = 0;

AuctionItem auctionItems[MAX_ITEMS];
Bid bids[MAX_BIDS];
int bidCount = 0;

void generateRandomPassword(char *password) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < PASSWORD_LENGTH - 1; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[PASSWORD_LENGTH - 1] = '\0';
}

int authenticateUser(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return users[i].userId;
        }
    }
    return -1;
}

int registerUser(char *username, char *password) {
    if (userCount >= MAX_USERS) {
        printf("Maximum users reached.\n");
        return -1;
    }
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    users[userCount].userId = userCount + 1; // ID starts from 1
    userCount++;
    return users[userCount - 1].userId;
}

void addItem(char *itemName) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!auctionItems[i].isActive) {
            strcpy(auctionItems[i].itemName, itemName);
            auctionItems[i].itemId = i + 1;
            auctionItems[i].currentBid = 0;
            auctionItems[i].highestBidderId = 0;
            auctionItems[i].isActive = 1;
            printf("Item added: %s\n", itemName);
            return;
        }
    }
    printf("Auction items limit reached.\n");
}

void placeBid(int userId, int itemId, int bidAmount) {
    if (itemId < 1 || itemId > MAX_ITEMS || !auctionItems[itemId - 1].isActive) {
        printf("Invalid item ID.\n");
        return;
    }

    if (bidAmount <= auctionItems[itemId - 1].currentBid) {
        printf("Bid must be higher than the current bid of %d.\n", auctionItems[itemId - 1].currentBid);
        return;
    }

    // Log the bid
    bids[bidCount].userId = userId;
    bids[bidCount].bidAmount = bidAmount;
    bidCount++;

    auctionItems[itemId - 1].currentBid = bidAmount;
    auctionItems[itemId - 1].highestBidderId = userId;

    printf("Bid placed by User %d on Item %s for %d.\n", userId, auctionItems[itemId - 1].itemName, bidAmount);
}

void displayItems() {
    printf("Auction Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (auctionItems[i].isActive) {
            printf("Item ID: %d | Name: %s | Current Bid: %d | Highest Bidder ID: %d\n",
                   auctionItems[i].itemId, auctionItems[i].itemName,
                   auctionItems[i].currentBid, auctionItems[i].highestBidderId);
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random password generation
    char username[NAME_LENGTH], password[PASSWORD_LENGTH];
    int choice, userId;

    while (1) {
        printf("\n1. Register User\n2. Login\n3. Add Auction Item\n4. Place Bid\n5. Display Items\n6. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                generateRandomPassword(password);
                printf("Generated Password: %s\n", password);
                registerUser(username, password);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                userId = authenticateUser(username, password);
                if (userId != -1) {
                    printf("Login successful. User ID: %d\n", userId);
                } else {
                    printf("Invalid username or password.\n");
                }
                break;
            case 3:
                printf("Enter auction item name: ");
                char itemName[ITEM_NAME_LENGTH];
                scanf("%s", itemName);
                addItem(itemName);
                break;
            case 4:
                printf("Enter item ID to bid on: ");
                int itemId, bidAmount;
                scanf("%d", &itemId);
                printf("Enter bid amount: ");
                scanf("%d", &bidAmount);
                placeBid(userId, itemId, bidAmount);
                break;
            case 5:
                displayItems();
                break;
            case 6:
                printf("Exiting the auction system. Be cautious!\n");
                exit(0);
            default:
                printf("Invalid choice. Stay vigilant!\n");
                break;
        }
    }

    return 0;
}