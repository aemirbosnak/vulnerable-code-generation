//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define MAX_BIDS 1000
#define MIN_BID_INCREMENT 1

typedef struct {
    char name[50];
    int bid;
} Bidder;

typedef struct {
    char name[50];
    int price;
} Item;

int main() {
    int num_items, num_bidders;
    scanf("%d %d", &num_items, &num_bidders);

    Item items[MAX_ITEMS];
    Bidder bidders[MAX_BIDDERS];
    int num_bids[MAX_BIDDERS] = {0};

    for (int i = 0; i < num_items; i++) {
        scanf("%s %d", items[i].name, &items[i].price);
    }

    for (int i = 0; i < num_bidders; i++) {
        scanf("%s", bidders[i].name);
    }

    srand(time(NULL));
    for (int i = 0; i < num_items; i++) {
        int bidder_index = rand() % num_bidders;
        bidders[bidder_index].bid = items[i].price;
        num_bids[bidder_index]++;
    }

    int max_bid = 0;
    int max_bid_index = 0;

    while (1) {
        for (int i = 0; i < num_items; i++) {
            for (int j = 0; j < num_bidders; j++) {
                if (bidders[j].bid == items[i].price) {
                    printf("%s is the current high bidder for %s with a bid of $%d.\n", bidders[j].name, items[i].name, items[i].price);
                }
            }
        }

        for (int i = 0; i < num_bidders; i++) {
            if (num_bids[i] > max_bid) {
                max_bid = num_bids[i];
                max_bid_index = i;
            }
        }

        if (max_bid == num_items) {
            printf("All items have been sold. The highest bidder is %s with %d bids.\n", bidders[max_bid_index].name, max_bid);
            break;
        }
    }

    return 0;
}