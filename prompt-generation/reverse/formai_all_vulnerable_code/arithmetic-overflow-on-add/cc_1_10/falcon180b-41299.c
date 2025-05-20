//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 1000
#define MAX_USERS 100
#define MAX_ITEM_NAME 100
#define MAX_USER_NAME 50

typedef struct {
    char name[MAX_ITEM_NAME];
    int price;
    int highest_bid;
    int highest_bidder;
    time_t end_time;
    int sold;
} item;

typedef struct {
    char name[MAX_USER_NAME];
    int balance;
} user;

item items[MAX_ITEMS];
user users[MAX_USERS];
int num_items = 0;
int num_users = 0;

void create_item(char* name, int price, time_t end_time) {
    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    items[num_items].highest_bid = 0;
    items[num_items].highest_bidder = -1;
    items[num_items].end_time = end_time;
    items[num_items].sold = 0;
    num_items++;
}

void create_user(char* name, int balance) {
    strcpy(users[num_users].name, name);
    users[num_users].balance = balance;
    num_users++;
}

void place_bid(int item_index, int bid_amount, int user_index) {
    if(items[item_index].highest_bid < bid_amount) {
        items[item_index].highest_bid = bid_amount;
        items[item_index].highest_bidder = user_index;
    }
}

void end_auction(int item_index) {
    if(items[item_index].highest_bid > 0) {
        items[item_index].sold = 1;
        users[items[item_index].highest_bidder].balance -= items[item_index].highest_bid;
    }
}

int main() {
    create_item("iPhone X", 1000, time(NULL) + 3600);
    create_item("MacBook Pro", 2000, time(NULL) + 7200);
    create_user("John Doe", 5000);
    create_user("Jane Smith", 10000);

    place_bid(0, 1500, 0);
    place_bid(0, 2500, 1);
    place_bid(1, 3000, 0);

    end_auction(0);

    return 0;
}