//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float bidAmount;
} Bidder;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float startingPrice;
    int highestBidderId;
    float highestBid;
} AuctionItem;

AuctionItem items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int itemCount = 0, bidderCount = 0;

void displayMenu() {
    printf("\n--- Digital Auction System ---\n");
    printf("1. Add Bidder\n");
    printf("2. Add Item for Auction\n");
    printf("3. Place Bid\n");
    printf("4. Display Items\n");
    printf("5. View Results\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

void addBidder() {
    if (bidderCount >= MAX_BIDDERS) {
        printf("Cannot add more bidders.\n");
        return;
    }
    
    printf("Enter Bidder's Name: ");
    scanf("%s", bidders[bidderCount].name);
    bidders[bidderCount].id = bidderCount + 1;
    bidders[bidderCount].bidAmount = 0;
    bidderCount++;
    printf("Bidder added with ID: %d\n", bidders[bidderCount - 1].id);
}

void addItemForAuction() {
    if (itemCount >= MAX_ITEMS) {
        printf("Cannot add more auction items.\n");
        return;
    }
    
    printf("Enter Item Name: ");
    scanf("%s", items[itemCount].name);
    printf("Enter Starting Price: ");
    scanf("%f", &items[itemCount].startingPrice);
    
    items[itemCount].id = itemCount + 1;
    items[itemCount].highestBidderId = 0;
    items[itemCount].highestBid = items[itemCount].startingPrice;
    itemCount++;
    printf("Item added with ID: %d\n", items[itemCount - 1].id);
}

void placeBid() {
    int bidderId, itemId;
    float bidAmount;

    printf("Enter Bidder ID: ");
    scanf("%d", &bidderId);
    if (bidderId <= 0 || bidderId > bidderCount) {
        printf("Invalid Bidder ID.\n");
        return;
    }
    
    printf("Enter Item ID: ");
    scanf("%d", &itemId);
    if (itemId <= 0 || itemId > itemCount) {
        printf("Invalid Item ID.\n");
        return;
    }
    
    printf("Enter Bid Amount: ");
    scanf("%f", &bidAmount);
    
    if (bidAmount <= items[itemId - 1].highestBid) {
        printf("Bid must be higher than the current highest bid of %.2f\n", items[itemId - 1].highestBid);
        return;
    }
    
    items[itemId - 1].highestBid = bidAmount;
    items[itemId - 1].highestBidderId = bidderId;
    bidders[bidderId - 1].bidAmount = bidAmount;
    printf("Bid placed successfully!\n");
}

void displayItems() {
    printf("\n--- Auction Items ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item ID: %d, Name: %s, Starting Price: %.2f, Highest Bid: %.2f, Highest Bidder ID: %d\n", 
               items[i].id, items[i].name, items[i].startingPrice, items[i].highestBid, items[i].highestBidderId);
    }
}

void viewResults() {
    printf("\n--- Auction Results ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s, Final Price: %.2f, Winning Bidder ID: %d\n", 
               items[i].name, items[i].highestBid, items[i].highestBidderId);
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBidder();
                break;
            case 2:
                addItemForAuction();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                displayItems();
                break;
            case 5:
                viewResults();
                break;
            case 6:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}