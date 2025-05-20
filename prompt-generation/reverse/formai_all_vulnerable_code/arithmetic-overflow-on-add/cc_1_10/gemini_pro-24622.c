//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Item struct
typedef struct Item {
    int id;
    char *name;
    float starting_price;
    float current_price;
    int highest_bidder;
    time_t end_time;
} Item;

// Bid struct
typedef struct Bid {
    int bidder_id;
    float amount;
    time_t timestamp;
} Bid;

// User struct
typedef struct User {
    int id;
    char *username;
    float balance;
} User;

// Create new item
Item *new_item(int id, char *name, float starting_price, time_t end_time) {
    Item *item = malloc(sizeof(Item));
    item->id = id;
    item->name = strdup(name);
    item->starting_price = starting_price;
    item->current_price = starting_price;
    item->highest_bidder = -1;
    item->end_time = end_time;
    return item;
}

// Create new bid
Bid *new_bid(int bidder_id, float amount) {
    Bid *bid = malloc(sizeof(Bid));
    bid->bidder_id = bidder_id;
    bid->amount = amount;
    bid->timestamp = time(NULL);
    return bid;
}

// Create new user
User *new_user(int id, char *username, float balance) {
    User *user = malloc(sizeof(User));
    user->id = id;
    user->username = strdup(username);
    user->balance = balance;
    return user;
}

// Print item
void print_item(Item *item) {
    printf("Item ID: %d\n", item->id);
    printf("Name: %s\n", item->name);
    printf("Starting Price: %.2f\n", item->starting_price);
    printf("Current Price: %.2f\n", item->current_price);
    printf("Highest Bidder: %d\n", item->highest_bidder);
    printf("End Time: %s\n", ctime(&item->end_time));
}

// Print bid
void print_bid(Bid *bid) {
    printf("Bidder ID: %d\n", bid->bidder_id);
    printf("Amount: %.2f\n", bid->amount);
    printf("Timestamp: %s\n", ctime(&bid->timestamp));
}

// Print user
void print_user(User *user) {
    printf("User ID: %d\n", user->id);
    printf("Username: %s\n", user->username);
    printf("Balance: %.2f\n", user->balance);
}

// Main function
int main() {
    // Create some items
    Item *item1 = new_item(1, "iPhone 13", 999.99, time(NULL) + 86400);
    Item *item2 = new_item(2, "MacBook Pro", 1999.99, time(NULL) + 86400);
    Item *item3 = new_item(3, "Apple Watch", 399.99, time(NULL) + 86400);

    // Create some bids
    Bid *bid1 = new_bid(1, 1000.00);
    Bid *bid2 = new_bid(2, 1200.00);
    Bid *bid3 = new_bid(3, 1500.00);

    // Create some users
    User *user1 = new_user(1, "alice", 1000.00);
    User *user2 = new_user(2, "bob", 2000.00);
    User *user3 = new_user(3, "charlie", 3000.00);

    // Print the items
    printf("Items:\n");
    print_item(item1);
    print_item(item2);
    print_item(item3);

    // Print the bids
    printf("\nBids:\n");
    print_bid(bid1);
    print_bid(bid2);
    print_bid(bid3);

    // Print the users
    printf("\nUsers:\n");
    print_user(user1);
    print_user(user2);
    print_user(user3);

    return 0;
}