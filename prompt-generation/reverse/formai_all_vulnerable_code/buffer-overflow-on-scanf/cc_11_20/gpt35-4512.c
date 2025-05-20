//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 10

typedef struct {
    int item_number;
    char item_name[50];
    int current_bid;
    int num_bids;
    int bidder_ids[MAX_BIDDERS];
} AuctionItem;

typedef struct {
    int bid_id;
    char bidder_name[50];
    int item_number;
    int amount;
} Bid;

int main() {
    AuctionItem items[MAX_ITEMS];
    Bid bids[MAX_BIDDERS * MAX_ITEMS];
    int num_items = 0;
    int num_bids = 0;
    char input[50];

    while (strcmp(input, "exit") != 0) {
        printf("1. Add item\n");
        printf("2. List items\n");
        printf("3. Start bidding on an item\n");
        printf("4. List bids for an item\n");
        printf("5. List winning bids\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) { // Add item
            if (num_items >= MAX_ITEMS) {
                printf("Cannot add any more items.\n");
                continue;
            }

            AuctionItem item;
            printf("Enter item name: ");
            scanf("%s", item.item_name);
            item.item_number = num_items + 1;
            item.current_bid = 0;
            item.num_bids = 0;
            items[num_items++] = item;
        } else if (strcmp(input, "2") == 0) { // List items
            if (num_items == 0) {
                printf("No items.\n");
                continue;
            }

            printf("Item Number\tItem Name\tCurrent Bid\n");
            for (int i = 0; i < num_items; i++) {
                printf("%d\t\t%s\t\t%d\n", items[i].item_number, items[i].item_name, items[i].current_bid);
            }
        } else if (strcmp(input, "3") == 0) { // Start bidding on an item
            if (num_items == 0) {
                printf("No items to bid on.\n");
                continue;
            }

            int item_number, bidder_id;
            printf("Enter item number: ");
            scanf("%d", &item_number);
            printf("Enter bidder id: ");
            scanf("%d", &bidder_id);

            AuctionItem item = items[item_number - 1];
            if (item.current_bid == 0) {
                printf("Enter starting bid: ");
                scanf("%d", &item.current_bid);
            }
            Bid bid;
            bid.bid_id = item.num_bids + 1;
            strcpy(bid.bidder_name, "Bidder");
            sprintf(bid.bidder_name + strlen(bid.bidder_name), "%d", bidder_id);
            bid.item_number = item_number;
            printf("Enter bid amount: ");
            scanf("%d", &bid.amount);
            bids[num_bids++] = bid;
            item.bidder_ids[item.num_bids++] = bidder_id;
            items[item_number - 1] = item;
        } else if (strcmp(input, "4") == 0) { // List bids for an item
            int item_number;
            printf("Enter item number: ");
            scanf("%d", &item_number);

            AuctionItem item = items[item_number - 1];

            if (item.num_bids == 0) {
                printf("No bids for this item.\n");
                continue;
            }

            printf("Bid ID\tBidder\tAmount\n");
            for (int i = 0; i < item.num_bids; i++) {
                Bid bid = bids[item.bidder_ids[i] - 1];
                printf("%d\t%s\t%d\n", bid.bid_id, bid.bidder_name, bid.amount);
            }
        } else if (strcmp(input, "5") == 0) { // List winning bids
            if (num_items == 0) {
                printf("No items.\n");
                continue;
            }

            printf("Item Number\tItem Name\tWinning Bidder\tAmount\n");
            for (int i = 0; i < num_items; i++) {
                AuctionItem item = items[i];

                if (item.num_bids == 0) {
                    printf("%d\t\t%s\t\tNo bids\n", item.item_number, item.item_name);
                    continue;
                }

                Bid winning_bid = bids[item.bidder_ids[0] - 1];
                for (int j = 1; j < item.num_bids; j++) {
                    Bid bid = bids[item.bidder_ids[j] - 1];
                    if (bid.amount > winning_bid.amount) {
                        winning_bid = bid;
                    }
                }

                printf("%d\t\t%s\t\t%s\t\t\t%d\n", item.item_number, item.item_name,
                       winning_bid.bidder_name, winning_bid.amount);
            }
        }
    }
    return 0;
}