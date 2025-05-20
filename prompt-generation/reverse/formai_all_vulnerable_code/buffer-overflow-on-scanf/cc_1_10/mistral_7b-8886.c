//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 10
#define MIN_BID_INCREMENT 10
#define AUCTION_DURATION 60

typedef struct {
    int id;
    char name[50];
    int current_bid;
    int time_left;
} Item;

void init_item(Item* item, int id, char* name, int initial_bid) {
    item->id = id;
    strcpy(item->name, name);
    item->current_bid = initial_bid;
    item->time_left = AUCTION_DURATION;
}

void print_item(Item item) {
    printf("%d: %s - Current Bid: %d - Time Left: %d\n", item.id, item.name, item.current_bid, item.time_left);
}

int compare_time(const void* a, const void* b) {
    return ((Item*)a)->time_left > ((Item*)b)->time_left ? -1 : 1;
}

int main() {
    srand(time(NULL));

    Item items[MAX_ITEMS];

    for (int i = 0; i < MAX_ITEMS; ++i) {
        char name[50];
        printf("Enter name for item %d: ", i + 1);
        scanf("%s", name);
        int initial_bid = rand() % 50 + 50;
        init_item(&items[i], i + 1, name, initial_bid);
    }

    qsort(items, MAX_ITEMS, sizeof(Item), compare_time);

    int choice;
    int my_bid;

    while (1) {
        printf("\n");
        for (int i = 0; i < MAX_ITEMS; ++i) {
            print_item(items[i]);
        }

        printf("\n1. Place a bid\n2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int item_id;
            printf("Enter item ID: ");
            scanf("%d", &item_id);

            for (int i = 0; i < MAX_ITEMS; ++i) {
                if (items[i].id == item_id) {
                    if (items[i].time_left <= 0) {
                        printf("This item's auction has ended.\n");
                        continue;
                    }

                    printf("Current highest bid for item %d is %d.\n", item_id, items[i].current_bid);
                    printf("Enter your bid: ");
                    scanf("%d", &my_bid);

                    if (my_bid < items[i].current_bid + MIN_BID_INCREMENT) {
                        printf("Your bid is lower than the current highest bid.\n");
                        continue;
                    }

                    items[i].current_bid = my_bid;
                    break;
                }
            }
        } else {
            break;
        }
    }

    return 0;
}