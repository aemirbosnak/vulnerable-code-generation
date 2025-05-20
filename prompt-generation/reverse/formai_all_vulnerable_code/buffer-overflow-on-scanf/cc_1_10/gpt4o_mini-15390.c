//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold information of each auction item.
typedef struct {
    char name[50];
    char description[200];
    float startingBid;
    float currentBid;
    char highestBidder[50];
} AuctionItem;

// Function to create a new auction item.
void createAuctionItem(AuctionItem *item) {
    printf("Enter the name of the item: ");
    fgets(item->name, sizeof(item->name), stdin);
    item->name[strcspn(item->name, "\n")] = 0; // Remove newline

    printf("Enter a description of the item: ");
    fgets(item->description, sizeof(item->description), stdin);
    item->description[strcspn(item->description, "\n")] = 0; // Remove newline

    printf("Enter the starting bid for the item: ");
    scanf("%f", &item->startingBid);
    item->currentBid = item->startingBid;
    strcpy(item->highestBidder, "No bids yet");

    // Clear stdin buffer
    while (getchar() != '\n');
}

// Function to place a bid on an auction item.
void placeBid(AuctionItem *item) {
    char bidder[50];
    float bidAmount;

    printf("Enter your name: ");
    fgets(bidder, sizeof(bidder), stdin);
    bidder[strcspn(bidder, "\n")] = 0; // Remove newline

    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    // Clear stdin buffer
    while (getchar() != '\n');

    if (bidAmount > item->currentBid) {
        item->currentBid = bidAmount;
        strcpy(item->highestBidder, bidder);
        printf("Your bid of %.2f has been placed successfully!\n", bidAmount);
    } else {
        printf("Your bid must be higher than the current bid of %.2f.\n", item->currentBid);
    }
}

// Function to display auction item details.
void displayItemDetails(const AuctionItem *item) {
    printf("\nItem Name: %s\n", item->name);
    printf("Description: %s\n", item->description);
    printf("Starting Bid: %.2f\n", item->startingBid);
    printf("Current Bid: %.2f\n", item->currentBid);
    printf("Current Highest Bidder: %s\n", item->highestBidder);
}

int main() {
    AuctionItem auctionItem;
    int choice;

    printf("Welcome to the Medieval Digital Auction System!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Create an auction item\n");
        printf("2. Place a bid on the auction item\n");
        printf("3. View auction item details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear stdin buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                createAuctionItem(&auctionItem);
                break;
            case 2:
                placeBid(&auctionItem);
                break;
            case 3:
                displayItemDetails(&auctionItem);
                break;
            case 4:
                printf("Thank you for using the Medieval Digital Auction System! Farewell!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}