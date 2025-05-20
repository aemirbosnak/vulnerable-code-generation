//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char itemName[50];
    float startingBid;
    float highestBid;
    char highestBidder[50];
    int isActive;
} AuctionItem;

void createAuction(AuctionItem *item) {
    printf("Enter the item name: ");
    getchar();  // Clear buffer
    fgets(item->itemName, sizeof(item->itemName), stdin);
    item->itemName[strcspn(item->itemName, "\n")] = 0;  // Remove the newline character

    printf("Enter the starting bid: ");
    scanf("%f", &(item->startingBid));
    item->highestBid = item->startingBid;
    item->isActive = 1;
    strcpy(item->highestBidder, "No bids yet");
}

void placeBid(AuctionItem *item) {
    if (!item->isActive) {
        printf("This auction is no longer active.\n");
        return;
    }
    
    float bid;
    printf("Enter your bid: ");
    scanf("%f", &bid);

    if (bid > item->highestBid) {
        item->highestBid = bid;
        printf("Enter your name: ");
        getchar();  // Clear buffer
        fgets(item->highestBidder, sizeof(item->highestBidder), stdin);
        item->highestBidder[strcspn(item->highestBidder, "\n")] = 0;  // Remove the newline character
        printf("Congratulations! Your bid of %.2f has been placed.\n", bid);
    } else {
        printf("Your bid is too low. The current highest bid is %.2f.\n", item->highestBid);
    }
}

void viewAuction(AuctionItem *item) {
    printf("\nAuction Details:\n");
    printf("Item Name: %s\n", item->itemName);
    printf("Starting Bid: %.2f\n", item->startingBid);
    printf("Highest Bid: %.2f\n", item->highestBid);
    printf("Highest Bidder: %s\n", item->highestBidder);
    printf("Auction Status: %s\n", item->isActive ? "Active" : "Closed");
}

void closeAuction(AuctionItem *item) {
    item->isActive = 0;
    printf("Auction for %s has been closed.\n", item->itemName);
}

int main() {
    AuctionItem *auction = malloc(sizeof(AuctionItem));
    if (!auction) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    int choice;
    do {
        printf("\nDigital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. View Auction\n");
        printf("4. Close Auction\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAuction(auction);
                break;
            case 2:
                placeBid(auction);
                break;
            case 3:
                viewAuction(auction);
                break;
            case 4:
                closeAuction(auction);
                break;
            case 5:
                printf("Exiting the auction system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);
    
    free(auction);
    return 0;
}