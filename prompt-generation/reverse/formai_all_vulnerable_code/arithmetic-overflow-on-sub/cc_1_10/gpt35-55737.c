//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char item_name[50];
    int starting_bid;
    int current_bid;
    char bidder_name[50];
} auction_item;

int main() {
    int num_items;
    printf("How many auction items? ");
    scanf("%d", &num_items);

    auction_item *items = malloc(num_items * sizeof(auction_item));
    if (items == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    for (int i = 0; i < num_items; i++) {
        printf("\nItem %d:\n", i+1);
        printf("Item name: ");
        fgets(items[i].item_name, 50, stdin);
        printf("Starting bid: ");
        scanf("%d", &items[i].starting_bid);
        items[i].current_bid = items[i].starting_bid;
        printf("Current bidder name: ");
        fgets(items[i].bidder_name, 50, stdin);
    }

    int user_choice = -1;
    while (user_choice != 0) {
        printf("\n\nAuction Menu:\n");
        printf("0. Exit program\n");
        for (int i = 1; i <= num_items; i++) {
            printf("%d. %s (current bid: $%d)\n", i, items[i-1].item_name, items[i-1].current_bid);
        }

        printf("\nEnter choice: ");
        scanf("%d", &user_choice);
        if (user_choice == 0) {
            break;
        }

        printf("Enter bid amount for item %d: ", user_choice);
        int bid_amt;
        scanf("%d", &bid_amt);
        if (bid_amt > items[user_choice-1].current_bid) {
            printf("New bid for %s: $%d (from %s)\n", items[user_choice-1].item_name, bid_amt, items[user_choice-1].bidder_name);
            items[user_choice-1].current_bid = bid_amt;

            printf("Enter bidder name: ");
            fgets(items[user_choice-1].bidder_name, 50, stdin);
        } else {
            printf("Sorry, bid must be greater than current bid\n");
        }
    }

    free(items);
    return 0;
}