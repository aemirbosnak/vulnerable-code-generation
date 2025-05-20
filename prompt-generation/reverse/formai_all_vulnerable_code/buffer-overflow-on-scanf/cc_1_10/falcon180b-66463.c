//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct item {
    char name[50];
    int bid;
    int bidder;
};

void display_items(struct item items[], int size) {
    printf("\nItem\tBidder\tBid\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t%d\n", items[i].name, items[i].bidder, items[i].bid);
    }
}

void bid_item(struct item items[], int size, int item_index, int bid) {
    if (item_index < 0 || item_index >= size) {
        printf("Invalid item index.\n");
        return;
    }
    if (items[item_index].bid > bid) {
        printf("Your bid is too low.\n");
        return;
    }
    items[item_index].bid = bid;
    items[item_index].bidder = rand() % 100;
    printf("You have successfully bid on item %s with bid amount %d.\n", items[item_index].name, bid);
}

int main() {
    int size;
    printf("Enter the number of items for auction: ");
    scanf("%d", &size);
    struct item items[size];
    for (int i = 0; i < size; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i].name);
    }
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        items[i].bid = rand() % 100;
        items[i].bidder = rand() % 100;
    }
    display_items(items, size);
    int choice;
    while (1) {
        printf("\nEnter your choice:\n1. Bid on an item\n2. View current bids\n3. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item index to bid on: ");
                int item_index;
                scanf("%d", &item_index);
                bid_item(items, size, item_index, rand() % 100);
                break;
            case 2:
                display_items(items, size);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}