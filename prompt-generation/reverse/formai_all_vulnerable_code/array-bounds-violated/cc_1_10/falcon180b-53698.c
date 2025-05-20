//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 50
#define MAX_BIDS 100

typedef struct {
    char name[50];
    int bid;
} Bidder;

typedef struct {
    char name[50];
    int starting_price;
    int current_price;
    Bidder highest_bidder;
} Item;

Bidder bidders[MAX_BIDDERS];
Item items[MAX_ITEMS];

void register_bidder(char* name) {
    int i;
    for (i = 0; i < MAX_BIDDERS; i++) {
        if (bidders[i].name[0] == '\0') {
            strcpy(bidders[i].name, name);
            break;
        }
    }
}

void add_item(char* name, int starting_price) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            strcpy(items[i].name, name);
            items[i].starting_price = starting_price;
            items[i].current_price = starting_price;
            items[i].highest_bidder.name[0] = '\0';
            items[i].highest_bidder.bid = 0;
            break;
        }
    }
}

void place_bid(int item_index, int bid) {
    if (bid > items[item_index].current_price) {
        items[item_index].current_price = bid;
        items[item_index].highest_bidder = bidders[0];
    }
}

void display_items() {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0]!= '\0') {
            printf("%s - Current price: $%d - Highest bidder: %s\n", items[i].name, items[i].current_price, items[i].highest_bidder.name);
        }
    }
}

int main() {
    int choice, item_index, bid;
    char name[50];

    system("clear");

    printf("Welcome to the Digital Auction System!\n");

    while (1) {
        printf("\n");
        printf("1. Register as a bidder\n");
        printf("2. Add an item for auction\n");
        printf("3. Place a bid\n");
        printf("4. Display items\n");
        printf("5. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                register_bidder(name);
                break;
            case 2:
                printf("Enter the name of the item: ");
                scanf("%s", name);
                add_item(name, 0);
                break;
            case 3:
                printf("Enter the item index: ");
                scanf("%d", &item_index);
                printf("Enter your bid: ");
                scanf("%d", &bid);
                place_bid(item_index, bid);
                break;
            case 4:
                display_items();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}