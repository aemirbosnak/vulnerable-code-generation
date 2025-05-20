//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct bidding {
    char name[30];
    float amount;
};

void display_bid(struct bidding bid) {
    printf("%s bids $%.2f.\n", bid.name, bid.amount);
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Cyberpunk Digital Auction System.\n");

    // Set up initial starting bid and bidder
    struct bidding current_bid;
    strcpy(current_bid.name, "AI-001");
    current_bid.amount = 500.0;
    display_bid(current_bid);

    // Set up array of bidders
    struct bidding bidders[5];
    strcpy(bidders[0].name, "Johnny Silverhand");
    strcpy(bidders[1].name, "Alt Cunningham");
    strcpy(bidders[2].name, "Sandra Dorsett");
    strcpy(bidders[3].name, "Panam Palmer");
    strcpy(bidders[4].name, "Viktor Vektor");

    // Bidding loop
    int num_bidders = 5;
    int current_bidder;
    struct bidding new_bid;
    char user_input;
    int round = 1;
    do {
        printf("\nRound %d:\n", round);
        current_bidder = rand() % num_bidders;
        printf("%s, it is your turn to bid.\n", bidders[current_bidder].name);
        printf("Would you like to bid higher than $%.2f? (y/n)", current_bid.amount);
        scanf(" %c", &user_input);
        if (user_input == 'y') {
            printf("How much would you like to bid, %s? $", bidders[current_bidder].name);
            scanf("%f", &new_bid.amount);
            strcpy(new_bid.name, bidders[current_bidder].name);
            if (new_bid.amount > current_bid.amount) {
                display_bid(new_bid);
                current_bid = new_bid;
            } else {
                printf("Sorry, your bid of $%.2f is not higher than the current bid of $%.2f.\n", 
                    new_bid.amount, current_bid.amount);
            }
        } else {
            printf("%s passes.\n", bidders[current_bidder].name);
        }
        round++;
    } while(round <= num_bidders);
    printf("\nThe final bid of $%.2f goes to %s!", current_bid.amount, current_bid.name);
    return 0;
}