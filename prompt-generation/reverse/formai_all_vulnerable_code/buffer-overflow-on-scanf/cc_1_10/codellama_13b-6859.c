//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: funny
/*
 * C Digital Auction System
 *
 * Example program
 *
 * In a funny style
 *
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void welcome(void);
void menu(void);
void bid(void);
void auction_result(int);

// Global variables
int min_bid = 100;
int max_bid = 1000;
int bid_step = 100;
int bid_time = 30;
int highest_bid = 0;
int highest_bidder = 0;

int main() {
    welcome();
    menu();
    bid();
    auction_result(highest_bidder);
    return 0;
}

void welcome(void) {
    printf("Welcome to the digital auction system!\n");
}

void menu(void) {
    printf("Menu:\n");
    printf("1. Bid\n");
    printf("2. Auction result\n");
    printf("3. Exit\n");
}

void bid(void) {
    int bidder = 0;
    int bid = 0;
    int time = bid_time;

    while (time > 0) {
        printf("Bidder %d, please enter your bid: ", bidder + 1);
        scanf("%d", &bid);
        if (bid < min_bid || bid > max_bid) {
            printf("Invalid bid. Please enter a valid bid.\n");
            continue;
        }
        if (bid > highest_bid) {
            highest_bid = bid;
            highest_bidder = bidder + 1;
        }
        bidder++;
        time--;
    }
}

void auction_result(int bidder) {
    printf("Auction result:\n");
    printf("Highest bid: %d\n", highest_bid);
    printf("Highest bidder: %d\n", bidder);
}