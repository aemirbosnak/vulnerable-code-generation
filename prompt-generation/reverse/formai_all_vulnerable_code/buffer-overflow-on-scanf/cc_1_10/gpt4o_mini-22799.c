//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Structure for an auction item
struct AuctionItem {
    int id;
    char name[MAX_NAME_LENGTH];
    float startingPrice;
    float currentBid;
    char highestBidder[MAX_NAME_LENGTH];
};

// Global variables
struct AuctionItem items[MAX_ITEMS];
int itemCount = 0;

// Function declarations
void addItem();
void displayItems();
void placeBid();

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n---- Digital Auction System ----\n");
        printf("1. Add Auction Item\n");
        printf("2. Display Auction Items\n");
        printf("3. Place a Bid\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                printf("Exiting the auction system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add an auction item
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Auction item limit reached! Cannot add more items.\n");
        return;
    }

    struct AuctionItem newItem;
    newItem.id = itemCount + 1;

    printf("Enter item name: ");
    scanf("%s", newItem.name);
    
    printf("Enter starting price: ");
    scanf("%f", &newItem.startingPrice);
    
    newItem.currentBid = newItem.startingPrice;
    strcpy(newItem.highestBidder, "None");

    items[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully! Item ID: %d\n", newItem.id);
}

// Function to display auction items
void displayItems() {
    if (itemCount == 0) {
        printf("No auction items available.\n");
        return;
    }

    printf("\n---- Auction Items ----\n");
    for (int i = 0; i < itemCount; i++) {
        struct AuctionItem item = items[i];
        printf("ID: %d | Name: %s | Starting Price: %.2f | Current Bid: %.2f | Highest Bidder: %s\n",
               item.id, item.name, item.startingPrice, item.currentBid, item.highestBidder);
    }
}

// Function to place a bid on an item
void placeBid() {
    int itemId;
    float bidAmount;
    char bidderName[MAX_NAME_LENGTH];

    printf("Enter item ID to bid on: ");
    scanf("%d", &itemId);

    if (itemId < 1 || itemId > itemCount) {
        printf("Invalid item ID!\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", bidderName);

    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= items[itemId - 1].currentBid) {
        printf("Your bid must be higher than the current bid!\n");
    } else {
        items[itemId - 1].currentBid = bidAmount;
        strcpy(items[itemId - 1].highestBidder, bidderName);
        printf("Bid placed successfully! Current highest bid for item ID %d is %.2f by %s\n",
               itemId, bidAmount, bidderName);
    }
}