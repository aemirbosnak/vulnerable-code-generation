//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    // Declare variables
    int highest_bid = 0;
    int bid;
    int num_bids;
    int item_price;
    int increment = 1;

    // Initialize variables
    srand(time(NULL));
    item_price = rand() % 1000 + 1;

    // Display initial bid
    printf("The starting bid for this item is $%d\n", item_price);

    // Accept bids
    while (1)
    {
        printf("Enter your bid: ");
        scanf("%d", &bid);

        // Check for highest bid
        if (bid > highest_bid)
        {
            highest_bid = bid;
        }

        // Check for end of bidding
        if (bid == highest_bid)
        {
            printf("The bidding has ended!\n");
            break;
        }

        // Check for increment
        if (bid % increment == 0)
        {
            printf("Bidding increment is $%d\n", increment);
            increment++;
        }
    }

    // Display winner and final price
    printf("The winner is bidder #%d with a bid of $%d\n", num_bids, highest_bid);
    printf("The final price of the item is $%d\n", item_price * highest_bid);

    return 0;
}