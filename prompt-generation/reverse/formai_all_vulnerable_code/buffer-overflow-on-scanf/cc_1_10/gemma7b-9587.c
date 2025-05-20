//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10

struct Item {
    char name[20];
    int starting_price;
    int current_bid;
    char winner[20];
};

void display_auction_list(struct Item items[]) {
    for (int i = 0; i < MAX_BIDS; i++) {
        printf("Item: %s\n", items[i].name);
        printf("Starting Price: %d\n", items[i].starting_price);
        printf("Current Bid: %d\n", items[i].current_bid);
        printf("Winner: %s\n", items[i].winner);
        printf("\n");
    }
}

void place_bid(struct Item items[], int user_bid) {
    for (int i = 0; i < MAX_BIDS; i++) {
        if (strcmp(items[i].winner, "") == 0) {
            items[i].current_bid = user_bid;
            strcpy(items[i].winner, "User");
            printf("Your bid has been placed successfully!\n");
            return;
        }
    }

    printf("Error: Your bid could not be placed.\n");
}

void notify_winner(struct Item items[]) {
    for (int i = 0; i < MAX_BIDS; i++) {
        if (strcmp(items[i].winner, "User") == 0) {
            printf("Congratulations, %s! You have won the auction for %s!\n", items[i].winner, items[i].name);
            printf("Please pay the total amount of %d.\n", items[i].current_bid);
        }
    }
}

int main() {
    struct Item items[MAX_BIDS] = {
        {"Laptop", 500, 200, ""},
        {"Smartphone", 1000, 600, ""},
        {"Watch", 2000, 800, ""}
    };

    display_auction_list(items);

    int user_bid;
    printf("Enter your bid: ");
    scanf("%d", &user_bid);

    place_bid(items, user_bid);

    notify_winner(items);

    return 0;
}