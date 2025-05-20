//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bidder {
    char name[50];
    float bidAmount;
} Bidder;

typedef struct AuctionItem {
    char itemName[100];
    char description[300];
    Bidder highestBidder;
} AuctionItem;

void displayWelcomeMessage() {
    printf("Welcome to the Romantic Auction of Hearts!\n");
    printf("Here, love blossoms with every bid you make...\n\n");
}

void displayItemDetails(AuctionItem item) {
    printf("Item for Auction: %s\n", item.itemName);
    printf("Description: %s\n", item.description);
    printf("Current Highest Bid by: %s | Amount: $%.2f\n\n",
           item.highestBidder.name, item.highestBidder.bidAmount);
}

void placeBid(AuctionItem *item) {
    Bidder newBidder;
    printf("Enter your name (Ode of Love): ");
    scanf("%s", newBidder.name);
    
    printf("Enter your bid amount (offer of affection in $): ");
    scanf("%f", &newBidder.bidAmount);
    
    if (newBidder.bidAmount > item->highestBidder.bidAmount) {
        item->highestBidder = newBidder;
        printf("Your bid has been accepted, dear love!\n");
    } else {
        printf("Oh dear, your bid needs a little more romance!\n");
    }
}

void showGoodbyeMessage(AuctionItem item) {
    printf("Thank you for participating in the Romantic Auction of Hearts.\n");
    printf("The cherished item, %s, is now in the heart of %s with a bid of $%.2f.\n", 
            item.itemName, item.highestBidder.name, item.highestBidder.bidAmount);
}

int main() {
    // Set up the auction item, the embodiment of romance
    AuctionItem cherishedGift;
    strcpy(cherishedGift.itemName, "A Dozen Red Roses");
    strcpy(cherishedGift.description, "A beautiful bouquet of twelve fragrant red roses, symbolizing love and passion.");

    cherishedGift.highestBidder.bidAmount = 0; // Initial highest bid
    
    // Display the welcome message
    displayWelcomeMessage();

    // Display item details before the bidding begins
    displayItemDetails(cherishedGift);

    // Allow bids up to a maximum of 3 attempts
    for (int i = 0; i < 3; i++) {
        printf("Round %d of bidding...\n", i + 1);
        placeBid(&cherishedGift);
    }

    // Show the concluding message of gratitude
    showGoodbyeMessage(cherishedGift);
    
    return 0;
}