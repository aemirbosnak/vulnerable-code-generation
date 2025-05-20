//FormAI DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_AUCTIONS 5

typedef struct {
    char name[50];
    int bid_amount;
} Bidder;

typedef struct {
    char item_name[50];
    int starting_price;
    Bidder bidders[MAX_BIDDERS];
    int num_bidders;
} Auction;

void display_auction_list(Auction *auctions, int num_auctions);
void add_bidder(Auction *auction, Bidder bidder);
void display_bidder_list(Auction auction);
int get_highest_bid(Auction auction);

int main() {

    Auction auctions[MAX_AUCTIONS] = {
        {"iPhone X", 1000},
        {"Samsung Galaxy S9", 900},
        {"Google Pixel 3", 800},
        {"Sony PlayStation 4", 500},
        {"Nintendo Switch", 300}
    };
    int num_auctions = 5;

    while(1) {
        printf("Welcome to the Digital Auction System!\n");
        printf("What would you like to do?\n");
        printf("1. View auctions\n");
        printf("2. Add bidder to auction\n");
        printf("3. View bidders of auction\n");
        printf("4. Get highest bid of auction\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_auction_list(auctions, num_auctions);
                break;
            case 2:
                printf("Which auction would you like to add a bidder to?\n");
                display_auction_list(auctions, num_auctions);
                int auction_choice;
                scanf("%d", &auction_choice);
                if(auction_choice < 1 || auction_choice > num_auctions) {
                    printf("Invalid choice.\n");
                } else {
                    int starting_price = auctions[auction_choice-1].starting_price;
                    printf("What is your name?\n");
                    char name[50];
                    scanf("%s", name);
                    printf("What is your bid? (starting price: $%d)\n", starting_price);
                    int bid_amount;
                    scanf("%d", &bid_amount);
                    if(bid_amount < starting_price) {
                        printf("Your bid is lower than the starting price.\n");
                    } else {
                        Bidder bidder = {name, bid_amount};
                        add_bidder(&auctions[auction_choice-1], bidder);
                        printf("Bid added successfully.\n");
                    }
                }
                break;
            case 3:
                printf("Which auction would you like to view bidders of?\n");
                display_auction_list(auctions, num_auctions);
                scanf("%d", &auction_choice);
                display_bidder_list(auctions[auction_choice-1]);
                break;
            case 4:
                printf("Which auction would you like to get the highest bid of?\n");
                display_auction_list(auctions, num_auctions);
                scanf("%d", &auction_choice);
                int highest_bid = get_highest_bid(auctions[auction_choice-1]);
                printf("The highest bid is $%d.\n", highest_bid);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}

void display_auction_list(Auction *auctions, int num_auctions) {
    printf("\n");
    for(int i=0; i<num_auctions; i++) {
        printf("%d. %s (starting price: $%d)\n", i+1, auctions[i].item_name, auctions[i].starting_price);
    }
}

void add_bidder(Auction *auction, Bidder bidder) {
    if(auction->num_bidders < MAX_BIDDERS) {
        auction->bidders[auction->num_bidders] = bidder;
        auction->num_bidders++;
    }
}

void display_bidder_list(Auction auction) {
    printf("\n");
    for(int i=0; i<auction.num_bidders; i++) {
        printf("%s: $%d\n", auction.bidders[i].name, auction.bidders[i].bid_amount);
    }
}

int get_highest_bid(Auction auction) {
    int highest_bid = auction.starting_price;
    for(int i=0; i<auction.num_bidders; i++) {
        if(auction.bidders[i].bid_amount > highest_bid) {
            highest_bid = auction.bidders[i].bid_amount;
        }
    }
    return highest_bid;
}