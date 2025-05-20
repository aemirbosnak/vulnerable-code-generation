//FormAI DATASET v1.0 Category: Digital Auction System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct auction_item {
    char item_name[20];
    int current_bid;
    char highest_bidder[20];
};

void display_items(struct auction_item items[], int size);
void bid_item(struct auction_item *item);

int main() {
    int num_items, i, item_choice;
    struct auction_item *items, chosen_item;

    printf("Welcome to the Digital Auction System!\n");
    printf("Please enter the number of items to auction: ");
    scanf("%d", &num_items);

    items = (struct auction_item*) malloc(num_items * sizeof(struct auction_item));

    for (i = 0; i < num_items; i++) {
        printf("Please enter the name of item #%d: ", i+1);
        scanf(" %s", items[i].item_name);
        items[i].current_bid = 0;
        strcpy(items[i].highest_bidder, "-");
    }

    while (1) {
        display_items(items, num_items);

        printf("Please choose an item to bid on (enter 0 to exit): ");
        scanf("%d", &item_choice);

        if (item_choice == 0) {
            break;
        }

        chosen_item = items[item_choice-1];
        bid_item(&chosen_item);

        if (chosen_item.current_bid > items[item_choice-1].current_bid) {
            items[item_choice-1] = chosen_item;
        }
    }

    printf("Auction closed. Here are the final bids:\n");
    display_items(items, num_items);

    free(items);

    return 0;
}

void display_items(struct auction_item items[], int size) {
    int i;

    printf("\nCurrent Items for Auction:\n");
    printf("-----------------------------\n");

    for (i = 0; i < size; i++) {
        printf("%d. %s (%d) - Highest bid: %d\n", i+1, items[i].item_name, items[i].current_bid, items[i].highest_bidder);
    }

    printf("-----------------------------\n\n");
}

void bid_item(struct auction_item *item) {
    int new_bid;
    char bidder_name[20];

    printf("\nPlease enter your name: ");
    scanf(" %s", bidder_name);

    printf("Please enter your bid: ");
    scanf("%d", &new_bid);

    if (new_bid > item->current_bid) {
        item->current_bid = new_bid;
        strcpy(item->highest_bidder, bidder_name);
        printf("Congratulations! You are the highest bidder for %s at $%d!\n", item->item_name, item->current_bid);
    } else {
        printf("Sorry, your bid for %s at $%d was not high enough. The current bid is $%d by %s.\n", item->item_name, new_bid, item->current_bid, item->highest_bidder);
    }
}