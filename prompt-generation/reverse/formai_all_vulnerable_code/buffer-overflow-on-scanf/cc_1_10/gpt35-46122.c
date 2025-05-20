//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure definition for a Bid
typedef struct {
    char bidderName[50];
    float bidAmount;
} Bid;

// Structure definition for an Auction Item
typedef struct {
    char itemName[100];
    float minimumBid;
    Bid highestBid;
} AuctionItem;

// Function to get user input for the name and minimum bid of an item
void getInput(AuctionItem *item)
{
    printf("Enter the name of the item: ");
    fgets(item->itemName, 100, stdin);
    printf("Enter the minimum bid amount: ");
    scanf("%f", &item->minimumBid);
    fflush(stdin);
}

// Function to get user input for a bid
void getBidInput(Bid *bid, char *bidderName)
{
    printf("Enter your bid amount: ");
    scanf("%f", &bid->bidAmount);
    fflush(stdin);
    strcpy(bid->bidderName, bidderName);
}

// Function to display the details of an auction item
void displayItemDetails(AuctionItem item)
{
    printf("Item Name: %sMinimum Bid: $%.2f\n", item.itemName, item.minimumBid);
    if (item.highestBid.bidAmount != 0) {
        printf("Current Highest Bid: $%.2f by %s\n", item.highestBid.bidAmount, item.highestBid.bidderName);
    }
}

// Function to check if a bid is valid
bool isValidBid(AuctionItem item, Bid bid)
{
    if (item.highestBid.bidAmount == 0) {
        if (bid.bidAmount >= item.minimumBid) {
            return true;
        } else {
            return false;
        }
    } else {
        if (bid.bidAmount > item.highestBid.bidAmount) {
            return true;
        } else {
            return false;
        }
    }
}

int main()
{
    AuctionItem item;
    Bid bid;
    char bidderName[50];
    int option;

    // Get user input for the item
    getInput(&item);

    do {
        // Display the menu
        printf("\n\nAuction for %s", item.itemName);
        printf("1. Display Item Details\n2. Place Bid\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        fflush(stdin);

        switch(option) {
            case 1:
                displayItemDetails(item);
                break;

            case 2:
                // Get user input for the bidder name and bid amount
                printf("Enter your name: ");
                fgets(bidderName, 50, stdin);
                getBidInput(&bid, bidderName);

                if (isValidBid(item, bid)) {
                    item.highestBid = bid;
                    printf("Bid Successful!\n");
                } else {
                    printf("Bid Not Valid. Try Again!\n");
                }
                break;

            case 3:
                printf("Exiting Auction System...\n");
                break;

            default:
                printf("Invalid Option. Try Again!\n");
                break;
        }
    } while(option != 3);

    return 0;
}