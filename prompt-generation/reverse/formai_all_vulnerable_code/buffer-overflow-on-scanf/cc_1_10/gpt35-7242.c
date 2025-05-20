//FormAI DATASET v1.0 Category: Digital Auction System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    int id;
    char name[50];
    double price;
    int bids_count;
    int bids[MAX_ITEMS];
} Item;

typedef struct Auction {
    Item items[MAX_ITEMS];
    int items_count;
} Auction;

void print_auction_menu() {
    printf("\n---- Auction Menu ----\n");
    printf("1. List all items\n");
    printf("2. Add new item\n");
    printf("3. Bid on item\n");
    printf("4. Exit\n");
}

void list_all_items(Auction *auction) {
    printf("\n---- All Items ----\n");
    for (int i = 0; i < auction->items_count; i++) {
        printf("Item #%d: %s (current price: $%.2f, # of bids: %d)\n",
               auction->items[i].id, auction->items[i].name,
               auction->items[i].price, auction->items[i].bids_count);
    }
    printf("\n");
}

void add_new_item(Auction *auction) {
    char name[50];
    double price;
    printf("Enter name of item: ");
    scanf("%s", name);
    printf("Enter starting price: $");
    scanf("%lf", &price);
    Item item = {auction->items_count + 1, name, price, 0, {0}};
    auction->items[auction->items_count++] = item;
    printf("Item #%d added successfully.\n", item.id);
}

void bid_on_item(Auction *auction) {
    int item_id, bid_amount;
    printf("Enter ID of item to bid on: ");
    scanf("%d", &item_id);
    Item *item = NULL;
    for (int i = 0; i < auction->items_count; i++) {
        if (auction->items[i].id == item_id) {
            item = &auction->items[i];
            break;
        }
    }
    if (item == NULL) {
        printf("Item not found.\n");
        return;
    }
    printf("Enter your bid amount: $");
    scanf("%d", &bid_amount);
    if (bid_amount <= item->price) {
        printf("Bid amount must be higher than current price ($%.2f).\n", item->price);
        return;
    }
    item->price = bid_amount;
    item->bids[item->bids_count++] = bid_amount;
    printf("Bid on item #%d successful. New price: $%.2f\n", item_id, item->price);
}

int main() {
    Auction auction = { .items_count = 0 };
    int choice;
    do {
        print_auction_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                list_all_items(&auction);
                break;
            case 2:
                add_new_item(&auction);
                break;
            case 3:
                bid_on_item(&auction);
                break;
            case 4:
                printf("Exiting auction...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}