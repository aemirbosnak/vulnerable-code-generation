//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 1000
#define MAX_BIDS 1000

typedef struct {
    char name[50];
    int bid;
} bidder;

typedef struct {
    char name[50];
    int start_price;
    int current_price;
    bidder highest_bidder;
} item;

int main() {
    int num_items, num_bidders;
    bidder bidders[MAX_BIDDERS];
    item items[MAX_ITEMS];

    printf("Enter the number of items to auction: ");
    scanf("%d", &num_items);

    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    for (int i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter the starting price of item %s: ", items[i].name);
        scanf("%d", &items[i].start_price);
        items[i].current_price = items[i].start_price;
        items[i].highest_bidder.bid = 0;
    }

    for (int i = 0; i < num_bidders; i++) {
        printf("Enter the name of bidder %d: ", i+1);
        scanf("%s", bidders[i].name);
    }

    int bid_count = 0;
    while (bid_count < num_items) {
        for (int i = 0; i < num_bidders; i++) {
            printf("Bid for item %s by bidder %s: ", items[bid_count].name, bidders[i].name);
            scanf("%d", &bidders[i].bid);
            if (bidders[i].bid > items[bid_count].current_price) {
                items[bid_count].current_price = bidders[i].bid;
                items[bid_count].highest_bidder = bidders[i];
            }
        }
        bid_count++;
    }

    printf("Auction results:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %s sold for $%d to bidder %s\n", items[i].name, items[i].current_price, items[i].highest_bidder.name);
    }

    return 0;
}