//FormAI DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LENGTH 30
#define MAX_BIDDER_NAME_LENGTH 20

typedef struct Item {
    char name[MAX_ITEM_NAME_LENGTH];
    double current_bid;
    char current_bidder[MAX_BIDDER_NAME_LENGTH];
} Item;

typedef struct Bid {
    double amount;
    char bidder_name[MAX_BIDDER_NAME_LENGTH];
} Bid;

void print_menu() {
    printf("--------------------\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Bid on Item\n");
    printf("4. Exit\n");
    printf("--------------------\n");
}

void add_item(Item **items, int *num_items) {
    printf("Enter item name: ");
    char name[MAX_ITEM_NAME_LENGTH];
    scanf("%s", name);

    Item new_item = {0};
    strncpy(new_item.name, name, MAX_ITEM_NAME_LENGTH);

    *items = (Item*) realloc(*items, (*num_items + 1) * sizeof(Item));
    (*items)[*num_items] = new_item;
    *num_items += 1;

    printf("Item added successfully.\n");
}

void view_items(Item *items, int num_items) {
    printf("| %-30s | %-10s | %-20s |\n", "Item Name", "Current Bid", "Current Bidder");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < num_items; i++) {
        Item item = items[i];
        printf("| %-30s | %-10.2f | %-20s |\n", item.name, item.current_bid, item.current_bidder);
    }
}

int find_item_index(Item *items, int num_items, char *item_name) {
    for (int i = 0; i < num_items; i++) {
        Item item = items[i];
        if (strcmp(item_name, item.name) == 0) {
            return i;
        }
    }

    return -1;
}

void bid_on_item(Item *items, int num_items) {
    printf("Enter item name: ");
    char item_name[MAX_ITEM_NAME_LENGTH];
    scanf("%s", item_name);

    int item_index = find_item_index(items, num_items, item_name);
    if (item_index == -1) {
        printf("Item not found.\n");
        return;
    }

    Item *item = &items[item_index];

    printf("Current bid for %s is %.2f.\n", item->name, item->current_bid);

    printf("Enter your name: ");
    char bidder_name[MAX_BIDDER_NAME_LENGTH];
    scanf("%s", bidder_name);

    printf("Enter your bid amount: ");
    double bid_amount;
    scanf("%lf", &bid_amount);

    if (bid_amount <= item->current_bid) {
        printf("Your bid must be higher than the current bid.\n");
        return;
    }

    Bid new_bid = {0};
    new_bid.amount = bid_amount;
    strncpy(new_bid.bidder_name, bidder_name, MAX_BIDDER_NAME_LENGTH);

    item->current_bid = bid_amount;
    strncpy(item->current_bidder, bidder_name, MAX_BIDDER_NAME_LENGTH);

    printf("Bid successful!\n");
}

int main() {
    Item *items = NULL;
    int num_items = 0;

    int menu_choice = 0;
    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                add_item(&items, &num_items);
                break;
            case 2:
                view_items(items, num_items);
                break;
            case 3:
                bid_on_item(items, num_items);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (menu_choice != 4);

    if (items != NULL) {
        free(items);
    }

    return 0;
}