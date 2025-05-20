//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_BIDS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float startingBid;
    float currentBid;
    char highestBidder[NAME_LENGTH];
} Item;

Item items[MAX_ITEMS];
int itemCount = 0;

void displayItems() {
    printf("\nAvailable Items for Auction:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s\n", i + 1, items[i].name);
        printf("Starting Bid: $%.2f\n", items[i].startingBid);
        printf("Current Bid: $%.2f\n", items[i].currentBid);
        printf("Highest Bidder: %s\n", items[i].highestBidder[0] ? items[i].highestBidder : "None");
        printf("------------------------------------------------\n");
    }
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Auction is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    
    printf("Enter item name: ");
    scanf(" %[^\n]%*c", newItem.name);
    
    printf("Enter starting bid: ");
    scanf("%f", &newItem.startingBid);
    
    newItem.currentBid = newItem.startingBid;
    newItem.highestBidder[0] = '\0'; // No bidders yet

    items[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void placeBid() {
    int itemIndex;
    char bidderName[NAME_LENGTH];
    float bidAmount;

    printf("Enter the item number you want to bid on: ");
    scanf("%d", &itemIndex);
    
    if (itemIndex < 1 || itemIndex > itemCount) {
        printf("Invalid item number.\n");
        return;
    }
    
    itemIndex--; // Convert to 0-based index

    printf("Enter your name: ");
    scanf(" %[^\n]%*c", bidderName);
    
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    
    if (bidAmount > items[itemIndex].currentBid) {
        items[itemIndex].currentBid = bidAmount;
        strcpy(items[itemIndex].highestBidder, bidderName);
        printf("Bid placed successfully!\n");
    } else {
        printf("Bid amount must be higher than the current bid!\n");
    }
}

void viewCurrentBids() {
    printf("\nCurrent Bids:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s, Current Bid: $%.2f, Highest Bidder: %s\n", 
               items[i].name, 
               items[i].currentBid, 
               items[i].highestBidder[0] ? items[i].highestBidder : "None");
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Add Item\n");
        printf("2. View Available Items\n");
        printf("3. Place Bid\n");
        printf("4. View Current Bids\n");
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
                viewCurrentBids();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}