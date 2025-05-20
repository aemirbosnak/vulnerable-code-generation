//FormAI DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

/* Structure for bidding information */
struct Bid {
    int bidderId;
    double bidAmount;
};

/* Structure for auction item */
struct AuctionItem {
    int itemId;
    char itemName[50];
    struct Bid highestBid;
};

/* Recursive function to perform digital auction */
void auction(struct AuctionItem items[], int n, int i) {
    double bidAmount;
    int bidderId;
    printf("\n\n--- ITEM %d ---\n", items[i].itemId);
    printf("Item Name: %s\n", items[i].itemName);
    printf("Current Highest Bid: %.2f, By Bidder ID: %d\n", items[i].highestBid.bidAmount, items[i].highestBid.bidderId);
    printf("Enter Your Bid Amount: ");
    scanf("%lf", &bidAmount);
    printf("Enter Your Bidder ID: ");
    scanf("%d", &bidderId);
    if(bidAmount <= items[i].highestBid.bidAmount) {
        printf("Your Bid is too low, Try Again!\n");
        auction(items, n, i); // Recursive Call
    } else {
        items[i].highestBid.bidAmount = bidAmount;
        items[i].highestBid.bidderId = bidderId;
        printf("Congratulations!! You are the highest bidder now.\n");
        if(i < n-1) {
            auction(items, n, i+1); // Recursive Call
        } else {
            printf("\n\n\n--- AUCTION OVER ---\n");
            for(int i=0; i<n; i++) {
                printf("Item ID: %d, Item Name: %s, Highest Bid: %.2f, Winner Bidder ID: %d\n", 
                    items[i].itemId, items[i].itemName, items[i].highestBid.bidAmount, items[i].highestBid.bidderId);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the Number of Auction Items: ");
    scanf("%d", &n);
    struct AuctionItem items[n];
    for(int i=0; i<n; i++) {
        printf("\n\n--- ITEM %d ---\n", i+1);
        items[i].itemId = i+1;
        printf("Enter Item Name: ");
        scanf("%s", items[i].itemName);
        items[i].highestBid.bidAmount = 0.0;
        items[i].highestBid.bidderId = -1;
    }
    auction(items, n, 0); // Start Auction for Item 1
    return 0;
}