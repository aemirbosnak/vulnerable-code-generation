//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_ITEMS 5
#define NAME_LENGTH 50

typedef struct {
    char itemName[NAME_LENGTH];
    float currentBid;
    char highestBidder[NAME_LENGTH];
} AuctionItem;

typedef struct {
    char username[NAME_LENGTH];
    float balance;
} User;

User users[MAX_USERS];
AuctionItem items[MAX_ITEMS];
int userCount = 0;
int itemCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    users[userCount].balance = 100.0; // Each user starts with 100 balance
    userCount++;
    printf("User %s registered successfully!\n", users[userCount - 1].username);
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Item limit reached!\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", items[itemCount].itemName);
    items[itemCount].currentBid = 0.0;
    strcpy(items[itemCount].highestBidder, "None");
    itemCount++;
    printf("Item %s added successfully!\n", items[itemCount - 1].itemName);
}

void placeBid() {
    char bidder[NAME_LENGTH];
    char itemName[NAME_LENGTH];
    float bidAmount;

    printf("Enter your username: ");
    scanf("%s", bidder);
    
    // Verify if user exists
    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, bidder) == 0) {
            userIndex = i;
            break;
        }
    }
    if (userIndex == -1) {
        printf("User does not exist!\n");
        return;
    }

    printf("Enter item name for bidding: ");
    scanf("%s", itemName);
    
    // Search for the item
    int itemIndex = -1;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].itemName, itemName) == 0) {
            itemIndex = i;
            break;
        }
    }
    if (itemIndex == -1) {
        printf("Item does not exist!\n");
        return;
    }

    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= items[itemIndex].currentBid) {
        printf("Bid must be higher than current bid of %.2f.\n", items[itemIndex].currentBid);
        return;
    }
    if (bidAmount > users[userIndex].balance) {
        printf("Insufficient funds! Your balance is %.2f\n", users[userIndex].balance);
        return;
    }

    // Update the user's balance and the item's current bid
    users[userIndex].balance -= bidAmount;
    items[itemIndex].currentBid = bidAmount;
    strcpy(items[itemIndex].highestBidder, bidder);
    printf("Bid of %.2f placed by %s on %s successfully!\n", bidAmount, bidder, itemName);
}

void displayAuctionItems() {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s, Current Bid: %.2f, Highest Bidder: %s\n", 
                items[i].itemName, items[i].currentBid, items[i].highestBidder);
    }
}

void displayUsers() {
    printf("\nRegistered Users:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Username: %s, Balance: %.2f\n", users[i].username, users[i].balance);
    }
}

void menu() {
    while (1) {
        printf("\n--- Digital Auction System Menu ---\n");
        printf("1. Register User\n");
        printf("2. Add Item\n");
        printf("3. Place Bid\n");
        printf("4. Display Items\n");
        printf("5. Display Users\n");
        printf("6. Exit\n");
        printf("Select an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                addItem();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                displayAuctionItems();
                break;
            case 5:
                displayUsers();
                break;
            case 6:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Digital Auction System!\n");
    menu();
    return 0;
}