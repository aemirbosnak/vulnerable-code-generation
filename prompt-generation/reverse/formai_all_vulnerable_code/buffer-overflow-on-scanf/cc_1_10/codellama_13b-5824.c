//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 10

typedef struct {
    char name[20];
    int price;
    int quantity;
} Item;

typedef struct {
    char name[20];
    int bid;
} Bidder;

void print_menu() {
    printf("Welcome to the Retro Digital Auction System!\n");
    printf("1. Add new item\n");
    printf("2. Place bid\n");
    printf("3. View items\n");
    printf("4. View bids\n");
    printf("5. Exit\n");
}

void add_item(Item items[], int *num_items) {
    printf("Enter the item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter the item price: ");
    scanf("%d", &items[*num_items].price);
    printf("Enter the item quantity: ");
    scanf("%d", &items[*num_items].quantity);
    (*num_items)++;
}

void place_bid(Bidder bidders[], Item items[], int *num_bidders, int *num_items) {
    printf("Enter the bidder name: ");
    scanf("%s", bidders[*num_bidders].name);
    printf("Enter the bid amount: ");
    scanf("%d", &bidders[*num_bidders].bid);
    (*num_bidders)++;

    int i, j;
    for (i = 0; i < *num_items; i++) {
        if (items[i].quantity > 0) {
            if (items[i].price > bidders[*num_bidders - 1].bid) {
                printf("The item %s is sold to bidder %s for $%d.\n", items[i].name, bidders[*num_bidders - 1].name, bidders[*num_bidders - 1].bid);
                items[i].quantity--;
                break;
            }
        }
    }
}

void view_items(Item items[], int num_items) {
    int i;
    for (i = 0; i < num_items; i++) {
        printf("Item %s: $%d (%d left)\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void view_bidders(Bidder bidders[], int num_bidders) {
    int i;
    for (i = 0; i < num_bidders; i++) {
        printf("Bidder %s: $%d\n", bidders[i].name, bidders[i].bid);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;
    Bidder bidders[MAX_BIDS];
    int num_bidders = 0;

    print_menu();

    while (1) {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                place_bid(bidders, items, &num_bidders, &num_items);
                break;
            case 3:
                view_items(items, num_items);
                break;
            case 4:
                view_bidders(bidders, num_bidders);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}