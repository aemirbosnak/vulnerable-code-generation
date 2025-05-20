//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int price;
    int quantity;
    int time_remaining;
} item;

typedef struct {
    char name[50];
    int max_bid;
    int quantity;
    int time_remaining;
} auction;

int main() {
    int num_items = 5;
    int num_bidders = 3;
    int num_auctions = 2;

    item items[num_items];
    auction auctions[num_auctions];

    for (int i = 0; i < num_items; i++) {
        srand(time(NULL));
        items[i].price = rand() % 100 + 1;
        items[i].quantity = rand() % 100 + 1;
        items[i].time_remaining = 60 * rand() % 1200 + 1;
        strcpy(items[i].name, "Item ");
        sprintf(items[i].name + 6, "%d", i + 1);
    }

    for (int i = 0; i < num_auctions; i++) {
        auctions[i].max_bid = 0;
        auctions[i].quantity = rand() % 100 + 1;
        auctions[i].time_remaining = 60 * rand() % 1200 + 1;
        strcpy(auctions[i].name, "Auction ");
        sprintf(auctions[i].name + 6, "%d", i + 1);
    }

    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - Price: %d, Quantity: %d, Time remaining: %d\n", items[i].name, items[i].price, items[i].quantity, items[i].time_remaining);
    }

    printf("\nAuction:\n");
    for (int i = 0; i < num_auctions; i++) {
        printf("%s - Max bid: %d, Quantity: %d, Time remaining: %d\n", auctions[i].name, auctions[i].max_bid, auctions[i].quantity, auctions[i].time_remaining);
    }

    return 0;
}