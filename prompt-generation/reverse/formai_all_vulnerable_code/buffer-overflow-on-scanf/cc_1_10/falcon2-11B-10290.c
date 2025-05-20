//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>

int main() {
    // Create an array to hold items for auction
    int items[5] = {10, 20, 30, 40, 50};

    // Print the array contents
    printf("The items for auction are: \n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", items[i]);
    }
    printf("\n");

    // Set the starting bid for each item
    int startingBids[5] = {0};

    // Print the starting bids
    printf("The starting bids are: \n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", startingBids[i]);
    }
    printf("\n");

    // Run the auction
    int auction[5] = {0};
    int maxBid = 0;

    for (int i = 0; i < 5; i++) {
        // Print the current item
        printf("Item %d is up for auction. The current bid is %d.\n", i + 1, auction[i]);

        // Check if there are any bids
        if (auction[i] == 0) {
            // Set the starting bid as the current bid
            auction[i] = startingBids[i];
        }

        // Check if there is a new bid
        int newBid = 0;
        do {
            printf("Enter a new bid (0 to pass): ");
            scanf("%d", &newBid);
            if (newBid == 0) {
                continue;
            }
        } while (newBid <= auction[i]);

        // Update the maximum bid
        if (newBid > maxBid) {
            maxBid = newBid;
        }

        // Update the auction
        auction[i] = newBid;

        // Print the updated auction
        printf("The current bid is now %d.\n", auction[i]);
    }

    // Print the final bids
    printf("The final bids are: \n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", auction[i]);
    }
    printf("\n");

    return 0;
}