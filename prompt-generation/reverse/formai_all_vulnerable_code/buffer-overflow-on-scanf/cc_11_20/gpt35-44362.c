//FormAI DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50
#define AUCTION_LENGTH 60

typedef struct bidder {
    char name[50];
    float balance;
} Bidder;

typedef struct item {
    char name[ITEM_NAME_LENGTH];
    float current_price;
    int bidder_index;
} Item;

int main() {
    Bidder bidders[MAX_BIDDERS];
    Item items[MAX_ITEMS];
    int num_bidders = 0;
    int num_items = 0;
    int current_item_index = 0;
    int seconds_left = AUCTION_LENGTH;

    // Add bidders
    printf("Welcome to the Digital Auction System!\n");
    printf("Let's start by adding some bidders:\n");
    while (num_bidders < MAX_BIDDERS) {
        printf("Enter the name of bidder %d (or \"done\" to finish):\n", num_bidders + 1);
        scanf("%s", bidders[num_bidders].name);

        if (strcmp(bidders[num_bidders].name, "done") == 0) {
            break;
        }

        printf("Enter the balance of bidder %d:\n", num_bidders + 1);
        scanf("%f", &bidders[num_bidders].balance);

        num_bidders++;
    }

    // Add items
    printf("Now, let's add some items up for auction:\n");
    while (num_items < MAX_ITEMS) {
        printf("Enter the name of item %d (or \"done\" to finish):\n", num_items + 1);
        scanf("%s", items[num_items].name);

        if (strcmp(items[num_items].name, "done") == 0) {
            break;
        }

        printf("Enter the starting price of item %d:\n", num_items + 1);
        scanf("%f", &items[num_items].current_price);
        items[num_items].bidder_index = -1;

        num_items++;
    }

    // Start auction
    printf("\n\n------------------\n");
    printf("Starting auction now!\n");
    printf("------------------\n\n");

    while (seconds_left > 0 && current_item_index < num_items) {
        Item current_item = items[current_item_index];

        // Print current item
        printf("------------------\n");
        printf("Current item: %s\n", current_item.name);
        printf("Current price: %.2f\n", current_item.current_price);

        // Allow bidders to bid
        int current_bidder_index = 0;
        while (current_bidder_index < num_bidders) {
            Bidder current_bidder = bidders[current_bidder_index];

            // Only allow bidding if bidder has enough balance
            if (current_bidder.balance >= current_item.current_price + 0.01) {
                printf("It is %s's turn to bid.\n", current_bidder.name);
                printf("%s, enter your bid (or \"pass\" to skip):\n", current_bidder.name);
                char bid_input[10];
                scanf("%s", bid_input);

                if (strcmp(bid_input, "pass") == 0) {
                    printf("%s has passed.\n", current_bidder.name);
                } else {
                    float bid = atof(bid_input);
                    if (bid > current_item.current_price) {
                        current_item.bidder_index = current_bidder_index;
                        current_item.current_price = bid;

                        printf("%s has bid %.2f!\n", current_bidder.name, bid);
                    } else {
                        printf("Sorry, your bid must be higher than the current price of %.2f.\n", current_item.current_price);
                    }
                }
            }

            current_bidder_index++;
        }

        // Print winning bidder and update balances
        if (current_item.bidder_index != -1) {
            Bidder winning_bidder = bidders[current_item.bidder_index];

            printf("------------------\n");
            printf("Sold to %s for %.2f!\n", winning_bidder.name, current_item.current_price);

            // Update balances
            for (int i = 0; i < num_bidders; i++) {
                if (i == current_item.bidder_index) {
                    bidders[i].balance -= current_item.current_price;
                } else {
                    bidders[i].balance += current_item.current_price / (num_bidders - 1);
                }
            }
        } else {
            printf("------------------\n");
            printf("No one bid on %s.\n", current_item.name);
        }

        printf("\n");
        current_item_index++;
        seconds_left--;
    }

    printf("Auction over!\n");
    printf("Final balances:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%s: %.2f\n", bidders[i].name, bidders[i].balance);
    }

    return 0;
}