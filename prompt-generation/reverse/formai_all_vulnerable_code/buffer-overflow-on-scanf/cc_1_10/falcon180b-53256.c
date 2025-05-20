//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    char name[50];
    int id;
    double price;
    int quantity;
} Item;

typedef struct {
    int item_id;
    int bidder_id;
    double bid_amount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int num_items = 0;
int num_bids = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item ID: ");
    scanf("%d", &items[num_items].id);
    printf("Enter item price: ");
    scanf("%lf", &items[num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);
    num_items++;
}

void display_items() {
    printf("\nItem List:\n");
    for(int i=0; i<num_items; i++) {
        printf("%d. %s (%d) - $%.2lf (%d)\n", i+1, items[i].name, items[i].id, items[i].price, items[i].quantity);
    }
}

void place_bid() {
    printf("\nEnter item ID to bid on: ");
    scanf("%d", &bids[num_bids].item_id);
    printf("Enter your bid amount: ");
    scanf("%lf", &bids[num_bids].bid_amount);
    bids[num_bids].bidder_id = 1; // assuming only one bidder for simplicity
    num_bids++;
}

void display_bids() {
    printf("\nBid List:\n");
    for(int i=0; i<num_bids; i++) {
        printf("%d. Bidder %d bids $%.2lf on item %d\n", i+1, bids[i].bidder_id, bids[i].bid_amount, bids[i].item_id);
    }
}

int main() {
    int choice;
    do {
        printf("\nDigital Auction System\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Place bid\n");
        printf("4. Display bids\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                display_bids();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 5);

    return 0;
}