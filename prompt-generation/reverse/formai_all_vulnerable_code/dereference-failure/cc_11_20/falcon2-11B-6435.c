//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int item_id;
    int price;
    int bid;
    int bidder;
} auction_item;

typedef struct {
    int num_items;
    auction_item *items;
} auction;

int main() {
    srand(time(NULL)); // seed the random number generator

    auction my_auction;
    my_auction.num_items = 5;
    my_auction.items = (auction_item *)malloc(my_auction.num_items * sizeof(auction_item));

    // initialize the items
    for (int i = 0; i < my_auction.num_items; i++) {
        my_auction.items[i].item_id = rand() % 1000 + 1;
        my_auction.items[i].price = rand() % 1000 + 1;
        my_auction.items[i].bid = 0;
        my_auction.items[i].bidder = -1;
    }

    printf("Welcome to the digital auction!\n");
    printf("There are %d items up for auction.\n", my_auction.num_items);

    // simulate the auction
    while (1) {
        // display the items
        for (int i = 0; i < my_auction.num_items; i++) {
            printf("Item %d: %d, current bid: %d\n", my_auction.items[i].item_id, my_auction.items[i].price, my_auction.items[i].bid);
        }

        // take bids
        int item_id, bidder, bid;
        printf("Enter the item number to bid on: ");
        scanf("%d", &item_id);
        if (item_id < 1 || item_id > my_auction.num_items) {
            printf("Invalid item number. Please try again.\n");
        } else {
            printf("Enter your bid: ");
            scanf("%d", &bid);
            if (bid <= 0) {
                printf("Invalid bid. Please enter a positive integer.\n");
            } else {
                for (int i = 0; i < my_auction.num_items; i++) {
                    if (my_auction.items[i].item_id == item_id) {
                        my_auction.items[i].bid = bid;
                        my_auction.items[i].bidder = getpid(); // get the current process ID
                        printf("Your bid for item %d is %d.\n", item_id, bid);
                        break;
                    }
                }
            }
        }

        // end the auction
        printf("Would you like to end the auction? (y/n): ");
        char answer;
        scanf(" %c", &answer);
        if (answer == 'y') {
            break;
        }
    }

    // display the results
    for (int i = 0; i < my_auction.num_items; i++) {
        if (my_auction.items[i].bid > 0) {
            printf("Item %d was won by bidder %d with a bid of %d.\n", my_auction.items[i].item_id, getpid(), my_auction.items[i].bid);
        }
    }

    free(my_auction.items);
    return 0;
}