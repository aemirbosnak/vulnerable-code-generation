//FormAI DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int item_id;
    char item_name[50];
    float item_price;
    int bid_count;
};

struct Bid {
    int bid_id;
    int item_id;
    float bid_amount;
    char bidder_name[50];
};

void add_item(struct Item *items, int *num_items);
void view_items(struct Item *items, int num_items);
void add_bid(struct Bid *bids, int *num_bids, struct Item *items, int num_items);
void view_bids(struct Bid *bids, int num_bids);

int main() {
    struct Item items[50];
    int num_items = 0;
    struct Bid bids[100];
    int num_bids = 0;
    int choice;

    do {
        printf("Welcome to the Digital Auction System\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Add Bid\n");
        printf("4. View Bids\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_item(items, &num_items);
                    break;
            case 2: view_items(items, num_items);
                    break;
            case 3: add_bid(bids, &num_bids, items, num_items);
                    break;
            case 4: view_bids(bids, num_bids);
                    break;
            case 5: printf("Thank you for using Digital Auction System\n");
                    break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;
}

void add_item(struct Item *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].item_name);
    printf("Enter item price: ");
    scanf("%f", &items[*num_items].item_price);
    items[*num_items].item_id = *num_items + 1;
    items[*num_items].bid_count = 0;
    (*num_items)++;
}

void view_items(struct Item *items, int num_items) {
    printf("Item ID\tItem Name\tItem Price\tBid Count\n");
    for(int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%.2f\t%d\n", items[i].item_id, items[i].item_name, items[i].item_price, items[i].bid_count);
    }
}

void add_bid(struct Bid *bids, int *num_bids, struct Item *items, int num_items) {
    printf("Enter item ID: ");
    int item_id;
    scanf("%d", &item_id);
    int found = 0;
    for(int i = 0; i < num_items; i++) {
        if(items[i].item_id == item_id) {
            found = 1;
            printf("Enter bidder name: ");
            scanf("%s", bids[*num_bids].bidder_name);
            printf("Enter bid amount: ");
            scanf("%f", &bids[*num_bids].bid_amount);
            items[i].bid_count++;
            bids[*num_bids].bid_id = *num_bids + 1;
            bids[*num_bids].item_id = item_id;
            (*num_bids)++;
            break;
        }
    }
    if(!found) {
        printf("Invalid item ID\n");
    }
}

void view_bids(struct Bid *bids, int num_bids) {
    printf("Bid ID\tItem ID\tBidder Name\tBid Amount\n");
    for(int i = 0; i < num_bids; i++) {
        printf("%d\t%d\t%s\t%.2f\n", bids[i].bid_id, bids[i].item_id, bids[i].bidder_name, bids[i].bid_amount);
    }
}