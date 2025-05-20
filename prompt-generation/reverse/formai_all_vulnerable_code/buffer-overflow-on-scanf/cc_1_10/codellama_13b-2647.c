//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 10
#define MAX_BID_AMOUNT 100

struct bidder {
    char name[20];
    int bid_amount;
};

struct item {
    char name[20];
    int starting_price;
    int current_price;
    int number_of_bids;
    struct bidder highest_bidder;
};

int main() {
    struct item items[MAX_ITEMS];
    struct bidder bidders[MAX_BIDDERS];

    int i, j;
    int number_of_items;
    int number_of_bidders;
    int bid_amount;
    char item_name[20];
    char bidder_name[20];

    printf("Welcome to the Digital Auction System!\n");
    printf("Please enter the number of items: ");
    scanf("%d", &number_of_items);

    for (i = 0; i < number_of_items; i++) {
        printf("Enter item name: ");
        scanf("%s", item_name);
        strcpy(items[i].name, item_name);
        printf("Enter starting price: ");
        scanf("%d", &items[i].starting_price);
        items[i].current_price = items[i].starting_price;
        items[i].number_of_bids = 0;
    }

    printf("Please enter the number of bidders: ");
    scanf("%d", &number_of_bidders);

    for (i = 0; i < number_of_bidders; i++) {
        printf("Enter bidder name: ");
        scanf("%s", bidder_name);
        strcpy(bidders[i].name, bidder_name);
        bidders[i].bid_amount = 0;
    }

    for (i = 0; i < number_of_items; i++) {
        printf("Item: %s\n", items[i].name);
        printf("Starting price: %d\n", items[i].starting_price);
        printf("Current price: %d\n", items[i].current_price);
        printf("Number of bids: %d\n", items[i].number_of_bids);
        printf("Highest bidder: %s\n", items[i].highest_bidder.name);
        printf("Bid amount: %d\n", items[i].highest_bidder.bid_amount);
        printf("\n");
    }

    for (i = 0; i < number_of_bidders; i++) {
        printf("Bidder: %s\n", bidders[i].name);
        printf("Bid amount: %d\n", bidders[i].bid_amount);
        printf("\n");
    }

    for (i = 0; i < number_of_items; i++) {
        for (j = 0; j < number_of_bidders; j++) {
            printf("Enter bid amount for bidder %s on item %s: ", bidders[j].name, items[i].name);
            scanf("%d", &bid_amount);
            if (bid_amount > items[i].current_price) {
                items[i].current_price = bid_amount;
                items[i].number_of_bids++;
                strcpy(items[i].highest_bidder.name, bidders[j].name);
                items[i].highest_bidder.bid_amount = bid_amount;
            }
        }
    }

    for (i = 0; i < number_of_items; i++) {
        printf("Item: %s\n", items[i].name);
        printf("Starting price: %d\n", items[i].starting_price);
        printf("Current price: %d\n", items[i].current_price);
        printf("Number of bids: %d\n", items[i].number_of_bids);
        printf("Highest bidder: %s\n", items[i].highest_bidder.name);
        printf("Bid amount: %d\n", items[i].highest_bidder.bid_amount);
        printf("\n");
    }

    return 0;
}