//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 5

typedef struct {
    char name[50];
    int balance;
} Bidder;

int main() {
    Bidder bidders[MAX_BIDDERS];
    char item[50];
    int min_bid, highest_bid = 0, highest_bidder;
    int num_bidders = 0;
    int i, j;
    srand(time(0));

    printf("Welcome to the Digital Auction System!\n");
    printf("What item would you like to auction off?\n");
    scanf("%s", item);

    printf("What is the minimum bid for %s?\n", item);
    scanf("%d", &min_bid);

    printf("How many bidders will participate?\n");
    scanf("%d", &num_bidders);

    if (num_bidders > MAX_BIDDERS) {
        printf("Sorry, we can only handle up to %d bidders\n", MAX_BIDDERS);
        return 1;
    }

    for (i = 0; i < num_bidders; i++) {
        printf("Enter bidder %d's name: ", i+1);
        scanf("%s", bidders[i].name);
        bidders[i].balance = rand() % 10000;
    }

    printf("\n\n");
    printf("Starting bid for %s is %d\n", item, min_bid);
    printf("Let the bidding begin!\n");

    while (highest_bid < min_bid) {
        for (i = 0; i < num_bidders; i++) {
            if (bidders[i].balance > highest_bid) {
                printf("%s's turn to bid.\n", bidders[i].name);
                printf("%s, what is your bid? (balance: %d)\n", bidders[i].name, bidders[i].balance);
                scanf("%d", &j);
                if (j > bidders[i].balance) {
                    printf("Sorry, you don't have enough funds for that bid.\n");
                } else if (j <= highest_bid) {
                    printf("Sorry, your bid is too low.\n");
                } else {
                    highest_bid = j;
                    highest_bidder = i;
                    printf("%s bids %d!\n", bidders[highest_bidder].name, highest_bid);
                }
            }
        }
    }

    printf("\n\nThe winner of the auction for %s is %s with a bid of %d\n", item, bidders[highest_bidder].name, highest_bid);
    printf("Thanks for using the Digital Auction System!\n");

    return 0;
}