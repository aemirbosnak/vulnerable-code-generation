//FormAI DATASET v1.0 Category: Digital Auction System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure for storing auction item information
typedef struct {
    int itemID;
    char itemName[50];
    char itemDescription[150];
    float minimumBid;
    float currentBid;
    int bidderID;
} AuctionItem;

// Structure for storing bidder information
typedef struct {
    int bidderID;
    char bidderName[50];
    float availableFunds;
} Bidder;

// Function prototypes
int getMenuChoice();
void displayAuctionItems(AuctionItem[], int);
void displayBidderInfo(Bidder);
int getItemIndex(AuctionItem[], int, int);
int getBidderIndex(Bidder[], int, int);
void placeBid(AuctionItem[], int, Bidder[], int);
void printWinningBid(AuctionItem);

int main() {
    int numItems = 0; // Total number of auction items
    int numBidders = 0; // Total number of bidders
    int menuChoice = 0; // User menu choice

    // Dynamically allocate memory for auction items and bidders arrays
    AuctionItem *items = malloc(sizeof(AuctionItem));
    Bidder *bidders = malloc(sizeof(Bidder));

    // Variable for storing item information temporarily
    AuctionItem tempItem;

    // Variable for storing bidder information temporarily
    Bidder tempBidder;

    printf("Welcome to the Digital Auction System!\n");

    do {
        // Get user menu choice
        menuChoice = getMenuChoice();

        switch (menuChoice) {
            case 1: // Add an item for auction
                printf("\nAdding item for auction:\n");
                printf("Enter item name: ");
                scanf("%s", tempItem.itemName);
                printf("Enter item description: ");
                getchar(); // Remove newline character from buffer
                fgets(tempItem.itemDescription, 150, stdin);
                printf("Enter minimum bid: ");
                scanf("%f", &tempItem.minimumBid);

                // Set item ID to number of total items + 1
                tempItem.itemID = numItems + 1;

                // Add item to array and increment total number of items
                items = realloc(items, sizeof(AuctionItem) * (numItems + 1));
                items[numItems] = tempItem;
                numItems++;

                printf("Item added successfully!\n");

                break;
            case 2: // Add a bidder
                printf("\nAdding bidder:\n");
                printf("Enter bidder name: ");
                scanf("%s", tempBidder.bidderName);
                printf("Enter available funds: ");
                scanf("%f", &tempBidder.availableFunds);

                // Set bidder ID to number of total bidders + 1
                tempBidder.bidderID = numBidders + 1;

                // Add bidder to array and increment total number of bidders
                bidders = realloc(bidders, sizeof(Bidder) * (numBidders + 1));
                bidders[numBidders] = tempBidder;
                numBidders++;

                printf("Bidder added successfully!\n");

                break;
            case 3: // Display available items for auction
                printf("\nAvailable items for auction:\n");
                displayAuctionItems(items, numItems);
                printf("\n");

                break;
            case 4: // Place a bid on an item
                placeBid(items, numItems, bidders, numBidders);

                break;
            case 5: // Display bidder information
                printf("\nEnter bidder ID: ");
                int bidderID;
                scanf("%d", &bidderID);

                int bidderIndex = getBidderIndex(bidders, numBidders, bidderID);

                // If bidder exists, display their information
                if (bidderIndex >= 0) {
                    printf("\nBidder information:\n");
                    displayBidderInfo(bidders[bidderIndex]);
                    printf("\n");
                } else {
                    printf("Bidder not found.\n");
                }

                break;
            case 6: // Quit program
                printf("\nThank you for using the Digital Auction System!\n");
                free(items);
                free(bidders);
                exit(0);
            default: // Invalid menu choice
                printf("\nInvalid menu choice. Please try again.\n");
                break;
        }
    } while (true);

    return 0;
}

// Function to get user menu choice
int getMenuChoice() {
    printf("\nDigital Auction System Menu:\n");
    printf("1. Add item for auction\n");
    printf("2. Add bidder\n");
    printf("3. Display available items for auction\n");
    printf("4. Place bid on an item\n");
    printf("5. Display bidder information\n");
    printf("6. Quit program\n");
    printf("Enter choice: ");

    int choice;
    scanf("%d", &choice);

    return choice;
}

// Function to display available items for auction
void displayAuctionItems(AuctionItem items[], int numItems) {
    printf("ID | Item Name | Minimum Bid | Current Bid | BidderID\n");

    for (int i = 0; i < numItems; i++) {
        printf("%d | %-9s | %-11.2f | ", items[i].itemID, items[i].itemName, items[i].minimumBid);

        if (items[i].currentBid > 0) {
            printf("%-11.2f | %-7d\n", items[i].currentBid, items[i].bidderID);
        } else {
            printf("N/A         |\n");
        }
    }
}

// Function to display bidder information
void displayBidderInfo(Bidder bidder) {
    printf("ID: %d\nName: %s\nAvailable Funds: $%.2f\n", bidder.bidderID, bidder.bidderName, bidder.availableFunds);
}

// Function to get index of auction item in items array
int getItemIndex(AuctionItem items[], int numItems, int itemID) {
    for (int i = 0; i < numItems; i++) {
        if (items[i].itemID == itemID) {
            return i;
        }
    }

    return -1;
}

// Function to get index of bidder in bidders array
int getBidderIndex(Bidder bidders[], int numBidders, int bidderID) {
    for (int i = 0; i < numBidders; i++) {
        if (bidders[i].bidderID == bidderID) {
            return i;
        }
    }

    return -1;
}

// Function to place a bid on an item
void placeBid(AuctionItem items[], int numItems, Bidder bidders[], int numBidders) {
    printf("\nEnter item ID: ");
    int itemID;
    scanf("%d", &itemID);

    int itemIndex = getItemIndex(items, numItems, itemID);

    // If item exists, display current bid and prompt user for new bid
    if (itemIndex >= 0) {
        printf("\nCurrent bid: $%.2f", items[itemIndex].currentBid);
        printf("\nEnter bidder ID: ");
        int bidderID;
        scanf("%d", &bidderID);

        int bidderIndex = getBidderIndex(bidders, numBidders, bidderID);

        // If bidder exists and has enough funds, place bid and update current bid and bidder ID in items array
        if (bidderIndex >= 0 && bidders[bidderIndex].availableFunds >= items[itemIndex].minimumBid) {
            float bidAmount;
            printf("\nEnter bid amount: ");
            scanf("%f", &bidAmount);

            if (bidAmount < items[itemIndex].minimumBid) {
                printf("\nBid amount must be at least $%.2f. Bid not accepted.\n", items[itemIndex].minimumBid);
            } else if (bidAmount <= items[itemIndex].currentBid) {
                printf("\nBid amount must be greater than current bid of $%.2f. Bid not accepted.\n", items[itemIndex].currentBid);
            } else {
                items[itemIndex].currentBid = bidAmount;
                items[itemIndex].bidderID = bidderID;
                bidders[bidderIndex].availableFunds -= bidAmount;
            }
        } else if (bidderIndex < 0) {
            printf("\nBidder not found. Bid not accepted.\n");
        } else if (bidders[bidderIndex].availableFunds < items[itemIndex].minimumBid) {
            printf("\nBidder does not have enough funds to place bid. Bid not accepted.\n");
        }
    } else {
        printf("\nItem not found.\n");
    }
}

// Function to print winning bid information for an auction item
void printWinningBid(AuctionItem item) {
    printf("\nWinning bid for %s (ID: %d):\n", item.itemName, item.itemID);
    printf("Bidder ID: %d\nBid amount: $%.2f\n", item.bidderID, item.currentBid);
}