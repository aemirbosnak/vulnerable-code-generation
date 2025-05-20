//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50
#define USERNAME_LENGTH 30

typedef struct {
    int id;
    char name[ITEM_NAME_LENGTH];
    float startingPrice;
    float currentPrice;
    char highestBidder[USERNAME_LENGTH];
    int isActive;
} AuctionItem;

AuctionItem items[MAX_ITEMS];
int itemCount = 0;

void displayMenu() {
    printf("\nDigital Auction System\n");
    printf("1. Add Auction Item\n");
    printf("2. View Auction Items\n");
    printf("3. Place Bid\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Maximum item limit reached.\n");
        return;
    }
    AuctionItem newItem;
    newItem.id = itemCount + 1;

    printf("Enter item name: ");
    getchar(); // to consume newline character
    fgets(newItem.name, ITEM_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // remove newline character

    printf("Enter starting price: ");
    scanf("%f", &newItem.startingPrice);
    newItem.currentPrice = newItem.startingPrice;
    strcpy(newItem.highestBidder, "None");
    newItem.isActive = 1;

    items[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void viewItems() {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        if (items[i].isActive) {
            printf("Item ID: %d\n", items[i].id);
            printf("Name: %s\n", items[i].name);
            printf("Current Price: %.2f\n", items[i].currentPrice);
            printf("Highest Bidder: %s\n", items[i].highestBidder);
            printf("-----------------------\n");
        }
    }
}

void placeBid() {
    int itemId;
    char bidder[USERNAME_LENGTH];
    float bidAmount;

    printf("Enter item ID to bid on: ");
    scanf("%d", &itemId);
    if (itemId < 1 || itemId > itemCount || !items[itemId - 1].isActive) {
        printf("Invalid item ID.\n");
        return;
    }

    printf("Enter your name: ");
    getchar(); // to consume newline character
    fgets(bidder, USERNAME_LENGTH, stdin);
    bidder[strcspn(bidder, "\n")] = 0; // remove newline character

    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if (bidAmount <= items[itemId - 1].currentPrice) {
        printf("Bid must be higher than current price (%.2f).\n", items[itemId - 1].currentPrice);
    } else {
        items[itemId - 1].currentPrice = bidAmount;
        strcpy(items[itemId - 1].highestBidder, bidder);
        printf("Your bid has been placed successfully!\n");
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                printf("Exiting the auction system...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}