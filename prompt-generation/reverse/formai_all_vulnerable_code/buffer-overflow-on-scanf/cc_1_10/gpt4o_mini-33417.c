//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 10
#define ITEM_NAME_LEN 50

typedef struct {
    char name[ITEM_NAME_LEN];
    float startingBid;
    float highestBid;
    char highestBidder[ITEM_NAME_LEN];
    int auctionActive;
} AuctionItem;

AuctionItem auctionItems[MAX_ITEMS];
int itemCount = 0;

void displayMenu() {
    printf("Welcome to the Digital Auction System\n");
    printf("1. Add Auction Item\n");
    printf("2. Make a Bid\n");
    printf("3. Display Items\n");
    printf("4. End Auction\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Cannot add more items, limit reached!\n");
        return;
    }
    
    printf("Enter item name: ");
    scanf("%s", auctionItems[itemCount].name);
    printf("Enter starting bid: ");
    scanf("%f", &auctionItems[itemCount].startingBid);
    
    auctionItems[itemCount].highestBid = auctionItems[itemCount].startingBid;
    strcpy(auctionItems[itemCount].highestBidder, "None");
    auctionItems[itemCount].auctionActive = 1;
    
    itemCount++;
    printf("Auction item added: %s starting at %.2f\n", auctionItems[itemCount - 1].name, auctionItems[itemCount - 1].startingBid);
}

void makeBid() {
    if (itemCount == 0) {
        printf("No auction items available!\n");
        return;
    }
    
    char bidder[ITEM_NAME_LEN];
    printf("Enter your name: ");
    scanf("%s", bidder);
    
    printf("Select item number to bid on:\n");
    for (int i = 0; i < itemCount; i++) {
        if (auctionItems[i].auctionActive) {
            printf("%d. %s (Current bid: %.2f)\n", i + 1, auctionItems[i].name, auctionItems[i].highestBid);
        }
    }

    int itemNumber;
    printf("Enter item number: ");
    scanf("%d", &itemNumber);
    
    if (itemNumber < 1 || itemNumber > itemCount || !auctionItems[itemNumber - 1].auctionActive) {
        printf("Invalid item selected!\n");
        return;
    }
    
    float bidAmount;
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    
    if (bidAmount <= auctionItems[itemNumber - 1].highestBid) {
        printf("Bid must be higher than the current bid of %.2f!\n", auctionItems[itemNumber - 1].highestBid);
        return;
    }
    
    auctionItems[itemNumber - 1].highestBid = bidAmount;
    strcpy(auctionItems[itemNumber - 1].highestBidder, bidder);
    printf("Bid placed successfully! New highest bid for %s is %.2f by %s.\n",
           auctionItems[itemNumber - 1].name, auctionItems[itemNumber - 1].highestBid, bidder);
}

void displayItems() {
    if (itemCount == 0) {
        printf("No auction items to display!\n");
        return;
    }
    
    printf("Auction Items Currently Active:\n");
    for (int i = 0; i < itemCount; i++) {
        if (auctionItems[i].auctionActive) {
            printf("Item: %s | Starting Bid: %.2f | Highest Bid: %.2f | Highest Bidder: %s\n",
                   auctionItems[i].name, auctionItems[i].startingBid, auctionItems[i].highestBid, auctionItems[i].highestBidder);
        }
    }
}

void endAuction() {
    if (itemCount == 0) {
        printf("No auction items to end!\n");
        return;
    }
    
    printf("Ending Auctions:\n");
    for (int i = 0; i < itemCount; i++) {
        if (auctionItems[i].auctionActive) {
            printf("Auction for %s ended. Final Price: %.2f by %s\n",
                   auctionItems[i].name, auctionItems[i].highestBid, auctionItems[i].highestBidder);
            auctionItems[i].auctionActive = 0; // mark item as inactive
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
                makeBid();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                endAuction();
                break;
            case 5:
                printf("Exiting the Digital Auction System. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select from the menu.\n");
        }
    }
    
    return 0;
}