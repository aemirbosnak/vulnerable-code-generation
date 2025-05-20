//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDS 10
#define ITEM_PRICE 100
#define MIN_INCREMENT 5

int main() {
    srand(time(NULL));

    int current_bid = ITEM_PRICE;
    int bids[MAX_BIDS] = {0};
    int num_bids = 0;
    int winning_bid = ITEM_PRICE;
    int winner_index = -1;

    printf("Welcome to the Digital Auction System. The starting bid is %d.\n", ITEM_PRICE);

    while(num_bids < MAX_BIDS) {
        printf("Enter your bid: ");
        int bid;
        scanf("%d", &bid);

        if(bid < current_bid) {
            printf("Your bid must be greater than or equal to the current bid of %d.\n", current_bid);
            continue;
        }

        if((bid - current_bid) < MIN_INCREMENT) {
            printf("Your bid must be at least %d more than the current bid.\n", MIN_INCREMENT);
            continue;
        }

        if(rand() % 5 == 0 && num_bids > 0) { // 20% chance of the bid being cancelled
            int cancelled_bid = bids[rand() % num_bids];
            printf("Sorry, your bid of %d has been cancelled. The new current bid is %d.\n", cancelled_bid, winning_bid);
            current_bid = winning_bid;
            continue;
        }

        bids[num_bids] = bid;
        num_bids++;

        if(bid > winning_bid) {
            winning_bid = bid;
            winner_index = num_bids - 1;
            printf("Congratulations, you are now the winning bidder!\n");
        } else {
            printf("Your bid has been placed. The current bid is %d.\n", winning_bid);
        }

        current_bid = winning_bid + MIN_INCREMENT;
    }

    printf("The auction is now closed. The winning bid was %d by bidder %d.", winning_bid, winner_index + 1);

    return 0;
}