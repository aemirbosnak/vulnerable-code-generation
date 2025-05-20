//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 10
#define MAX_BIDS 100
#define MIN_BID 0
#define INCREMENT 1

typedef struct {
    char name[50];
    int bid;
    time_t time;
} Bidder;

Bidder bidders[MAX_BIDDERS];
int num_bidders = 0;
int highest_bid = MIN_BID;

void print_bidders() {
    printf("Current bidders:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%d. %s - %d\n", i+1, bidders[i].name, bidders[i].bid);
    }
}

void new_bid(char* name, int bid) {
    if (num_bidders >= MAX_BIDDERS) {
        printf("Max number of bidders reached.\n");
        return;
    }

    strcpy(bidders[num_bidders].name, name);
    bidders[num_bidders].bid = bid;
    bidders[num_bidders].time = time(NULL);

    if (bid > highest_bid) {
        highest_bid = bid;
        num_bidders--; // move the winner to the beginning for easier access
        strcpy(bidders[0].name, bidders[num_bidders+1].name);
    }

    num_bidders++;
}

int main() {
    srand(time(NULL));

    char bidder_name[50];
    int bid;

    while (1) {
        printf("\nWelcome to the Digital Auction System!\n");
        print_bidders();

        printf("\nEnter your name: ");
        scanf("%s", bidder_name);

        printf("Enter your bid: ");
        scanf("%d", &bid);

        new_bid(bidder_name, bid);

        printf("Your bid has been accepted. Current highest bid is %d by %s.\n", highest_bid, bidders[0].name);

        if (rand() % 5 == 0) { // simulate random system events
            printf("\nSystem Event: The auction is closed for the night.\n");
            break;
        }
    }

    printf("\nAuction closed. Winner is %s with a bid of %d.\n", bidders[0].name, highest_bid);

    return 0;
}