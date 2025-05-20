//FormAI DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for auction items
struct AuctionItem {
    int itemNumber;
    char itemName[50];
    char itemDescription[100];
    float startingPrice;
    float currentBid;
};

// Function to add items to the auction
void addItem(struct AuctionItem *items[], int *numItems) {
    // Create new item
    struct AuctionItem *newItem = malloc(sizeof(struct AuctionItem));
    
    // Get input for item details
    printf("Enter item name: ");
    scanf("%s", newItem->itemName);
    printf("Enter item description: ");
    scanf("%s", newItem->itemDescription);
    printf("Enter starting price: ");
    scanf("%f", &newItem->startingPrice);
    
    // Set item number and current bid to 0
    newItem->itemNumber = *numItems + 1;
    newItem->currentBid = 0.00;
    
    // Add new item to items array
    items[*numItems] = newItem;
    
    // Increment numItems
    (*numItems)++;
    
    printf("\nItem %d added to auction successfully!\n", newItem->itemNumber);
}

// Function to display all items in the auction
void displayItems(struct AuctionItem *items[], int numItems) {
    printf("\n-----------------------------\n");
    printf("ITEMS CURRENTLY UP FOR AUCTION\n");
    printf("-----------------------------\n");
    
    for (int i = 0; i < numItems; i++) {
        printf("Item Number: %d\n", items[i]->itemNumber);
        printf("Item Name: %s\n", items[i]->itemName);
        printf("Item Description: %s\n", items[i]->itemDescription);
        printf("Starting Price: $%.2f\n", items[i]->startingPrice);
        printf("Current Bid: $%.2f\n", items[i]->currentBid);
        printf("-----------------------------\n");
    }
}

// Function to allow a bidder to place a bid on an item
void placeBid(struct AuctionItem *items[], int numItems) {
    // Display all items so bidder can choose which one to bid on
    displayItems(items, numItems);
    
    // Get input for item number and bid amount
    int itemNum;
    float bidAmount;
    printf("Enter item number you want to bid on: ");
    scanf("%d", &itemNum);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);
    
    // Find item to bid on
    struct AuctionItem *itemToBidOn;
    for (int i = 0; i < numItems; i++) {
        if (items[i]->itemNumber == itemNum) {
            itemToBidOn = items[i];
            break;
        }
    }
    
    // Check if bid is higher than current bid and starting price
    if (bidAmount <= itemToBidOn->currentBid || bidAmount < itemToBidOn->startingPrice) {
        printf("\nYour bid must be higher than the current bid and the starting price.\n");
        return;
    }
    
    // Set new current bid
    itemToBidOn->currentBid = bidAmount;
    
    printf("\nBid placed successfully!\n");
}

int main() {
    printf("Welcome to the Digital Auction System!\n");
    
    // Define array of pointers to AuctionItem structs
    struct AuctionItem *items[100];
    int numItems = 0;
    
    // Display menu options until user chooses to exit
    int choice;
    do {
        printf("\n------------------\n");
        printf("AUCTION MENU\n");
        printf("------------------\n");
        printf("1. Add an item to the auction\n");
        printf("2. Display all items currently up for auction\n");
        printf("3. Place a bid on an item\n");
        printf("4. Exit the auction\n");
        printf("------------------\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                displayItems(items, numItems);
                break;
            case 3:
                placeBid(items, numItems);
                break;
            case 4:
                printf("\nThank you for using the Digital Auction System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}