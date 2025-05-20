//FormAI DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BIDDERS 10
#define MAX_ITEM_NAME 50
#define MAX_DESC 100
#define MAX_ITEMS 5

typedef struct {
    char bidder_name[50];
    int bid_amount;
} Bid;

typedef struct {
    char item_name[MAX_ITEM_NAME];
    char description[MAX_DESC];
    int current_highest_bid;
    Bid highest_bidder;
    Bid bids[MAX_BIDDERS];
    int num_bids;
} AuctionItem;

AuctionItem items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items == MAX_ITEMS) {
        printf("The auction is full.");
        return;
    }

    printf("Enter the item name: ");
    fflush(stdin);
    fgets(items[num_items].item_name, MAX_ITEM_NAME, stdin);
    items[num_items].item_name[strcspn(items[num_items].item_name, "\n")] = '\0';

    printf("Enter the item description: ");
    fflush(stdin);
    fgets(items[num_items].description, MAX_DESC, stdin);
    items[num_items].description[strcspn(items[num_items].description, "\n")] = '\0';

    items[num_items].current_highest_bid = 0;
    items[num_items].num_bids = 0;

    num_items++;
}

void display_items() {
    if (num_items == 0) {
        printf("There are no items in the auction.\n");
        return;
    }

    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", items[i].item_name);
        printf("Description: %s\n", items[i].description);
        printf("Current Highest Bid: $%d\n", items[i].current_highest_bid);
        printf("Current Highest Bidder: %s\n", items[i].highest_bidder.bidder_name);
        printf("Previous Bids:\n");
        for (int j = 0; j < items[i].num_bids; j++) {
            printf("%s: $%d\n", items[i].bids[j].bidder_name, items[i].bids[j].bid_amount);
        }
        printf("\n");
    }
}

void make_bid(char* bidder_name, int bid_amount, int item_index) {
    if (item_index < 0 || item_index >= num_items) {
        printf("That is not a valid item number.\n");
        return;
    }

    if (bid_amount <= items[item_index].current_highest_bid) {
        printf("Your bid must be higher than the current highest bid of $%d.\n", items[item_index].current_highest_bid);
        return;
    }

    if (items[item_index].num_bids == MAX_BIDDERS) {
        printf("There are no more bids allowed for this item.\n");
        return;
    }

    Bid new_bid;
    strcpy(new_bid.bidder_name, bidder_name);
    new_bid.bid_amount = bid_amount;

    items[item_index].bids[items[item_index].num_bids] = new_bid;
    items[item_index].num_bids++;

    items[item_index].current_highest_bid = bid_amount;
    items[item_index].highest_bidder = new_bid;

    printf("Bid made successfully.\n");
}

int main() {
    bool running = true;
    while (running) {
        printf("Welcome to the digital auction system!\n\n");
        printf("Select an option:\n");
        printf("1. Add item to auction\n");
        printf("2. Display all items in the auction\n");
        printf("3. Make a bid on an item\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3: {
                printf("Enter the item number you would like to bid on: ");
                int item_num;
                scanf("%d", &item_num);

                printf("Enter your name: ");
                char bidder_name[50];
                fflush(stdin);
                fgets(bidder_name, 50, stdin);
                bidder_name[strcspn(bidder_name, "\n")] = '\0';

                printf("Enter your bid amount: ");
                int bid_amount;
                scanf("%d", &bid_amount);

                make_bid(bidder_name, bid_amount, item_num-1);
                break;
            }
            case 4:
                running = false;
                break;
            default:
                printf("Invalid option.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}