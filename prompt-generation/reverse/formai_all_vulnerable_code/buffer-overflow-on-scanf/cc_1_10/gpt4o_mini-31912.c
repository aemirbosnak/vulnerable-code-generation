//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    int id;
    char name[50];
    double highestBid;
    int highestBidderID;
} AuctionItem;

typedef struct {
    int id;
    char name[50];
} User;

AuctionItem items[MAX_ITEMS];
User users[MAX_ITEMS];
int itemCount = 0;
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_ITEMS) {
        printf("User registration limit reached!\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", users[userCount].name);
    users[userCount].id = userCount + 1; // User ID starts from 1
    userCount++;
    printf("Registration successful! Your User ID: %d\n", users[userCount - 1].id);
}

void createAuctionItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Auction item limit reached!\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[itemCount].name);
    items[itemCount].id = itemCount + 1; // Item ID starts from 1
    items[itemCount].highestBid = 0;
    items[itemCount].highestBidderID = -1;
    itemCount++;
    printf("Auction item created successfully! Item ID: %d\n", items[itemCount - 1].id);
}

void placeBid() {
    int userID, itemID;
    double bidAmount;

    printf("Enter your User ID: ");
    scanf("%d", &userID);
    printf("Enter auction item ID: ");
    scanf("%d", &itemID);
    printf("Enter your bid amount: ");
    scanf("%lf", &bidAmount);

    if (itemID < 1 || itemID > itemCount || userID < 1 || userID > userCount) {
        printf("Invalid User ID or Item ID!\n");
        return;
    }

    AuctionItem *item = &items[itemID - 1];

    if (bidAmount > item->highestBid) {
        item->highestBid = bidAmount;
        item->highestBidderID = userID;
        printf("Bid placed successfully!\n");
    } else {
        printf("Your bid must be higher than the current highest bid of %.2f.\n", item->highestBid);
    }
}

void viewHighestBid() {
    int itemID;

    printf("Enter auction item ID: ");
    scanf("%d", &itemID);

    if (itemID < 1 || itemID > itemCount) {
        printf("Invalid Item ID!\n");
        return;
    }

    AuctionItem *item = &items[itemID - 1];

    if (item->highestBidderID != -1) {
        printf("Highest bid for %s: %.2f by User ID: %d\n", item->name, item->highestBid, item->highestBidderID);
    } else {
        printf("No bids placed for %s yet.\n", item->name);
    }
}

void displayItems() {
    printf("\nAuction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s\n", items[i].id, items[i].name);
    }
}

void displayMenu() {
    int choice;
    do {
        printf("\n--- Digital Auction System ---\n");
        printf("1. Register User\n");
        printf("2. Create Auction Item\n");
        printf("3. Place Bid\n");
        printf("4. View Highest Bid\n");
        printf("5. Display Items\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                viewHighestBid();
                break;
            case 5:
                displayItems();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    displayMenu();
    return 0;
}