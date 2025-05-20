//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int highest_bid = 0;
    char highest_bidder[20] = "";
    int current_bid;
    char bidder_name[20];

    printf("Welcome to the Digital Auction System!\n");
    printf("The item up for auction is a brand new iPhone X.\n");
    printf("Bidding starts at $1000. Please enter your bid:\n");

    // loops until a valid bid is entered
    while (1)
    {
        scanf("%d", &current_bid);

        if (current_bid < 1000)
        {
            printf("Bid must be at least $1000. Please try again:\n");
        }
        else
        {
            break;
        }
    }

    highest_bid = current_bid;
    printf("Your bid of $%d has been accepted as the highest bid.\n", highest_bid);

    printf("Please enter your name:\n");
    scanf("%s", bidder_name);
    printf("Thank you, %s, for your bid of $%d.\n", bidder_name, highest_bid);

    // allows for multiple bidders to place bids
    while (1)
    {
        printf("Current highest bid is $%d by %s. Please enter your bid:\n", highest_bid, bidder_name);
        scanf("%d", &current_bid);

        if (current_bid > highest_bid)
        {
            highest_bid = current_bid;
            printf("Your bid of $%d has been accepted as the highest bid.\n", highest_bid);

            printf("Please enter your name:\n");
            scanf("%s", bidder_name);
            printf("Thank you, %s, for your bid of $%d.\n", bidder_name, highest_bid);

            // keeps track of the highest bidder
            if (highest_bid > current_bid) {
                strcpy(highest_bidder, bidder_name);
            }
        }
        else if (current_bid < 1000)
        {
            printf("Bid must be at least $1000. Please try again.\n");
        }
        else
        {
            printf("Your bid of $%d has been rejected. Current highest bid is $%d by %s.\n", current_bid, highest_bid, bidder_name);
        }
    }

    return 0;
}