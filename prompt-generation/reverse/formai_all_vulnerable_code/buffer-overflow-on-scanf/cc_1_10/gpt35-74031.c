//FormAI DATASET v1.0 Category: Digital Auction System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct auction_item {
    char name[50];
    int starting_bid;
    int current_bid;
    char highest_bidder[50];
};

void print_item_information(struct auction_item item) {
    printf("Item: %s\n", item.name);
    printf("Starting bid: $%d\n", item.starting_bid);
    printf("Current bid: $%d\n", item.current_bid);
    printf("Highest bidder: %s\n", item.highest_bidder);
}

void bid_on_item(struct auction_item *item, int new_bid, char *bidder_name) {
    if (new_bid > item->current_bid) {
        item->current_bid = new_bid;
        strcpy(item->highest_bidder, bidder_name);
        printf("%s is now the highest bidder!\n", item->highest_bidder);
    } else {
        printf("Sorry, your bid is not high enough.\n");
    }
}

int main() {
    struct auction_item item1;
    strcpy(item1.name, "Painting");
    item1.starting_bid = 100;
    item1.current_bid = 0;
    strcpy(item1.highest_bidder, "No one");

    printf("Welcome to the digital auction system!\n");
    printf("\nItem for auction: Painting\n");
    printf("Starting bid: $%d\n", item1.starting_bid);
    printf("\nEnter your name to bid on the item: ");
    char bidder_name[50];
    scanf("%s", bidder_name);

    while (true) {
        printf("\nCurrent highest bidder: %s\n", item1.highest_bidder);
        printf("Current highest bid: $%d\n", item1.current_bid);
        printf("Enter your bid (or enter 0 to exit): ");
        int new_bid;
        scanf("%d", &new_bid);

        if (new_bid == 0) {
            break;
        }
        bid_on_item(&item1, new_bid, bidder_name);
    }

    printf("\nFinal item information:\n");
    print_item_information(item1);

    return 0;
}