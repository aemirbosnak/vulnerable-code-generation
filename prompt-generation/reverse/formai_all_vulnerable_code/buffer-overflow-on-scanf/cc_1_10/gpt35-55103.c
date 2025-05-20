//FormAI DATASET v1.0 Category: Digital Auction System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_BIDS 10  // maximum number of bids allowed
#define MAX_LEN 50   // maximum length of bidder name

// structure to hold bid information
typedef struct {
    char bidder_name[MAX_LEN];
    int bid_amount;
} bid_info;

// function to display current highest bid
void display_highest_bid(bid_info * bids, int num_bids) {
    int max_bid = 0;
    char max_bidder[MAX_LEN];
    for(int i=0; i<num_bids; i++) {
        if(bids[i].bid_amount > max_bid) {
            max_bid = bids[i].bid_amount;
            strcpy(max_bidder, bids[i].bidder_name);
        }
    }
    printf("Current highest bid is %d by %s\n", max_bid, max_bidder);
}

int main() {
    bid_info bids[MAX_BIDS];
    int num_bids = 0;
    char next_bidder[MAX_LEN];
    int next_bid_amount;

    printf("Welcome to the digital auction system!\n");

    // auction loop
    while(true) {
        display_highest_bid(bids, num_bids); // display current highest bid

        // get next bid
        printf("Enter bidder name (or 'q' to quit): ");
        scanf("%s", next_bidder);
        if(strcmp(next_bidder, "q") == 0) break; // quit if user enters 'q'
        printf("Enter bid amount: ");
        scanf("%d", &next_bid_amount);

        // check if bid is higher than current highest bid
        if(num_bids > 0 && next_bid_amount <= bids[num_bids-1].bid_amount) {
            printf("Bid amount must be higher than current highest bid!\n");
            continue;
        }

        // add bid to list
        strcpy(bids[num_bids].bidder_name, next_bidder);
        bids[num_bids].bid_amount = next_bid_amount;
        num_bids++;

        if(num_bids == MAX_BIDS) break; // limit number of bids allowed
    }

    // display final highest bid
    display_highest_bid(bids, num_bids);

    printf("Thank you for using the digital auction system!\n");

    return EXIT_SUCCESS;
}