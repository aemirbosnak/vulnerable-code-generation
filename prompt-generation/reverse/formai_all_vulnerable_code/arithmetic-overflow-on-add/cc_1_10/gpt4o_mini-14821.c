//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_ITEMS 100
#define USERNAME_LEN 30
#define ITEM_NAME_LEN 50

typedef struct {
    char name[ITEM_NAME_LEN];
    float starting_price;
    float current_bid;
    char highest_bidder[USERNAME_LEN];
    time_t end_time;
    int is_active;
} AuctionItem;

typedef struct {
    char username[USERNAME_LEN];
    int user_id;
} User;

User users[MAX_USERS];
int user_count = 0;

AuctionItem items[MAX_ITEMS];
int item_count = 0;

void addUser(const char *username) {
    if (user_count < MAX_USERS) {
        strcpy(users[user_count].username, username);
        users[user_count].user_id = user_count;
        user_count++;
    } else {
        printf("User limit reached!\n");
    }
}

void addItem(const char *name, float starting_price, int duration) {
    if (item_count < MAX_ITEMS) {
        strcpy(items[item_count].name, name);
        items[item_count].starting_price = starting_price;
        items[item_count].current_bid = starting_price;
        strcpy(items[item_count].highest_bidder, "No bids yet");
        items[item_count].end_time = time(NULL) + duration;
        items[item_count].is_active = 1;
        item_count++;
    } else {
        printf("Item limit reached!\n");
    }
}

void placeBid(int user_id, int item_id, float bid_amount) {
    if (item_id < item_count && items[item_id].is_active) {
        if (time(NULL) < items[item_id].end_time) {
            if (bid_amount > items[item_id].current_bid) {
                items[item_id].current_bid = bid_amount;
                sprintf(items[item_id].highest_bidder, "%s", users[user_id].username);
                printf("Bid placed successfully by %s!\n", users[user_id].username);
            } else {
                printf("Bid must be higher than the current bid!\n");
            }
        } else {
            printf("Auction for %s has already ended.\n", items[item_id].name);
        }
    } else {
        printf("Invalid item ID or the item is not active.\n");
    }
}

void endAuction(int item_id) {
    if (item_id < item_count && items[item_id].is_active) {
        items[item_id].is_active = 0;
        printf("Auction for %s ended. Highest bid was made by %s at %.2f\n",
               items[item_id].name, items[item_id].highest_bidder, items[item_id].current_bid);
    } else {
        printf("Invalid item ID or the auction is already ended.\n");
    }
}

void showActiveAuctions() {
    printf("\nActive Auctions:\n");
    for (int i = 0; i < item_count; i++) {
        if (items[i].is_active) {
            printf("Item %d: %s, Starting Price: %.2f, Current Bid: %.2f, Highest Bidder: %s\n",
                   i, items[i].name, items[i].starting_price, items[i].current_bid, items[i].highest_bidder);
        }
    }
}

int main() {
    addUser("Alice");
    addUser("Bob");
    addUser("Charlie");

    addItem("Laptop", 1000.00, 30);
    addItem("Smartphone", 500.00, 60);
    addItem("Watch", 150.00, 45);

    showActiveAuctions();

    placeBid(0, 0, 1050.00); // Alice bids on Laptop
    placeBid(1, 0, 1100.00); // Bob outbids Alice
    placeBid(2, 1, 550.00);  // Charlie bids on Smartphone

    showActiveAuctions();

    // Wait for 2 seconds to simulate auction duration passing
    sleep(2);

    // End auction for Laptop
    endAuction(0);

    // Show all auctions
    showActiveAuctions();

    return 0;
}