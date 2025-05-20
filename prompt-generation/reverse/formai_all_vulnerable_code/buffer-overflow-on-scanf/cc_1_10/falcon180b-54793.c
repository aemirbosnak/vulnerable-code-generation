//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITEMS 100

struct item {
    int id;
    double price;
    int bidder_id;
};

int main() {
    int n_items, n_bidders;
    struct item items[MAX_ITEMS];
    int bids[MAX_ITEMS];
    double min_bid[MAX_ITEMS];
    int bidder_ids[MAX_ITEMS];
    int n_bids;
    int i, j, k, l;

    printf("Enter the number of items: ");
    scanf("%d", &n_items);

    printf("Enter the number of bidders: ");
    scanf("%d", &n_bidders);

    printf("Enter the items:\n");
    for (i = 0; i < n_items; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %lf", &items[i].id, &items[i].price);
    }

    printf("Enter the bids:\n");
    for (i = 0; i < n_items; i++) {
        n_bids = 0;
        bids[i] = 0;
        min_bid[i] = items[i].price;
        while (n_bids < n_bidders) {
            printf("Bid for item %d from bidder %d: ", i+1, n_bids+1);
            scanf("%d", &bids[i]);
            if (bids[i] >= min_bid[i]) {
                bidder_ids[i] = n_bids;
                min_bid[i] = bids[i];
                n_bids++;
            }
        }
    }

    printf("The results of the auction:\n");
    for (i = 0; i < n_items; i++) {
        printf("Item %d was sold to bidder %d for $%.2lf\n", items[i].id, bidder_ids[i], min_bid[i]);
    }

    return 0;
}