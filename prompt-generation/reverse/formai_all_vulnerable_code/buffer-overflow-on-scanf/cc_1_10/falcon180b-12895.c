//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define MAX_ITEM_NAME_LENGTH 50

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int starting_price;
    int highest_bid;
    int highest_bidder;
} Item;

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int budget;
    int bid_history[MAX_ITEMS];
} Bidder;

int main() {
    int num_items, num_bidders;
    Item items[MAX_ITEMS];
    Bidder bidders[MAX_BIDDERS];

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    for (int i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter the starting price of item %s: ", items[i].name);
        scanf("%d", &items[i].starting_price);
    }

    for (int i = 0; i < num_bidders; i++) {
        printf("Enter the name of bidder %d: ", i+1);
        scanf("%s", bidders[i].name);
        printf("Enter the budget of bidder %s: ", bidders[i].name);
        scanf("%d", &bidders[i].budget);
    }

    int highest_bid[MAX_ITEMS];
    for (int i = 0; i < num_items; i++) {
        highest_bid[i] = items[i].starting_price;
    }

    int bid_index[MAX_ITEMS];
    for (int i = 0; i < num_items; i++) {
        bid_index[i] = 0;
    }

    int current_bidder = 0;
    int highest_bidder_index = 0;

    while (current_bidder < num_bidders) {
        printf("Bidder %s has %d budget remaining.\n", bidders[current_bidder].name, bidders[current_bidder].budget);

        for (int i = 0; i < num_items; i++) {
            if (highest_bid[i] <= bidders[current_bidder].budget) {
                printf("Item %s current highest bid is %d.\n", items[i].name, highest_bid[i]);
                printf("Enter your bid for item %s: ", items[i].name);
                scanf("%d", &bidders[current_bidder].bid_history[i]);

                if (bidders[current_bidder].bid_history[i] > highest_bid[i]) {
                    highest_bid[i] = bidders[current_bidder].bid_history[i];
                    items[i].highest_bid = highest_bid[i];
                    items[i].highest_bidder = current_bidder;
                }
            }
        }

        current_bidder++;
    }

    printf("Auction ended.\n");

    for (int i = 0; i < num_items; i++) {
        printf("Item %s sold to bidder %s for %d.\n", items[i].name, bidders[items[i].highest_bidder].name, items[i].highest_bid);
    }

    return 0;
}