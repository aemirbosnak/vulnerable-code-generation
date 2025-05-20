//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item in the auction
struct Item {
    char name[100];
    int price;
};

// Structure to represent a bid on an item
struct Bid {
    char bidder[100];
    int amount;
};

// Function to get the highest bid for an item
int get_highest_bid(struct Bid *bids, int num_bids) {
    if (num_bids == 0) {
        return 0;
    } else {
        int highest_bid = bids[0].amount;
        for (int i = 1; i < num_bids; i++) {
            if (bids[i].amount > highest_bid) {
                highest_bid = bids[i].amount;
            }
        }
        return highest_bid;
    }
}

// Function to get the winning bid for an item
struct Bid *get_winning_bid(struct Bid *bids, int num_bids) {
    if (num_bids == 0) {
        return NULL;
    } else {
        int highest_bid = get_highest_bid(bids, num_bids);
        for (int i = 0; i < num_bids; i++) {
            if (bids[i].amount == highest_bid) {
                return &bids[i];
            }
        }
        return NULL;
    }
}

// Function to run the auction for an item
void run_auction(struct Item *item) {
    int num_bids = 0;
    struct Bid bids[100];

    // Get the first bid
    printf("Enter your bid for %s: ", item->name);
    scanf("%s %d", bids[num_bids].bidder, &bids[num_bids].amount);
    num_bids++;

    // Get subsequent bids
    while (1) {
        // Get the next bid
        printf("Enter your bid (or press enter to finish): ");
        scanf("%s %d", bids[num_bids].bidder, &bids[num_bids].amount);

        // Check if the user has finished entering bids
        if (bids[num_bids].bidder[0] == '\0') {
            break;
        }

        // Increment the number of bids
        num_bids++;
    }

    // Get the winning bid
    struct Bid *winning_bid = get_winning_bid(bids, num_bids);

    // Print the winning bid
    if (winning_bid == NULL) {
        printf("No bids were entered.\n");
    } else {
        printf("The winning bid for %s is %d from %s.\n", item->name, winning_bid->amount, winning_bid->bidder);
    }
}

// Main function
int main() {
    // Create the items for the auction
    struct Item items[] = {
        {"Painting", 100},
        {"Sculpture", 200},
        {"Vase", 300}
    };

    // Run the auction for each item
    for (int i = 0; i < 3; i++) {
        run_auction(&items[i]);
    }

    return 0;
}