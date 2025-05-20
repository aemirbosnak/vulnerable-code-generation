//FormAI DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PRICE 50
#define MAX_PRICE 200
#define BIDDING_TIME 60

int main()
{
    int current_bid = MIN_PRICE;
    int highest_bid = 0;
    int bidder_id = 0;
    int time_left = BIDDING_TIME;
    char bidder_name[50];

    srand(time(NULL));

    printf("\nWelcome to the Digital Auction System!\n\n");

    printf("Starting price for the item is $%d.\n", current_bid);
    printf("Bidding time is %d seconds.\n", BIDDING_TIME);

    printf("\nLet the auction begin!\n");

    while (time_left > 0) {
        printf("\nCurrent bid: $%d   Time left: %d seconds\n", current_bid, time_left);

        printf("Enter your name: ");
        scanf("%s", bidder_name);

        printf("Enter your bid amount: ");
        scanf("%d", &bidder_id);

        if (bidder_id <= highest_bid) {
            printf("Sorry, your bid is too low. Please try again.\n");
            continue;
        }

        highest_bid = bidder_id;

        if (highest_bid > current_bid) {
            printf("\nCongratulations, %s! You are the highest bidder with $%d.\n", bidder_name, highest_bid);
            current_bid = highest_bid + (rand() % (MAX_PRICE - highest_bid + 1));
        } else {
            printf("\nCongratulations, %s! You are the highest bidder with $%d, but the reserve price has not been met.\n", bidder_name, highest_bid);
        }

        time_left--;
    }

    printf("\nTime's up!\n");

    if (highest_bid >= current_bid) {
        printf("Congratulations, %s! You won the auction with $%d.\n\n", bidder_name, highest_bid);
    } else {
        printf("Sorry, the reserve price was not met. The item remains unsold.\n\n");
    }

    return 0;
}