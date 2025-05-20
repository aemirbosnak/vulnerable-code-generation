//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_AUCTIONS 5
#define NAME_LENGTH 50
#define ITEM_LENGTH 100

typedef struct {
    int id;
    char item[ITEM_LENGTH];
    double startingBid;
    double highestBid;
    char highestBidder[NAME_LENGTH];
} Auction;

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Bidder;

void displayAuctions(Auction auctions[], int count) {
    printf("\nAvailable Auctions:\n");
    for (int i = 0; i < count; i++) {
        printf("Auction ID: %d | Item: %s | Starting Bid: %.2f | Current Highest Bid: %.2f (by %s)\n",
               auctions[i].id, auctions[i].item, auctions[i].startingBid, auctions[i].highestBid,
               auctions[i].highestBidder[0] ? auctions[i].highestBidder : "No bids yet");
    }
}

void placeBid(Bidder bidders[], Auction *auction, double bid, char bidderName[]) {
    if (bid > auction->highestBid) {
        auction->highestBid = bid;
        strncpy(auction->highestBidder, bidderName, NAME_LENGTH);
        printf("Bid of %.2f placed by %s on Auction ID: %d for item %s\n", bid, bidderName, auction->id, auction->item);
    } else {
        printf("Bid of %.2f is lower than the current highest bid of %.2f.\n", bid, auction->highestBid);
    }
}

int main() {
    Auction auctions[MAX_AUCTIONS] = {
        {1, "Vintage Clock", 50.00, 0.00, ""},
        {2, "Modern Art Painting", 100.00, 0.00, ""},
        {3, "Antique Vase", 30.00, 0.00, ""},
        {4, "Signed Football", 20.00, 0.00, ""},
        {5, "Luxury Watch", 200.00, 0.00, ""}
    };
    
    Bidder bidders[MAX_BIDDERS] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"},
        {4, "Diana"},
        {5, "Edward"}
    };

    int auctionCount = 5;
    int bidderCount = 5;
    int choice;
    
    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Display Auctions\n");
        printf("2. Place a Bid\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayAuctions(auctions, auctionCount);
                break;
            case 2: {
                int auctionId;
                double bidAmount;
                char bidderName[NAME_LENGTH];
                
                printf("Enter Auction ID to bid on: ");
                scanf("%d", &auctionId);
                
                if (auctionId < 1 || auctionId > auctionCount) {
                    printf("Invalid Auction ID.\n");
                    break;
                }
                
                printf("Enter your Bid Amount: ");
                scanf("%lf", &bidAmount);
                
                printf("Enter your Name: ");
                scanf("%s", bidderName);
                
                placeBid(bidders, &auctions[auctionId - 1], bidAmount, bidderName);
                break;
            }
            case 3:
                printf("Exiting the Auction System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}