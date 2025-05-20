//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Item {
    int item_id;
    char item_name[100];
    float item_price;
};

typedef struct {
    char buyer_name[100];
    float bidding_price;
    time_t bid_time;
} Bidder;

struct Auction {
    int auction_id;
    struct Item item;
    Bidder *highest_bidder;
    Bidder *bidders_list;
    int bidders_count;
    time_t start_time;
    time_t end_time;
};

struct Auction create_auction(int id, char* name, float price, time_t start_time, time_t end_time) {
    struct Auction auction;
    auction.auction_id = id;
    
    auction.item.item_id = id;
    strncpy(auction.item.item_name, name, 100);
    auction.item.item_price = price;

    auction.bidders_count = 0;
    auction.highest_bidder = NULL;
    auction.bidders_list = NULL;

    auction.start_time = start_time;
    auction.end_time = end_time;

    return auction;
}

void add_bidder(struct Auction *auction, Bidder bidder) {
    auction->bidders_count++;
    auction->bidders_list = realloc(auction->bidders_list, sizeof(Bidder) * auction->bidders_count);
    auction->bidders_list[auction->bidders_count - 1] = bidder;
}

Bidder *find_highest_bidder(struct Auction *auction) {
    Bidder *highest_bidder = NULL;
    for(int i = 0; i < auction->bidders_count; i++) {
        Bidder bidder = auction->bidders_list[i];
        if(bidder.bidding_price > auction->item.item_price) {
            if(highest_bidder == NULL || bidder.bidding_price > highest_bidder->bidding_price) {
                highest_bidder = &auction->bidders_list[i];
            }
        }
    }
    return highest_bidder;
}

void place_bid(struct Auction *auction, char* name, float price) {
    Bidder bidder;
    strncpy(bidder.buyer_name, name, 100);
    bidder.bidding_price = price;
    bidder.bid_time = time(NULL);

    add_bidder(auction, bidder);

    Bidder *highest_bidder = find_highest_bidder(auction);
    if(highest_bidder != NULL) {
        auction->highest_bidder = highest_bidder;
        auction->item.item_price = highest_bidder->bidding_price;
    }
}

void print_winner(struct Auction *auction) {
    if(auction->highest_bidder == NULL) {
        printf("Auction %d has no bidders.\n", auction->auction_id);
    } else {
        printf("%s won the auction of %s for $%.2f\n", auction->highest_bidder->buyer_name, auction->item.item_name, auction->item.item_price);
    }
}

void print_auction(struct Auction *auction) {
    printf("Auction %d:\n", auction->auction_id);
    printf("\tItem: %s, starting price: $%.2f\n", auction->item.item_name, auction->item.item_price);
    printf("\tBidders:\n");
    for(int i = 0; i < auction->bidders_count; i++) {
        Bidder bidder = auction->bidders_list[i];
        printf("\t\t%s - $%.2f - %s", bidder.buyer_name, bidder.bidding_price, ctime(&bidder.bid_time));
    }
}

int main() {

    // create auctions
    struct Auction auction1 = create_auction(1, "Vintage Watch", 100.0, time(NULL), time(NULL) + 3600);
    struct Auction auction2 = create_auction(2, "Signed Jersey", 300.0, time(NULL), time(NULL) + 7200);

    // place bids
    place_bid(&auction1, "Alice", 120.0);
    place_bid(&auction1, "Bob", 110.0);
    place_bid(&auction2, "Charlie", 400.0);
    place_bid(&auction1, "Eve", 125.0);
    place_bid(&auction2, "Bob", 350.0);

    // print winners
    print_winner(&auction1);
    print_winner(&auction2);

    // print auctions
    print_auction(&auction1);
    print_auction(&auction2);

    return 0;
}