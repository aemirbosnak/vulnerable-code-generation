//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char name[50];
    int bid;
} Bidder;

typedef struct {
    char name[50];
    int price;
} Item;

// Function Prototypes
void printWelcomeMessage();
void printItemDetails(Item item);
void printBidderDetails(Bidder bidder);
void printWinningBidder(Bidder bidder);
void printClosingMessage();

// Main Function
int main() {
    // Initialize Variables
    int numBidders, numItems;
    Bidder bidders[100];
    Item items[100];

    // Print Welcome Message
    printWelcomeMessage();

    // Get Number of Items
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    // Get Item Details
    for (int i = 0; i < numItems; i++) {
        printf("\nEnter the name of item %d: ", i + 1);
        scanf(" %[^\n]%*c", items[i].name);
        printf("Enter the starting price of item %d: ", i + 1);
        scanf("%d", &items[i].price);
    }

    // Get Number of Bidders
    printf("\nEnter the number of bidders: ");
    scanf("%d", &numBidders);

    // Get Bidder Details
    for (int i = 0; i < numBidders; i++) {
        printf("\nEnter the name of bidder %d: ", i + 1);
        scanf(" %[^\n]%*c", bidders[i].name);
        printf("Enter the maximum bid of bidder %d: ", i + 1);
        scanf("%d", &bidders[i].bid);
    }

    // Find Winning Bidder
    Bidder winningBidder;
    int winningBid = 0;
    for (int i = 0; i < numBidders; i++) {
        if (bidders[i].bid > winningBid) {
            winningBid = bidders[i].bid;
            winningBidder = bidders[i];
        }
    }

    // Print Item Details
    printf("\n\nItems for Auction:\n");
    for (int i = 0; i < numItems; i++) {
        printItemDetails(items[i]);
    }

    // Print Bidder Details
    printf("\n\nBidders:\n");
    for (int i = 0; i < numBidders; i++) {
        printBidderDetails(bidders[i]);
    }

    // Print Winning Bidder
    printf("\n\nWinning Bidder:\n");
    printWinningBidder(winningBidder);

    // Print Closing Message
    printClosingMessage();

    return 0;
}

// Function Definitions
void printWelcomeMessage() {
    printf("\n\n*********************************************************************************************************************************\n");
    printf("                                                Sherlock Holmes Digital Auction System                                                  \n");
    printf("*********************************************************************************************************************************\n\n");
}

void printItemDetails(Item item) {
    printf("Item Name: %s\n", item.name);
    printf("Starting Price: %d\n", item.price);
}

void printBidderDetails(Bidder bidder) {
    printf("Bidder Name: %s\n", bidder.name);
    printf("Maximum Bid: %d\n", bidder.bid);
}

void printWinningBidder(Bidder bidder) {
    printf("Name: %s\n", bidder.name);
    printf("Winning Bid: %d\n", bidder.bid);
}

void printClosingMessage() {
    printf("\n\n*********************************************************************************************************************************\n");
    printf("                                            Thank you for participating in the auction!                                                  \n");
    printf("*********************************************************************************************************************************\n\n");
}