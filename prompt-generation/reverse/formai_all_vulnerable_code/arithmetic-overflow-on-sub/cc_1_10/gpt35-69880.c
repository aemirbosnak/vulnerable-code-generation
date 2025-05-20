//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 50

typedef struct item {
    char name[50];
    int current_bid;
    int num_bids;
    int bids[MAX_BIDDERS];
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

int add_item(char* name) {
    if (num_items >= MAX_ITEMS) {
        return -1; // too many items
    }
    strcpy(items[num_items].name, name);
    items[num_items].current_bid = 0;
    items[num_items].num_bids = 0;
    num_items++;
    return num_items - 1;
}

int make_bid(int item_index, int bid) {
    if (item_index < 0 || item_index >= num_items) {
        return -1; // item does not exist
    }
    if (bid <= items[item_index].current_bid) {
        return -2; // bid not higher than current bid
    }
    if (items[item_index].num_bids >= MAX_BIDDERS) {
        return -3; // too many bids for this item
    }
    items[item_index].bids[items[item_index].num_bids] = bid;
    items[item_index].num_bids++;
    items[item_index].current_bid = bid;
    return 0;
}

void print_items() {
    int i, j;
    for (i = 0; i < num_items; i++) {
        printf("%d. %s\n", i+1, items[i].name);
        printf("   Current bid: %d\n", items[i].current_bid);
        printf("   Bids:\n");
        for (j = 0; j < items[i].num_bids; j++) {
            printf("     %d\n", items[i].bids[j]);
        }
    }
}

int main() {
    int choice;
    char name[50];
    int bid, item_index;
    do {
        printf("Main menu:\n");
        printf("1. Add item\n");
        printf("2. Make bid\n");
        printf("3. Print items\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                if (add_item(name) < 0) {
                    printf("Could not add item\n");
                }
                break;
            case 2:
                printf("Enter item number: ");
                scanf("%d", &item_index);
                item_index--;
                printf("Enter bid: ");
                scanf("%d", &bid);
                switch (make_bid(item_index, bid)) {
                    case -1:
                        printf("Item does not exist\n");
                        break;
                    case -2:
                        printf("Bid must be higher than current bid\n");
                        break;
                    case -3:
                        printf("Too many bids for this item\n");
                        break;
                    default:
                        printf("Bid successful\n");
                        break;
                }
                break;
            case 3:
                print_items();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);
    return 0;
}