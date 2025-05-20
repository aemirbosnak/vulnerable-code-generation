//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define MAX_USERS 10

typedef struct {
    char itemName[50];
    float startingPrice;
    float currentBid;
    char currentHighestBidder[50];
    time_t auctionEndTime;
    int isActive;
} AuctionItem;

typedef struct {
    char username[50];
    char password[20];
} User;

AuctionItem auctionItems[MAX_ITEMS];
User users[MAX_USERS];
int itemCount = 0;
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    printf("Enter password: ");
    scanf("%s", users[userCount].password);
    userCount++;
    printf("Registration successful!\n");
}

void createAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Item limit reached. Cannot create more items.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", auctionItems[itemCount].itemName);
    printf("Enter starting price: ");
    scanf("%f", &auctionItems[itemCount].startingPrice);
    
    auctionItems[itemCount].currentBid = auctionItems[itemCount].startingPrice;
    strcpy(auctionItems[itemCount].currentHighestBidder, "None");
    
    auctionItems[itemCount].isActive = 1;
    auctionItems[itemCount].auctionEndTime = time(NULL) + 60; // Auction lasts for 60 seconds
    itemCount++;
    printf("Auction item created successfully!\n");
}

void placeBid() {
    char bidder[50];
    float bidAmount;
    printf("Enter your username: ");
    scanf("%s", bidder);
    
    printf("Enter bid amount: ");
    scanf("%f", &bidAmount);
    
    for (int i = 0; i < itemCount; i++) {
        if (auctionItems[i].isActive) {
            printf("Current highest bid for %s: %.2f by %s\n", 
                    auctionItems[i].itemName, 
                    auctionItems[i].currentBid, 
                    auctionItems[i].currentHighestBidder);
            if (bidAmount > auctionItems[i].currentBid) {
                auctionItems[i].currentBid = bidAmount;
                strcpy(auctionItems[i].currentHighestBidder, bidder);
                printf("Bid placed successfully! New highest bid: %.2f by %s\n", 
                       bidAmount, bidder);
            } else {
                printf("Bid amount must be greater than the current highest bid.\n");
            }
        }
    }
}

void endAuctions() {
    time_t currentTime = time(NULL);
    for (int i = 0; i < itemCount; i++) {
        if (auctionItems[i].isActive && auctionItems[i].auctionEndTime < currentTime) {
            auctionItems[i].isActive = 0;
            printf("Auction for %s has ended. Final bid: %.2f by %s\n", 
                    auctionItems[i].itemName, 
                    auctionItems[i].currentBid, 
                    auctionItems[i].currentHighestBidder);
        }
    }
}

void displayMenu() {
    printf("\n--- Digital Auction System ---\n");
    printf("1. Register User\n");
    printf("2. Create Auction Item\n");
    printf("3. Place Bid\n");
    printf("4. End Auctions\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
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
                endAuctions();
                break;
            case 5:
                printf("Exiting... Thank you for using the Digital Auction System!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}