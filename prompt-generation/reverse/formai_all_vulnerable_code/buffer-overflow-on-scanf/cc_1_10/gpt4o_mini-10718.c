//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_BIDS_PER_ITEM 10
#define ITEM_NAME_LENGTH 50
#define USERNAME_LENGTH 50

typedef struct {
    char username[USERNAME_LENGTH];
    double amount;
} Bid;

typedef struct {
    char name[ITEM_NAME_LENGTH];
    double starting_price;
    double current_price;
    Bid bids[MAX_BIDS_PER_ITEM];
    int bid_count;
    bool active;
} AuctionItem;

void addItem(AuctionItem *items, int *item_count) {
    printf("Enter item name: ");
    scanf("%s", items[*item_count].name);
    printf("Enter starting price: ");
    scanf("%lf", &items[*item_count].starting_price);
    items[*item_count].current_price = items[*item_count].starting_price;
    items[*item_count].bid_count = 0;
    items[*item_count].active = true;
    (*item_count)++;
    printf("Item added successfully!\n");
}

void placeBid(AuctionItem *items, int item_count) {
    int index;
    char username[USERNAME_LENGTH];
    double bid_amount;

    printf("Enter item index to place bid (0-%d): ", item_count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= item_count || !items[index].active) {
        printf("Invalid item index.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter your bid amount: ");
    scanf("%lf", &bid_amount);

    if (bid_amount <= items[index].current_price) {
        printf("Bid must be higher than the current price of %.2lf.\n", items[index].current_price);
        return;
    }
    
    if (items[index].bid_count >= MAX_BIDS_PER_ITEM) {
        printf("No more bids can be accepted for this item.\n");
        return;
    }

    Bid new_bid;
    strcpy(new_bid.username, username);
    new_bid.amount = bid_amount;
    items[index].bids[items[index].bid_count++] = new_bid;
    items[index].current_price = bid_amount;
    printf("Bid placed successfully!\n");
}

void viewAuctions(AuctionItem *items, int item_count) {
    for (int i = 0; i < item_count; i++) {
        printf("Item %d: %s\n", i, items[i].name);
        if (items[i].active) {
            printf("Starting Price: %.2lf, Current Price: %.2lf, Bids: %d\n",
                items[i].starting_price, items[i].current_price, items[i].bid_count);
        } else {
            printf("This auction has ended.\n");
        }
        printf("\n");
    }
}

void endAuction(AuctionItem *items, int item_count) {
    int index;
    printf("Enter item index to end auction (0-%d): ", item_count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= item_count) {
        printf("Invalid item index.\n");
        return;
    }

    items[index].active = false;
    printf("Auction for item %s has ended. Final price: %.2lf\n", items[index].name, items[index].current_price);
}

int main() {
    AuctionItem items[MAX_ITEMS];
    int item_count = 0;
    int choice;

    while (1) {
        printf("Digital Auction System\n");
        printf("1. Add Item\n");
        printf("2. Place Bid\n");
        printf("3. View Auctions\n");
        printf("4. End Auction\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (item_count < MAX_ITEMS) {
                    addItem(items, &item_count);
                } else {
                    printf("Cannot add more items.\n");
                }
                break;
            case 2:
                placeBid(items, item_count);
                break;
            case 3:
                viewAuctions(items, item_count);
                break;
            case 4:
                endAuction(items, item_count);
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}