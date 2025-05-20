//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define MAX_BIDS 100

typedef struct {
    int id;
    char name[50];
    int balance;
} Bidder;

typedef struct {
    int id;
    char name[50];
    int min_bid;
    Bidder *winner;
    int end_time;
} Item;

int main() {
    srand(time(NULL));
    int num_items, num_bidders;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    Bidder bidders[MAX_BIDDERS];
    for (int i = 0; i < num_bidders; i++) {
        bidders[i].id = i + 1;
        bidders[i].balance = rand() % 1000;
        printf("Bidder %d has $%d\n", bidders[i].id, bidders[i].balance);
    }

    Item items[MAX_ITEMS];
    for (int i = 0; i < num_items; i++) {
        items[i].id = i + 1;
        items[i].min_bid = rand() % 1000;
        items[i].winner = NULL;
        items[i].end_time = rand() % 10;
        printf("Item %d has a minimum bid of $%d\n", items[i].id, items[i].min_bid);
    }

    int current_item = 0;
    while (current_item < num_items) {
        printf("Current item: %d\n", items[current_item].id);
        for (int i = 0; i < num_bidders; i++) {
            printf("Bidder %d has $%d\n", bidders[i].id, bidders[i].balance);
        }
        int bid_amount;
        printf("Enter your bid amount: ");
        scanf("%d", &bid_amount);
        if (bid_amount >= items[current_item].min_bid) {
            items[current_item].winner = &bidders[0];
            for (int i = 1; i < num_bidders; i++) {
                if (bidders[i].balance > bidders[0].balance) {
                    items[current_item].winner = &bidders[i];
                }
            }
            printf("You have the highest bid of $%d\n", bid_amount);
        } else {
            printf("Your bid is too low.\n");
        }
        current_item++;
        sleep(1);
    }

    return 0;
}