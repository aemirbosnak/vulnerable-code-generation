//FormAI DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define structures for bid and auction items
typedef struct {
    int id;
    char bidder[50];
    int bid_amount;
} Bid;

typedef struct {
    int id;
    char item_name[50];
    char item_description[100];
    int starting_price;
    Bid highest_bid;
} AuctionItem;

// Function to generate random number for item ID
int generateItemId() {
    srand(time(NULL));
    int i = rand() % 100 + 1; // Generate random number between 1-100
    return i;
}

// Function to start auction for an item
void startAuction(AuctionItem *item) {
    Bid current_bid;
    current_bid.id = generateItemId(); // Generate ID for current bid
    printf("\nStarting auction for %s with a starting price of $%d\n", item->item_name, item->starting_price);
    printf("Enter your bidder name: ");
    scanf("%s", current_bid.bidder);
    printf("Enter your bid amount: $");
    scanf("%d", &current_bid.bid_amount);
    if (current_bid.bid_amount < item->starting_price) {
        printf("Error: Bid amount cannot be less than starting price.\n");
        startAuction(item);
    } else {
        item->highest_bid = current_bid;
        printf("Congratulations, you are the highest bidder with a bid of $%d!\n", current_bid.bid_amount);
    }
}

// Function to update bid for an item
void updateBid(AuctionItem *item) {
    Bid current_bid;
    current_bid.id = generateItemId(); // Generate ID for current bid
    printf("\nCurrent highest bid for %s is $%d by %s\n", item->item_name, item->highest_bid.bid_amount, item->highest_bid.bidder);
    printf("Enter your bidder name: ");
    scanf("%s", current_bid.bidder);
    printf("Enter your bid amount: $");
    scanf("%d", &current_bid.bid_amount);
    if (current_bid.bid_amount <= item->highest_bid.bid_amount) {
        printf("Error: Bid amount must be greater than current highest bid.\n");
        updateBid(item);
    } else {
        item->highest_bid = current_bid;
        printf("Congratulations, you are the new highest bidder with a bid of $%d!\n", current_bid.bid_amount);
    }
}

// Main function to run auction system
int main() {
    AuctionItem item;
    item.id = generateItemId(); // Generate ID for item
    printf("Enter name of item: ");
    scanf("%s", item.item_name);
    printf("Enter item description: ");
    scanf("%s", item.item_description);
    printf("Enter starting price: $");
    scanf("%d", &item.starting_price);
    item.highest_bid.bid_amount = 0; // Set initial bid amount to 0
    char input;
    printf("\nWelcome to the auction system for %s!\n", item.item_name);
    printf("Enter 's' to start the auction or 'q' to quit: ");
    scanf(" %c", &input);
    while (input != 'q') {
        if (input == 's') {
            if (item.highest_bid.bid_amount == 0) {
                startAuction(&item);
            } else {
                updateBid(&item);
            }
        } else {
            printf("Error: Invalid input.\n");
        }
        printf("\nEnter 's' to start the auction or 'q' to quit: ");
        scanf(" %c", &input);
    }
    printf("\nAuction for %s has ended. Final bid amount is $%d by %s.\n", item.item_name, item.highest_bid.bid_amount, item.highest_bid.bidder);
    return 0;
}