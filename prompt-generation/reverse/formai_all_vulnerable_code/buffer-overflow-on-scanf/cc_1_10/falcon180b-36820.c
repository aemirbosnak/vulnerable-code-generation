//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_USERS 100
#define MAX_BIDS 100

typedef struct {
    char name[50];
    int id;
} User;

typedef struct {
    char name[100];
    int id;
    int starting_price;
    int current_price;
    User* highest_bidder;
} Item;

User users[MAX_USERS];
Item items[MAX_ITEMS];

void generate_random_user(User* user) {
    strcpy(user->name, "User ");
    sprintf(user->name + 5, "%d", rand() % 1000);
    user->id = rand() % MAX_USERS;
}

void generate_random_item(Item* item) {
    strcpy(item->name, "Item ");
    sprintf(item->name + 6, "%d", rand() % 1000);
    item->id = rand() % MAX_ITEMS;
    item->starting_price = rand() % 1000;
    item->current_price = item->starting_price;
    item->highest_bidder = NULL;
}

void print_user(User user) {
    printf("Name: %s\n", user.name);
    printf("ID: %d\n", user.id);
}

void print_item(Item item) {
    printf("Name: %s\n", item.name);
    printf("ID: %d\n", item.id);
    printf("Starting Price: $%d\n", item.starting_price);
    printf("Current Price: $%d\n", item.current_price);
    if (item.highest_bidder!= NULL) {
        printf("Highest Bidder: ");
        print_user(*item.highest_bidder);
    } else {
        printf("No bids yet.\n");
    }
}

int main() {
    srand(time(NULL));

    int num_users = rand() % MAX_USERS + 1;
    int num_items = rand() % MAX_ITEMS + 1;

    printf("Welcome to the Digital Auction System!\n");
    printf("There are %d users and %d items in this auction.\n\n", num_users, num_items);

    for (int i = 0; i < num_users; i++) {
        generate_random_user(&users[i]);
        printf("User %d registered.\n", users[i].id);
    }

    for (int i = 0; i < num_items; i++) {
        generate_random_item(&items[i]);
        printf("Item %d added to the auction.\n", items[i].id);
    }

    int current_item = 0;
    while (current_item < num_items) {
        print_item(items[current_item]);
        int choice;
        printf("Press 1 to bid or any other key to continue.\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int bid_amount;
            printf("Enter your bid amount: $");
            scanf("%d", &bid_amount);

            if (items[current_item].highest_bidder == NULL || bid_amount > items[current_item].current_price) {
                items[current_item].highest_bidder = &users[rand() % MAX_USERS];
                items[current_item].current_price = bid_amount;
            }
        }

        current_item++;
        if (current_item == num_items) {
            current_item = 0;
        }
    }

    return 0;
}