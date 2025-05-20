//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 50
#define MAX_BIDS 1000

typedef struct {
    char name[50];
    int id;
    double balance;
} Bidder;

typedef struct {
    char name[50];
    int id;
    double price;
    int bidder_id;
} Item;

typedef struct {
    int item_id;
    double amount;
    int bidder_id;
} Bid;

Bidder bidders[MAX_BIDDERS];
Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int num_bidders, num_items, num_bids;

void add_bidder() {
    printf("Enter bidder name: ");
    scanf("%s", bidders[num_bidders].name);
    bidders[num_bidders].id = num_bidders + 1;
    bidders[num_bidders].balance = 0.0;
    num_bidders++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    items[num_items].id = num_items + 1;
    items[num_items].price = 0.0;
    num_items++;
}

void place_bid() {
    int i, j;
    double amount;

    printf("Enter item ID: ");
    scanf("%d", &i);

    for (j = 0; j < num_items; j++) {
        if (items[j].id == i) {
            printf("Enter bid amount: ");
            scanf("%lf", &amount);

            bids[num_bids].item_id = i;
            bids[num_bids].amount = amount;
            bids[num_bids].bidder_id = 0;

            for (int k = 0; k < num_bidders; k++) {
                if (strcmp(bidders[k].name, bidders[0].name) == 0) {
                    bids[num_bids].bidder_id = k + 1;
                    break;
                }
            }

            num_bids++;
            break;
        }
    }
}

void display_items() {
    int i;

    for (i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", items[i].id, items[i].name, items[i].price);
    }
}

void display_bids() {
    int i;

    for (i = 0; i < num_bids; i++) {
        printf("Bid #%d: Item %d - $%.2f by Bidder %d\n", i + 1, bids[i].item_id, bids[i].amount, bids[i].bidder_id);
    }
}

int main() {
    int choice;

    num_bidders = 0;
    num_items = 0;
    num_bids = 0;

    do {
        printf("\n1. Add Bidder\n2. Add Item\n3. Place Bid\n4. Display Items\n5. Display Bids\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_bidder();
                break;
            case 2:
                add_item();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                display_items();
                break;
            case 5:
                display_bids();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}