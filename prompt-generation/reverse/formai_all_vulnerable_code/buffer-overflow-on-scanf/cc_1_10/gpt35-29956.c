//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 10
#define MAX_BIDS 5

struct Item {
    int itemId;
    char itemName[50];
    float basePrice;
    float currentBid;
    bool auctionClosed;
    int bids[MAX_BIDS];
};

int numItems = 0;
struct Item items[MAX_ITEMS];

void addItem() {
    if (numItems >= MAX_ITEMS) {
        printf("Maximum number of items reached.\n");
        return;
    }

    struct Item item;

    printf("Enter item name: ");
    scanf("%s", item.itemName);

    printf("Enter base price: ");
    scanf("%f", &item.basePrice);

    item.currentBid = item.basePrice;
    item.auctionClosed = false;
    item.itemId = numItems + 1;

    items[numItems] = item;
    numItems++;

    printf("Item added successfully!\n");
}

void displayItems() {
    printf("ID\tITEM NAME\tBASE PRICE\tCURRENT BID\n");

    for (int i = 0; i < numItems; i++) {
        printf("%d\t%s\t\t%.2f\t\t%.2f\n", items[i].itemId, items[i].itemName, items[i].basePrice, items[i].currentBid);
    }
}

void placeBid() {
    int itemId, bidAmount;
    bool itemFound = false;

    printf("Enter item ID: ");
    scanf("%d", &itemId);

    for (int i = 0; i < numItems; i++) {
        if (items[i].itemId == itemId) {
            itemFound = true;

            if (items[i].auctionClosed) {
                printf("Auction for this item is closed.\n");
                return;
            }

            printf("Enter bid amount: ");
            scanf("%d", &bidAmount);

            if (bidAmount <= items[i].currentBid) {
                printf("Bid amount should be greater than current bid.\n");
                return;
            }

            for (int j = 0; j < MAX_BIDS; j++) {
                if (items[i].bids[j] == 0) {
                    items[i].bids[j] = bidAmount;
                    break;
                }
            }

            items[i].currentBid = bidAmount;
            printf("Bid placed successfully!\n");
            break;
        }
    }

    if (!itemFound) {
        printf("Invalid item ID.\n");
    }
}

void closeAuction() {
    int itemId;
    bool itemFound = false;

    printf("Enter item ID: ");
    scanf("%d", &itemId);

    for (int i = 0; i < numItems; i++) {
        if (items[i].itemId == itemId) {
            itemFound = true;

            if (items[i].auctionClosed) {
                printf("Auction for this item is already closed.\n");
                return;
            }

            items[i].auctionClosed = true;

            // Sort bids in descending order
            for (int j = 0; j < MAX_BIDS - 1; j++) {
                for (int k = j + 1; k < MAX_BIDS; k++) {
                    if (items[i].bids[j] < items[i].bids[k]) {
                        int temp = items[i].bids[j];
                        items[i].bids[j] = items[i].bids[k];
                        items[i].bids[k] = temp;
                    }
                }
            }

            printf("Item sold to highest bidder for %.2f\n", items[i].bids[0]);
            break;
        }
    }

    if (!itemFound) {
        printf("Invalid item ID.\n");
    }
}

int main() {
    int choice;

    while (true) {
        printf("\n1. Add item\n");
        printf("2. Display items\n");
        printf("3. Place bid\n");
        printf("4. Close auction\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
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
                closeAuction();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}