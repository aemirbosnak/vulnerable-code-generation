//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BIDDERS 50
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int bidAmount;
} Bidder;

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    int startingPrice;
    int currentPrice;
    Bidder highestBidder;
} AuctionItem;

AuctionItem items[MAX_ITEMS];
int itemCount = 0;

void addItem(const char *name, int startingPrice) {
    if (itemCount < MAX_ITEMS) {
        strcpy(items[itemCount].itemName, name);
        items[itemCount].startingPrice = startingPrice;
        items[itemCount].currentPrice = startingPrice;
        Bidder emptyBidder = {"None", 0};
        items[itemCount].highestBidder = emptyBidder;
        itemCount++;
        printf("Item '%s' added to auction with a starting price of $%d.\n", name, startingPrice);
    } else {
        printf("Failed to add item: auction limit reached!\n");
    }
}

void placeBid(int itemIndex, const char *bidderName, int amount) {
    if (itemIndex < 0 || itemIndex >= itemCount) {
        printf("Invalid Item Index!\n");
        return;
    }

    if (amount <= items[itemIndex].currentPrice) {
        printf("Bid must be higher than current price of $%d\n", items[itemIndex].currentPrice);
        return;
    }

    items[itemIndex].currentPrice = amount;
    strcpy(items[itemIndex].highestBidder.name, bidderName);
    items[itemIndex].highestBidder.bidAmount = amount;
    printf("Bid of $%d placed by %s on item '%s'.\n", amount, bidderName, items[itemIndex].itemName);
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items currently available for auction.\n");
        return;
    }

    printf("\n------ Auction Items ------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s\n", i+1, items[i].itemName);
        printf("  Starting Price: $%d\n", items[i].startingPrice);
        printf("  Current Price: $%d\n", items[i].currentPrice);
        printf("  Highest Bidder: %s ($%d)\n\n", items[i].highestBidder.name, items[i].highestBidder.bidAmount);
    }
    printf("---------------------------\n");
}

void closeAuction() {
    printf("Closing the auction...\n");
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].highestBidder.name, "None") != 0) {
            printf("Item '%s' sold to %s for $%d\n", items[i].itemName, items[i].highestBidder.name, items[i].highestBidder.bidAmount);
        } else {
            printf("Item '%s' had no bids and will not be sold.\n", items[i].itemName);
        }
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int price, amount;

    while (true) {
        printf("\n1. Add Auction Item\n2. Place Bid\n3. Display Items\n4. Close Auction\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter starting price: ");
                scanf("%d", &price);
                addItem(name, price);
                break;

            case 2:
                printf("Enter item index to bid on (1 to %d): ", itemCount);
                int itemIndex;
                scanf("%d", &itemIndex);
                itemIndex--; // adjust for zero-based indexing

                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your bid amount: ");
                scanf("%d", &amount);
                placeBid(itemIndex, name, amount);
                break;

            case 3:
                displayItems();
                break;

            case 4:
                closeAuction();
                return 0;

            case 5:
                printf("Exiting the auction system.\n");
                return 0;

            default:
                printf("Invalid option! Please select again.\n");
        }
    }
    return 0;
}