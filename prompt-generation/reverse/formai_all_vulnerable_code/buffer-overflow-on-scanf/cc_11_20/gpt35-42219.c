//FormAI DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10

typedef struct Bidder {
    char name[50];
    int bid;
} Bidder;

int main(void) {
    // Welcome message
    printf("Welcome to the Digital Auction System!\n");

    // Get item name
    char item[50];
    printf("Enter item name: ");
    fgets(item, 50, stdin);

    // Get starting price
    int starting_price;
    printf("Enter starting price: ");
    scanf("%d", &starting_price);

    // Initialize bidders
    Bidder bidders[MAX_BIDDERS];
    int num_bidders = 0;

    // Auction starts
    printf("Auction starts for %s at $%d.\n", item, starting_price);

    // Main loop
    int current_bid = starting_price;
    while (1) {
        // Get bidder name
        char name[50];
        printf("Current bid: $%d\n", current_bid);
        printf("Enter your name or 'quit' to end the auction: ");
        fgets(name, 50, stdin);
        name[strcspn(name, "\n")] = 0; // remove newline character

        // Check if bidder wants to quit
        if (strcmp(name, "quit") == 0) {
            // Print winner and exit
            printf("Auction ended for %s.\n", item);
            if (num_bidders > 0) {
                printf("Winner: %s with a bid of $%d.\n", bidders[0].name, bidders[0].bid);
            } else {
                printf("No bidders for %s.\n", item);
            }
            return 0;
        }

        // Check if bidder already exists
        int bidder_index = -1;
        for (int i = 0; i < num_bidders; i++) {
            if (strcmp(name, bidders[i].name) == 0) {
                bidder_index = i;
                break;
            }
        }

        // Get bid amount
        int bid;
        printf("Enter your bid: ");
        scanf("%d", &bid);

        // Check if bid is valid
        if (bid <= current_bid) {
            printf("Invalid bid. Please enter a higher value than the current bid.\n");
            continue;
        }

        // Add bidder if it doesn't exist
        if (bidder_index == -1) {
            if (num_bidders >= MAX_BIDDERS) {
                printf("Maximum number of bidders has been reached. Cannot add more bidders.\n");
                continue;
            }
            strcpy(bidders[num_bidders].name, name);
            bidders[num_bidders].bid = bid;
            num_bidders++;
        } else {
            // Update bid for existing bidder
            bidders[bidder_index].bid = bid;
        }

        // Sort bidders by bid amount
        for (int i = 0; i < num_bidders - 1; i++) {
            for (int j = i + 1; j < num_bidders; j++) {
                if (bidders[i].bid < bidders[j].bid) {
                    Bidder temp = bidders[i];
                    bidders[i] = bidders[j];
                    bidders[j] = temp;
                }
            }
        }

        // Update current bid
        current_bid = bidders[0].bid;
    }
}