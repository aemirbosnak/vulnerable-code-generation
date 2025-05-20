//FormAI DATASET v1.0 Category: Digital Auction System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME 50
#define MAX_ITEM_DESC 100
#define MAX_USERS 10
#define MAX_BIDS 100

// Structure to hold information about each item
struct AuctionItem {
    char name[MAX_ITEM_NAME];
    char description[MAX_ITEM_DESC];
    double currentBid;
    char highestBidder[MAX_USERS];
    int uniqueID;
};

// Structure to hold information about each user
struct AuctionUser {
    char username[MAX_USERS];
    double funds;
};

// Structure to hold information about each bid
struct AuctionBid {
    int itemID;
    char bidder[MAX_USERS];
    double bidValue;
};

// Global variables
struct AuctionItem items[MAX_BIDS];
struct AuctionUser users[MAX_USERS];
struct AuctionBid bids[MAX_BIDS];
int totalItems = 0;
int totalUsers = 0;
int totalBids = 0;

// Function to add a new item to the auction
void addItem() {
    struct AuctionItem newItem;
    printf("Enter item name: ");
    fgets(newItem.name, MAX_ITEM_NAME, stdin);
    printf("Enter item description: ");
    fgets(newItem.description, MAX_ITEM_DESC, stdin);
    printf("Enter starting bid: ");
    scanf("%lf", &newItem.currentBid);
    while(getchar() != '\n'); // Clear remaining input
    newItem.uniqueID = totalItems++;
    items[newItem.uniqueID] = newItem;
    printf("Item added successfully with ID %d\n", newItem.uniqueID);
}

// Function to add a new user to the auction
void addUser() {
    struct AuctionUser newUser;
    printf("Enter username: ");
    fgets(newUser.username, MAX_USERS, stdin);
    printf("Enter starting funds: ");
    scanf("%lf", &newUser.funds);
    while(getchar() != '\n'); // Clear remaining input
    totalUsers++;
    users[totalUsers-1] = newUser;
    printf("User added successfully with ID %d\n", totalUsers-1);
}

// Function to display all items currently being auctioned
void displayItems() {
    printf("Items currently being auctioned:\n");
    for(int i=0; i<totalItems; i++) {
        printf("ID: %d | Name: %s | Description: %s | Current Bid: %.2f | Highest Bidder: %s\n", items[i].uniqueID, items[i].name, items[i].description, items[i].currentBid, items[i].highestBidder);
    }
}

// Function to display all users in the auction
void displayUsers() {
    printf("All users in the auction:\n");
    for(int i=0; i<totalUsers; i++) {
        printf("ID: %d | Username: %s | Funds: %.2f\n", i, users[i].username, users[i].funds);
    }
}

// Function to display all bids made in the auction
void displayBids() {
    printf("All bids made in the auction:\n");
    for(int i=0; i<totalBids; i++) {
        printf("Item ID: %d | Bidder: %s | Bid Value: %.2f\n", bids[i].itemID, bids[i].bidder, bids[i].bidValue);
    }
}

// Function to place a bid on an item
void placeBid() {
    int itemID, bidderID;
    double bidValue;
    printf("Enter item ID to bid on: ");
    scanf("%d", &itemID);
    while(getchar() != '\n'); // Clear remaining input
    printf("Enter bidder ID: ");
    scanf("%d", &bidderID);
    while(getchar() != '\n'); // Clear remaining input
    printf("Enter bid value: ");
    scanf("%lf", &bidValue);
    while(getchar() != '\n'); // Clear remaining input
    if(bidValue > items[itemID].currentBid) {
        strcpy(items[itemID].highestBidder, users[bidderID].username);
        items[itemID].currentBid = bidValue;
        struct AuctionBid newBid = {itemID, users[bidderID].username, bidValue};
        bids[totalBids++] = newBid;
        printf("Bid successful!\n");
    } else {
        printf("Bid not high enough\n");
    }
}

// Main function to run the program
int main() {
    char input;
    do {
        printf("\n\nWelcome to the Digital Auction System:\n");
        printf("1. Add Item\n");
        printf("2. Add User\n");
        printf("3. Display Items\n");
        printf("4. Display Users\n");
        printf("5. Display Bids\n");
        printf("6. Place Bid\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%c", &input);
        while(getchar() != '\n'); // Clear remaining input

        switch(input) {
            case '1':
                addItem();
                break;
            case '2':
                addUser();
                break;
            case '3':
                displayItems();
                break;
            case '4':
                displayUsers();
                break;
            case '5':
                displayBids();
                break;
            case '6':
                placeBid();
                break;
            case '0':
                printf("Exiting Auction System\n");
                break;
            default:
                printf("Invalid input, try again.\n");
        }
    } while(input != '0');

    return 0;
}