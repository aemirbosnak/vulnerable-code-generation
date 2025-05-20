//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 10

struct Item {
    char name[50];
    double value;
    int num_bids;
    double bids[MAX_BIDS];
    char bidder_names[MAX_BIDS][50];
};

void display_menu() {
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Bid on Item\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

void add_item(struct Item items[], int num_items) {
    char name[50];
    double value;
    printf("Enter name of item: ");
    scanf("%s", name);
    printf("Enter value of item: ");
    scanf("%lf", &value);
    strcpy(items[num_items].name, name);
    items[num_items].value = value;
    items[num_items].num_bids = 0;
    printf("Item added successfully.\n");
}

void display_items(struct Item items[], int num_items) {
    if (num_items == 0) {
        printf("No items to display.\n");
        return;
    }
    printf("Items currently available for auction:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s (Value: %.2lf)\n", i + 1, items[i].name, items[i].value);
        printf("Bids:\n");
        for (int j = 0; j < items[i].num_bids; j++) {
            printf("- %.2lf by %s\n", items[i].bids[j], items[i].bidder_names[j]);
        }
        printf("\n");
    }
}

void bid_item(struct Item items[], int num_items) {
    if (num_items == 0) {
        printf("No items to bid on.\n");
        return;
    }
    int item_num;
    printf("Enter item number to bid on (1 - %d): ", num_items);
    scanf("%d", &item_num);
    item_num--;
    if (item_num < 0 || item_num >= num_items) {
        printf("Invalid item number.\n");
        return;
    }
    char name[50];
    double bid;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your bid: ");
    scanf("%lf", &bid);
    if (bid <= items[item_num].value) {
        printf("Bid must be higher than current value.\n");
        return;
    }
    if (items[item_num].num_bids == MAX_BIDS) {
        printf("Max number of bids reached for this item.\n");
        return;
    }
    items[item_num].bids[items[item_num].num_bids] = bid;
    strcpy(items[item_num].bidder_names[items[item_num].num_bids], name);
    items[item_num].num_bids++;
    items[item_num].value = bid;
    printf("Bid placed successfully.\n");
}

int main() {
    srand(time(NULL));
    struct Item items[10];
    int num_items = 0;
    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(items, num_items);
                num_items++;
                break;
            case 2:
                display_items(items, num_items);
                break;
            case 3:
                bid_item(items, num_items);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}