//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BIDS 10 // Maximum number of bids allowed
#define MAX_DEPOSIT 100000 // Maximum deposit allowed
#define AUCTION_TIME 300 // Time in seconds for auction to run

typedef struct {
    char name[50];
    int deposit;
    int bid[MAX_BIDS];
} Bidder;

int main() {
    Bidder bidders[5]; // Array of 5 bidders
    int current_bids[5]; // Array to keep track of current highest bids for each bidder
    int auction_start_time = time(NULL); // Get current time
    time_t current_time;
    int bid;
    int highest_bidder;
    bool active_bid[MAX_BIDS] = {true}; // Active bid status for each bid

    // Initialize bidders
    for (int i = 0; i < 5; i++) {
        printf("Enter name of bidder %d: ", i + 1);
        scanf("%s", bidders[i].name);
        printf("Enter deposit of bidder %d (must be less than %d): ", i + 1, MAX_DEPOSIT);
        scanf("%d", &bidders[i].deposit);

        if (bidders[i].deposit > MAX_DEPOSIT) {
            printf("Invalid deposit amount. Please enter a deposit less than %d.\n", MAX_DEPOSIT);
            i--;
        } else {
            for (int j = 0; j < MAX_BIDS; j++) {
                bidders[i].bid[j] = 0;
            }
        }
    }

    // Auction loop
    while (time(NULL) - auction_start_time <= AUCTION_TIME) {
        // Print current time and active bidders
        current_time = time(NULL);
        printf("Current Time: %s", ctime(&current_time));
        printf("Active Bidders:\n");
        for (int i = 0; i < 5; i++) {
            if (bidders[i].deposit > 0) {
                printf("%s\n", bidders[i].name);
            }
        }

        // Get bid input from bidders
        for (int i = 0; i < 5; i++) {
            highest_bidder = -1;
            // Check if bidder is still active
            if (bidders[i].deposit <= 0) {
                continue;
            }
            printf("%s, enter your bid (current highest bid is %d, enter 0 for no bid): ", bidders[i].name, current_bids[i]);
            scanf("%d", &bid);
            // Check if bid is valid
            if (bid < 0 || bid > bidders[i].deposit || (bid > 0 && !active_bid[i])) {
                printf("Invalid bid entered. Please enter a valid bid.\n");
                i--;
            } else if (bid > current_bids[i]) {
                current_bids[i] = bid;
                if (highest_bidder == -1) {
                    highest_bidder = i;
                }
            } else if (bid == 0) {
                bidders[i].deposit = 0; // Bidder has withdrawn from auction
            }
        }

        // Determine highest bidder and deduct bid amount from deposit
        bidders[highest_bidder].deposit -= current_bids[highest_bidder];
        current_bids[highest_bidder] = 0;

        // Check if auction is over (all bidders have withdrawn or no active bidders)
        bool all_withdrawn = true;
        for (int i = 0; i < 5; i++) {
            if (bidders[i].deposit > 0) {
                all_withdrawn = false;
                break;
            }
        }
        if (all_withdrawn) {
            printf("Auction is over. No bidders left.\n");
            break;
        }
        bool all_inactive = true;
        for (int i = 0; i < 5; i++) {
            if (bidders[i].deposit > 0 && active_bid[i]) {
                all_inactive = false;
                break;
            }
        }
        if (all_inactive) {
            printf("Auction is over. No active bidders left.\n");
            break;
        }
    }

    // Print results
    printf("Final Results:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %d\n", bidders[i].name, bidders[i].deposit);
    }

    return 0;
}