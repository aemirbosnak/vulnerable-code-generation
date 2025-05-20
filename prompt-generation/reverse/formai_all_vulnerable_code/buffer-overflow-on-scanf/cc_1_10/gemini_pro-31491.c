//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int bid;
} Bidder;

// Function to compare two bidders by their bids
int compareBids(const void *a, const void *b) {
    Bidder *bidderA = (Bidder *)a;
    Bidder *bidderB = (Bidder *)b;
    return bidderB->bid - bidderA->bid;
}

int main() {
    // Initialize the auction system
    int numBidders;
    printf("Enter the number of bidders: ");
    scanf("%d", &numBidders);

    Bidder *bidders = (Bidder *)malloc(sizeof(Bidder) * numBidders);

    // Get the names and bids of the bidders
    for (int i = 0; i < numBidders; i++) {
        printf("Enter the name of bidder %d: ", i + 1);
        char name[256];
        scanf("%s", name);
        bidders[i].name = strdup(name);

        printf("Enter the bid of bidder %d: ", i + 1);
        scanf("%d", &bidders[i].bid);
    }

    // Sort the bidders by their bids in descending order
    qsort(bidders, numBidders, sizeof(Bidder), compareBids);

    // Determine the winning bidder
    Bidder *winningBidder = &bidders[0];

    // Print the results of the auction
    printf("The winning bidder is %s with a bid of %d\n", winningBidder->name, winningBidder->bid);

    // Clean up the memory allocated for the bidders
    for (int i = 0; i < numBidders; i++) {
        free(bidders[i].name);
    }
    free(bidders);

    return 0;
}