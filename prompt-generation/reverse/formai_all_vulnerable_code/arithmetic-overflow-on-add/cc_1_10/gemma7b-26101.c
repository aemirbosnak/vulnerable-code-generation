//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char name[20];
    int start_price;
    int current_price;
    int num_bids;
    time_t end_time;
} Auction;

Auction auctions[MAX_AUCTIONS];

void initialize_auctions() {
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        auctions[i].name[0] = '\0';
        auctions[i].start_price = 0;
        auctions[i].current_price = 0;
        auctions[i].num_bids = 0;
        auctions[i].end_time = 0;
    }
}

void add_auction(char *name, int start_price, time_t end_time) {
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        if (auctions[i].name[0] == '\0') {
            strcpy(auctions[i].name, name);
            auctions[i].start_price = start_price;
            auctions[i].current_price = start_price;
            auctions[i].num_bids = 0;
            auctions[i].end_time = end_time;
            return;
        }
    }

    printf("Error: No more auctions can be added.\n");
}

void bid_on_auction(char *name, int bid) {
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        if (strcmp(auctions[i].name, name) == 0) {
            if (bid > auctions[i].current_price) {
                auctions[i].current_price = bid;
                auctions[i].num_bids++;
                printf("Thank you for your bid of %d on %s.\n", bid, auctions[i].name);
            } else {
                printf("Error: Your bid is not higher than the current price.\n");
            }
            return;
        }
    }

    printf("Error: No auction found with that name.\n");
}

int main() {
    initialize_auctions();

    add_auction("Car", 10000, time(NULL) + 60 * 60 * 24);
    add_auction("House", 20000, time(NULL) + 60 * 60 * 24);
    add_auction("Laptop", 5000, time(NULL) + 60 * 60 * 24);

    bid_on_auction("Car", 12000);
    bid_on_auction("House", 22000);
    bid_on_auction("Laptop", 6000);

    return 0;
}