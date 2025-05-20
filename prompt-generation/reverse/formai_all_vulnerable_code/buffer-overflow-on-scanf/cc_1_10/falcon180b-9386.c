//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 50

typedef struct {
    char name[50];
    int id;
} bidder;

typedef struct {
    char name[50];
    int id;
    int highest_bid;
} item;

void create_bidder(bidder *bidders, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter bidder %d name: ", i+1);
        scanf("%s", bidders[i].name);
        bidders[i].id = i;
    }
}

void create_item(item *items, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter item %d name: ", i+1);
        scanf("%s", items[i].name);
        items[i].id = i;
        items[i].highest_bid = 0;
    }
}

void display_items(item *items, int n) {
    printf("\nItems:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - Highest bid: $%d\n", i+1, items[i].name, items[i].highest_bid);
    }
}

int main() {
    bidder bidders[MAX_BIDDERS];
    item items[MAX_ITEMS];

    int n_bidders, n_items;

    printf("Enter number of bidders: ");
    scanf("%d", &n_bidders);

    printf("Enter number of items: ");
    scanf("%d", &n_items);

    create_bidder(bidders, n_bidders);
    create_item(items, n_items);

    int choice;
    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Place a bid\n");
        printf("2. Display items\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &choice);
                printf("Enter bid amount: ");
                int bid;
                scanf("%d", &bid);

                for (int i = 0; i < n_items; i++) {
                    if (items[i].id == choice) {
                        if (bid > items[i].highest_bid) {
                            items[i].highest_bid = bid;
                            printf("Bid placed successfully!\n");
                        } else {
                            printf("Your bid is too low.\n");
                        }
                        break;
                    }
                }
                break;

            case 2:
                display_items(items, n_items);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}