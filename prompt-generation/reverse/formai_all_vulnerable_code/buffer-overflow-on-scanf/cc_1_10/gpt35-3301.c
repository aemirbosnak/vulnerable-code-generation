//FormAI DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID_COUNT 10

// Struct to represent an item being auctioned
typedef struct {
    char name[50];
    double starting_price;
    double current_bid;
    char current_bidder[50];
    int bid_count;
    double bid_history[MAX_BID_COUNT];
} AuctionItem;

// Function to display the current bid status of an item
void displayBidStatus(AuctionItem item) {
    printf("\n\n%s is currently being auctioned.\n", item.name);
    printf("Starting Price: %.2f\n", item.starting_price);
    printf("Current Bid: %.2f by %s\n\n", item.current_bid, item.current_bidder);
}

// Function to handle bidding on an item
void processBid(AuctionItem *item, char *bidder, double amount) {
    if (amount > item->current_bid) {
        item->current_bid = amount;
        strcpy(item->current_bidder, bidder);
        item->bid_history[item->bid_count++] = amount;
        printf("%s is now the highest bidder with a bid of %.2f!\n", bidder, amount);
    }
    else {
        printf("Bid of %.2f rejected. You must bid higher than the current highest bid of %.2f.\n", amount, item->current_bid);
    }
}

int main() {
    AuctionItem item = {"Original Picasso Painting", 1000000.00, 0.00, "", 0, {0}};
    char bidder[50];
    double amount;

    displayBidStatus(item);

    // Start the auction
    printf("The auction for %s is now open!\n", item.name);
    printf("To place a bid, enter your name and bid amount separated by a space.\n");
    printf("To close the auction, enter 'END AUCTION'.\n\n");

    // Accept and process bids until the auction is closed
    while (1) {
        printf("Enter bid: ");
        scanf("%s", bidder);
        if (strcmp(bidder, "END") == 0) {
            break;
        }
        scanf("%lf", &amount);
        processBid(&item, bidder, amount);
    }

    // Display the final status of the auction
    printf("\n\nThe auction for %s is now closed.\n", item.name);
    printf("Final Bid: %.2f by %s\n", item.current_bid, item.current_bidder);
    printf("Bid History:");
    for (int i = 0; i < item.bid_count; i++) {
        printf(" %.2f", item.bid_history[i]);
    }

    return 0;
}