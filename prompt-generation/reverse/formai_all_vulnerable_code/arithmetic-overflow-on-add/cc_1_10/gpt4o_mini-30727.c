//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float startingPrice;
    float currentBid;
    char currentBidder[MAX_NAME_LENGTH];
    time_t endTime;
} AuctionItem;

typedef struct {
    char bidderName[MAX_NAME_LENGTH];
    float bidAmount;
} Bid;

AuctionItem items[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Unable to add more items.\n");
        return;
    }
    AuctionItem newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter starting price: ");
    scanf("%f", &newItem.startingPrice);
    newItem.currentBid = newItem.startingPrice;
    newItem.endTime = time(NULL) + 60; // Auction ends in 60 seconds
    strcpy(newItem.currentBidder, "No bids yet");

    items[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void placeBid() {
    char bidderName[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", bidderName);

    printf("Select item number to bid on:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s (Current Bid: %.2f)\n", i + 1, items[i].name, items[i].currentBid);
    }

    int itemIndex;
    printf("Enter item number: ");
    scanf("%d", &itemIndex);
    
    if (itemIndex < 1 || itemIndex > itemCount) {
        printf("Invalid item number.\n");
        return;
    }
    itemIndex--; // Convert to zero-based index

    if (time(NULL) > items[itemIndex].endTime) {
        printf("Auction for this item has ended.\n");
        return;
    }

    float bidAmount;
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    
    if (bidAmount <= items[itemIndex].currentBid) {
        printf("Bid must be higher than current bid of %.2f.\n", items[itemIndex].currentBid);
        return;
    }

    items[itemIndex].currentBid = bidAmount;
    strcpy(items[itemIndex].currentBidder, bidderName);
    printf("Bid placed successfully! New highest bid is %.2f by %s\n", bidAmount, bidderName);
}

void displayItems() {
    printf("\nAuction Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s, Current Bid: %.2f, Current Bidder: %s\n", i + 1, items[i].name, items[i].currentBid, items[i].currentBidder);
        if (time(NULL) > items[i].endTime) {
            printf("Auction for this item has ended.\n");
        } else {
            printf("Auction ends in %ld seconds.\n", (items[i].endTime - time(NULL)));
        }
    }
}

void viewAuctionResults() {
    printf("\nAuction Results:\n");
    for (int i = 0; i < itemCount; i++) {
        if (time(NULL) > items[i].endTime) {
            printf("Item: %s, Final Bid: %.2f by %s\n", items[i].name, items[i].currentBid, items[i].currentBidder);
        } else {
            printf("Item: %s has not ended yet.\n", items[i].name);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Add Auction Item\n");
        printf("2. Place a Bid\n");
        printf("3. Display Auction Items\n");
        printf("4. View Auction Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                placeBid();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                viewAuctionResults();
                break;
            case 5:
                printf("Exiting the auction system.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}