//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>

int main() {
    // Create an array to hold items for auction
    int items[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Define the number of items for auction
    int num_items = 10;

    // Define the minimum bid price
    int min_bid = 0;

    // Define the current bid price
    int current_bid = 0;

    // Define the highest bidder
    int highest_bidder = 0;

    // Define the highest bid price
    int highest_bid = 0;

    // Start the auction
    printf("Welcome to the C Digital Auction System!\n");

    // Loop through each item for auction
    for (int i = 0; i < num_items; i++) {
        // Display the current item number and its price
        printf("Item %d is up for auction at $%d.\n", i + 1, items[i]);

        // Get the user's bid price
        printf("Enter your bid price: ");
        scanf("%d", &current_bid);

        // Check if the bid price is greater than the minimum bid price
        if (current_bid > min_bid) {
            // Update the highest bidder and highest bid price
            if (current_bid > highest_bid) {
                highest_bidder = i + 1;
                highest_bid = current_bid;
            }

            // Display the current highest bid price
            printf("The current highest bid is $%d from bidder %d.\n", highest_bid, highest_bidder);
        } else {
            // Display an error message if the bid price is lower than the minimum bid price
            printf("Invalid bid price! Minimum bid price is $%d.\n", min_bid);
        }
    }

    // Display the final highest bid price
    printf("The final highest bid is $%d from bidder %d.\n", highest_bid, highest_bidder);

    return 0;
}