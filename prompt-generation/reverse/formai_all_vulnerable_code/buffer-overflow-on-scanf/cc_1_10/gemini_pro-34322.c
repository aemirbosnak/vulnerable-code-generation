//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define our precious items up for grabs
struct Item {
    int id;
    char *name;
    float reservePrice;
    float currentBid;
    bool isSold;
};

// Let's have some inventory to choose from!
struct Item items[] = {
    {1, "Mystical Amulet", 100.0f, 0.0f, false},
    {2, "Ancient Scroll", 50.0f, 0.0f, false},
    {3, "Gilded Sword", 150.0f, 0.0f, false},
    {4, "Enchanted Chalice", 75.0f, 0.0f, false},
    {5, "Starlit Lantern", 25.0f, 0.0f, false}
};

// How many treasures do we have?
#define NUM_ITEMS (sizeof(items) / sizeof(struct Item))

// The heart of our auction: the bidding process
void Bid(int itemID, float amount) {
    // Find the item we're bidding on
    struct Item *item = NULL;
    for (int i = 0; i < NUM_ITEMS; i++) {
        if (items[i].id == itemID) {
            item = &items[i];
            break;
        }
    }

    // Item not found? It's like searching for a ghost!
    if (!item) {
        printf("Hmm, we couldn't find that item. Please try again!\n");
        return;
    }

    // Ensure we're not below the reserve price
    if (amount < item->reservePrice) {
        printf("Your bid is too low! Our treasures are worth much more!\n");
        return;
    }

    // Are we outbidding the previous contender?
    if (amount > item->currentBid) {
        item->currentBid = amount;
        printf("Congratulations! You're now the leading bidder on '%s'!\n", item->name);
    } else {
        printf("Sorry, someone else has currently outbid you. Keep trying!\n");
    }
}

// Time to announce the final results! Who's won what?
void AnnounceWinners() {
    printf("\n**Drumroll, please! Our auction is coming to an end!**\n");

    // Let's iterate through our treasures and reveal the lucky winners
    for (int i = 0; i < NUM_ITEMS; i++) {
        struct Item *item = &items[i];

        // If we have a winner, let's congratulate them!
        if (item->isSold) {
            printf("Congratulations to the winner of '%s': %f was the final bid!\n", item->name, item->currentBid);
        } else {
            // No winner? That's a bummer, but the treasure is still up for grabs!
            printf("'%s' remains unsold. Better luck next time!\n", item->name);
        }
    }
}

int main() {
    // Let's kick off the auction with a warm welcome
    printf("\n**Welcome to the Digital Auction Extravaganza!**\n");
    printf("Get ready to bid on some truly extraordinary treasures!\n\n");

    // Main loop for the auction. Time to bid, folks!
    bool keepBidding = true;
    while (keepBidding) {
        // Display the current inventory of treasures
        printf("**Our Current Treasures:**\n");
        for (int i = 0; i < NUM_ITEMS; i++) {
            struct Item *item = &items[i];
            printf("%d. %s - Current Bid: %.2f\n", item->id, item->name, item->currentBid);
        }

        // Prompt the user to enter an item ID to bid on
        printf("\nEnter the ID of the item you wish to bid on (or 0 to exit): ");
        int itemID;
        scanf("%d", &itemID);

        // If they want to exit, let's wrap up the auction
        if (itemID == 0) {
            keepBidding = false;
            continue;
        }

        // Get the bid amount from the user
        printf("Enter your bid amount: ");
        float amount;
        scanf("%f", &amount);

        // Process the bid and update the current highest bid
        Bid(itemID, amount);
    }

    // Announce the winners of the auction
    AnnounceWinners();

    return 0;
}