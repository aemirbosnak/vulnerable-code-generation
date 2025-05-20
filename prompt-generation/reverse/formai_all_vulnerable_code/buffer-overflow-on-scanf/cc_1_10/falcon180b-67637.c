//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100

typedef struct {
    char name[50];
    int id;
} bidder;

typedef struct {
    char name[100];
    int id;
    int price;
} item;

int main() {
    srand(time(0));

    bidder bidders[MAX_BIDDERS];
    item items[MAX_ITEMS];

    int num_bidders = 0, num_items = 0;

    while (num_bidders < MAX_BIDDERS) {
        printf("Enter bidder name: ");
        scanf("%s", bidders[num_bidders].name);
        bidders[num_bidders].id = rand() % 1000;
        num_bidders++;
    }

    while (num_items < MAX_ITEMS) {
        printf("Enter item name: ");
        scanf("%s", items[num_items].name);
        items[num_items].id = rand() % 1000;
        items[num_items].price = rand() % 1000;
        num_items++;
    }

    int max_bid = 0, max_bidder_id = 0;

    for (int i = 0; i < num_items; i++) {
        printf("Item %d: %s - Current bid: $%d\n", items[i].id, items[i].name, items[i].price);

        for (int j = 0; j < num_bidders; j++) {
            if (items[i].price > max_bid) {
                max_bid = items[i].price;
                max_bidder_id = bidders[j].id;
            }
        }

        printf("Highest bid by bidder %d: $%d\n\n", max_bidder_id, max_bid);
    }

    return 0;
}