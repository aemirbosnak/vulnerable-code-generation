//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
/*
Program: Mind-Bending Digital Auction System
Author: AI Bot
Date: 2021-12-22
Description: This program simulates a digital auction system, in which users can bid on different items.
*/

// Header Files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_USERS 10
#define MAX_ITEMS 5

// Structures
struct item {
    char name[20];
    float base_price;
    int highest_bid;
    char highest_bidder[20];
};

struct user {
    char name[20];
    int balance;
    int num_bids;
};

// Function Prototype
void print_item_info(struct item *itm);
void print_user_info(struct user *usr);
void print_all_items(struct item *itm, int num_items);
void print_all_users(struct user *usr, int num_users);
void place_bid(struct user *usr, int num_users, struct item *itm, int num_items);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Auction Items
    struct item items[MAX_ITEMS] = {
        {"iPhone 13", 1000.0, 0, "None"},
        {"MacBook Pro", 1500.0, 0, "None"},
        {"PlayStation 5", 500.0, 0, "None"},
        {"Samsung Galaxy S21", 900.0, 0, "None"},
        {"Nintendo Switch", 300.0, 0, "None"}
    };

    // Users
    struct user users[MAX_USERS] = {
        {"John", 2000, 0},
        {"Kate", 1500, 0},
        {"Sam", 1000, 0},
        {"Mike", 500, 0},
        {"Alex", 700, 0},
        {"Lisa", 900, 0},
        {"Tom", 1200, 0},
        {"Mary", 800, 0},
        {"Ben", 600, 0},
        {"Olivia", 100, 0}
    };

    int num_items = sizeof(items)/sizeof(items[0]);
    int num_users = sizeof(users)/sizeof(users[0]);

    printf("Welcome to the Mind-Bending Digital Auction System!\n");

    while(1) {
        int choice;
        printf("\n");
        printf("Please choose an option:\n");
        printf("1. View all items\n");
        printf("2. View all users\n");
        printf("3. Place a bid\n");
        printf("4. Exit\n");
        printf("> ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_all_items(items, num_items);
                break;
            case 2:
                print_all_users(users, num_users);
                break;
            case 3:
                place_bid(users, num_users, items, num_items);
                break;
            case 4:
                printf("Thank you for using the Mind-Bending Digital Auction System! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}

void print_item_info(struct item *itm) {
    printf("%-20s $%.2f\n", itm->name, itm->base_price);
}

void print_user_info(struct user *usr) {
    printf("%-20s $%d\n", usr->name, usr->balance);
}

void print_all_items(struct item *itm, int num_items) {
    printf("All Auction Items:\n");
    for(int i = 0; i < num_items; i++) {
        printf("%d. ", i+1);
        print_item_info(&itm[i]);
    }
}

void print_all_users(struct user *usr, int num_users) {
    printf("All Users:\n");
    for(int i = 0; i < num_users; i++) {
        printf("%d. ", i+1);
        print_user_info(&usr[i]);
    }
}

void place_bid(struct user *usr, int num_users, struct item *itm, int num_items) {
    int item_choice, user_choice, bid_amount;
    printf("Please choose an item to bid on:\n");
    print_all_items(itm, num_items);
    printf("> ");
    scanf("%d", &item_choice);

    if(item_choice < 1 || item_choice > num_items) {
        printf("Invalid item choice. Please enter a valid choice.\n");
        return;
    }

    printf("Please choose a user to place the bid:\n");
    print_all_users(usr, num_users);
    printf("> ");
    scanf("%d", &user_choice);

    if(user_choice < 1 || user_choice > num_users) {
        printf("Invalid user choice. Please enter a valid choice.\n");
        return;
    }

    printf("Please enter bid amount: ");
    scanf("%d", &bid_amount);

    if(bid_amount <= itm[item_choice-1].highest_bid) {
        printf("Bid amount must be greater than the current highest bid.\n");
        return;
    }

    if(bid_amount > usr[user_choice-1].balance) {
        printf("User does not have sufficient balance to place this bid.\n");
        return;
    }

    itm[item_choice-1].highest_bid = bid_amount;
    strcpy(itm[item_choice-1].highest_bidder, usr[user_choice-1].name);
    itm[item_choice-1].base_price = bid_amount;

    usr[user_choice-1].balance -= bid_amount;
    usr[user_choice-1].num_bids++;

    int random_user = rand() % num_users;
    usr[random_user].balance += bid_amount;

    printf("Bid placed successfully!\n");
    printf("%s is the current highest bidder for %s with a bid of $%d.\n", itm[item_choice-1].highest_bidder, itm[item_choice-1].name, itm[item_choice-1].highest_bid);
    printf("%s has been charged $%d for the bid.\n", usr[user_choice-1].name, bid_amount);
    printf("The winning bidder will be randomly selected at the end of the auction.\n");
}