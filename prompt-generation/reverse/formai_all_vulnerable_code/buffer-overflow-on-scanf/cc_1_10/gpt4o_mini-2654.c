//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_BIDDERS 100
#define NAME_LENGTH 50

typedef struct {
    char itemName[NAME_LENGTH];
    float startingPrice;
    float currentHighestBid;
    char highestBidder[NAME_LENGTH];
} AuctionItem;

typedef struct {
    char bidderName[NAME_LENGTH];
    int registered;
} Bidder;

AuctionItem items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int itemCount = 0;
int bidderCount = 0;

void registerBidder(char *name) {
    if(bidderCount >= MAX_BIDDERS) {
        printf("Bidder registration limit reached.\n");
        return;
    }
    for(int i = 0; i < bidderCount; i++) {
        if(strcmp(bidders[i].bidderName, name) == 0) {
            printf("Bidder already registered.\n");
            return;
        }
    }
    strcpy(bidders[bidderCount].bidderName, name);
    bidders[bidderCount].registered = 1;
    bidderCount++;
    printf("Bidder %s registered successfully.\n", name);
}

void createAuctionItem(char *name, float price) {
    if(itemCount >= MAX_ITEMS) {
        printf("Auction item limit reached.\n");
        return;
    }
    strcpy(items[itemCount].itemName, name);
    items[itemCount].startingPrice = price;
    items[itemCount].currentHighestBid = price;
    strcpy(items[itemCount].highestBidder, "None");
    itemCount++;
    printf("Auction item %s created successfully with starting price %.2f.\n", name, price);
}

void placeBid(char *itemName, char *bidderName, float bidAmount) {
    for(int i = 0; i < itemCount; i++) {
        if(strcmp(items[i].itemName, itemName) == 0) {
            if(bidAmount > items[i].currentHighestBid) {
                items[i].currentHighestBid = bidAmount;
                strcpy(items[i].highestBidder, bidderName);
                printf("Bid of %.2f placed on item %s by bidder %s.\n", bidAmount, itemName, bidderName);
            } else {
                printf("Bid must be higher than the current highest bid of %.2f.\n", items[i].currentHighestBid);
            }
            return;
        }
    }
    printf("Item %s not found.\n", itemName);
}

void displayItems() {
    printf("\nAuction Items:\n");
    for(int i = 0; i < itemCount; i++) {
        printf("Item: %s, Starting Price: %.2f, Current Highest Bid: %.2f, Highest Bidder: %s\n",
               items[i].itemName, items[i].startingPrice, items[i].currentHighestBid,
               items[i].highestBidder);
    }
}

int main() {
    char name[NAME_LENGTH];
    int choice;
    float price;
    float bidAmount;
    
    while(1) {
        printf("\nDigital Auction System\n");
        printf("1. Register Bidder\n");
        printf("2. Create Auction Item\n");
        printf("3. Place Bid\n");
        printf("4. Display Auction Items\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline after int input

        switch(choice) {
            case 1:
                printf("Enter your name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                registerBidder(name);
                break;
            case 2:
                printf("Enter item name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                printf("Enter starting price: ");
                scanf("%f", &price);
                createAuctionItem(name, price);
                break;
            case 3:
                printf("Enter item name to bid on: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                printf("Enter your name: ");
                fgets(bidders[bidderCount].bidderName, NAME_LENGTH, stdin);
                bidders[bidderCount].bidderName[strcspn(bidders[bidderCount].bidderName, "\n")] = '\0'; // Remove newline character
                printf("Enter bid amount: ");
                scanf("%f", &bidAmount);
                placeBid(name, bidders[bidderCount].bidderName, bidAmount);
                break;
            case 4:
                displayItems();
                break;
            case 5:
                printf("Exiting the auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}