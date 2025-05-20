//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 20
#define MAX_BIDDERS 20
#define MAX_BIDS 20

typedef struct {
    char name[50];
    int id;
    int max_bid;
    int num_bids;
} Bidder;

typedef struct {
    char name[50];
    int id;
    int current_bid;
    int highest_bidder_id;
} Item;

int main() {
    srand(time(NULL));

    Bidder bidders[MAX_BIDDERS];
    Item items[MAX_ITEMS];

    int num_bidders = 0;
    int num_items = 0;

    printf("Welcome to the Digital Auction System!\n\n");

    // Register bidders
    while (num_bidders < MAX_BIDDERS) {
        printf("Enter bidder name: ");
        scanf("%s", bidders[num_bidders].name);
        printf("Enter bidder ID (1-%d): ", num_bidders + 1);
        scanf("%d", &bidders[num_bidders].id);
        num_bidders++;
    }

    // Register items
    while (num_items < MAX_ITEMS) {
        printf("Enter item name: ");
        scanf("%s", items[num_items].name);
        printf("Enter item ID (1-%d): ", num_items + 1);
        scanf("%d", &items[num_items].id);
        printf("Enter starting bid: ");
        scanf("%d", &items[num_items].current_bid);
        num_items++;
    }

    // Start auction
    int auction_ended = 0;
    while (!auction_ended) {
        printf("\nCurrent bids:\n");
        for (int i = 0; i < num_items; i++) {
            printf("%s - Current bid: $%d (Highest bidder: %d)\n", items[i].name, items[i].current_bid, items[i].highest_bidder_id);
        }

        int choice;
        printf("\nEnter your choice:\n1. Place a bid\n2. View your bids\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                int item_id;
                scanf("%d", &item_id);

                for (int i = 0; i < num_items; i++) {
                    if (items[i].id == item_id) {
                        printf("Enter your bid: ");
                        int bid;
                        scanf("%d", &bid);

                        if (bid > items[i].current_bid) {
                            items[i].current_bid = bid;
                            items[i].highest_bidder_id = rand() % num_bidders + 1;
                        } else {
                            printf("Your bid is too low.\n");
                        }

                        break;
                    }
                }

                break;

            case 2:
                printf("Your bids:\n");
                for (int i = 0; i < num_items; i++) {
                    for (int j = 0; j < num_bidders; j++) {
                        if (bidders[j].id == items[i].highest_bidder_id) {
                            printf("%s - Bid: $%d\n", items[i].name, items[i].current_bid);
                            break;
                        }
                    }
                }

                break;

            case 3:
                auction_ended = 1;
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}