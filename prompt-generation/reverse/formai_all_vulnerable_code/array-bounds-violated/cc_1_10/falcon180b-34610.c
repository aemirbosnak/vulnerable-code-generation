//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define MAX_BIDS 100

typedef struct {
    char name[50];
    int id;
    int highest_bid;
    int bid_count;
} Bidder;

typedef struct {
    char name[100];
    int id;
    int starting_price;
    int current_price;
    int bid_count;
    int highest_bidder_id;
} Item;

int main() {
    srand(time(NULL));

    int num_items, num_bidders;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    Bidder bidders[num_bidders];
    for (int i = 0; i < num_bidders; i++) {
        bidders[i].id = i + 1;
        printf("Enter bidder %d's name: ", bidders[i].id);
        scanf("%s", bidders[i].name);
    }

    Item items[num_items];
    for (int i = 0; i < num_items; i++) {
        items[i].id = i + 1;
        printf("Enter item %d's name: ", items[i].id);
        scanf("%s", items[i].name);
        printf("Enter starting price: ");
        scanf("%d", &items[i].starting_price);
        items[i].current_price = items[i].starting_price;
        items[i].highest_bidder_id = 0;
    }

    int bid_count = 0;
    while (bid_count < MAX_BIDS) {
        int item_index = rand() % num_items;
        int bidder_index = rand() % num_bidders;

        if (items[item_index].current_price > bidders[bidder_index].highest_bid) {
            items[item_index].current_price = bidders[bidder_index].highest_bid + 1;
            items[item_index].highest_bidder_id = bidder_index;
        }

        bid_count++;
    }

    printf("\nAuction results:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: %s\n", items[i].id, items[i].name);
        printf("Highest bid: $%d by bidder %d\n", items[i].current_price, items[i].highest_bidder_id);
    }

    return 0;
}