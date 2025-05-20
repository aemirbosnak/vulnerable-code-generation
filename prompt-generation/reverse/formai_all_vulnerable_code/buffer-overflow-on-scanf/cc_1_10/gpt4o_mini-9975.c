//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 50
#define NAME_LENGTH 50
#define ITEM_NAME_LENGTH 100

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float startingPrice;
    float currentBid;
    char highestBidder[NAME_LENGTH];
    int isActive;
} AuctionItem;

typedef struct {
    char name[NAME_LENGTH];
    float budget;
} Bidder;

AuctionItem items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int itemCount = 0;
int bidderCount = 0;

void displayMenu() {
    printf("\nWelcome to the Digital Auction System!\n");
    printf("1. Add Auction Item\n");
    printf("2. Register Bidder\n");
    printf("3. Place a Bid\n");
    printf("4. Display Auction Items\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void addAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }
    
    AuctionItem item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter starting price: ");
    scanf("%f", &item.startingPrice);

    item.currentBid = item.startingPrice;
    item.isActive = 1; // Item is active
    strcpy(item.highestBidder, "None");

    items[itemCount++] = item;
    printf("Item added successfully!\n");
}

void registerBidder() {
    if (bidderCount >= MAX_BIDDERS) {
        printf("Error: Maximum number of bidders reached.\n");
        return;
    }

    Bidder bidder;
    printf("Enter bidder name: ");
    scanf("%s", bidder.name);
    printf("Enter budget: ");
    scanf("%f", &bidder.budget);

    bidders[bidderCount++] = bidder;
    printf("Bidder registered successfully!\n");
}

void placeBid() {
    char bidderName[NAME_LENGTH];
    char itemName[ITEM_NAME_LENGTH];
    
    printf("Enter your name: ");
    scanf("%s", bidderName);
    printf("Enter item name to bid on: ");
    scanf("%s", itemName);
    float bidAmount;
    printf("Enter your bid: ");
    scanf("%f", &bidAmount);

    // Search for the bidder
    int bidderIndex = -1;
    for (int i = 0; i < bidderCount; i++) {
        if (strcmp(bidders[i].name, bidderName) == 0) {
            bidderIndex = i;
            break;
        }
    }

    if (bidderIndex == -1) {
        printf("Error: Bidder not found.\n");
        return;
    }

    // Search for the auction item
    int itemIndex = -1;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0 && items[i].isActive) {
            itemIndex = i;
            break;
        }
    }

    if (itemIndex == -1) {
        printf("Error: Auction item not found or inactive.\n");
        return;
    }

    // Check if the bid is valid
    if (bidAmount <= items[itemIndex].currentBid || bidAmount > bidders[bidderIndex].budget) {
        printf("Error: Invalid bid amount.\n");
        return;
    }

    // Update the bid
    items[itemIndex].currentBid = bidAmount;
    strcpy(items[itemIndex].highestBidder, bidderName);
    printf("Bid placed successfully!\n");
}

void displayAuctionItems() {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        if (items[i].isActive) {
            printf("Item: %s, Current Bid: %.2f, Highest Bidder: %s\n",
                   items[i].name, items[i].currentBid, items[i].highestBidder);
        }
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAuctionItem();
                break;
            case 2:
                registerBidder();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                displayAuctionItems();
                break;
            case 5:
                printf("Exiting the Auction System. Thank you!\n");
                exit(0);
            default:
                printf("Error: Invalid option. Please try again.\n");
        }
    }

    return 0;
}