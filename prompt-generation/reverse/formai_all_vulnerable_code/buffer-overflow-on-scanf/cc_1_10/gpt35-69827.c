//FormAI DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_BIDS 10

struct item {
    int ID;
    char name[20];
    int starting_bid;
    int current_bid;
    char highest_bidder[20];
    int bid_count;
};

int num_items = 0;
struct item items[MAX_ITEMS];

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Maximum number of items has been reached.\n");
        return;
    }
    struct item new_item;
    new_item.ID = num_items + 1;
    printf("Enter the name of the item: ");
    scanf("%s", new_item.name);
    printf("Enter the starting bid: ");
    scanf("%d", &new_item.starting_bid);
    new_item.current_bid = new_item.starting_bid;
    strcpy(new_item.highest_bidder, "");
    new_item.bid_count = 0;
    items[num_items++] = new_item;
}

void display_items() {
    printf("ID  | Name                 | Starting Bid | Current Bid | Bidder\n");
    printf("----|---------------------|--------------|-------------|-------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-3d | %-20s | %-12d | %-11d | %s\n", items[i].ID, items[i].name, items[i].starting_bid, items[i].current_bid, items[i].highest_bidder);
    }
}

void bid_on_item() {
    int ID;
    printf("Enter the ID of the item you want to bid on: ");
    scanf("%d", &ID);
    if (ID <= 0 || ID > num_items) {
        printf("Invalid item ID.\n");
        return;
    }
    struct item *chosen_item = &items[ID - 1];
    int bid;
    printf("Enter your bid: ");
    scanf("%d", &bid);
    if (bid <= chosen_item->current_bid) {
        printf("Your bid must be higher than the current bid.\n");
        return;
    }
    if (chosen_item->bid_count >= MAX_BIDS) {
        printf("Maximum number of bids has been reached for this item.\n");
        return;
    }
    chosen_item->current_bid = bid;
    printf("Congratulations! You are now the highest bidder on item %d.\n", ID);
    strcpy(chosen_item->highest_bidder, "You");
    chosen_item->bid_count++;
}

int main() {
    int choice;
    do {
        printf("\n1. Add Item\n2. Display Items\n3. Bid on Item\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                bid_on_item();
                break;
            case 4:
                printf("Thank you for using the Digital Auction System.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}