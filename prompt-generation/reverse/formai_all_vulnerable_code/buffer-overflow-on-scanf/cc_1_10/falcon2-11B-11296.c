//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int bid;
    int bidder;
    int current_bidder;
} auction_bid;

int main() {
    auction_bid bids[100];
    int num_bids = 0;
    int current_bidder = 0;
    int current_bid = 0;

    while (1) {
        printf("Enter your bid: ");
        scanf("%d", &current_bid);

        if (current_bid < 0) {
            printf("Invalid bid. Please enter a positive integer.\n");
            continue;
        }

        if (num_bids == 0) {
            bids[current_bidder].bid = current_bid;
            bids[current_bidder].bidder = current_bidder;
            bids[current_bidder].current_bidder = current_bidder;
            current_bidder++;
            num_bids++;
        } else if (current_bid > bids[current_bidder - 1].bid) {
            bids[current_bidder].bid = current_bid;
            bids[current_bidder].bidder = current_bidder;
            bids[current_bidder].current_bidder = current_bidder;
            current_bidder++;
            num_bids++;
        } else {
            printf("Invalid bid. Please enter a higher bid.\n");
        }

        printf("Current bids:\n");
        for (int i = 0; i < num_bids; i++) {
            printf("%d - %d (%d)\n", bids[i].bid, bids[i].bidder, bids[i].current_bidder);
        }

        printf("Do you want to place another bid? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            continue;
        } else if (choice == 'N' || choice == 'n') {
            break;
        } else {
            printf("Invalid input. Please enter Y or N.\n");
        }
    }

    printf("Auction ended. Thank you for participating!\n");

    return 0;
}