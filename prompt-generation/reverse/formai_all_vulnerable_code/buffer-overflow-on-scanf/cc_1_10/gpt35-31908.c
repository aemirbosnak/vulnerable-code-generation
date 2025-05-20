//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));  // initialize random seed

    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    int* bids = (int*)malloc(numPlayers * sizeof(int));
    int numBids = 0;

    printf("Starting the auction...\n");

    while (numBids < numPlayers)
    {
        printf("Next bid: ");
        int bid;
        scanf("%d", &bid);

        if (bid <= 0)
        {
            printf("Invalid bid. Please enter a positive integer.\n");
            continue;
        }

        int i;
        for (i = 0; i < numBids; i++)
        {
            if (bid <= bids[i])
            {
                printf("Bid must be higher than previous bids.\n");
                break;
            }
        }

        if (i == numBids)
        {
            printf("Bid accepted!\n");
            bids[numBids] = bid;
            numBids++;
        }
    }

    printf("All players have bid. \n\n");

    int winnerIndex = rand() % numPlayers;
    printf("Congratulations to Player %d, who wins the auction with a bid of %d!\n", winnerIndex + 1, bids[winnerIndex]);

    free(bids);

    return 0;
}