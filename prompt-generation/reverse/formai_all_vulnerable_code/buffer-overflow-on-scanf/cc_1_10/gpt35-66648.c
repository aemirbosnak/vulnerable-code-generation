//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct bidder {
    char name[50];
    int max_bid;
};

struct auction_item {
    int id;
    char description[100];
    struct bidder highest_bidder;
    int current_bid;
};

void print_item(struct auction_item item) {
    printf("ID: %d\n", item.id);
    printf("Description: %s\n", item.description);
    printf("Current Bid: %d\n", item.current_bid);
    printf("Highest Bidder: %s (%d)\n", item.highest_bidder.name, item.highest_bidder.max_bid);
}

int main() {
    srand(time(NULL));
    struct auction_item item;
    item.id = rand() % 1000 + 1;
    sprintf(item.description, "Item %d: Example Auction Item", item.id);
    item.current_bid = 0;

    printf("Welcome to the Digital Auction System!\n");
    printf("Here is the current item up for bid:\n");
    print_item(item);

    printf("Enter your name (max 50 characters): ");
    fgets(item.highest_bidder.name, 50, stdin);
    item.highest_bidder.name[strcspn(item.highest_bidder.name, "\n")] = 0;

    printf("Enter your max bid: ");
    scanf("%d", &item.highest_bidder.max_bid);

    if (item.highest_bidder.max_bid > item.current_bid) {
        item.current_bid = item.highest_bidder.max_bid;
        printf("Congratulations! You are now the highest bidder for this item.\n");
    } else {
        printf("Sorry, your bid is not high enough.\n");
    }

    printf("Here is the updated item:\n");
    print_item(item);

    return 0;
}