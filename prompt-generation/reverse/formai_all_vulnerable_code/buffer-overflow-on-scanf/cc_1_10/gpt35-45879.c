//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the Cyberpunk Digital Auction System!\n\n");

    // Initializing the random number generator with the current time
    srand(time(NULL));

    // Declaring and initializing the variables
    int num_items = 10, item_prices[num_items], item_winner[num_items];
    char item_names[num_items][20];

    // Initializing the items with random prices and names
    for(int i=0; i<num_items; i++)
    {
        item_prices[i] = rand() % 1000 + 1;
        sprintf(item_names[i], "Item %d", i+1);
    }

    // Displaying the items and their prices
    printf("Items Available for Auction:\n");
    for(int i=0; i<num_items; i++)
    {
        printf("%s - $%d\n", item_names[i], item_prices[i]);
    }

    // Getting the bids from the users
    for(int i=0; i<num_items; i++)
    {
        printf("\nEnter your bid for %s: $", item_names[i]);
        int user_bid;
        scanf("%d", &user_bid);

        // Saving the winner and the winning bid for the item
        if(user_bid > item_prices[i])
        {
            item_prices[i] = user_bid;
            item_winner[i] = 1;
        }
        else
        {
            item_winner[i] = 0;
        }
    }

    // Displaying the winners and their prizes
    printf("\nAuction Results:\n");
    for(int i=0; i<num_items; i++)
    {
        if(item_winner[i])
            printf("Winner of %s - $%d\n", item_names[i], item_prices[i]);
        else
            printf("No winner for %s\n", item_names[i]);
    }

    printf("\nThank you for participating in the Cyberpunk Digital Auction System!\n");

    return 0;
}