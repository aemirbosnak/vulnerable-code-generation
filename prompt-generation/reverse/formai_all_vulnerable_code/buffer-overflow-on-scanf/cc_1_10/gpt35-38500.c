//FormAI DATASET v1.0 Category: Digital Auction System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

int get_bid(int bid_price) {
    int bid;
    printf("Enter your bid: ");
    scanf("%d", &bid);
    if(bid <= bid_price) {
        printf("Your bid must be higher than the current bid price of %d\n", bid_price);
        return get_bid(bid_price);
    }
    return bid;
}

int main() {
    int bid_price = 0;
    int bidder_count = 0;
    int bid_count = 0;
    int highest_bid = 0;
    int highest_bidder = 0;

    printf("Welcome to the Digital Auction System!\n\n");

    printf("Enter the starting bid price: ");
    scanf("%d", &bid_price);

    while(1) {
        printf("\nCurrent bid price is %d\n", bid_price);
        if(bid_count > 0) {
            printf("The highest bidder is bidder %d with a bid of %d\n", highest_bidder, highest_bid);
        }
        int bid = get_bid(bid_price);
        if(bid > highest_bid) {
            highest_bid = bid;
            highest_bidder = bidder_count + 1;
        }
        // Check if user want to quit
        printf("Do you want to quit? (0 - No, 1 - Yes): ");
        int option;
        scanf("%d", &option);
        if(option == 1) {
            break;
        }

        bid_price = highest_bid + 1;
        bidder_count++;
        bid_count++;
    }

    printf("\nAuction Summary\n");
    printf("The starting bid price was %d\n", bid_price);
    printf("There were %d total bids\n", bid_count);
    printf("The highest bidder was bidder %d with a bid of %d\n", highest_bidder, highest_bid);

    return 0;
}