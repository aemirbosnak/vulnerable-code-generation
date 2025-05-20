//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the item structure
struct item {
    char name[50];
    float price;
    int quantity;
};

// Declare the auction structure
struct auction {
    char name[50];
    struct item items[100];
    int numItems;
};

// Declare the bidder structure
struct bidder {
    char name[50];
    float money;
};

// Declare the function prototypes
void createAuction(struct auction *auction);
void addItem(struct auction *auction, struct item *item);
void removeItem(struct auction *auction, int index);
void printAuction(struct auction *auction);
void startAuction(struct auction *auction, struct bidder *bidders, int numBidders);

// Main function
int main() {
    // Create the auction
    struct auction auction;
    createAuction(&auction);

    // Add some items to the auction
    struct item item1;
    strcpy(item1.name, "Mona Lisa");
    item1.price = 1000000000;
    item1.quantity = 1;
    addItem(&auction, &item1);

    struct item item2;
    strcpy(item2.name, "Starry Night");
    item2.price = 500000000;
    item2.quantity = 1;
    addItem(&auction, &item2);

    struct item item3;
    strcpy(item3.name, "The Scream");
    item3.price = 120000000;
    item3.quantity = 1;
    addItem(&auction, &item3);

    // Print the auction
    printAuction(&auction);

    // Create some bidders
    struct bidder bidders[3];
    strcpy(bidders[0].name, "Bill Gates");
    bidders[0].money = 1000000000;

    strcpy(bidders[1].name, "Warren Buffett");
    bidders[1].money = 750000000;

    strcpy(bidders[2].name, "Jeff Bezos");
    bidders[2].money = 1200000000;

    // Start the auction
    startAuction(&auction, bidders, 3);

    return 0;
}

// Create auction function
void createAuction(struct auction *auction) {
    printf("What is the name of the auction?\n");
    scanf("%s", auction->name);

    auction->numItems = 0;
}

// Add item function
void addItem(struct auction *auction, struct item *item) {
    auction->items[auction->numItems] = *item;
    auction->numItems++;
}

// Remove item function
void removeItem(struct auction *auction, int index) {
    for (int i = index; i < auction->numItems - 1; i++) {
        auction->items[i] = auction->items[i + 1];
    }
    auction->numItems--;
}

// Print auction function
void printAuction(struct auction *auction) {
    printf("Auction Name: %s\n", auction->name);
    printf("Number of Items: %d\n", auction->numItems);
    for (int i = 0; i < auction->numItems; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", auction->items[i].name);
        printf("Price: $%.2f\n", auction->items[i].price);
        printf("Quantity: %d\n", auction->items[i].quantity);
        printf("\n");
    }
}

// Start auction function
void startAuction(struct auction *auction, struct bidder *bidders, int numBidders) {
    for (int i = 0; i < auction->numItems; i++) {
        float highestBid = 0;
        int highestBidderIndex = -1;
        for (int j = 0; j < numBidders; j++) {
            float bid = 0;
            printf("%s, what is your bid for %s?\n", bidders[j].name, auction->items[i].name);
            scanf("%f", &bid);
            if (bid > highestBid && bid <= bidders[j].money) {
                highestBid = bid;
                highestBidderIndex = j;
            }
        }
        if (highestBidderIndex != -1) {
            printf("%s wins %s for $%.2f!\n", bidders[highestBidderIndex].name, auction->items[i].name, highestBid);
            bidders[highestBidderIndex].money -= highestBid;
            auction->items[i].quantity--;
        } else {
            printf("No one bid on %s.\n", auction->items[i].name);
        }
    }
}