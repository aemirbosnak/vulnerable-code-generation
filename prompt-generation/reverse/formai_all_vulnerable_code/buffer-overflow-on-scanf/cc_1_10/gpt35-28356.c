//FormAI DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDS 10
#define STARTING_BID 100
#define BID_INCREMENT 10

int main()
{
    int current_bid = STARTING_BID;
    int bids[MAX_BIDS];
    int num_bids = 0;
    char bidder_names[MAX_BIDS][50];
    char winner_name[50] = "";
    int winner_bid = 0;
    srand(time(NULL));
    int random_num = rand() % 100;

    printf("Welcome to the Digital Auction System!\n\n");
    printf("The item up for auction is a mystery item. Its value is between 1 and 100.\n\n");
    printf("The starting bid is %d.\n", current_bid);
    printf("Bidders may increase the bid by %d.\n", BID_INCREMENT);
    printf("The auction will end once %d bids have been placed.\n\n", MAX_BIDS);

    while (num_bids < MAX_BIDS) {
        printf("Bidders, please enter your name: ");
        scanf("%s", bidder_names[num_bids]);
        printf("Your current bid is %d. What is your new bid? ", current_bid);
        scanf("%d", &bids[num_bids]);

        if (bids[num_bids] <= current_bid) {
            printf("Sorry, your bid must be higher than the current bid of %d.\n\n", current_bid);
            continue;
        }

        current_bid = bids[num_bids];
        num_bids++;

        if (num_bids == MAX_BIDS) {
            break;
        }

        printf("Would you like to continue bidding? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    printf("\nThe auction has ended!\n\n");

    for (int i = 0; i < num_bids; i++) {
        if (bids[i] > winner_bid) {
            winner_bid = bids[i];
            strcpy(winner_name, bidder_names[i]);
        }
    }

    if (winner_bid > random_num) {
        printf("%s has won the auction with a bid of %d.\n", winner_name, winner_bid);
        printf("The mystery item was worth %d.\n\n", random_num);
    } else {
        printf("No one has won the auction, as the mystery item was worth %d and the highest bid was %d.\n\n", random_num, winner_bid);
    }

    return 0;
}