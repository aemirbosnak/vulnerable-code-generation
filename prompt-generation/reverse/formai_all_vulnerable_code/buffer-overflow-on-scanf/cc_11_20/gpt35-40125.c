//FormAI DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// User struct for the bidders
typedef struct user {
    char name[20];
    int balance;
} User;

// Auction item struct
typedef struct item {
    char name[20];
    int price;
    User* highest_bidder;
} Item;

int main() {
    // Initialize random seed for randomizing initial balance of users
    srand(time(NULL));

    // Initialize the auction item
    Item sword = {"Sword of King Arthur", 100, NULL};

    // Initialize the array of users
    User users[5] = {
        {"Sir Lancelot", rand() % 1000},
        {"Lady Guinevere", rand() % 1000},
        {"Sir Galahad", rand() % 1000},
        {"Merlin", rand() % 1000},
        {"Morgana", rand() % 1000}
    };

    int num_bidders = sizeof(users) / sizeof(users[0]);
    int auction_ongoing = 1;

    printf("Welcome to the Medieval Auction!\n");
    printf("Today's item: %s\n", sword.name);

    while (auction_ongoing) {
        // Print current highest bid
        printf("Current highest bid: %d\n", sword.price);

        // Print bidders and their balances
        printf("Bidders:\n");
        for (int i = 0; i < num_bidders; i++) {
            printf("%-15s Balance: %d\n", users[i].name, users[i].balance);
        }

        // Prompt user for bid
        printf("Enter your bid (or 0 to quit): ");
        int bid;
        scanf("%d", &bid);

        // If user enters 0, quit the auction
        if (bid == 0) {
            auction_ongoing = 0;
            break;
        }

        // Check if bid is higher than current highest bid
        if (bid > sword.price) {
            // Determine the highest bidder
            User* highest_bidder = NULL;
            for (int i = 0; i < num_bidders; i++) {
                if (users[i].balance >= bid) {
                    highest_bidder = &users[i];
                    break;
                }
            }

            // If highest bidder is found, update the item and bidder
            if (highest_bidder != NULL) {
                sword.price = bid;
                sword.highest_bidder = highest_bidder;
                highest_bidder->balance -= bid;
                printf("%s is the highest bidder with a bid of %d!\n", highest_bidder->name, bid);
            } else {
                printf("Sorry, you do not have enough money to bid that much.\n");
            }
        } else {
            printf("Sorry, your bid must be higher than the current highest bid of %d.\n", sword.price);
        }

        // Check if auction should continue
        int no_bids = 1;
        for (int i = 0; i < num_bidders; i++) {
            if (users[i].balance >= sword.price) {
                no_bids = 0;
                break;
            }
        }
        if (no_bids) {
            auction_ongoing = 0;
        }
    }

    // Print final result of auction
    printf("Auction over! %s sold for %d gold to %s\n", sword.name, sword.price, sword.highest_bidder->name);
    printf("Remaining balances:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%-15s Balance: %d\n", users[i].name, users[i].balance);
    }

    return 0;
}