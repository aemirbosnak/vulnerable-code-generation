//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Create a list of items for auction
    int items[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int item_count = sizeof(items) / sizeof(int);

    // Print the list of items
    printf("Items for auction: ");
    for (int i = 0; i < item_count; i++) {
        printf("%d ", items[i]);
    }
    printf("\n");

    // Simulate bidding
    srand(time(NULL));
    int max_bid = 0;
    int bidder = -1;

    printf("Bidding starts at $100.\n");
    printf("Enter your bid or 'q' to quit: ");

    while (1) {
        int bid;
        scanf("%d", &bid);

        if (bid == -1) {
            break;
        }

        if (bid > max_bid) {
            max_bid = bid;
            bidder = 1;
        } else if (bid == max_bid) {
            bidder = 0;
        }

        printf("Current bid: $%d\n", max_bid);
        printf("Enter your bid or 'q' to quit: ");
    }

    if (bidder == -1) {
        printf("No bids received.\n");
    } else if (bidder == 0) {
        printf("Bidder 1 wins!\n");
    } else if (bidder == 1) {
        printf("Bidder 2 wins!\n");
    }

    return 0;
}