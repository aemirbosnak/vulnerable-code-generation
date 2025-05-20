//FormAI DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 999999

struct bidder {
    char name[50];
    int bid_amount;
};

int main() {
    int max_bidders, num_bidders = 0, item_number = 1;
    struct bidder *bidders;
    srand(time(NULL));
    
    printf("Welcome to the Digital Auction System!\n");
    printf("Enter the maximum number of bidders: ");
    scanf("%d", &max_bidders);
    bidders = (struct bidder*)malloc(max_bidders * sizeof(struct bidder));
    
    while (num_bidders < max_bidders) {
        printf("\nAuction Item #%d\n", item_number);
        printf("==================\n");
        printf("Enter the starting bid amount: ");
        
        int starting_bid;
        scanf("%d", &starting_bid);
        
        printf("Starting bid: $%d\n", starting_bid);
        printf("Bidding ends in 30 seconds...\n");
        printf("===================================\n");
        printf("Bidders, please enter your name and bid amount:\n");
        
        fflush(stdin);
        char bidder_name[50];
        int bidder_bid;
        struct bidder b;
        
        printf("Bidder name: ");
        fgets(bidder_name, 50, stdin);
        bidder_name[strlen(bidder_name)-1] = '\0';
        
        printf("Bidder bid: $");
        scanf("%d", &bidder_bid);
        
        if (bidder_bid <= starting_bid) {
            printf("Error: Bid must be greater than starting bid.\n");
            continue;
        }
        
        if (bidder_bid > MAX_BID) {
            printf("Error: Bid exceeds maximum amount.\n");
            continue;
        }
        
        strcpy(b.name, bidder_name);
        b.bid_amount = bidder_bid;
        bidders[num_bidders] = b;
        num_bidders++;
        
        printf("\nBid accepted!\n");
        printf("Bidders so far:\n");
        
        for (int i = 0; i < num_bidders; i++) {
            printf("%s - $%d\n", bidders[i].name, bidders[i].bid_amount);
        }
        
        item_number++;
    }
    
    printf("\nAuction has ended!\n");
    printf("Final bids:\n");
    int highest_bid = -1;
    struct bidder winner;
    
    for (int i = 0; i < num_bidders; i++) {
        printf("%s - $%d\n", bidders[i].name, bidders[i].bid_amount);
        
        if (bidders[i].bid_amount > highest_bid) {
            highest_bid = bidders[i].bid_amount;
            winner = bidders[i];
        }
    }
    
    printf("\nAnd the winner is...\n");
    printf("%s with a bid of $%d\n", winner.name, winner.bid_amount);
    free(bidders);
    
    return 0;
}