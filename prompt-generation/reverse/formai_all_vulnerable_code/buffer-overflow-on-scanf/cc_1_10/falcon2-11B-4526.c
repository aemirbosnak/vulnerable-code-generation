//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct bid {
    int price;
    int bidder_id;
} bid_t;

typedef struct item {
    int price;
    int seller_id;
} item_t;

int main() {
    int num_items, num_bidders, bid_price, bidder_id;
    bid_t *bids;
    item_t *items;

    srand(time(NULL));

    printf("Enter the number of items:\n");
    scanf("%d", &num_items);

    printf("Enter the number of bidders:\n");
    scanf("%d", &num_bidders);

    bids = (bid_t *)malloc(num_items * sizeof(bid_t));
    items = (item_t *)malloc(num_items * sizeof(item_t));

    for(int i = 0; i < num_items; i++) {
        items[i].price = rand() % 1000;
        items[i].seller_id = i;
    }

    for(int i = 0; i < num_bidders; i++) {
        printf("Bidder %d, enter your bid price:\n", i+1);
        scanf("%d", &bid_price);

        for(int j = 0; j < num_items; j++) {
            if(items[j].price == bid_price) {
                bids[j].price = bid_price;
                bids[j].bidder_id = i;
                break;
            }
        }
    }

    for(int i = 0; i < num_items; i++) {
        if(bids[i].bidder_id!= -1) {
            printf("Item %d has been sold to bidder %d for %d\n", i+1, bids[i].bidder_id+1, bids[i].price);
        }
    }

    free(bids);
    free(items);

    return 0;
}