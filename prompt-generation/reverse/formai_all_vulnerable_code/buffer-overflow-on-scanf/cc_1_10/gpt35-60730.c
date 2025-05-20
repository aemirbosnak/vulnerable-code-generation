//FormAI DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define BIDDING_TIME 5

struct Item {
    char name[50];
    int starting_price;
    int current_bid;
    int time_remaining;
    char highest_bidder[50];
} items[MAX_ITEMS];

int num_items = 0;

void add_item() {
    if (num_items < MAX_ITEMS) {
        printf("Enter item name: ");
        scanf("%s", items[num_items].name);
        printf("Enter starting price: ");
        scanf("%d", &items[num_items].starting_price);
        items[num_items].current_bid = items[num_items].starting_price;
        items[num_items].time_remaining = BIDDING_TIME;
        strcpy(items[num_items].highest_bidder, "None");
        num_items++;
    } else {
        printf("Maximum number of items reached.\n");
    }
}

void display_items() {
    printf("Item\tStarting price\tCurrent bid\tTime remaining\tHighest bidder\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t$%d\t\t$%d\t\t%d seconds\t%s\n", 
            items[i].name, items[i].starting_price, items[i].current_bid, items[i].time_remaining,
            items[i].highest_bidder);
    }
}

void bid() {
    int item_num, bid_amount;
    printf("Enter item number: ");
    scanf("%d", &item_num);
    if (item_num > 0 && item_num <= num_items) {
        printf("Enter bid amount: ");
        scanf("%d", &bid_amount);
        if (bid_amount > items[item_num-1].current_bid) {
            items[item_num-1].current_bid = bid_amount;
            printf("Bid accepted.\n");
            printf("Enter bidder name: ");
            scanf("%s", items[item_num-1].highest_bidder);
        } else {
            printf("Bid not high enough.\n");
        }
    } else {
        printf("Invalid item number.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add item\n2. Display items\n3. Bid\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                bid();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
        for (int i = 0; i < num_items; i++) {
            if (items[i].time_remaining > 0) {
                items[i].time_remaining--;
                if (items[i].time_remaining == 0) {
                    printf("Bidding for %s has ended.\n", items[i].name);
                    printf("Highest bidder: %s\n", items[i].highest_bidder);
                }
            }
        }
    } while (1);
    return 0;
}