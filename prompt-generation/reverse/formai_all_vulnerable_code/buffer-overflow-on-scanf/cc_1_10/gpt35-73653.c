//FormAI DATASET v1.0 Category: Digital Auction System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME 50
#define MAX_BIDDER_NAME 30

struct Item {
    char name[MAX_ITEM_NAME];
    float highestBid;
    char highestBidder[MAX_BIDDER_NAME];
};

void printMenu() {
    printf("\n========== Auction Menu ==========\n");
    printf("1. View Items\n");
    printf("2. Add Item\n");
    printf("3. Place Bid\n");
    printf("4. View Highest Bid for an Item\n");
    printf("5. Exit\n");
}

void viewItems(struct Item *items, int numItems) {
    printf("\n========== Items ==========\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s: $%.2f (highest bid by %s)\n", i + 1, items[i].name, items[i].highestBid, items[i].highestBidder);
    }
}

void addItem(struct Item *items, int *numItems) {
    if (*numItems >= 100) {
        printf("\nMaximum number of items has been reached.\n");
        return;
    }

    printf("\nEnter item name: ");
    scanf("%s", items[*numItems].name);

    items[*numItems].highestBid = 0;
    strcpy(items[*numItems].highestBidder, "none");

    *numItems += 1;

    printf("\nThe item has been added to the auction.\n");
}

void placeBid(struct Item *items, int numItems) {
    int itemNum, bidderNameValid = 0;
    float bidAmount;
    char bidderName[MAX_BIDDER_NAME];

    viewItems(items, numItems);
    printf("\nEnter the item number you want to bid on: ");
    scanf("%d", &itemNum);

    if (itemNum < 1 || itemNum > numItems) {
        printf("\nInvalid item number.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", bidderName);

    while (!bidderNameValid) {
        printf("Enter your bid amount: $");
        scanf("%f", &bidAmount);
        if (bidAmount < items[itemNum-1].highestBid) {
            printf("\nBid must be higher than current highest bid of $%.2f\n", items[itemNum-1].highestBid);
        } else {
            bidderNameValid = 1;
        }
    }

    items[itemNum-1].highestBid = bidAmount;
    strcpy(items[itemNum-1].highestBidder, bidderName);

    printf("\nThank you for your bid, %s. Current highest bid for %s is $%.2f\n", bidderName, items[itemNum-1].name, items[itemNum-1].highestBid);
}

void viewHighestBid(struct Item *items, int numItems) {
    int itemNum;

    viewItems(items, numItems);
    printf("\nEnter the item number: ");
    scanf("%d", &itemNum);

    if (itemNum < 1 || itemNum > numItems) {
        printf("\nInvalid item number.\n");
        return;
    }

    printf("\nThe highest bid for %s is $%.2f (by %s)\n", items[itemNum-1].name, items[itemNum-1].highestBid, items[itemNum-1].highestBidder);
}

int main() {
    struct Item items[100];
    int numItems = 0;
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewItems(items, numItems);
                break;
            case 2:
                addItem(items, &numItems);
                break;
            case 3:
                placeBid(items, numItems);
                break;
            case 4:
                viewHighestBid(items, numItems);
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}