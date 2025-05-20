//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item and Bid structures
typedef struct {
    char name[50];
    float price;
} Item;

typedef struct {
    int bidderID;
    float amount;
} Bid;

// Function prototypes
void printWelcome();
void printMenu();
void addItem(Item *items, int *itemCount);
void printItems(Item *items, int itemCount);
void addBid(Item *items, Bid *bids, int itemCount, int bidCount);
void printBids(Item *items, Bid *bids, int itemCount, int bidCount);
void endAuction(Item *items, Bid *bids, int itemCount, int bidCount);

// Main function
int main() {
    // Print a warm welcome
    printWelcome();

    // Initialize items and bids arrays
    Item items[100];
    Bid bids[100];
    int itemCount = 0;
    int bidCount = 0;

    // Main auction loop
    int choice;
    do {
        // Print menu and get user choice
        printMenu();
        scanf("%d", &choice);

        // Execute the user's choice
        switch (choice) {
        case 1:
            addItem(items, &itemCount);
            break;
        case 2:
            printItems(items, itemCount);
            break;
        case 3:
            addBid(items, bids, itemCount, bidCount);
            bidCount++;
            break;
        case 4:
            printBids(items, bids, itemCount, bidCount);
            break;
        case 5:
            endAuction(items, bids, itemCount, bidCount);
            choice = 0;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice);

    // Return success
    return 0;
}

// Function definitions

void printWelcome() {
    printf("\n################################################################################\n");
    printf("**Welcome to the Digital Auction System**\n");
    printf("################################################################################\n");
}

void printMenu() {
    printf("\nPlease choose an option:\n");
    printf("1. Add an item\n");
    printf("2. List items\n");
    printf("3. Place a bid\n");
    printf("4. Print bids\n");
    printf("5. End auction\n");
    printf("0. Exit\n");
    printf("\nEnter your choice: ");
}

void addItem(Item *items, int *itemCount) {
    // Get item details
    printf("Enter item name: ");
    scanf(" %[^\n]", items[*itemCount].name);
    printf("Enter starting price: ");
    scanf("%f", &items[*itemCount].price);

    // Add item to array
    itemCount++;

    // Print success message
    printf("Item added successfully.\n");
}

void printItems(Item *items, int itemCount) {
    // Print item details
    printf("\n**Items for auction:**\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
    printf("\n");
}

void addBid(Item *items, Bid *bids, int itemCount, int bidCount) {
    // Get bid details
    int itemID;
    float bidAmount;
    printf("Enter the item ID: ");
    scanf("%d", &itemID);
    itemID--; // Adjust for 0-based array
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    // Check if bid is valid
    if (bidAmount > items[itemID].price) {
        // Add bid to array
        bids[bidCount].bidderID = bidCount + 1;
        bids[bidCount].amount = bidAmount;

        // Update item price
        items[itemID].price = bidAmount;

        // Print success message
        printf("Bid placed successfully.\n");
    } else {
        // Print error message
        printf("Bid not placed. The bid amount must be greater than the current price.\n");
    }
}

void printBids(Item *items, Bid *bids, int itemCount, int bidCount) {
    // Print bid details
    printf("\n**Bids:**\n");
    for (int i = 0; i < bidCount; i++) {
        printf("Item %s - $%.2f (Bidder: %d)\n", items[bids[i].bidderID - 1].name, bids[i].amount, bids[i].bidderID);
    }
    printf("\n");
}

void endAuction(Item *items, Bid *bids, int itemCount, int bidCount) {
    // Find the highest bid for each item
    for (int i = 0; i < itemCount; i++) {
        int highestBidderID = -1;
        float highestBidAmount = 0;
        for (int j = 0; j < bidCount; j++) {
            if (bids[j].bidderID - 1 == i) {
                if (bids[j].amount > highestBidAmount) {
                    highestBidderID = bids[j].bidderID;
                    highestBidAmount = bids[j].amount;
                }
            }
        }

        // Print the winner
        if (highestBidderID != -1) {
            printf("Item %s won by Bidder %d for $%.2f\n", items[i].name, highestBidderID, highestBidAmount);
        } else {
            printf("Item %s not sold.\n", items[i].name);
        }
    }

    // Print goodbye message
    printf("\nThank you for participating in the auction!\n");
}