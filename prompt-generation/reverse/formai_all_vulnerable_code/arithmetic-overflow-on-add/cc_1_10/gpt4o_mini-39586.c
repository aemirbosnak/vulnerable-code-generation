//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_BIDS 100
#define ITEM_NAME_LENGTH 50
#define USERNAME_LENGTH 50

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    float startPrice;
    float currentBid;
    char highestBidder[USERNAME_LENGTH];
    time_t endTime;
} AuctionItem;

typedef struct {
    char username[USERNAME_LENGTH];
    float bidAmount;
} Bid;

// Function prototypes
void initializeAuctionItems(AuctionItem items[], int count);
void displayItems(AuctionItem items[], int count);
void placeBid(AuctionItem *item, const char *username, float amount);
void closeAuction(AuctionItem items[], int count);

int main() {
    AuctionItem items[MAX_ITEMS];
    initializeAuctionItems(items, MAX_ITEMS);

    int choice;
    char username[USERNAME_LENGTH];
    
    printf("Welcome to the Decentralized Digital Auction System!\n");

    while (1) {
        printf("\n1. Display items\n2. Place a bid\n3. Close auction\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayItems(items, MAX_ITEMS);
                break;
            case 2:
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter item index to bid on (0-%d): ", MAX_ITEMS - 1);
                int index;
                scanf("%d", &index);
                if (index < 0 || index >= MAX_ITEMS) {
                    printf("Invalid item index.\n");
                    break;
                }
                printf("Enter your bid amount: ");
                float bidAmount;
                scanf("%f", &bidAmount);
                placeBid(&items[index], username, bidAmount);
                break;
            case 3:
                closeAuction(items, MAX_ITEMS);
                break;
            case 4:
                printf("Exiting the Auction System.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void initializeAuctionItems(AuctionItem items[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(items[i].itemName, ITEM_NAME_LENGTH, "Item %d", i + 1);
        items[i].startPrice = (float)(10 + i * 5);
        items[i].currentBid = items[i].startPrice;
        strcpy(items[i].highestBidder, "None");
        items[i].endTime = time(NULL) + 60; // Auction lasts for 60 seconds
    }
}

void displayItems(AuctionItem items[], int count) {
    printf("\nAvailable Auction Items:\n");
    for (int i = 0; i < count; i++) {
        printf("Index: %d, Name: %s, Current Bid: %.2f, Highest Bidder: %s\n",
               i, items[i].itemName, items[i].currentBid, items[i].highestBidder);
    }
}

void placeBid(AuctionItem *item, const char *username, float amount) {
    if (time(NULL) > item->endTime) {
        printf("Auction for %s is closed. No bids can be placed.\n", item->itemName);
        return;
    }

    if (amount <= item->currentBid) {
        printf("Your bid must be higher than the current bid of %.2f.\n", item->currentBid);
        return;
    }

    item->currentBid = amount;
    strcpy(item->highestBidder, username);
    printf("Bid of %.2f placed by %s on %s.\n", amount, username, item->itemName);
}

void closeAuction(AuctionItem items[], int count) {
    printf("\nClosing Auction:\n");
    for (int i = 0; i < count; i++) {
        if (time(NULL) > items[i].endTime) {
            printf("Item: %s, Final Bid: %.2f, Winner: %s\n",
                   items[i].itemName, items[i].currentBid, items[i].highestBidder);
        }
    }
}