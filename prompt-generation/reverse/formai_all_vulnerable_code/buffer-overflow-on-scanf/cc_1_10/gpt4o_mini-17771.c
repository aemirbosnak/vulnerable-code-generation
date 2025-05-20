//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_BIDDERS 10
#define ITEM_NAME_LENGTH 30
#define BIDDER_NAME_LENGTH 30

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int starting_price;
    int current_price;
    int highest_bidder_index;
    int is_sold;
} Item;

typedef struct {
    char name[BIDDER_NAME_LENGTH];
    int budget;
} Bidder;

Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int item_count = 0;
int bidder_count = 0;

void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Item limit reached, cannot add more items.\n");
        return;
    }
    printf("Enter item name: ");
    scanf(" %[^\n]", items[item_count].name);
    printf("Enter starting price: ");
    scanf("%d", &items[item_count].starting_price);
    items[item_count].current_price = items[item_count].starting_price;
    items[item_count].highest_bidder_index = -1;
    items[item_count].is_sold = 0;
    item_count++;
    printf("Item added successfully!\n");
}

void add_bidder() {
    if (bidder_count >= MAX_BIDDERS) {
        printf("Bidder limit reached, cannot add more bidders.\n");
        return;
    }
    printf("Enter bidder name: ");
    scanf(" %[^\n]", bidders[bidder_count].name);
    printf("Enter budget: ");
    scanf("%d", &bidders[bidder_count].budget);
    bidder_count++;
    printf("Bidder added successfully!\n");
}

void place_bid() {
    int item_index, bidder_index, bid_amount;

    printf("Available items:\n");
    for (int i = 0; i < item_count; i++) {
        if (!items[i].is_sold) {
            printf("%d. %s - Current Price: $%d\n", i + 1, items[i].name, items[i].current_price);
        }
    }
    printf("Select item index to bid on (1 to %d): ", item_count);
    scanf("%d", &item_index);
    item_index--; // Adjust for 0-based index

    if (item_index < 0 || item_index >= item_count || items[item_index].is_sold) {
        printf("Invalid item selection.\n");
        return;
    }

    printf("Available bidders:\n");
    for (int i = 0; i < bidder_count; i++) {
        printf("%d. %s - Budget: $%d\n", i + 1, bidders[i].name, bidders[i].budget);
    }
    printf("Select bidder index (1 to %d): ", bidder_count);
    scanf("%d", &bidder_index);
    bidder_index--; // Adjust for 0-based index

    if (bidder_index < 0 || bidder_index >= bidder_count) {
        printf("Invalid bidder selection.\n");
        return;
    }

    printf("Enter bid amount: ");
    scanf("%d", &bid_amount);

    if (bid_amount <= items[item_index].current_price) {
        printf("Bid must be higher than current price.\n");
        return;
    }
    if (bid_amount > bidders[bidder_index].budget) {
        printf("Bidder does not have enough budget.\n");
        return;
    }

    items[item_index].current_price = bid_amount;
    items[item_index].highest_bidder_index = bidder_index;
    bidders[bidder_index].budget -= bid_amount;
    printf("%s placed a bid of $%d on %s.\n", bidders[bidder_index].name, bid_amount, items[item_index].name);
}

void finalize_auction() {
    printf("Finalizing bids...\n");
    for (int i = 0; i < item_count; i++) {
        if (items[i].highest_bidder_index != -1) {
            items[i].is_sold = 1;
            printf("Item '%s' sold to bidder '%s' for $%d.\n", 
                    items[i].name, 
                    bidders[items[i].highest_bidder_index].name, 
                    items[i].current_price);
        } else {
            printf("Item '%s' was not sold.\n", items[i].name);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Digital Auction System ===\n");
        printf("1. Add Item\n");
        printf("2. Add Bidder\n");
        printf("3. Place Bid\n");
        printf("4. Finalize Auction\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_bidder();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                finalize_auction();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}