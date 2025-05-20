//FormAI DATASET v1.0 Category: Digital Auction System ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store item information
struct item {
    char itemName[100];
    int itemID;
    float startingPrice;
    float currentPrice;
    char bidderName[100];
};

// Declare global variables
struct item itemList[100];
int numItems = 0;
float minBidIncrement = 1.0;

// Function to add an item to the list
void addItem() {
    printf("Enter item name: ");
    scanf("%s", itemList[numItems].itemName);
    printf("Enter item ID: ");
    scanf("%d", &itemList[numItems].itemID);
    printf("Enter starting price: ");
    scanf("%f", &itemList[numItems].startingPrice);
    itemList[numItems].currentPrice = itemList[numItems].startingPrice;
    strcpy(itemList[numItems].bidderName, "-");
    numItems++;
}

// Function to display all items
void displayItems() {
    printf("Item ID\tItem Name\tStarting Price\tCurrent Price\tBidder Name\n");
    for(int i=0; i<numItems; i++) {
        printf("%d\t%s\t%f\t%f\t%s\n", itemList[i].itemID, itemList[i].itemName, itemList[i].startingPrice, itemList[i].currentPrice, itemList[i].bidderName);
    }
}

// Function to get the index of an item by ID
int getItemIndex(int itemID) {
    for(int i=0; i<numItems; i++) {
        if(itemList[i].itemID == itemID) {
            return i;
        }
    }
    return -1;
}

// Function to place a bid on an item
void placeBid() {
    int itemID, itemIndex;
    float bidAmount;
    char bidderName[100];
    printf("Enter item ID: ");
    scanf("%d", &itemID);
    itemIndex = getItemIndex(itemID);
    if(itemIndex == -1) {
        printf("Invalid item ID.\n");
        return;
    }
    printf("Enter bidder name: ");
    scanf("%s", bidderName);
    printf("Enter bid amount: ");
    scanf("%f", &bidAmount);
    if(bidAmount < itemList[itemIndex].currentPrice + minBidIncrement) {
        printf("Bid amount must be at least %f higher than current price.\n", minBidIncrement);
        return;
    }
    itemList[itemIndex].currentPrice = bidAmount;
    strcpy(itemList[itemIndex].bidderName, bidderName);
    printf("Bid placed successfully!\n");
}

int main() {
    int choice;
    do {
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Place bid\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
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
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(1);
    return 0;
}