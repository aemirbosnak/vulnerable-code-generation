//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct user {
    char name[50];
    int bid;
};

int main() {
    struct user users[10];
    int num_users, current_bid, min_bid;

    // initialize users
    for (int i = 0; i < 10; i++) {
        printf("Enter name and bid for user %d: ", i+1);
        scanf("%s %d", users[i].name, &users[i].bid);
    }

    // set up initial bids
    for (int i = 0; i < 10; i++) {
        if (users[i].bid < min_bid) {
            min_bid = users[i].bid;
        }
    }

    // start bidding
    current_bid = min_bid;
    while (1) {
        // display current bid
        printf("Current bid is %d\n", current_bid);

        // get new bid
        printf("Enter new bid: ");
        scanf("%d", &current_bid);

        // update min_bid
        for (int i = 0; i < 10; i++) {
            if (current_bid < users[i].bid) {
                users[i].bid = current_bid;
            }
        }

        // check for end of bidding
        if (current_bid == min_bid) {
            printf("Bidding is closed.\n");
            break;
        }
    }

    // determine winner and print result
    int winner_index = 0;
    for (int i = 0; i < 10; i++) {
        if (users[i].bid == min_bid) {
            winner_index = i;
        }
    }
    printf("The winner is %s with bid of %d!\n", users[winner_index].name, min_bid);

    return 0;
}