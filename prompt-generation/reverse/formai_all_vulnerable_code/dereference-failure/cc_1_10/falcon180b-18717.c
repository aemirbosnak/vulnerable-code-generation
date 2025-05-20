//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100
#define MAX_BIDS 1000

typedef struct {
    char name[50];
    int id;
} Bidder;

typedef struct {
    char name[100];
    int id;
    int starting_price;
    int current_price;
    Bidder* highest_bidder;
} Item;

Bidder bidders[MAX_BIDDERS];
Item items[MAX_ITEMS];
int num_bidders = 0;
int num_items = 0;

void add_bidder(char* name, int id) {
    strcpy(bidders[num_bidders].name, name);
    bidders[num_bidders].id = id;
    num_bidders++;
}

int get_bidder_id(char* name) {
    for (int i = 0; i < num_bidders; i++) {
        if (strcmp(bidders[i].name, name) == 0) {
            return bidders[i].id;
        }
    }
    return -1;
}

void add_item(char* name, int id, int starting_price) {
    strcpy(items[num_items].name, name);
    items[num_items].id = id;
    items[num_items].starting_price = starting_price;
    items[num_items].current_price = starting_price;
    items[num_items].highest_bidder = NULL;
    num_items++;
}

int get_item_id(char* name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return items[i].id;
        }
    }
    return -1;
}

void place_bid(int item_id, int bidder_id, int amount) {
    int i = get_item_id(item_id);
    if (i == -1) {
        printf("Item not found.\n");
        return;
    }
    int j = get_bidder_id(items[i].highest_bidder->name);
    if (j == -1) {
        items[i].highest_bidder = &bidders[bidder_id];
        items[i].current_price = amount;
    } else if (amount > items[i].current_price) {
        items[i].highest_bidder = &bidders[bidder_id];
        items[i].current_price = amount;
    }
}

void display_items() {
    printf("Item ID | Item Name | Current Price | Highest Bidder\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d | %s | $%d | %s\n", items[i].id, items[i].name, items[i].current_price, items[i].highest_bidder->name);
    }
}

int main() {
    add_bidder("Alice", 1);
    add_bidder("Bob", 2);
    add_bidder("Charlie", 3);

    add_item("Laptop", 1, 500);
    add_item("Phone", 2, 300);
    add_item("Tablet", 3, 200);

    place_bid(1, 1, 550);
    place_bid(2, 2, 325);
    place_bid(3, 1, 225);

    display_items();

    return 0;
}