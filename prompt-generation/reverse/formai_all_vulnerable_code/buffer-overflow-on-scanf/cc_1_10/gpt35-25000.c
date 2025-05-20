//FormAI DATASET v1.0 Category: Digital Auction System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Item {
    char name[50];
    char description[100];
    int starting_bid;
    int current_bid;
    char bidder_name[50];
    int time_left;
    int owner_id;
    int sold;
} items[10];

struct User {
    char name[50];
    int id;
    int balance;
} users[10];

int num_items = 0;
int num_users = 0;

void add_item(char *name, char *description, int starting_bid, int owner_id) {
    strcpy(items[num_items].name, name);
    strcpy(items[num_items].description, description);
    items[num_items].starting_bid = starting_bid;
    items[num_items].current_bid = starting_bid;
    items[num_items].time_left = 10;
    items[num_items].owner_id = owner_id;
    items[num_items].sold = 0;
    num_items++;
}

int find_user(char *name) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void create_user(char *name, int balance) {
    strcpy(users[num_users].name, name);
    users[num_users].id = num_users;
    users[num_users].balance = balance;
    num_users++;
}

void bid(char *name, int item_num, int bid_amount) {
    int user_id = find_user(name);
    if (users[user_id].balance >= bid_amount && bid_amount > items[item_num].current_bid) {
        users[user_id].balance -= bid_amount;
        if (items[item_num].current_bid != items[item_num].starting_bid) {
            users[find_user(items[item_num].bidder_name)].balance += items[item_num].current_bid;
        }
        items[item_num].current_bid = bid_amount;
        strcpy(items[item_num].bidder_name, name);
    }
}

void print_current_bids() {
    for (int i = 0; i < num_items; i++) {
        if (!items[i].sold) {
            printf("Item #%d: %s\n", i, items[i].name);
            printf("Current Bid: %d\n", items[i].current_bid);
            printf("Time Left: %d minutes\n", items[i].time_left);
            printf("Description: %s\n", items[i].description);
            printf("-----------------------------\n");
        }
    }
}

void sell_item(int item_num) {
    items[item_num].owner_id = -1;
    items[item_num].sold = 1;
    users[find_user(items[item_num].bidder_name)].balance -= items[item_num].current_bid;
    users[items[item_num].owner_id].balance += items[item_num].current_bid;
}

void run_auction() {
    while (1) {
        if (num_items == 0) {
            printf("No items to auction.\n");
            break;
        }
        print_current_bids();
        printf("Enter item number to bid on or -1 to exit: ");
        int choice;
        scanf("%d", &choice);
        if (choice == -1) {
            break;
        }
        char name[50];
        printf("Enter your name: ");
        scanf("%s", name);
        int bid_amount;
        printf("Enter bid amount: ");
        scanf("%d", &bid_amount);
        bid(name, choice, bid_amount);
        items[choice].time_left--;
        if (items[choice].time_left == 0) {
            sell_item(choice);
        }
    }
}

int main() {
    int ch;
    char name[50];
    int balance, starting_bid, owner_id;
    char description[100];
    while(1) {
        printf("1. Create User\n");
        printf("2. Add Item\n");
        printf("3. Start Auction\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter user name: ");
                scanf("%s", name);
                printf("Enter balance: ");
                scanf("%d", &balance);
                create_user(name, balance);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item description: ");
                scanf("%s", description);
                printf("Enter starting bid: ");
                scanf("%d", &starting_bid);
                printf("Enter owner id: ");
                scanf("%d", &owner_id);
                add_item(name, description, starting_bid, owner_id);
                break;
            case 3:
                run_auction();
                break;
            case 4:
                return 0;
        }
    }
}