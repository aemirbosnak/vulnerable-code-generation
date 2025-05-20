//FormAI DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 10
#define ITEM_NAME_LENGTH 50
#define USER_NAME_LENGTH 20


typedef struct {
    char name[ITEM_NAME_LENGTH];
    double current_bid;
    char highest_bidder[USER_NAME_LENGTH];
} Item;

typedef struct {
    char name[USER_NAME_LENGTH];
    double balance;
} User;

void print_item(Item item) {
    printf("=====================\n");
    printf("Item Name: %s\n", item.name);
    printf("Current Bid: $%.2f\n", item.current_bid);
    printf("Highest Bidder: %s\n", item.highest_bidder);
    printf("=====================\n");
}

void print_user_balance(User user) {
    printf("User: %s\nBalance: $%.2f\n", user.name, user.balance);
}

int main() {

    // Seed random number generator
    srand(time(NULL));

    // Create an item
    Item item = { "Antique clock", 50.00, "" };

    // Create users
    User user1 = { "John", 500.00 };
    User user2 = { "Sarah", 1000.00 };
    User user3 = { "Mark", 250.00 };

    // Create an array of users
    User users[3] = { user1, user2, user3 };

    // Inform users of the item for auction
    printf("Welcome to the digital auction system!\n");
    print_item(item);

    // Start the auction
    int num_bids = 0;
    while (num_bids < MAX_BIDS) {
        // Choose a random user
        int user_index = rand() % 3;
        User user = users[user_index];
        printf("\nIt is %s's turn.\n", user.name);

        // Request bid
        double bid;
        printf("Enter your bid (minimum $%.2f): $", item.current_bid + 0.01);
        scanf("%lf", &bid);

        // Check if bid is valid
        if (bid < item.current_bid + 0.01) {
            printf("Bid must be at least $%.2f.\n", item.current_bid + 0.01);
            continue;
        }
        if (bid > user.balance) {
            printf("You do not have enough funds to make that bid.\n");
            continue;
        }

        // Update item and user information
        item.current_bid = bid;
        strcpy(item.highest_bidder, user.name);
        user.balance -= bid;

        // Inform users of new highest bid and highest bidder
        printf("\nNew highest bid: $%.2f\n", item.current_bid);
        printf("Highest bidder: %s\n", item.highest_bidder);

        // Print user balance
        for (int i = 0; i < 3; i++) {
            print_user_balance(users[i]);
        }

        num_bids++;
    }

    // End the auction
    printf("\nThe auction has ended!\n");
    printf("Final item information:\n");
    print_item(item);
    printf("\nFinal user balances:\n");
    for (int i = 0; i < 3; i++) {
        print_user_balance(users[i]);
    }

    return 0;
}