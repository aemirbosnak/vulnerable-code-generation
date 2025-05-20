//FormAI DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_NAME_LENGTH 20

// Structure to hold the bid details
typedef struct {
    char name[MAX_NAME_LENGTH];
    float bid_amount;
} Bid;

// Function to display the highest bid
void display_highest_bid(Bid *bids, int num_bids) {
    int i;
    float highest_bid = 0.0;
    char highest_bidder[MAX_NAME_LENGTH];
    
    for (i=0; i<num_bids; i++) {
        if (bids[i].bid_amount > highest_bid) {
            highest_bid = bids[i].bid_amount;
            strcpy(highest_bidder, bids[i].name);
        }
    }
    
    printf("Highest Bid: %.2f by %s", highest_bid, highest_bidder);
}

int main() {
    int i, num_bidders;
    Bid bids[MAX_BIDDERS];
    
    printf("Welcome to the Digital Auction System!\n");
    printf("How many people are bidding today? (Max 10)\n");
    scanf("%d", &num_bidders);
    
    // Input bid details for each bidder
    for (i=0; i<num_bidders; i++) {
        printf("Enter name of bidder %d: ", i+1);
        scanf("%s", bids[i].name);
        printf("Enter bid amount for bidder %d: ", i+1);
        scanf("%f", &bids[i].bid_amount);
    }
    
    // Display the highest bid
    display_highest_bid(bids, num_bidders);
    
    return 0;
}