//FormAI DATASET v1.0 Category: Digital Auction System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct for creating a new item in the auction
typedef struct {
    int id;
    char name[100];
    double startingBid;
    double currentBid;
    char highestBidder[100];
    int daysRemaining;
} AuctionItem;

// Global variables
int numItems = 0;
AuctionItem items[100];

// Function prototypes
void addAuctionItem();
void displayAuctionItems();
void bidOnAuctionItem();

int main() {
    int choice;
    while (1) {
        // Display menu
        printf("1. Add auction item\n");
        printf("2. Display auction items\n");
        printf("3. Bid on auction item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addAuctionItem();
                break;
            case 2:
                displayAuctionItems();
                break;
            case 3:
                bidOnAuctionItem();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }
}

// Function to add a new item to the auction
void addAuctionItem() {
    AuctionItem item;
    item.id = numItems + 1;

    printf("Enter item name: ");
    scanf("%s", item.name);

    printf("Enter starting bid: ");
    scanf("%lf", &item.startingBid);

    item.currentBid = item.startingBid;

    printf("Enter number of days remaining: ");
    scanf("%d", &item.daysRemaining);

    items[numItems] = item;
    numItems++;

    printf("\nAuction item added!\n");
}

// Function to display all items in the auction
void displayAuctionItems() {
    printf("Auction Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item #%d\n", items[i].id);
        printf("Name: %s\n", items[i].name);
        printf("Starting bid: %.2lf\n", items[i].startingBid);
        printf("Current bid: %.2lf\n", items[i].currentBid);
        printf("Highest bidder: %s\n", items[i].highestBidder);
        printf("Days remaining: %d\n", items[i].daysRemaining);
        printf("\n");
    }
}

// Function to make a bid on an item in the auction
void bidOnAuctionItem() {
    int itemId;
    printf("Enter item number to bid on: ");
    scanf("%d", &itemId);

    int itemIndex = -1;
    for (int i = 0; i < numItems; i++) {
        if (items[i].id == itemId) {
            itemIndex = i;
            break;
        }
    }

    if (itemIndex == -1) {
        printf("Item not found. Please try again.\n");
        return;
    }

    printf("Enter your name: ");
    char name[100];
    scanf("%s", name);

    printf("Enter your bid: ");
    double bid;
    scanf("%lf", &bid);

    if (bid > items[itemIndex].currentBid) {
        items[itemIndex].currentBid = bid;
        strcpy(items[itemIndex].highestBidder, name);
        printf("Bid accepted!\n");
    } else {
        printf("Bid not high enough. Please enter a higher bid.\n");
    }
}