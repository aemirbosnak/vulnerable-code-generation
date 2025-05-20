//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 100
#define MAX_BIDS 100
#define MAX_AMOUNT 100000

typedef struct {
    char name[100];
    char item[100];
    int amount;
} bidder;

typedef struct {
    char name[100];
    char item[100];
    int amount;
} bid;

typedef struct {
    char name[100];
    char item[100];
    int amount;
    int winner;
} item;

int main() {
    srand(time(0)); // initialize random seed
    int num_bidders = 0;
    int num_items = 0;
    int num_bids = 0;
    int num_auctions = 0;
    int amount = 0;

    item items[MAX_ITEMS]; // array to store item information
    bidder bidders[MAX_BIDDERS]; // array to store bidder information
    bid bids[MAX_BIDS]; // array to store bid information

    printf("Welcome to the Paranoid Digital Auction System!\n");
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    for (int i = 0; i < num_bidders; i++) {
        printf("Enter bidder name: ");
        fgets(bidders[i].name, 100, stdin);
        printf("Enter bidder item: ");
        fgets(bidders[i].item, 100, stdin);
        printf("Enter bidder amount: ");
        scanf("%d", &bidders[i].amount);
    }

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        printf("Enter item name: ");
        fgets(items[i].name, 100, stdin);
        printf("Enter item amount: ");
        scanf("%d", &items[i].amount);
    }

    printf("Enter the number of bids: ");
    scanf("%d", &num_bids);

    for (int i = 0; i < num_bids; i++) {
        printf("Enter bidder name: ");
        fgets(bids[i].name, 100, stdin);
        printf("Enter bid item: ");
        fgets(bids[i].item, 100, stdin);
        printf("Enter bid amount: ");
        scanf("%d", &bids[i].amount);
    }

    printf("Enter the number of auctions: ");
    scanf("%d", &num_auctions);

    for (int i = 0; i < num_auctions; i++) {
        int highest_bid = 0;
        int winner = 0;

        for (int j = 0; j < num_bidders; j++) {
            for (int k = 0; k < num_bids; k++) {
                if (bids[k].amount > highest_bid) {
                    highest_bid = bids[k].amount;
                    winner = k;
                }
            }
        }

        items[i].amount = highest_bid;
        items[i].winner = winner;
    }

    for (int i = 0; i < num_items; i++) {
        printf("Item %d: %s - Amount: %d\n", i + 1, items[i].name, items[i].amount);
    }

    return 0;
}