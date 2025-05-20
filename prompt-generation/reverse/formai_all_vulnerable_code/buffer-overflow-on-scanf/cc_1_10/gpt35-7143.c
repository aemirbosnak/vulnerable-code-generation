//FormAI DATASET v1.0 Category: Digital Auction System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 10

int main(){
    // Declare the auction variables
    float item_price;
    int num_bidders;
    float bids[MAX_BIDDERS];
    char bidder_names[MAX_BIDDERS][50];
    int i, j;
    int winner_index = -1;
    float max_bid = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Get the item price
    printf("Enter the starting price of the item: ");
    scanf("%f", &item_price);

    // Get the number of bidders
    printf("Enter the number of bidders (maximum %d): ", MAX_BIDDERS);
    scanf("%d", &num_bidders);

    // Get the names and bids of the bidders
    for (i = 0; i < num_bidders; i++){
        printf("Enter name of bidder #%d: ", i+1);
        scanf("%s", bidder_names[i]);
        bids[i] = item_price;
    }

    // Start the auction
    printf("\nThe auction has started!\n");

    // Iterate through the auction rounds
    for (i = 1; i <= 5; i++){
        printf("\n--- Auction Round #%d ---\n", i);
        for (j = 0; j < num_bidders; j++){
            // Generate a random bid for the bidder
            float random_bid = ((float)rand()/(float)(RAND_MAX)) * 100;

            // Add the random bid to the bidder's total bid
            bids[j] += random_bid;

            // Print out the bidder's name and bid
            printf("%s has bid $%.2f.\n", bidder_names[j], bids[j]);
        }
    }

    // End the auction
    printf("\n--- The auction has ended! ---\n");

    // Determine the winner
    for (i = 0; i < num_bidders; i++){
        if (bids[i] > max_bid){
            max_bid = bids[i];
            winner_index = i;
        }
    }

    // Print out the winner and their bid
    printf("%s has won the auction with a bid of $%.2f!\n", bidder_names[winner_index], max_bid);

    // End the program
    return 0;
}