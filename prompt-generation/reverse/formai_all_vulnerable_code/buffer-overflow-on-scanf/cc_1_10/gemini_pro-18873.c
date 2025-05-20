//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: excited
#include <stdio.h>
#include "time.h"

const char *items[] = {"Painting", "Sculpture", "Vase", "Rug", "Lamp"};
const int prices[] = {1000, 5000, 2000, 3000, 1500};

typedef struct {
    char name[50];
    int bid;
} Bidder;

Bidder bidders[100];
int num_bidders = 0;

int main() {
    printf("Welcome to the Digital Auction System!\n\n");

    // Initialize the auction items
    int num_items = sizeof(items) / sizeof(char *);
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - Starting bid: $%d\n", i + 1, items[i], prices[i]);
    }

    // Get the number of bidders
    printf("\nHow many bidders are there? ");
    scanf("%d", &num_bidders);

    // Get the names and bids from the bidders
    for (int i = 0; i < num_bidders; i++) {
        printf("\nBidder %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", bidders[i].name);

        printf("Bid (enter 0 to pass): $");
        scanf("%d", &bidders[i].bid);
    }

    // Find the highest bidder for each item
    int highest_bidders[num_items];
    for (int i = 0; i < num_items; i++) {
        int highest_bid = 0;
        int highest_bidder_index = -1;

        for (int j = 0; j < num_bidders; j++) {
            if (bidders[j].bid > highest_bid && bidders[j].bid <= prices[i]) {
                highest_bid = bidders[j].bid;
                highest_bidder_index = j;
            }
        }

        highest_bidders[i] = highest_bidder_index;
    }

    // Print the results of the auction
    printf("\n\nAuction Results:\n");
    for (int i = 0; i < num_items; i++) {
        if (highest_bidders[i] != -1) {
            printf("%s sold to %s for $%d.\n", items[i], bidders[highest_bidders[i]].name, bidders[highest_bidders[i]].bid);
        } else {
            printf("%s not sold.\n", items[i]);
        }
    }

    return 0;
}