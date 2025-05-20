//FormAI DATASET v1.0 Category: Digital Auction System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* Surrealist Digital Auction System */

int main()
{
    int num_bids = 0;
    float current_bid = 0;
    char bidder_name[20];
    char artwork_name[50];
    int auction_duration = 0;
    int auction_start_time = 0;
    int time_left = 0;

    /* Welcome to the Surrealist Digital Auction System */
    printf("Welcome to the Surrealist Digital Auction System.\n");

    /* Get the name of the artwork for auction */
    printf("Please enter the name of the artwork for auction: ");
    scanf("%s", artwork_name);

    /* Get the starting bid for the artwork */
    printf("Please enter the starting bid for the artwork: $");
    scanf("%f", &current_bid);

    /* Get the duration of the auction in minutes */
    printf("Please enter the duration of the auction in minutes: ");
    scanf("%d", &auction_duration);

    /* Record the start time of the auction */
    auction_start_time = time(NULL);

    /* Keep the auction running until the time is up */
    while(time_left < auction_duration)
    {
        /* Display the current bid and time left */
        printf("Current bid: $%.2f \t Time left: %d minutes\n", current_bid, (auction_duration - time_left));

        /* Get a new bid from a bidder */
        printf("Enter your name to bid or 'quit' to end the auction: ");
        scanf("%s", bidder_name);

        /* Check if the bidder wants to quit the auction */
        if(strcmp(bidder_name, "quit") == 0)
        {
            break;
        }

        /* Get the new bid amount */
        float new_bid;
        printf("Enter your new bid amount: $");
        scanf("%f", &new_bid);

        /* Check if the new bid is higher than the current bid */
        if(new_bid > current_bid)
        {
            /* Record the new highest bid and the bidder's name */
            current_bid = new_bid;
            printf("%s is the new highest bidder with a bid of $%.2f\n", bidder_name, current_bid);
            num_bids++;
        }
        else
        {
            /* The new bid was not higher than the current bid */
            printf("Sorry, your bid of $%.2f is not higher than the current bid of $%.2f\n", new_bid, current_bid);
        }

        /* Record the current time and update the time left in the auction */
        time_left = (time(NULL) - auction_start_time) / 60;
    }

    /* Auction is over */
    printf("The %s auction is over.\n", artwork_name);

    /* Display the final bid */
    printf("Final bid: $%.2f\n", current_bid);

    /* Display the number of bids */
    printf("Number of bids: %d\n", num_bids);

    return 0;
}