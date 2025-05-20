//FormAI DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for Auction Item
typedef struct {
    char name[50];
    float startingBid;
    float currentBid;
    int bidder;
} AuctionItem;

// Function to get random number
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize array of auction items
    AuctionItem items[10];

    // Populate auction items with starting bids and names
    for(int i = 0; i < 10; i++) {
        items[i].startingBid = getRandomNumber(100, 1000);
        sprintf(items[i].name, "Auction Item %d", i+1);
        items[i].currentBid = items[i].startingBid;
        items[i].bidder = -1;
    }

    // Print out auction items
    printf("Welcome to the Digital Auction System!\n");
    printf("Here are the items that are up for auction:\n\n");
    for(int i = 0; i < 10; i++) {
        printf("%d. %s - Starting Bid: $%.2f\n", i+1, items[i].name, items[i].startingBid);
    }

    // Allow users to bid on items
    int itemNum, bidderNum;
    float bidAmt;
    while(1) {
        // Ask for item number
        printf("\nEnter the number of the item you would like to bid on (0 to quit): ");
        scanf("%d", &itemNum);

        // If user enters 0, quit program
        if(itemNum == 0) break;

        // Validate item number
        if(itemNum < 1 || itemNum > 10) {
            printf("Invalid item number. Please try again.\n");
            continue;
        }

        // Ask for bidder number
        printf("Enter your bidder number: ");
        scanf("%d", &bidderNum);

        // Validate bidder number
        if(bidderNum < 1 || bidderNum > 5) {
            printf("Invalid bidder number. Please try again.\n");
            continue;
        }

        // Ask for bid amount
        printf("Enter your bid amount: ");
        scanf("%f", &bidAmt);

        // Validate bid amount
        if(bidAmt <= items[itemNum-1].currentBid) {
            printf("Your bid must be higher than the current bid of $%.2f. Please try again.\n", items[itemNum-1].currentBid);
            continue;
        }

        // Update current bid and bidder information
        items[itemNum-1].currentBid = bidAmt;
        items[itemNum-1].bidder = bidderNum;

        // Print out bid confirmation
        printf("Bid accepted! Bidder %d is now the highest bidder on %s with a bid of $%.2f.\n", bidderNum, items[itemNum-1].name, bidAmt);
    }

    // Print out final results
    printf("\n\nAuction Results:\n\n");
    for(int i = 0; i < 10; i++) {
        printf("%s - Winning Bid: $%.2f - Winner: Bidder %d\n", items[i].name, items[i].currentBid, items[i].bidder);
    }

    return 0;
}