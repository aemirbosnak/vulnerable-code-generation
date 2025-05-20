//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum bid length and maximum item description length
#define MAX_BID_LENGTH 10
#define MAX_DESCRIPTION_LENGTH 50

// Define struct for auction items
struct auctionItem {
    char description[MAX_DESCRIPTION_LENGTH];
    double highestBid;
    char highestBidder[MAX_BID_LENGTH];
};

// Define function to create new auction item
void createAuctionItem(struct auctionItem *item) {
    printf("Enter item description: ");
    fgets(item->description, MAX_DESCRIPTION_LENGTH, stdin);
    item->description[strcspn(item->description, "\n")] = '\0'; // Remove trailing newline character
    
    printf("Enter starting bid: ");
    scanf("%lf", &item->highestBid);
    getchar(); // Clear trailing newline character
    
    printf("Enter bidder name: ");
    fgets(item->highestBidder, MAX_BID_LENGTH, stdin);
    item->highestBidder[strcspn(item->highestBidder, "\n")] = '\0'; // Remove trailing newline character
}

// Define function to print auction item details
void printAuctionItem(struct auctionItem item) {
    printf("Item Description: %s\n", item.description);
    printf("Highest Bid: %.2lf\n", item.highestBid);
    printf("Current Highest Bidder: %s\n", item.highestBidder);
}

int main() {
    int numItems;
    struct auctionItem *items;
    
    // Prompt user to enter number of auction items
    printf("Enter number of auction items: ");
    scanf("%d", &numItems);
    
    // Allocate memory for array of auction items
    items = (struct auctionItem*) malloc(numItems * sizeof(struct auctionItem));
    
    // Loop through each auction item and create it
    for (int i = 0; i < numItems; i++) {
        printf("\nCreating Item %d\n", i+1);
        createAuctionItem(&items[i]); // Pass address of auction item to function
    }
    
    // Print details of each auction item
    printf("\nAuction Item Details:\n");
    for (int i = 0; i < numItems; i++) {
        printf("\nItem %d:\n", i+1);
        printAuctionItem(items[i]);
    }
    
    // Free memory allocated for array of auction items
    free(items);
    
    return 0;
}