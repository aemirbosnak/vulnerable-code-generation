//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 100
#define MAX_USERS 50
#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float max_bid;
} User;

typedef struct {
    char item_name[MAX_NAME_LENGTH];
    float starting_price;
    float current_price;
    User highest_bidder;
    time_t end_time;
} AuctionItem;

User users[MAX_USERS];
AuctionItem items[MAX_ITEMS];
int user_count = 0;
int item_count = 0;

void addUser(char *name) {
    if (user_count < MAX_USERS) {
        strcpy(users[user_count].name, name);
        users[user_count].max_bid = 0;
        user_count++;
    } else {
        printf("Max users reached!\n");
    }
}

void addItem(char *item_name, float starting_price, time_t duration) {
    if (item_count < MAX_ITEMS) {
        strcpy(items[item_count].item_name, item_name);
        items[item_count].starting_price = starting_price;
        items[item_count].current_price = starting_price;
        items[item_count].highest_bidder.max_bid = 0;
        items[item_count].end_time = time(NULL) + duration;
        item_count++;
    } else {
        printf("Max items reached!\n");
    }
}

void placeBid(int user_index, int item_index, float bid_amount) {
    if (item_index < 0 || item_index >= item_count) {
        printf("Invalid item index.\n");
        return;
    }
    if (user_index < 0 || user_index >= user_count) {
        printf("Invalid user index.\n");
        return;
    }

    AuctionItem *item = &items[item_index];
    
    if (time(NULL) > item->end_time) {
        printf("Bidding for %s has ended.\n", item->item_name);
        return;
    }

    if (bid_amount <= item->current_price) {
        printf("Bid must be higher than the current price.\n");
        return;
    }

    item->current_price = bid_amount;
    users[user_index].max_bid = bid_amount;
    item->highest_bidder = users[user_index];
    printf("%s placed a bid of %.2f on %s\n", users[user_index].name, bid_amount, item->item_name);
}

void closeAuction(int item_index) {
    if (item_index < 0 || item_index >= item_count) {
        printf("Invalid item index.\n");
        return;
    }

    AuctionItem *item = &items[item_index];

    if (time(NULL) <= item->end_time) {
        printf("Auction for %s is still active.\n", item->item_name);
        return;
    }

    if (item->highest_bidder.max_bid > 0) {
        printf("Auction for %s closed. Highest bidder: %s with bid: %.2f\n", 
               item->item_name, 
               item->highest_bidder.name, 
               item->highest_bidder.max_bid);
    } else {
        printf("Auction for %s closed. No bids placed.\n", item->item_name);
    }
}

void displayItems() {
    for (int i = 0; i < item_count; i++) {
        AuctionItem *item = &items[i];
        printf("Item %d: %s | Starting Price: %.2f | Current Price: %.2f | Ends in: %ld seconds\n", 
               i, 
               item->item_name, 
               item->starting_price, 
               item->current_price, 
               (long)(item->end_time - time(NULL)));
    }
}

void auctionMenu() {
    int choice;
    char name[MAX_NAME_LENGTH];
    float price;
    int user_index, item_index;

    while (1) {
        printf("\n--- Digital Auction System ---\n");
        printf("1. Add User\n");
        printf("2. Add Auction Item\n");
        printf("3. Place Bid\n");
        printf("4. Close Auction\n");
        printf("5. Display Items\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter user name: ");
                scanf("%s", name);
                addUser(name);
                break;
            case 2:
                printf("Enter item name and starting price: ");
                scanf("%s %f", name, &price);
                addItem(name, price, 60); // 1 minute auction
                break;
            case 3:
                printf("Enter user index and item index and bid amount: ");
                scanf("%d %d %f", &user_index, &item_index, &price);
                placeBid(user_index, item_index, price);
                break;
            case 4:
                printf("Enter item index to close auction: ");
                scanf("%d", &item_index);
                closeAuction(item_index);
                break;
            case 5:
                displayItems();
                break;
            case 6:
                printf("Exiting Auction System.\n");
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    auctionMenu();
    return 0;
}