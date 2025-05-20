//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_BIDS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float starting_bid;
    float current_bid;
    char highest_bidder[NAME_LENGTH];
    time_t end_time;
} Item;

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int item_count = 0;
int bid_count = 0;

void addItem() {
    if (item_count >= MAX_ITEMS) {
        printf("Item limit reached!\n");
        return;
    }
    Item new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter starting bid: ");
    scanf("%f", &new_item.starting_bid);
    new_item.current_bid = new_item.starting_bid;
    strcpy(new_item.highest_bidder, "None");
    new_item.end_time = time(NULL) + 60; // auction lasts for 60 seconds
    items[item_count++] = new_item;
    printf("Item added: %s, Starting bid: %.2f\n", new_item.name, new_item.starting_bid);
}

void placeBid() {
    if (bid_count >= MAX_BIDS) {
        printf("Bid limit reached!\n");
        return;
    }
    char bidder[NAME_LENGTH];
    float amount;
    printf("Enter your name: ");
    scanf("%s", bidder);
    printf("Enter bid amount: ");
    scanf("%f", &amount);

    int auction_item;
    printf("Enter item index (0 to %d): ", item_count - 1);
    scanf("%d", &auction_item);

    if (auction_item < 0 || auction_item >= item_count) {
        printf("Invalid item index!\n");
        return;
    }

    Item *item = &items[auction_item];

    if (amount <= item->current_bid) {
        printf("Bid must be higher than the current bid of %.2f\n", item->current_bid);
        return;
    }

    if (time(NULL) > item->end_time) {
        printf("Auction for %s has ended!\n", item->name);
        return;
    }

    item->current_bid = amount;
    strcpy(item->highest_bidder, bidder);
    bids[bid_count++] = (Bid){ .name = "", .amount = amount };
    printf("Bid successful! You are now the highest bidder for %s\n", item->name);
}

void viewItems() {
    printf("\nCurrent auction items:\n");
    for (int i = 0; i < item_count; i++) {
        Item item = items[i];
        printf("Index: %d, Name: %s, Current Bid: %.2f, Highest Bidder: %s\n", 
                i, item.name, item.current_bid, item.highest_bidder);
    }
}

void checkAuctionStatus() {
    printf("\nChecking auction status:\n");
    for (int i = 0; i < item_count; i++) {
        Item item = items[i];
        if (time(NULL) > item.end_time) {
            printf("Auction for %s has ended. Final bid: %.2f by %s\n", 
                    item.name, item.current_bid, item.highest_bidder);
        } else {
            printf("Auction for %s is still ongoing.\n", item.name);
        }
    }
}

void mainMenu() {
    int choice;
    do {
        printf("\nDigital Auction System\n");
        printf("1. Add Item\n");
        printf("2. Place Bid\n");
        printf("3. View Items\n");
        printf("4. Check Auction Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: placeBid(); break;
            case 3: viewItems(); break;
            case 4: checkAuctionStatus(); break;
            case 5: printf("Exiting the auction system.\n"); break;
            default: printf("Invalid choice, try again.\n"); break;
        }
    } while (choice != 5);
}

int main() {
    mainMenu();
    return 0;
}