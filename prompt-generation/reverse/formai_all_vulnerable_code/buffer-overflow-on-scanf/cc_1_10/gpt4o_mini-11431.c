//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float startingPrice;
    float currentPrice;
    int bids;
} AuctionItem;

void addItem(AuctionItem *items, int *itemCount);
void viewItems(AuctionItem *items, int itemCount);
void bidOnItem(AuctionItem *items, int itemCount);
void displayMenu();

int main() {
    AuctionItem items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                viewItems(items, itemCount);
                break;
            case 3:
                bidOnItem(items, itemCount);
                break;
            case 4:
                printf("Exiting the auction system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Digital Auction System ---\n");
    printf("1. Add Auction Item\n");
    printf("2. View Auction Items\n");
    printf("3. Bid on Item\n");
    printf("4. Exit\n");
}

void addItem(AuctionItem *items, int *itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Maximum item limit reached.\n");
        return;
    }

    AuctionItem newItem;
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    printf("Enter the starting price: ");
    scanf("%f", &newItem.startingPrice);
    newItem.currentPrice = newItem.startingPrice;
    newItem.bids = 0;

    items[*itemCount] = newItem;
    (*itemCount)++;

    printf("Item '%s' added successfully.\n", newItem.name);
}

void viewItems(AuctionItem *items, int itemCount) {
    if (itemCount == 0) {
        printf("No items available for auction.\n");
        return;
    }

    printf("\n--- Available Auction Items ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s\n", i + 1, items[i].name);
        printf("Current Price: $%.2f\n", items[i].currentPrice);
        printf("Total Bids: %d\n\n", items[i].bids);
    }
}

void bidOnItem(AuctionItem *items, int itemCount) {
    if (itemCount == 0) {
        printf("No items available for bidding.\n");
        return;
    }

    int itemIndex;
    float bidAmount;

    viewItems(items, itemCount);
    printf("Enter the number of the item you want to bid on: ");
    scanf("%d", &itemIndex);
    
    if (itemIndex < 1 || itemIndex > itemCount) {
        printf("Invalid item number.\n");
        return;
    }

    itemIndex--; // Adjust for zero-based index
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= items[itemIndex].currentPrice) {
        printf("Bid amount must be higher than the current price ($%.2f).\n", items[itemIndex].currentPrice);
        return;
    }

    items[itemIndex].currentPrice = bidAmount;
    items[itemIndex].bids++;
    printf("Bid placed successfully on '%s'. New price is $%.2f\n", items[itemIndex].name, items[itemIndex].currentPrice);
}