//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void bid_on_auction(char *name, int bid_amount) {
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        if (strcmp(auctions[i].name, name) == 0) {
            if (bid_amount > auctions[i].current_price) {
                auctions[i].current_price = bid_amount;
                auctions[i].num_bids++;
                printf("Your bid of %d has been accepted.\n", bid_amount);
            } else {
                printf("Your bid of %d is not higher than the current price.\n", bid_amount);
            }
            return;
        }
    }

    printf("Error: Auction not found.\n");
}

void print_auctions() {
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        if (auctions[i].name[0] != '\0') {
            printf("Name: %s\n", auctions[i].name);
            printf("Start Price: %d\n", auctions[i].start_price);
            printf("Current Price: %d\n", auctions[i].current_price);
            printf("Number of Bids: %d\n", auctions[i].num_bids);
            printf("End Time: %s\n", auctions[i].end_time);
            printf("\n");
        }
    }
}

int main() {
    initialize_auctions();

    add_auction("Laptop", 500, time(NULL) + 60 * 60);
    add_auction("Smartphone", 300, time(NULL) + 60 * 30);
    add_auction("Watch", 200, time(NULL) + 60 * 15);

    bid_on_auction("Laptop", 600);
    bid_on_auction("Smartphone", 400);
    bid_on_auction("Watch", 250);

    print_auctions();

    return 0;
}