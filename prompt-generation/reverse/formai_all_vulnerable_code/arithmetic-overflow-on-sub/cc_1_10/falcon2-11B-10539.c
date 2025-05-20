//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int item_id;
    char item_name[50];
    int bid_amount;
} Item;

typedef struct {
    char bidder_name[50];
    int bid_amount;
} Bid;

int main() {
    Item items[10];
    Bid bids[10];
    int num_items = 0;
    int num_bids = 0;
    int item_id, bidder_name_len;

    // Load items into memory
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    for (int i = 0; i < num_items; i++) {
        printf("Enter item ID: ");
        scanf("%d", &items[i].item_id);
        printf("Enter item name: ");
        scanf("%s", items[i].item_name);
        printf("Enter initial bid amount: ");
        scanf("%d", &items[i].bid_amount);
    }

    // Load bids into memory
    printf("Enter number of bids: ");
    scanf("%d", &num_bids);
    for (int i = 0; i < num_bids; i++) {
        printf("Enter bidder name: ");
        scanf("%s", bids[i].bidder_name);
        printf("Enter bid amount: ");
        scanf("%d", &bids[i].bid_amount);
    }

    // Display items
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("ID: %d, Name: %s, Bid amount: %d\n", items[i].item_id, items[i].item_name, items[i].bid_amount);
    }

    // Display bids
    printf("Bids:\n");
    for (int i = 0; i < num_bids; i++) {
        printf("Name: %s, Bid amount: %d\n", bids[i].bidder_name, bids[i].bid_amount);
    }

    // Find the highest bid
    int highest_bid = 0;
    for (int i = 0; i < num_bids; i++) {
        if (bids[i].bid_amount > highest_bid) {
            highest_bid = bids[i].bid_amount;
        }
    }

    // Display the winner
    printf("Winner: %s\n", bids[num_bids - 1].bidder_name);

    // Clean up memory
    for (int i = 0; i < num_items; i++) {
        free(items[i].item_name);
    }
    for (int i = 0; i < num_bids; i++) {
        free(bids[i].bidder_name);
    }

    return 0;
}