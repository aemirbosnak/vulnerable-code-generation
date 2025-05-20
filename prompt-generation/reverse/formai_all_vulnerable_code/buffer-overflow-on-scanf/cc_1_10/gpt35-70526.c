//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10
#define ITEM_NAME_LEN 50
#define AUCTION_DURATION 60

typedef struct {
    char name[ITEM_NAME_LEN];
    float current_price;
    float bids[MAX_BIDS];
    int num_bids;
    int time_remaining;
} Item;

void display_item(Item item) {
    printf("Item: %s\n", item.name);
    printf("Current Price: %.2f\n", item.current_price);
    printf("Number of Bids: %d\n", item.num_bids);
    printf("Time Remaining: %d seconds\n", item.time_remaining);
}

void display_bids(Item item) {
    printf("Bids for %s:\n", item.name);
    for (int i = 0; i < item.num_bids; i++) {
        printf("\tBid %d: %.2f\n", i + 1, item.bids[i]);
    }
}

void make_bid(Item *item, float bid) {
    if (item->num_bids < MAX_BIDS) {
        if (bid > item->current_price) {
            item->bids[item->num_bids++] = bid;
            item->current_price = bid;
            printf("Bid accepted for %.2f\n", bid);
        } else {
            printf("Bid must be higher than current price\n");
        }
    } else {
        printf("Max number of bids reached for this item\n");
    }
}

int main() {
    Item item = {"Vintage record player", 150.00, {}, 0, AUCTION_DURATION};
    int time_left = AUCTION_DURATION;

    printf("Welcome to the Digital Auction System!\n");
    printf("The auction for %s has started. You have %d seconds to bid.\n\n", item.name, item.time_remaining);

    while (time_left > 0) {
        char input[10];
        float bid;

        display_item(item);
        printf("What would you like to do? (bid/display status/quit)\n");
        fgets(input, 10, stdin);
        strtok(input, "\n");

        if (strcmp(input, "bid") == 0) {
            printf("Enter bid amount: ");
            scanf("%f", &bid);
            make_bid(&item, bid);
            fflush(stdin);
        } else if (strcmp(input, "display status") == 0) {
            display_bids(item);
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }

        time_left--;
        item.time_remaining--;
    }

    printf("Auction has ended for %s.\n\n", item.name);
    display_item(item);

    printf("\nThank you for using the Digital Auction System!\n");
    return 0;
}