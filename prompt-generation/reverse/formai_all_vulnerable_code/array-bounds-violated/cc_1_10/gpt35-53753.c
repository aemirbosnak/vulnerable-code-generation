//FormAI DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BIDDERS 50
#define MAX_BID_AMOUNT 1000000

typedef struct {
    char name[50];
    int bid;
    bool winner;
} Bidder;

int main() {
    int num_bidders;
    Bidder bidders[MAX_BIDDERS];
    int highest_bid = 0;
    int winner_index;
    
    printf("Welcome to the Digital Auction System.\n");
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);
    
    for (int i = 0; i < num_bidders; i++) {
        printf("\nEnter name for bidder %d: ", i+1);
        scanf("%s", bidders[i].name);
        
        do {
            printf("Enter bid amount for bidder %d: ", i+1);
            scanf("%d", &bidders[i].bid);
        } while (bidders[i].bid > MAX_BID_AMOUNT);
        
        if (bidders[i].bid > highest_bid) {
            highest_bid = bidders[i].bid;
            winner_index = i;
        }
    }
    
    printf("\nThe winner is %s with a bid of $%d.\n", bidders[winner_index].name, bidders[winner_index].bid);
    
    for (int i = 0; i < num_bidders; i++) {
        if (i == winner_index) {
            bidders[i].winner = true;
        } else {
            bidders[i].winner = false;
        }
        
        printf("\n%s bid $%d and they %s the auction.\n", bidders[i].name, bidders[i].bid, bidders[i].winner ? "won" : "lost");
    }
    
    return 0;
}