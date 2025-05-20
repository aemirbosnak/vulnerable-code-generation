//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double current_bid;
    char bidder[MAX_NAME_LENGTH];
} item;

int main() {
    int num_items;
    printf("Welcome to the digital auction system!\n");
    printf("How many items are up for bidding?\n");
    scanf("%d", &num_items);

    item items[MAX_ITEMS];
    memset(items, 0, MAX_ITEMS * sizeof(item));

    for (int i = 0; i < num_items; i++) {
        printf("\nEnter item #%d's name: ", i+1);
        scanf("%19s", items[i].name);
        items[i].current_bid = 0;
        printf("Item #%d has been listed for auction!\n", i+1);
    }

    while (1) {
        int choice;
        printf("\n1. List all items\n2. Bid on an item\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("\nCurrent items up for bidding:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%d. %s - Current bid: %.2f by %s\n", i+1, items[i].name, items[i].current_bid, items[i].bidder);
                }
                break;
            }
            case 2: {
                int item_choice;
                printf("\nEnter the number of the item you would like to bid on: ");
                scanf("%d", &item_choice);
                if (item_choice <= 0 || item_choice > num_items) {
                    printf("Invalid item choice! Please try again.\n");
                    break;
                }

                item* curr_item = &items[item_choice-1];
                printf("You are bidding on %s, current bid: %.2f\n", curr_item->name, curr_item->current_bid);

                char bidder[MAX_NAME_LENGTH];
                double bid_amount;
                printf("Enter your name: ");
                scanf("%19s", bidder);
                printf("Enter your bid: ");
                scanf("%lf", &bid_amount);

                if (bid_amount > curr_item->current_bid) {
                    curr_item->current_bid = bid_amount;
                    strcpy(curr_item->bidder, bidder);
                    printf("You are now the highest bidder for %s with a bid of %.2f\n", curr_item->name, curr_item->current_bid);
                } else {
                    printf("Your bid of %.2f is lower than the current bid of %.2f for %s. Please try again with a higher bid.\n", bid_amount, curr_item->current_bid, curr_item->name);
                }
                break;
            }
            case 3: {
                printf("\nThank you for using our digital auction system!\n");
                return 0;
            }
            default: {
                printf("\nInvalid choice! Please try again.\n");
                break;
            }
        }
    }
    return 0;
}