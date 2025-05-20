//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the item structure
typedef struct Item {
    char name[50];
    int price;
    int owner;
} Item;

// Define the auction structure
typedef struct Auction {
    Item item;
    int highestBid;
    int highestBidder;
    int timeLeft;
} Auction;

// Create an array of items
Item items[] = {
    {"iPhone 13 Pro", 1000},
    {"MacBook Pro 14-inch", 2000},
    {"Apple Watch Series 7", 300},
    {"AirPods Pro", 200},
    {"iPad Mini 6", 400}
};

// Create an array of auctions
Auction auctions[5];

// Initialize the auctions
void initAuctions() {
    for (int i = 0; i < 5; i++) {
        auctions[i].item = items[i];
        auctions[i].highestBid = items[i].price;
        auctions[i].highestBidder = -1;
        auctions[i].timeLeft = 60;
    }
}

// Print the auctions
void printAuctions() {
    for (int i = 0; i < 5; i++) {
        printf("Item: %s\n", auctions[i].item.name);
        printf("Price: %d\n", auctions[i].item.price);
        printf("Highest Bid: %d\n", auctions[i].highestBid);
        printf("Highest Bidder: %d\n", auctions[i].highestBidder);
        printf("Time Left: %d\n\n", auctions[i].timeLeft);
    }
}

// Start the auction
void startAuction() {
    int auctionNumber;
    int bidAmount;
    int bidderNumber;

    while (1) {
        // Print the auctions
        printAuctions();

        // Get the auction number
        printf("Enter the auction number you want to bid on: ");
        scanf("%d", &auctionNumber);

        // Get the bid amount
        printf("Enter your bid amount: ");
        scanf("%d", &bidAmount);

        // Get the bidder number
        printf("Enter your bidder number: ");
        scanf("%d", &bidderNumber);

        // Check if the bid is valid
        if (bidAmount > auctions[auctionNumber].highestBid) {
            // Update the highest bid and the highest bidder
            auctions[auctionNumber].highestBid = bidAmount;
            auctions[auctionNumber].highestBidder = bidderNumber;
        } else {
            printf("Your bid is not valid.\n");
        }

        // Decrement the time left
        auctions[auctionNumber].timeLeft--;

        // Check if the auction is over
        if (auctions[auctionNumber].timeLeft == 0) {
            // Print the winner
            printf("The winner of auction %d is bidder %d with a bid of %d.\n", auctionNumber, auctions[auctionNumber].highestBidder, auctions[auctionNumber].highestBid);

            // Reset the auction
            auctions[auctionNumber].highestBid = items[auctionNumber].price;
            auctions[auctionNumber].highestBidder = -1;
            auctions[auctionNumber].timeLeft = 60;
        }
    }
}

int main() {
    // Initialize the auctions
    initAuctions();

    // Start the auction
    startAuction();

    return 0;
}