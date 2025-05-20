//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: systematic
// Auction.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int bid;
    char name[100];
} Bidder;

int main() {
    int n_bidders;
    scanf("%d", &n_bidders);

    Bidder* bidders = malloc(n_bidders * sizeof(Bidder));
    for (int i = 0; i < n_bidders; i++) {
        scanf("%d %s", &bidders[i].id, bidders[i].name);
    }

    int n_items;
    scanf("%d", &n_items);

    char* items = malloc(n_items * sizeof(char));
    for (int i = 0; i < n_items; i++) {
        scanf("%s", items[i]);
    }

    int* bids = malloc(n_bidders * sizeof(int));
    for (int i = 0; i < n_bidders; i++) {
        scanf("%d", &bids[i]);
    }

    int* item_ids = malloc(n_items * sizeof(int));
    for (int i = 0; i < n_items; i++) {
        scanf("%d", &item_ids[i]);
    }

    int* bids_per_item = malloc(n_items * sizeof(int));
    for (int i = 0; i < n_items; i++) {
        bids_per_item[i] = 0;
    }

    int highest_bid = 0;
    int winner = -1;
    for (int i = 0; i < n_bidders; i++) {
        for (int j = 0; j < n_items; j++) {
            if (bidders[i].id == item_ids[j]) {
                bids_per_item[j] += bids[i];
                if (bids_per_item[j] > highest_bid) {
                    highest_bid = bids_per_item[j];
                    winner = i;
                }
            }
        }
    }

    printf("Winner: %s\n", bidders[winner].name);

    return 0;
}