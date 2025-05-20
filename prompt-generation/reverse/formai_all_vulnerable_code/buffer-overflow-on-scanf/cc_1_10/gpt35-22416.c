//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_USERS 100
#define MAX_ITEMS 100
#define MAX_BIDS 1000

/* Structs */

typedef struct user {
    int id;
    char name[50];
    float balance;
} User;

typedef struct item {
    int id;
    char name[50];
    char description[100];
    float start_price;
    float current_price;
    int current_bidder_id;
} Item;

typedef struct bid {
    int id;
    int user_id;
    int item_id;
    float amount;
} Bid;

/* Global Variables */

User users[MAX_USERS];
Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];

int num_users = 0;
int num_items = 0;
int num_bids = 0;

pthread_mutex_t mutex;

/* Functions */

void printMenu() {
    printf("\n");
    printf("1: Add User\n");
    printf("2: Add Item\n");
    printf("3: List Users\n");
    printf("4: List Items\n");
    printf("5: Start Auction\n");
    printf("6: List Bids\n");
    printf("0: Exit\n");
    printf("\n");
}

void addUser() {
    printf("Enter user name: ");
    char name[50];
    scanf("%s", name);

    printf("Enter balance: ");
    float balance;
    scanf("%f", &balance);

    User newUser;
    newUser.id = num_users;
    strcpy(newUser.name, name);
    newUser.balance = balance;

    users[num_users] = newUser;
    num_users++;

    printf("User added successfully!\n");
}

void addItem() {
    printf("Enter item name: ");
    char name[50];
    scanf("%s", name);

    printf("Enter description: ");
    char description[100];
    scanf("%s", description);

    printf("Enter starting price: ");
    float start_price;
    scanf("%f", &start_price);

    Item newItem;
    newItem.id = num_items;
    strcpy(newItem.name, name);
    strcpy(newItem.description, description);
    newItem.start_price = start_price;
    newItem.current_price = start_price;
    newItem.current_bidder_id = -1;

    items[num_items] = newItem;
    num_items++;

    printf("Item added successfully!\n");
}

void listUsers() {
    printf("Users:\n");
    for(int i = 0; i < num_users; i++) {
        User currentUser = users[i];
        printf("%d: %s (Balance: %.2f)\n", currentUser.id, currentUser.name, currentUser.balance);
    }
}

void listItems() {
    printf("Items:\n");
    for(int i = 0; i < num_items; i++) {
        Item currentItem = items[i];
        printf("%d: %s (%.2f) - %s\n", currentItem.id, currentItem.name, currentItem.current_price, currentItem.description);
    }
}

void *auctionThread(void *data) {
    int *item_id_ptr = (int*) data;
    int item_id = *item_id_ptr;
    Item currentItem = items[item_id];

    pthread_mutex_lock(&mutex);

    printf("Starting auction for %s...\n", currentItem.name);
    printf("Starting price: %.2f\n", currentItem.start_price);

    while(1) {
        printf("Enter bid amount (0 to exit auction): ");
        float bid_amount;
        scanf("%f", &bid_amount);

        if(bid_amount <= 0) {
            printf("Auction ended.\n");
            break;
        }

        if(bid_amount <= currentItem.current_price) {
            printf("Bid amount must be higher than the current price (%.2f).\n", currentItem.current_price);
        } else {
            printf("Bid accepted.\n");

            int current_bidder_id = currentItem.current_bidder_id;
            if(current_bidder_id != -1) {
                User currentBidder = users[current_bidder_id];
                currentBidder.balance += currentItem.current_price;
                users[current_bidder_id] = currentBidder;
            }

            currentItem.current_price = bid_amount;
            currentItem.current_bidder_id = num_bids;

            Bid newBid;
            newBid.id = num_bids;
            newBid.user_id = num_users;
            newBid.item_id = item_id;
            newBid.amount = bid_amount;

            bids[num_bids] = newBid;
            num_bids++;

            User newBidder = users[num_users];
            newBidder.balance -= bid_amount;
            users[num_users] = newBidder;

            num_users++;

            printf("New current price: %.2f\n", currentItem.current_price);
        }
    }

    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

void startAuction() {
    printf("Enter item ID: ");
    int item_id;
    scanf("%d", &item_id);

    pthread_t auction_thread;
    pthread_create(&auction_thread, NULL, auctionThread, &item_id);
    pthread_join(auction_thread, NULL);
}

void listBids() {
    printf("Bids:\n");
    for(int i = 0; i < num_bids; i++) {
        Bid currentBid = bids[i];
        User currentBidder = users[currentBid.user_id];
        Item currentItem = items[currentBid.item_id];
        printf("%s bid %.2f on %s (current price: %.2f)\n", currentBidder.name, currentBid.amount, currentItem.name, currentItem.current_price);
    }
}

/* Main Function */

int main() {
    printf("Welcome to the Digital Auction System!\n");

    int option = -1;

    while(option != 0) {
        printMenu();

        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addUser();
                break;
            case 2:
                addItem();
                break;
            case 3:
                listUsers();
                break;
            case 4:
                listItems();
                break;
            case 5:
                startAuction();
                break;
            case 6:
                listBids();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}