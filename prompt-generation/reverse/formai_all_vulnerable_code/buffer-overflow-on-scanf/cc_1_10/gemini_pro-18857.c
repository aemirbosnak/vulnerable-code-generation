//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Bidder {
    char name[20];
    int bid;
};

struct Item {
    char name[20];
    int starting_bid;
    int current_bid;
    struct Bidder highest_bidder;
};

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the auction items
    struct Item items[] = {
        {"Sword of Montague", 100, 0, {""}},
        {"Dagger of Capulet", 150, 0, {""}},
        {"Potion of Love", 200, 0, {""}}
    };

    // Get the number of bidders
    int num_bidders;
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    // Create the bidders
    struct Bidder bidders[num_bidders];
    for (int i = 0; i < num_bidders; i++) {
        printf("Enter the name of bidder %d: ", i + 1);
        scanf("%s", bidders[i].name);
    }

    // Start the auction
    for (int i = 0; i < sizeof(items) / sizeof(struct Item); i++) {
        // Display the item
        printf("Item: %s\n", items[i].name);
        printf("Starting bid: %d\n", items[i].starting_bid);

        // Get the bids
        for (int j = 0; j < num_bidders; j++) {
            int bid;
            printf("%s, enter your bid: ", bidders[j].name);
            scanf("%d", &bid);

            // Check if the bid is valid
            if (bid < items[i].starting_bid) {
                printf("Invalid bid. Please enter a bid greater than or equal to the starting bid.\n");
                j--;
                continue;
            }

            // Update the highest bid
            if (bid > items[i].current_bid) {
                items[i].current_bid = bid;
                items[i].highest_bidder = bidders[j];
            }
        }

        // Display the winner
        printf("The winner of %s is %s with a bid of %d.\n", items[i].name, items[i].highest_bidder.name, items[i].current_bid);
    }

    return 0;
}