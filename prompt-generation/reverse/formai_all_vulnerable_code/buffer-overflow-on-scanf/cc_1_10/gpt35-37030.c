//FormAI DATASET v1.0 Category: Digital Auction System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the bid information
struct Bid {
    char bidderName[50];
    float bidAmount;
};

// Structure to store the auction item details
struct AuctionItem {
    int itemId;
    char itemName[50];
    char itemDescription[200];
    float minimumBid;
    struct Bid highestBid;
};

// Function to display the details of an auction item
void displayAuctionItem(struct AuctionItem item) {
    printf("\nItem ID: %d", item.itemId);
    printf("\nItem Name: %s", item.itemName);
    printf("\nItem Description: %s", item.itemDescription);
    printf("\nMinimum Bid: %.2f", item.minimumBid);
    if (item.highestBid.bidAmount > 0) {
        printf("\nHighest Bid: %.2f by %s", item.highestBid.bidAmount, item.highestBid.bidderName);
    }
}

// Function to receive a bid for an auction item
void receiveBid(struct AuctionItem *item, char *bidderName, float bidAmount) {
    if (bidAmount > item->highestBid.bidAmount) {
        strcpy(item->highestBid.bidderName, bidderName);
        item->highestBid.bidAmount = bidAmount;
    }
}

// Function to initialize an auction item
void initializeAuctionItem(struct AuctionItem *item, int itemId, char *itemName, char *itemDescription, float minimumBid) {
    item->itemId = itemId;
    strcpy(item->itemName, itemName);
    strcpy(item->itemDescription, itemDescription);
    item->minimumBid = minimumBid;
    item->highestBid.bidAmount = 0;
}

int main() {
    // Initializing the auction items
    struct AuctionItem item1, item2;
    initializeAuctionItem(&item1, 1, "Oil Painting", "A beautiful oil painting of a sunset", 100.00);
    initializeAuctionItem(&item2, 2, "Antique Vase", "A rare antique vase from the Ming dynasty", 500.00);
    
    // Displaying the auction items
    printf("\nAuction Item 1:");
    displayAuctionItem(item1);
    printf("\n\nAuction Item 2:");
    displayAuctionItem(item2);
    
    // Receiving bids for the auction items
    char bidderName[50];
    float bidAmount;
    
    printf("\nEnter your bid for Auction Item 1: ");
    scanf("%f", &bidAmount);
    printf("Enter your name: ");
    scanf("%s", bidderName);
    receiveBid(&item1, bidderName, bidAmount);
    
    printf("\nEnter your bid for Auction Item 2: ");
    scanf("%f", &bidAmount);
    printf("Enter your name: ");
    scanf("%s", bidderName);
    receiveBid(&item2, bidderName, bidAmount);
    
    // Displaying the auction items with the highest bids
    printf("\nAuction Item 1:");
    displayAuctionItem(item1);
    printf("\n\nAuction Item 2:");
    displayAuctionItem(item2);
    
    return 0;
}