//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// Structure for each auction item
struct auctionItem {
    int itemID;
    char itemName[30];
    float currentBid;
    char bidderName[30];
    bool sold;
};

// Function to add new auction item
void addNewItem(struct auctionItem items[], int numItems) {
    // Prompt user for details of new item
    printf("\nEnter details of new item:\n");
    printf("Item ID: ");
    scanf("%d", &items[numItems].itemID);

    printf("Item Name: ");
    scanf("%s", items[numItems].itemName);

    printf("Starting Bid: ");
    scanf("%f", &items[numItems].currentBid);

    // Set initial bidder name to empty string and sold status to false
    strcpy(items[numItems].bidderName, "");
    items[numItems].sold = false;

    printf("\n%s successfully added to auction.\n", items[numItems].itemName);
}

// Function to display all current auction items
void displayItems(struct auctionItem items[], int numItems) {
    printf("\nCurrent Auction Items:\n");
    printf("%-10s%-30s%-20s%s\n", "Item ID", "Item Name", "Current Bid", "Bidder Name");
    for(int i=0; i<numItems; i++) {
        printf("%-10d%-30s%-20.2f%s\n", items[i].itemID, items[i].itemName, items[i].currentBid, items[i].bidderName);
    }
}

// Function to update bid on item
void updateBid(struct auctionItem items[], int numItems) {
    int itemID;
    float newBid;
    char bidderName[30];

    printf("\nEnter ID of item to bid on: ");
    scanf("%d", &itemID);

    // Check if item exists and is available for bidding
    bool itemFound = false;
    for(int i=0; i<numItems; i++) {
        if(items[i].itemID == itemID) {
            itemFound = true;
            if(items[i].sold) {
                printf("\n%s has already been sold to %s for %.2f. You cannot bid on it.\n", items[i].itemName, items[i].bidderName, items[i].currentBid);
                return;
            }
            printf("\nEnter your name: ");
            scanf("%s", bidderName);
            printf("Enter your bid: ");
            scanf("%f", &newBid);

            if(newBid <= items[i].currentBid) {
                printf("\nYour bid of %.2f is not higher than the current bid of %.2f.\n", newBid, items[i].currentBid);
                return;
            }

            // Update current bid and bidder name
            items[i].currentBid = newBid;
            strcpy(items[i].bidderName, bidderName);

            printf("\nNew bid of %.2f by %s accepted for %s.\n", newBid, bidderName, items[i].itemName);
            return;
        }
    }
    if(!itemFound) {
        printf("\nItem with ID %d not found.\n", itemID);
    }
}

// Function to sell item to highest bidder
void sellItem(struct auctionItem items[], int numItems) {
    int itemID;

    printf("\nEnter ID of item to sell: ");
    scanf("%d", &itemID);

    // Check if item exists and is available for selling
    bool itemFound = false;
    for(int i=0; i<numItems; i++) {
        if(items[i].itemID == itemID) {
            itemFound = true;
            if(items[i].sold) {
                printf("\n%s has already been sold to %s for %.2f. You cannot sell it again.\n", items[i].itemName, items[i].bidderName, items[i].currentBid);
                return;
            }
            // Set sold status to true
            items[i].sold = true;

            printf("\n%s sold to %s for %.2f.\n", items[i].itemName, items[i].bidderName, items[i].currentBid);
            return;
        }
    }
    if(!itemFound) {
        printf("\nItem with ID %d not found.\n", itemID);
    }
}

// Main program to run auction system
int main() {
    int numItems = 0;
    struct auctionItem items[10];

    while(true) {
        printf("\n\nAuction Menu:");
        printf("\n1. Add New Item");
        printf("\n2. Display Current Items");
        printf("\n3. Update Bid");
        printf("\n4. Sell Item");
        printf("\n5. Exit");
        printf("\nEnter choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: addNewItem(items, numItems);
                    numItems++;
                    break;
            case 2: displayItems(items, numItems);
                    break;
            case 3: updateBid(items, numItems);
                    break;
            case 4: sellItem(items, numItems);
                    break;
            case 5: printf("\nGoodbye!\n");
                    exit(0);
            default: printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}