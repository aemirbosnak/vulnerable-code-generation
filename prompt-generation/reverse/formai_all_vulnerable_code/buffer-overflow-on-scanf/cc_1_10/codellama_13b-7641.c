//Code Llama-13B DATASET v1.0 Category: Digital Auction System ; Style: standalone
/*
 *  Digital Auction System
 *
 *  A program that allows users to bid on digital items.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_USERS 1000

typedef struct {
    char name[50];
    int bids[MAX_ITEMS];
    int balance;
} User;

typedef struct {
    char name[50];
    int price;
    int quantity;
} Item;

void print_menu();
void add_user(User* users, int* num_users);
void add_item(Item* items, int* num_items);
void bid(User* users, int* num_users, Item* items, int* num_items);
void end_auction(User* users, int num_users, Item* items, int num_items);

int main() {
    User users[MAX_USERS];
    Item items[MAX_ITEMS];
    int num_users = 0;
    int num_items = 0;

    print_menu();

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user(users, &num_users);
                break;
            case 2:
                add_item(items, &num_items);
                break;
            case 3:
                bid(users, &num_users, items, &num_items);
                break;
            case 4:
                end_auction(users, num_users, items, num_items);
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

void print_menu() {
    printf("---------------------------------\n");
    printf("Digital Auction System\n");
    printf("---------------------------------\n");
    printf("1. Add User\n");
    printf("2. Add Item\n");
    printf("3. Bid\n");
    printf("4. End Auction\n");
    printf("---------------------------------\n");
}

void add_user(User* users, int* num_users) {
    printf("Enter user name: ");
    scanf("%s", users[*num_users].name);
    users[*num_users].balance = 0;
    *num_users += 1;
}

void add_item(Item* items, int* num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: ");
    scanf("%d", &items[*num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].quantity);
    *num_items += 1;
}

void bid(User* users, int* num_users, Item* items, int* num_items) {
    int user_id;
    int item_id;
    int bid_amount;

    printf("Enter user ID: ");
    scanf("%d", &user_id);
    printf("Enter item ID: ");
    scanf("%d", &item_id);
    printf("Enter bid amount: ");
    scanf("%d", &bid_amount);

    if (user_id >= 0 && user_id < *num_users && item_id >= 0 && item_id < *num_items) {
        if (users[user_id].balance >= bid_amount) {
            users[user_id].balance -= bid_amount;
            items[item_id].price = bid_amount;
            printf("Bid placed successfully.\n");
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Invalid user or item ID.\n");
    }
}

void end_auction(User* users, int num_users, Item* items, int num_items) {
    printf("Auction ended.\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s has %d items.\n", users[i].name, users[i].bids[i]);
    }
    for (int i = 0; i < num_items; i++) {
        printf("%s has been sold for %d.\n", items[i].name, items[i].price);
    }
}