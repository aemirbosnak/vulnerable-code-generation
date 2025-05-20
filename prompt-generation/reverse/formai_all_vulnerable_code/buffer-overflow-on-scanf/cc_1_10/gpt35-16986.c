//FormAI DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10
#define MIN_BID_INCREMENT 5

struct Bid {
    char name[50];
    int amount;
};

int main() {
    struct Bid bids[MAX_BIDS];
    int bid_count = 0;
    int item_price = 100;
    int current_bid = 0;
    int i;

    printf("Welcome to the Digital Auction System!\n");
    printf("The starting price for the item is %d\n", item_price);

    while (current_bid < item_price) {
        char name[50];
        int amount;

        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter your bid: ");
        scanf("%d", &amount);

        if (amount <= current_bid || amount < item_price) {
            printf("Your bid is too low. Please enter a higher amount.\n");
            continue;
        }

        if (amount < current_bid + MIN_BID_INCREMENT) {
            printf("Your bid must be at least %d higher than the current bid.\n", MIN_BID_INCREMENT);
            continue;
        }

        if (bid_count >= MAX_BIDS) {
            printf("Sorry, we have reached the maximum number of bids.\n");
            break;
        }

        strcpy(bids[bid_count].name, name);
        bids[bid_count].amount = amount;
        bid_count++;
        current_bid = amount;

        printf("Your bid has been recorded.\n");
    }

    printf("The bidding has ended.\n");
    printf("The highest bid was $%d, made by %s.\n", current_bid, bids[bid_count - 1].name);

    return 0;
}