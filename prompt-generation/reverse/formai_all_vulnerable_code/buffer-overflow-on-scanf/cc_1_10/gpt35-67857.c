//FormAI DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>

// Define a struct to hold each item being auctioned
typedef struct {
    int id; // Item ID
    char name[50]; // Name of item
    float startingPrice; // Starting price of item
    int numBids; // Number of bids on item
    float highestBid; // Highest bid on item
    char highestBidder[50]; // Name of highest bidder
} AuctionItem;

// Define a function to display an item's information
void displayItem(AuctionItem item) {
    printf("Item ID: %d\n", item.id);
    printf("Name: %s\n", item.name);
    printf("Starting Price: %.2f\n", item.startingPrice);
    printf("Number of Bids: %d\n", item.numBids);
    printf("Highest Bid: %.2f\n", item.highestBid);
    printf("Highest Bidder: %s\n\n", item.highestBidder);
}

int main() {
    int numItems; // Number of items being auctioned
    printf("Welcome to the Digital Auction System!\n\n");
    printf("How many items will be auctioned? ");
    scanf("%d", &numItems);
    printf("\n");

    // Allocate memory for the array of AuctionItems
    AuctionItem *items = (AuctionItem*) malloc(numItems * sizeof(AuctionItem));

    // Get information for each item being auctioned
    for (int i = 0; i < numItems; i++) {
        printf("Item #%d\n", i + 1);
        printf("Item ID: ");
        scanf("%d", &items[i].id);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Starting Price: ");
        scanf("%f", &items[i].startingPrice);

        // Initialize other item fields
        items[i].numBids = 0;
        items[i].highestBid = items[i].startingPrice;
        strcpy(items[i].highestBidder, "None");

        printf("\n");
    }

    // Display initial information for all items
    printf("Initial Item Information:\n");
    for (int i = 0; i < numItems; i++) {
        displayItem(items[i]);
    }

    // Start auction for each item
    int itemNum = 1; // Number of current item being auctioned
    while (itemNum <= numItems) {
        AuctionItem currentItem = items[itemNum - 1];
        printf("Auctioning Item #%d: %s (Starting Price: %.2f)\n", itemNum, currentItem.name, currentItem.startingPrice);

        // Ask for bids until there are no more
        while (1) {
            char bidderName[50];
            float bidAmount;
            printf("Enter Your Name (or 'Done'): ");
            scanf("%s", bidderName);

            if (strcmp(bidderName, "Done") == 0) {
                break;
            }

            printf("Enter Your Bid: ");
            scanf("%f", &bidAmount);

            if (bidAmount <= currentItem.highestBid) {
                printf("Your Bid Must Be Higher Than The Current Highest Bid Of %.2f\n", currentItem.highestBid);
                continue;
            }

            currentItem.numBids++;
            currentItem.highestBid = bidAmount;
            strcpy(currentItem.highestBidder, bidderName);

            printf("Bid Accepted: %.2f By %s\n", currentItem.highestBid, currentItem.highestBidder);
        }

        // Update item information with final bid
        items[itemNum - 1] = currentItem;
        printf("\nFinal Item Information:\n");
        displayItem(currentItem);

        itemNum++;
    }

    // Display final information for all items
    printf("Final Item Information:\n");
    for (int i = 0; i < numItems; i++) {
        displayItem(items[i]);
    }

    // Free memory
    free(items);

    return 0;
}