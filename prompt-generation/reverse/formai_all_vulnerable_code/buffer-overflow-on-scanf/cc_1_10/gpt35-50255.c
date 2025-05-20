//FormAI DATASET v1.0 Category: Digital Auction System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct to hold bidder information
typedef struct Bidder {
    char name[20];
    int bid;
} Bidder;

// Function to display highest bidder
void display_winner(Bidder* bidders, int num_bidders) {
    int max_bid = 0;
    int max_index = 0;
    
    // Find highest bid
    for(int i = 0; i < num_bidders; i++) {
        if(bidders[i].bid > max_bid) {
            max_bid = bidders[i].bid;
            max_index = i;
        }
    }
    
    printf("\n\nAUCTION CLOSED!\n\n");
    printf("%s wins the auction with a bid of $%d!\n", bidders[max_index].name, bidders[max_index].bid);
}

int main() {
    int num_bidders;
    printf("Welcome to the Retro Digital Auction System!\n");
    printf("How many bidders are participating in this auction? ");
    scanf("%d", &num_bidders);
    
    // Allocate memory for bidders struct
    Bidder* bidders = (Bidder*) malloc(num_bidders * sizeof(Bidder));
    
    // Prompt each bidder to enter their name and initial bid
    for(int i = 0; i < num_bidders; i++) {
        printf("\n\nBidder %d:\n", i+1);
        printf("Enter your name: ");
        scanf("%s", bidders[i].name);
        printf("Enter your initial bid: $");
        scanf("%d", &(bidders[i].bid));
    }
    
    // Auction loop
    int winning_bid = bidders[0].bid;
    int current_bid;
    int current_bidder = 0;
    int bid_increment;
    char choice;
    srand(time(NULL));
    
    do {
        // Display current bidder and their bid
        printf("\n\nCurrent Bid: $%d\n", winning_bid);
        printf("Current Bidder: %s\n\n", bidders[current_bidder].name);
        
        // Generate random bid increment between $1 and $10
        bid_increment = rand() % 10 + 1;
        
        // Prompt bidder to enter new bid
        printf("Enter your new bid (minimum bid increment is $%d) or 'n' to pass: $", bid_increment);
        scanf("%d", &current_bid);
        
        if(current_bid < (winning_bid + bid_increment)) {
            // Invalid bid
            printf("Invalid bid. Your bid must be at least $%d greater than the current winning bid.\n", bid_increment);
        } else if(current_bid == winning_bid) {
            // Bid matches current winning bid
            printf("Your bid matches the current winning bid. Please bid a higher amount.\n");
        } else if(current_bid >= (winning_bid + bid_increment)) {
            // Valid bid
            winning_bid = current_bid;
            current_bidder++;
            
            if(current_bidder == num_bidders) {
                // Loop around to beginning of bidder list
                current_bidder = 0;
            }
            
            // Prompt next bidder whether to bid or pass
            printf("\n\n%s, it's your turn to bid. Do you want to bid or pass? (b/p) ", bidders[current_bidder].name);
            scanf(" %c", &choice);
        } else if(choice == 'p') {
            // Bidder chooses to pass
            current_bidder++;
            if(current_bidder == num_bidders) {
                // Loop around to beginning of bidder list
                current_bidder = 0;
            }
            printf("\n\n%s, it's your turn to bid. Do you want to bid or pass? (b/p) ", bidders[current_bidder].name);
            scanf(" %c", &choice);
        }
        
    } while(choice != 'n');
    
    // Display winner at close of auction
    display_winner(bidders, num_bidders);
    
    // Free memory
    free(bidders);
    
    return 0;
}