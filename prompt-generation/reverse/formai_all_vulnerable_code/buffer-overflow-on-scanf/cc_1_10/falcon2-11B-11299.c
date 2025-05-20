//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct bidder {
    char name[100];
    int bid;
};

int main() {
    srand(time(NULL));

    struct bidder bidders[10];

    int num_bidders = 0;
    int num_auctions = 0;
    int highest_bid = 0;
    char winner[100];

    printf("Welcome to the Digital Auction System!\n");
    printf("Please enter the number of bidders:\n");
    scanf("%d", &num_bidders);

    for (int i = 0; i < num_bidders; i++) {
        printf("Bidder %d: ", i + 1);
        fflush(stdout);
        scanf("%s %d", bidders[i].name, &bidders[i].bid);
        printf("Bidder %d: %s %d\n", i + 1, bidders[i].name, bidders[i].bid);
        fflush(stdout);
    }

    for (int i = 0; i < num_auctions; i++) {
        int random_bidder = rand() % num_bidders;
        printf("Auction %d:\n", i + 1);
        fflush(stdout);
        for (int j = 0; j < num_bidders; j++) {
            if (j == random_bidder) {
                printf("%s is the winner of Auction %d with a bid of %d\n", bidders[j].name, i + 1, bidders[j].bid);
                fflush(stdout);
                highest_bid = bidders[j].bid;
            } else {
                printf("%s bid %d\n", bidders[j].name, bidders[j].bid);
                fflush(stdout);
            }
        }
        printf("Highest bid: %d\n", highest_bid);
        fflush(stdout);
    }

    printf("Congratulations to all the winners!\n");

    return 0;
}