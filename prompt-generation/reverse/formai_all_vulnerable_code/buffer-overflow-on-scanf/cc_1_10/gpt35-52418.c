//FormAI DATASET v1.0 Category: Digital Auction System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 30
#define MAX_DESC_LEN 100
#define BID_INCREMENT 50

struct Item {
    char name[MAX_NAME_LEN];
    char desc[MAX_DESC_LEN];
    int current_bid;
    int num_bids;
    int highest_bidder_id;
    int item_id;
    int num_ratings;
    float avg_rating;
};

int get_new_item_id(struct Item items[]) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].item_id == 0) {
            return i + 1;
        }
    }
    return 0;
}

void add_item(struct Item items[], char name[], char desc[], int starting_bid) {
    int item_id = get_new_item_id(items);
    if (item_id != 0) {
        struct Item item;
        item.current_bid = starting_bid;
        item.num_bids = 0;
        item.highest_bidder_id = 0;
        item.item_id = item_id;
        item.num_ratings = 0;
        item.avg_rating = 0.0f;
        strncpy(item.name, name, MAX_NAME_LEN);
        strncpy(item.desc, desc, MAX_DESC_LEN);
        items[item_id-1] = item;
        printf("Item %d [%s] added successfully\n", item_id, item.name);
    } else {
        printf("Error: No more item spaces available.\n");
    }
}

void view_item(struct Item item) {
    printf("ID: %d\n", item.item_id);
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.desc);
    printf("Current bid: $%d\n", item.current_bid);
    printf("Number of bids: %d\n", item.num_bids);
    printf("Highest bidder ID: %d\n", item.highest_bidder_id);
    printf("Number of ratings: %d\n", item.num_ratings);
    printf("Average rating (out of 5): %.2f\n", item.avg_rating);
}

void view_all_items(struct Item items[]) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].item_id != 0) {
            view_item(items[i]);
            printf("\n");
        }
    }
}

void bid_on_item(struct Item *item, int bidder_id, int amount) {
    if (amount < item->current_bid + BID_INCREMENT) {
        printf("Error: Bid must be at least $%d more than current bid.\n", BID_INCREMENT);
        return;
    }

    item->current_bid = amount;
    item->num_bids++;
    item->highest_bidder_id = bidder_id;

    printf("Bid for item %d successful. Current highest bid is $%d.\n", item->item_id, item->current_bid);
}

void rate_item(struct Item *item, int rating) {
    if (rating < 1 || rating > 5) {
        printf("Error: Rating must be between 1 and 5.\n");
        return;
    }

    item->avg_rating = ((item->avg_rating * item->num_ratings) + rating) / (item->num_ratings + 1);
    item->num_ratings++;

    printf("Rating for item %d successful. Average rating is now %.2f.\n", item->item_id, item->avg_rating);
}

int main() {
    struct Item items[MAX_ITEMS];
    int num_items = 0;
    int user_id = 1;

    char command[20];
    while (1) {
        printf("\nWhat would you like to do? (add/view/viewall/bid/rate/exit)\n");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_NAME_LEN];
            char desc[MAX_DESC_LEN];
            int starting_bid;
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item description: ");
            scanf("%s", desc);
            printf("Enter starting bid: ");
            scanf("%d", &starting_bid);
            add_item(items, name, desc, starting_bid);
        } else if (strcmp(command, "view") == 0) {
            int item_id;
            printf("Enter item ID: ");
            scanf("%d", &item_id);
            if (item_id <= 0 || item_id > MAX_ITEMS || items[item_id-1].item_id == 0) {
                printf("Error: Invalid item ID.\n");
            } else {
                view_item(items[item_id-1]);
            }
        } else if (strcmp(command, "viewall") == 0) {
            view_all_items(items);
        } else if (strcmp(command, "bid") == 0) {
            int item_id;
            int amount;
            printf("Enter item ID to bid on: ");
            scanf("%d", &item_id);
            if (item_id <= 0 || item_id > MAX_ITEMS || items[item_id-1].item_id == 0) {
                printf("Error: Invalid item ID.\n");
                continue;
            }
            printf("Enter bid amount: ");
            scanf("%d", &amount);
            bid_on_item(&items[item_id-1], user_id, amount);
        } else if (strcmp(command, "rate") == 0) {
            int item_id;
            int rating;
            printf("Enter item ID to rate: ");
            scanf("%d", &item_id);
            if (item_id <= 0 || item_id > MAX_ITEMS || items[item_id-1].item_id == 0) {
                printf("Error: Invalid item ID.\n");
                continue;
            }
            printf("Enter rating (1-5): ");
            scanf("%d", &rating);
            rate_item(&items[item_id-1], rating);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}