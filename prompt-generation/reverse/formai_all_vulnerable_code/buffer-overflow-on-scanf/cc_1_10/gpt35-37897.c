//FormAI DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between given range
int generateRand(int range_start, int range_end)
{
    srand(time(NULL));
    return (rand() % (range_end - range_start + 1)) + range_start;
}

// Function to validate the input
int validateInput(int min_value, int max_value)
{
    int input;
    do
    {
        printf("Enter your bid between %d and %d: ", min_value, max_value);
        scanf("%d", &input);
        if (input < min_value || input > max_value)
        {
            printf("Error: The bid should be between %d and %d.\n", min_value, max_value);
        }
    } while (input < min_value || input > max_value);
    return input;
}

int main()
{
    int starting_price = 100; // Initial price for the item
    int bidding_rounds = 3;   // Total number of bidding rounds
    int current_bid = 0;      // Current highest bid
    int max_bid = 1000;       // Maximum bid allowed
    int current_round = 1;    // Current bidding round
    int winner_bid = 0;       // Highest bid at the end of all rounds
    int winner_number = 0;    // Index number of the winner
    int bids[bidding_rounds]; // Array to store bids

    printf("Welcome to the Digital Auction System!\n");
    printf("The minimum bid for this item is $%d.\n\n", starting_price);

    while (current_round <= bidding_rounds)
    {
        printf("Bidding round %d starts!\n", current_round);
        current_bid = generateRand(starting_price, max_bid);
        printf("The current highest bid is $%d.\n", current_bid);
        bids[current_round - 1] = validateInput(current_bid + 1, max_bid);
        if (bids[current_round - 1] > current_bid)
        {
            current_bid = bids[current_round - 1];
            printf("Congratulations, you are now the highest bidder with $%d.\n\n", current_bid);
        }
        else
        {
            printf("Your bid of $%d is not the highest bid.\n\n", bids[current_round - 1]);
        }
        current_round++;
    }

    // Find the highest bid and the winner
    for (int i = 0; i < bidding_rounds; i++)
    {
        if (bids[i] > winner_bid)
        {
            winner_bid = bids[i];
            winner_number = i + 1;
        }
    }

    printf("The bidding is now closed.\n");
    printf("The highest bid was $%d from bidder %d.\n", winner_bid, winner_number);
    printf("Congratulations, bidder %d, you have won the auction with $%d!\n", winner_number, winner_bid);

    return 0;
}