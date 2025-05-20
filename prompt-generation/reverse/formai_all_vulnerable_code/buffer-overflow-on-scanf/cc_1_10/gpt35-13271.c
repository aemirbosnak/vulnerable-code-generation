//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_BIDS 10
#define MAX_NAME_LEN 50

typedef struct {
    char bidder_name[MAX_NAME_LEN];
    float bid_amount;
} Bid;

typedef struct {
    char item_name[MAX_NAME_LEN];
    float starting_price;
    Bid bids[MAX_BIDS];
    int num_bids;
} AuctionItem;

int main() {
    AuctionItem item;
    int i, num_items;
    float highest_bid;
    char exit_key;

    printf("Enter the number of auction items: ");
    scanf("%d", &num_items);
    fflush(stdin);

    for (i = 0; i < num_items; i++) {
        printf("\nEnter the details of item %d:\n", i+1);

        printf("Name: ");
        fgets(item.item_name, MAX_NAME_LEN, stdin);

        printf("Starting price: ");
        scanf("%f", &item.starting_price);
        fflush(stdin);

        item.num_bids = 0;
        highest_bid = item.starting_price;

        do {
            Bid new_bid;

            printf("\nEnter a bid for %s (or 'q' to quit): ", item.item_name);
            exit_key = getchar();

            if (exit_key == 'q') {
                break;
            }

            printf("Bidder name: ");
            fgets(new_bid.bidder_name, MAX_NAME_LEN, stdin);

            printf("Bid amount: ");
            scanf("%f", &new_bid.bid_amount);
            fflush(stdin);

            if (new_bid.bid_amount > highest_bid) {
                item.bids[item.num_bids] = new_bid;
                item.num_bids++;
                highest_bid = new_bid.bid_amount;
                printf("Bid accepted!\n");
            } else {
                printf("Bid must be greater than the current highest bid of %.2f\n", highest_bid);
            }

        } while (item.num_bids < MAX_BIDS);

        printf("Auction for %s ended with %d bids.\n", item.item_name, item.num_bids);
        printf("The highest bid was %.2f\n", highest_bid);

        for (i = 0; i < item.num_bids; i++) {
            printf("%s bid %.2f\n", item.bids[i].bidder_name, item.bids[i].bid_amount);
        }
    }

    return 0;
}