//FormAI DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to define each item being auctioned
typedef struct {
    char itemName[50];
    int minBid;
    int currBid;
    char currBidder[50];
} AuctionItem;

// Function to print the details of an auction item
void printAuctionItem(AuctionItem* item) {
    printf("Item Name: %s\n", item->itemName);
    printf("Minimum Bid: %d\n", item->minBid);
    printf("Current Bid: %d\n", item->currBid);
    printf("Current Bidder: %s\n\n", item->currBidder);
}

int main() {
    // Initialize the array of auction items
    AuctionItem items[3] = {
        {"Baseball Bat", 100, 100, ""},
        {"Vintage Book", 200, 200, ""},
        {"Rare Coin", 500, 500, ""}
    };

    // Infinite loop to accept bids until user quits
    int choice = 0;
    while (1) {
        // Print out the available items
        printf("Available Items:\n");
        for (int i = 0; i < 3; i++) {
            printf("%d. %s\n", i+1, items[i].itemName);
        }

        // Prompt user to select an item or quit
        printf("\nEnter the item number to bid on or enter 0 to quit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            // User quits
            printf("Thank you for using our auction system!\n");
            break;
        } else if (choice < 1 || choice > 3) {
            // Invalid input
            printf("Invalid input. Please try again.\n\n");
            continue;
        } else {
            AuctionItem* chosenItem = &items[choice-1];

            // Print out item details
            printAuctionItem(chosenItem);

            // Prompt user to enter bid
            int bid = 0;
            printf("Enter your bid: ");
            scanf("%d", &bid);

            if (bid <= chosenItem->currBid || bid < chosenItem->minBid) {
                // Invalid bid amount
                printf("Invalid bid amount. Please try again.\n\n");
            } else {
                // Update current bid and bidder
                chosenItem->currBid = bid;
                char bidderName[50];
                printf("Enter your name: ");
                scanf("%s", bidderName);
                strcpy(chosenItem->currBidder, bidderName);
                printf("Bid accepted! Thank you, %s!\n\n", bidderName);
            }
        }
    }

    return 0;
}