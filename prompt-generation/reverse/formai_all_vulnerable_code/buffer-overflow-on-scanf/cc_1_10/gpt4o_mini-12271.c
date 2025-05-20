//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float highestBid;
    char highestBidder[MAX_NAME_LENGTH];
} AuctionItem;

typedef struct {
    char username[MAX_NAME_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;
AuctionItem items[MAX_ITEMS];
int itemCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }
    printf("Enter your username: ");
    scanf("%s", users[userCount].username);
    userCount++;
    printf("User %s registered successfully!\n\n", users[userCount - 1].username);
}

void createAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Auction item limit reached.\n");
        return;
    }
    printf("Enter the item name: ");
    scanf("%s", items[itemCount].name);
    items[itemCount].highestBid = 0.0;
    strcpy(items[itemCount].highestBidder, "None");
    itemCount++;
    printf("Auction item %s created successfully!\n\n", items[itemCount - 1].name);
}

void placeBid() {
    char username[MAX_NAME_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);
    
    // Check if user is registered
    int userFound = 0;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            userFound = 1;
            break;
        }
    }
    if (!userFound) {
        printf("User not found, please register first.\n");
        return;
    }

    char itemName[MAX_NAME_LENGTH];
    float bidAmount;
    printf("Enter the item name to bid on: ");
    scanf("%s", itemName);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    
    // Find the auction item
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            if (bidAmount > items[i].highestBid) {
                items[i].highestBid = bidAmount;
                strcpy(items[i].highestBidder, username);
                printf("Bid placed successfully!\n");
            } else {
                printf("Bid amount must be higher than the current highest bid.\n");
            }
            return;
        }
    }
    printf("Auction item not found.\n");
}

void showAuctionItems() {
    printf("Current Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s | Highest Bid: %.2f | Highest Bidder: %s\n", 
                items[i].name, 
                items[i].highestBid, 
                items[i].highestBidder);
    }
    printf("\n");
}

void displayMenu() {
    printf("Welcome to the Digital Auction System\n");
    printf("1. Register User\n");
    printf("2. Create Auction Item\n");
    printf("3. Place Bid\n");
    printf("4. Show Auction Items\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                createAuctionItem();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                showAuctionItems();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}