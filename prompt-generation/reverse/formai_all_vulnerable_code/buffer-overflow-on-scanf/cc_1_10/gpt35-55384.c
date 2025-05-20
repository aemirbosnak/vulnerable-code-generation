//FormAI DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to store auction items
typedef struct AuctionItem {
    char name[20];
    int starting_bid;
    int current_bid;
    char highest_bidder[20];
    int time_left;
} AuctionItem;

// Function to start the auction
int startAuction(AuctionItem *items, int num_items);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of auction items
    AuctionItem items[3] = {
        {"Painting", 500, 0, "", 5},
        {"Vintage car", 10000, 0, "", 10},
        {"Diamond necklace", 2000, 0, "", 7}
    };

    // Start the auction
    int result = startAuction(items, 3);

    // Print the winner of the auction
    if (result == -1) {
        printf("No one won the auction\n");
    } else {
        printf("%s won the auction with a bid of %d\n", items[result].highest_bidder, items[result].current_bid);
    }

    return 0;
}

// Function to start the auction
int startAuction(AuctionItem *items, int num_items) {
    // Loop through each auction item
    for (int i = 0; i < num_items; i++) {
        printf("Starting auction for %s\n", items[i].name);
        items[i].current_bid = rand() % items[i].starting_bid + 1;
        printf("The starting bid for %s is %d\n", items[i].name, items[i].current_bid);

        // Loop through each bidder and get their bid
        int highest_bid = items[i].current_bid;
        for (int j = 1; j <= 3; j++) {
            printf("Enter your name for bidding: ");
            char name[20];
            scanf("%s", name);

            printf("Enter your bid for %s: ", items[i].name);
            int bid;
            scanf("%d", &bid);

            if (bid > highest_bid) {
                printf("Congratulations, you are currently the highest bidder for %s!\n", items[i].name);
                highest_bid = bid;
                strcpy(items[i].highest_bidder, name);
            } else {
                printf("Sorry, your bid was not high enough for %s.\n", items[i].name);
            }
        }

        // Print the highest bidder and bid amount
        printf("The auction for %s is over!\n", items[i].name);
        if (highest_bid > items[i].starting_bid) {
            printf("%s won the auction with a bid of %d\n", items[i].highest_bidder, highest_bid);
            items[i].current_bid = highest_bid;
        } else {
            printf("No one bid high enough for %s\n", items[i].name);
            items[i].current_bid = 0;
        }
        printf("\n");
    }

    // Find the overall winner of the auction
    int winner = -1;
    int highest_total_bid = 0;
    for (int i = 0; i < num_items; i++) {
        if (items[i].current_bid > highest_total_bid) {
            highest_total_bid = items[i].current_bid;
            winner = i;
        }
    }

    return winner;
}