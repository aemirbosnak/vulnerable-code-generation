//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 10
#define MIN_INCREMENT 5

// Structure for bidder
typedef struct {
    int id;
    char name[50];
    int bid;
} bidder;

bidder bidders[MAX_BIDDERS];
int current_bidder = 0;
int highest_bid = 0;

void init_bidders() {
    for (int i = 0; i < MAX_BIDDERS; i++) {
        bidders[i].id = i + 1;
        sprintf(bidders[i].name, "Bidder %d", i + 1);
        bidders[i].bid = 0;
    }
}

void display_bidders() {
    printf("\n***** AUCTION SYSTEM *****\n");
    printf("Bidder ID | Name          | Current Bid\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < MAX_BIDDERS; i++) {
        printf("%3d | %-15s | %5d\n", bidders[i].id, bidders[i].name, bidders[i].bid);
    }
}

void place_bid(int bid_amount) {
    if (bid_amount % MIN_INCREMENT != 0) {
        printf("\nInvalid bid amount. Bid must be a multiple of %d.\n", MIN_INCREMENT);
        return;
    }

    bidders[current_bidder].bid += bid_amount;

    if (highest_bid < bidders[current_bidder].bid) {
        highest_bid = bidders[current_bidder].bid;
    }
}

int main() {
    srand(time(NULL));
    init_bidders();

    printf("\nWelcome to the Retro Digital Auction System!\n");

    for (int i = 0; i < MAX_BIDDERS; i++) {
        int bid;
        printf("\nBidder %d, enter your bid: ", bidders[i].id);
        scanf("%d", &bid);
        place_bid(bid);
    }

    printf("\nHighest Bidder:\n");
    for (int i = 0; i < MAX_BIDDERS; i++) {
        if (bidders[i].bid == highest_bid) {
            printf("Bidder ID %d - %s\n", bidders[i].id, bidders[i].name);
            break;
        }
    }

    return 0;
}