//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[20];
    int value;
} item;

void generate_items(item *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        items[i].id = i;
        sprintf(items[i].name, "Item %d", i);
        items[i].value = rand() % 100;
    }
}

void display_items(item *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s ($%d)\n", items[i].id, items[i].name, items[i].value);
    }
}

int main() {
    srand(time(NULL));

    int num_items;
    printf("How many items do you want to auction off? ");
    scanf("%d", &num_items);

    item *items = malloc(num_items * sizeof(item));
    generate_items(items, num_items);

    display_items(items, num_items);

    int max_bid = 0;
    int max_bidder = -1;

    for (int i = 0; i < num_items; i++) {
        int current_bid = 0;
        int current_bidder = -1;

        while (current_bid < items[i].value) {
            printf("Current bid for %s is $%d. Do you want to bid? (y/n) ", items[i].name, current_bid);
            char choice;
            scanf(" %c", &choice);

            if (choice == 'y') {
                printf("Enter your bid: ");
                scanf("%d", &current_bid);

                if (current_bid > max_bid) {
                    max_bid = current_bid;
                    max_bidder = i;
                }

                if (current_bid < items[i].value) {
                    current_bidder = i;
                }
            }
        }

        printf("Item %s sold for $%d to bidder %d!\n", items[i].name, current_bid, current_bidder);
    }

    printf("The highest bid was $%d for item %d.\n", max_bid, max_bidder);

    return 0;
}