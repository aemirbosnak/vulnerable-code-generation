//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 50
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int bid_amount;
} Bid;

int main() {
    Bid bids[MAX_BIDS];
    int num_bids = 0;
    int current_bid = 0;
    int max_bid = 0;
    int num_winners = 0;
    char input[MAX_NAME_LENGTH + 10];
    
    printf("Welcome to the digital auction system!\n");
    printf("Please enter your bids followed by your name.\n");
    printf("Enter 'done' when you are finished.\n\n");
    
    // Read in bids
    while (1) {
        printf("Bid %d: ", current_bid + 1);
        fgets(input, MAX_NAME_LENGTH + 10, stdin);
        
        if (strcmp(input, "done\n") == 0) {
            break;
        }
        
        sscanf(input, "%d %s", &bids[current_bid].bid_amount, bids[current_bid].name);
        num_bids++;
        current_bid++;
    }
    
    // Find highest bid
    for (int i = 0; i < num_bids; i++) {
        if (bids[i].bid_amount > max_bid) {
            max_bid = bids[i].bid_amount;
        }
    }
    
    // Determine winners
    for (int i = 0; i < num_bids; i++) {
        if (bids[i].bid_amount == max_bid) {
            printf("Winner: %s, Bid: %d\n", bids[i].name, bids[i].bid_amount);
            num_winners++;
        }
    }
    
    if (num_winners == 1) {
        printf("Congratulations to the winner!\n");
    }
    else {
        printf("There were multiple winners!\n");
    }
    
    return 0;
}