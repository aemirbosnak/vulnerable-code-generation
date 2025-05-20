//FormAI DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Data structure to hold bidder information
typedef struct {
    char name[100];
    int bid_amount;
} Bidder;

int main() {
    int num_bidders;
    printf("Welcome to the Digital Auction System\n");
    printf("--------------------------------------\n");
    printf("How many bidders do you have: ");
    scanf("%d", &num_bidders);
    
    Bidder* bidders = malloc(sizeof(Bidder) * num_bidders);
    if (bidders == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }
    
    // Take input for all bidders
    for (int i = 0; i < num_bidders; i++) {
        printf("Enter name of bidder %d: ", i + 1);
        scanf("%s", bidders[i].name);
        printf("Enter bid amount for bidder %d: ", i + 1);
        scanf("%d", &bidders[i].bid_amount);
    }
    
    // Find highest bidder
    int highest_bid = 0;
    int highest_bidder_index = 0;
    for (int i = 0; i < num_bidders; i++) {
        if (bidders[i].bid_amount > highest_bid) {
            highest_bid = bidders[i].bid_amount;
            highest_bidder_index = i;
        }
    }
    
    // Print winner information
    printf("\n\nWinner of the auction is:\n");
    printf("----------------------------\n");
    printf("Name: %s\n", bidders[highest_bidder_index].name);
    printf("Bid amount: %d\n", bidders[highest_bidder_index].bid_amount);
    
    free(bidders);
    return 0;
}