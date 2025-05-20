//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 50
#define MAX_BIDS 100
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_BIDDER_NAME_LENGTH 50

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int price;
    int bidder_id;
    time_t end_time;
} item_t;

typedef struct {
    char name[MAX_BIDDER_NAME_LENGTH];
    int id;
} bidder_t;

int main() {
    int num_items, num_bidders;
    item_t items[MAX_ITEMS];
    bidder_t bidders[MAX_BIDDERS];
    int i, j, k;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter item %d name: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter item %d price: ", i + 1);
        scanf("%d", &items[i].price);
        printf("Enter item %d end time (yyyy-mm-dd hh:mm:ss): ", i + 1);
        scanf("%s", items[i].end_time);
        items[i].bidder_id = -1;
    }

    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    for (i = 0; i < num_bidders; i++) {
        printf("Enter bidder %d name: ", i + 1);
        scanf("%s", bidders[i].name);
        bidders[i].id = i + 1;
    }

    for (i = 0; i < num_items; i++) {
        printf("Item %d is now being auctioned.\n", i + 1);
        for (j = 0; j < num_bidders; j++) {
            printf("Bidder %d placed a bid of $%d.\n", j + 1, items[i].price);
        }
        for (j = 0; j < num_bidders; j++) {
            if (bidders[j].id == items[i].bidder_id) {
                printf("Bidder %d has won item %d for $%d.\n", j + 1, i + 1, items[i].price);
            } else {
                printf("Bidder %d has been outbid on item %d.\n", j + 1, i + 1);
            }
        }
    }

    return 0;
}