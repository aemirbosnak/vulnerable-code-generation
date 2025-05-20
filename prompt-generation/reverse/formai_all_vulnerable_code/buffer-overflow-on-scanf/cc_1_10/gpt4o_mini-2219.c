//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 100
#define MAX_AUCTIONS 50
#define NAME_LENGTH 50
#define ITEM_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    double highestBid;
    char highestBidder[NAME_LENGTH];
} Auction;

typedef struct {
    char username[NAME_LENGTH];
    double balance;
} User;

User users[MAX_USERS];
int userCount = 0;
Auction auctions[MAX_AUCTIONS];
int auctionCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    newUser.balance = 1000.0; // Assign initial balance
    users[userCount++] = newUser;
    printf("User %s registered successfully with a balance of $%.2f.\n", newUser.username, newUser.balance);
}

void createAuction() {
    if (auctionCount >= MAX_AUCTIONS) {
        printf("Auction limit reached!\n");
        return;
    }

    Auction newAuction;
    printf("Enter item name for auction: ");
    getchar(); // To consume the newline left by previous scanf
    fgets(newAuction.name, ITEM_LENGTH, stdin);
    newAuction.name[strcspn(newAuction.name, "\n")] = 0; // Remove newline character
    newAuction.highestBid = 0.0;
    strcpy(newAuction.highestBidder, "No bids yet");

    auctions[auctionCount++] = newAuction;
    printf("Auction for %s created successfully.\n", newAuction.name);
}

void placeBid() {
    char bidder[NAME_LENGTH];
    double bidAmount;
    printf("Enter your username: ");
    scanf("%s", bidder);

    // Find user
    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, bidder) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("User not found! Please register first.\n");
        return;
    }

    printf("Enter auction item name: ");
    getchar(); // To consume the newline left by previous scanf
    char auctionName[ITEM_LENGTH];
    fgets(auctionName, ITEM_LENGTH, stdin);
    auctionName[strcspn(auctionName, "\n")] = 0; // Remove newline character

    // Find auction
    int auctionIndex = -1;
    for (int i = 0; i < auctionCount; i++) {
        if (strcmp(auctions[i].name, auctionName) == 0) {
            auctionIndex = i;
            break;
        }
    }

    if (auctionIndex == -1) {
        printf("Auction not found!\n");
        return;
    }

    printf("Enter your bid amount: ");
    scanf("%lf", &bidAmount);

    // Validate bid
    if (bidAmount <= auctions[auctionIndex].highestBid) {
        printf("Bid must be higher than the current highest bid of $%.2f.\n", auctions[auctionIndex].highestBid);
        return;
    }
    if (bidAmount > users[userIndex].balance) {
        printf("Insufficient balance! Your current balance is $%.2f.\n", users[userIndex].balance);
        return;
    }

    // Accept bid
    users[userIndex].balance -= bidAmount;
    auctions[auctionIndex].highestBid = bidAmount;
    strcpy(auctions[auctionIndex].highestBidder, users[userIndex].username);
    printf("Bid of $%.2f placed by %s for %s.\n", bidAmount, users[userIndex].username, auctions[auctionIndex].name);
}

void viewAuctions() {
    printf("\nCurrent Auctions:\n");
    for (int i = 0; i < auctionCount; i++) {
        printf("Item: %s, Highest Bid: $%.2f, Highest Bidder: %s\n",
               auctions[i].name, auctions[i].highestBid, auctions[i].highestBidder);
    }
}

void viewUsers() {
    printf("\nRegistered Users:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Username: %s, Balance: $%.2f\n", users[i].username, users[i].balance);
    }
}

int main() {
    int choice;

    do {
        printf("\nDigital Auction System\n");
        printf("1. Register User\n");
        printf("2. Create Auction\n");
        printf("3. Place Bid\n");
        printf("4. View Auctions\n");
        printf("5. View Users\n");
        printf("6. Exit\n");
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
                viewAuctions();
                break;
            case 5:
                viewUsers();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}