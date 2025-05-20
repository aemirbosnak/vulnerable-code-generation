//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100

struct item {
    char name[50];
    int value;
};

struct bidder {
    char name[50];
    int bid;
};

void generate_random_item(struct item *item) {
    srand(time(0));
    item->value = rand() % 1000;
    sprintf(item->name, "Item %d", item->value);
}

int main() {
    struct item items[MAX_ITEMS];
    struct bidder bidders[MAX_BIDDERS];
    int num_items, num_bidders;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    for (int i = 0; i < num_items; i++) {
        generate_random_item(&items[i]);
    }

    for (int i = 0; i < num_bidders; i++) {
        printf("Enter the name of bidder %d: ", i + 1);
        scanf("%s", bidders[i].name);
        bidders[i].bid = 0;
    }

    int max_bid = 0;
    int max_bidder_index = -1;

    for (int i = 0; i < num_items; i++) {
        printf("Auction for item '%s' starting...\n", items[i].name);
        for (int j = 0; j < num_bidders; j++) {
            if (bidders[j].bid > max_bid) {
                max_bid = bidders[j].bid;
                max_bidder_index = j;
            }
        }
        printf("Item '%s' sold to bidder '%s' for $%d!\n", items[i].name, bidders[max_bidder_index].name, max_bid);
    }

    return 0;
}