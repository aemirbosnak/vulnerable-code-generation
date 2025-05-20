//FormAI DATASET v1.0 Category: Digital Auction System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID_LENGTH 10

typedef struct {
    char name[50];
    int highest_bid;
} Item;

void print_item(Item item) {
    printf("Item name: %s\n", item.name);
    printf("Highest bid: %d\n", item.highest_bid);
    printf("\n");
}

void print_items(Item items[], int num_items) {
    printf("Available items: \n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s\n", i+1, items[i].name);
    }
    printf("\n");
}

void bid_on_item(Item *item, int bid) {
    if (bid > item->highest_bid) {
        printf("New highest bid of $%d on %s\n", bid, item->name);
        item->highest_bid = bid;
    } else {
        printf("Bid of $%d is not higher than current highest bid of $%d on %s\n", bid, item->highest_bid, item->name);
    }
}

int main() {
    int num_items = 3;
    Item items[num_items];
    
    strcpy(items[0].name, "Painting");
    items[0].highest_bid = 1000;
    
    strcpy(items[1].name, "Sculpture");
    items[1].highest_bid = 500;
    
    strcpy(items[2].name, "Watch");
    items[2].highest_bid = 2000;
    
    print_items(items, num_items);
    
    int choice;
    printf("Enter the number of the item you want to bid on: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > num_items) {
        printf("Invalid choice.\n");
        return 1;
    }
    
    int bid;
    printf("Enter your bid (maximum of $%d): ", MAX_BID_LENGTH);
    char bid_str[MAX_BID_LENGTH];
    scanf("%s", bid_str);
    
    bid = atoi(bid_str);
    if (bid < 0 || bid > MAX_BID_LENGTH) {
        printf("Invalid bid amount.\n");
        return 1;
    }
    
    bid_on_item(&items[choice-1], bid);
    print_item(items[choice-1]);
    
    return 0;
}