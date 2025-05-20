//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char title[256];
    char description[256];
    int starting_bid;
    int reserve_price;
    time_t end_time;
    struct Auction* next;
} Auction;

Auction* create_auction(char* title, char* description, int starting_bid, int reserve_price, time_t end_time) {
    Auction* new_auction = malloc(sizeof(Auction));
    strcpy(new_auction->title, title);
    strcpy(new_auction->description, description);
    new_auction->starting_bid = starting_bid;
    new_auction->reserve_price = reserve_price;
    new_auction->end_time = end_time;
    new_auction->next = NULL;

    return new_auction;
}

void print_auctions(Auction* auctions) {
    while (auctions) {
        printf("Title: %s\n", auctions->title);
        printf("Description: %s\n", auctions->description);
        printf("Starting Bid: %d\n", auctions->starting_bid);
        printf("Reserve Price: %d\n", auctions->reserve_price);
        printf("End Time: %s\n", asctime(localtime(&auctions->end_time)));
        printf("\n");
        auctions = auctions->next;
    }
}

int main() {
    Auction* auctions = NULL;

    auctions = create_auction("Rare Painting", "A beautiful painting by Leonardo da Vinci.", 10000, 15000, time(NULL) + 60*60*24);
    auctions = create_auction("Antique Clock", "A vintage clock from the 18th century.", 5000, 8000, time(NULL) + 60*60*48);
    auctions = create_auction("Designer Watch", "A stylish watch by Patek Philippe.", 20000, 22000, time(NULL) + 60*60*12);

    print_auctions(auctions);

    return 0;
}