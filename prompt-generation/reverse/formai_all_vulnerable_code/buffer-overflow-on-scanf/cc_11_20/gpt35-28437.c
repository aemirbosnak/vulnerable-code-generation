//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDDERS 10    // maximum number of bidders
#define ITEM_PRICE 100.0  // price of the item being sold
#define END_TIME 60        // duration of the auction in seconds

int main() {
    int num_bidders = 0;           // number of bidders
    int bidder_numbers[MAX_BIDDERS];  // array to hold bidder numbers
    float bids[MAX_BIDDERS];       // array to hold bidder bids
    time_t start_time = time(NULL);  // time the auction starts

    // display the item being sold and the starting bid
    printf("Welcome to the auction!\n");
    printf("The item for sale is a digital camera.\n");
    printf("The starting bid is $%.2f\n\n", ITEM_PRICE);

    // loop until the auction ends
    while ((time(NULL) - start_time) < END_TIME) {
        // check if there are any bidders
        if (num_bidders == 0) {
            printf("No bidders. Starting bid still $%.2f\n\n", ITEM_PRICE);
        } else {
            // display current bids
            printf("Current bids:\n");
            for (int i = 0; i < num_bidders; i++) {
                printf("Bidder %d: $%.2f\n", bidder_numbers[i], bids[i]);
            }
            printf("\n");
        }

        // get bidder input
        int bidder_number;
        float bid_amount;
        printf("Enter your bidder number (1-%d) or 0 to quit: ", MAX_BIDDERS);
        scanf("%d", &bidder_number);
        if (bidder_number == 0) {
            break;
        }
        printf("Enter your bid amount: ");
        scanf("%f", &bid_amount);

        // check if bidder number is already taken
        for (int i = 0; i < num_bidders; i++) {
            if (bidder_numbers[i] == bidder_number) {
                printf("Bidder number already taken. Please choose a different number.\n\n");
                bidder_number = -1;
                break;
            }
        }

        // add bidder and bid to arrays
        if (bidder_number > 0 && num_bidders < MAX_BIDDERS) {
            bidder_numbers[num_bidders] = bidder_number;
            bids[num_bidders] = bid_amount;
            num_bidders++;
            printf("Thank you for your bid!\n\n");
        } else if (num_bidders == MAX_BIDDERS) {
            printf("Maximum number of bidders reached.\n\n");
        }
    }

    // determine the winning bid and bidder
    int winner = -1;
    float highest_bid = ITEM_PRICE;
    for (int i = 0; i < num_bidders; i++) {
        if (bids[i] > highest_bid) {
            winner = bidder_numbers[i];
            highest_bid = bids[i];
        }
    }

    // display the winner and their bid
    if (winner != -1) {
        printf("The winner is bidder %d with a bid of $%.2f.\n", winner, highest_bid);
    } else {
        printf("No winner. The starting bid was not met.\n");
    }

    return 0;
}