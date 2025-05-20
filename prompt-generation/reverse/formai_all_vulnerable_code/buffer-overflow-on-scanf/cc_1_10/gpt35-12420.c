//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_NAME_LENGTH 30

struct Bidder {
    char name[MAX_NAME_LENGTH];
    double bid;
};

int main() {
    struct Bidder bidders[MAX_BIDDERS];
    int num_bidders = 0;
    double highest_bid = 0;
    int highest_bidder_index = -1;
    int num_rounds = 0;

    printf("Welcome to the Digital Auction System!\n");

    while (num_bidders < MAX_BIDDERS) {
        char name[MAX_NAME_LENGTH];
        double bid;

        printf("Enter name and bid (or 'done' to finish adding bidders): ");
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        scanf("%lf", &bid);

        if (bid <= highest_bid) {
            printf("Sorry, your bid must be higher than the current highest bid of %.2f\n", highest_bid);
            continue;
        }

        if (num_bidders == 0) {
            printf("Welcome, %s! You are currently the highest bidder with a bid of %.2f\n", name, bid);
        } else {
            printf("Welcome, %s! You have surpassed the highest bid with a bid of %.2f\n", name, bid);
            printf("%s is no longer the highest bidder\n", bidders[highest_bidder_index].name);
        }

        struct Bidder new_bidder = { .bid = bid };
        strncpy(new_bidder.name, name, MAX_NAME_LENGTH);
        bidders[num_bidders] = new_bidder;

        num_bidders++;
        highest_bid = bid;
        highest_bidder_index = num_bidders - 1;

        if (num_bidders == MAX_BIDDERS) {
            printf("Maximum number of bidders reached\n");
        }
    }

    printf("The auction has ended after %d rounds\n", num_rounds);
    printf("The winning bidder is %s with a bid of %.2f\n", bidders[highest_bidder_index].name, highest_bid);

    return EXIT_SUCCESS;
}