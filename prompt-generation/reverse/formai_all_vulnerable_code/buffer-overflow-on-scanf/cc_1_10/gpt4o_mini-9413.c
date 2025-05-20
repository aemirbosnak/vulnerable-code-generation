//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define ITEM_NAME_LEN 50
#define BIDDER_NAME_LEN 50

typedef struct {
    char name[ITEM_NAME_LEN];
    int highestBid;
    char highestBidder[BIDDER_NAME_LEN];
    int active;
} Item;

typedef struct {
    char name[BIDDER_NAME_LEN];
} Bidder;

Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int itemCount = 0;
int bidderCount = 0;

void addBidder() {
    if (bidderCount < MAX_BIDDERS) {
        printf("Enter bidder name: ");
        scanf("%s", bidders[bidderCount].name);
        bidderCount++;
        printf("Bidder '%s' added!\n", bidders[bidderCount - 1].name);
    } else {
        printf("Maximum bidders reached!\n");
    }
}

void addItem() {
    if (itemCount < MAX_ITEMS) {
        printf("Enter item name: ");
        scanf("%s", items[itemCount].name);
        items[itemCount].highestBid = 0;
        strcpy(items[itemCount].highestBidder, "None");
        items[itemCount].active = 1;
        itemCount++;
        printf("Item '%s' added to auction!\n", items[itemCount - 1].name);
    } else {
        printf("Maximum items reached!\n");
    }
}

void placeBid() {
    char itemName[ITEM_NAME_LEN];
    char bidderName[BIDDER_NAME_LEN];
    int bidAmount;

    printf("Enter item name to bid on: ");
    scanf("%s", itemName);
    printf("Enter your name: ");
    scanf("%s", bidderName);
    printf("Enter your bid amount: ");
    scanf("%d", &bidAmount);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0 && items[i].active) {
            if (bidAmount > items[i].highestBid) {
                items[i].highestBid = bidAmount;
                strcpy(items[i].highestBidder, bidderName);
                printf("Bid of %d placed by %s on item '%s'!\n", bidAmount, bidderName, items[i].name);
            } else {
                printf("Your bid is too low! Current highest bid is %d by %s.\n", items[i].highestBid, items[i].highestBidder);
            }
            return;
        }
    }
    printf("Item not found or auction ended!\n");
}

void endAuction() {
    for (int i = 0; i < itemCount; i++) {
        if (items[i].active) {
            items[i].active = 0;
            printf("Auction for item '%s' ended!\n", items[i].name);
            printf("Final Bid: %d by %s\n", items[i].highestBid, items[i].highestBidder);
        }
    }
}

void displayItems() {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        if (items[i].active) {
            printf("Item: %s | Highest Bid: %d | Highest Bidder: %s\n", items[i].name, items[i].highestBid, items[i].highestBidder);
        }
    }
}

void displayBidders() {
    printf("\nRegistered Bidders:\n");
    for (int i = 0; i < bidderCount; i++) {
        printf("Bidder: %s\n", bidders[i].name);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nWelcome to the Digital Auction System!\n");
        printf("1. Add Bidder\n");
        printf("2. Add Item\n");
        printf("3. Place Bid\n");
        printf("4. End Auction\n");
        printf("5. Display Items\n");
        printf("6. Display Bidders\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBidder();
                break;
            case 2:
                addItem();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                endAuction();
                break;
            case 5:
                displayItems();
                break;
            case 6:
                displayBidders();
                break;
            case 7:
                printf("Thank you for using the Digital Auction System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}