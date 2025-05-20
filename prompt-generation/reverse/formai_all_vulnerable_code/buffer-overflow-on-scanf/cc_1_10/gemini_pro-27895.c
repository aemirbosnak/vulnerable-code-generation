//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double price;
} Item;

typedef struct {
    char *name;
    double bid;
} Bid;

int main() {
    int num_items, num_bids;
    scanf("%d %d", &num_items, &num_bids);

    Item *items = malloc(sizeof(Item) * num_items);
    for (int i = 0; i < num_items; i++) {
        char *name = malloc(100);
        double price;
        scanf(" %s %lf", name, &price);
        items[i].name = name;
        items[i].price = price;
    }

    Bid *bids = malloc(sizeof(Bid) * num_bids);
    for (int i = 0; i < num_bids; i++) {
        char *name = malloc(100);
        double bid;
        scanf(" %s %lf", name, &bid);
        bids[i].name = name;
        bids[i].bid = bid;
    }

    for (int i = 0; i < num_items; i++) {
        double max_bid = -1;
        char *winner = NULL;
        for (int j = 0; j < num_bids; j++) {
            if (strcmp(items[i].name, bids[j].name) == 0 && bids[j].bid > max_bid) {
                max_bid = bids[j].bid;
                winner = bids[j].name;
            }
        }

        if (max_bid > items[i].price) {
            printf("%s sold to %s for $%.2lf\n", items[i].name, winner, max_bid);
        } else {
            printf("%s reserve not met\n", items[i].name);
        }
    }

    for (int i = 0; i < num_items; i++) {
        free(items[i].name);
    }
    free(items);

    for (int i = 0; i < num_bids; i++) {
        free(bids[i].name);
    }
    free(bids);

    return 0;
}