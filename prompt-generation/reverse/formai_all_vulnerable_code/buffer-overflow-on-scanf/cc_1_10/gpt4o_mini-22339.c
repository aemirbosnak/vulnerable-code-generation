//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50
#define USER_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float starting_bid;
    float current_bid;
    char highest_bidder[USER_NAME_LENGTH];
    time_t end_time;
} AuctionItem;

typedef struct {
    char username[USER_NAME_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

AuctionItem auction_items[MAX_ITEMS];
int item_count = 0;

void create_auction_item() {
    if(item_count >= MAX_ITEMS) {
        printf("Maximum items reached!\n");
        return;
    }

    AuctionItem item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter starting bid: ");
    scanf("%f", &item.starting_bid);
    item.current_bid = item.starting_bid;
    strcpy(item.highest_bidder, "None");

    printf("Enter auction duration in seconds: ");
    int duration;
    scanf("%d", &duration);
    item.end_time = time(NULL) + duration;

    auction_items[item_count++] = item;
    printf("Auction item created successfully!\n");
}

void register_user() {
    if(user_count >= MAX_USERS) {
        printf("Maximum users reached!\n");
        return;
    }

    User user;
    printf("Enter your username: ");
    scanf("%s", user.username);
    
    users[user_count++] = user;
    printf("User registered successfully!\n");
}

void place_bid() {
    char username[USER_NAME_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);

    int item_index;
    printf("Enter item number to bid on (0 to %d): ", item_count - 1);
    scanf("%d", &item_index);

    if(item_index < 0 || item_index >= item_count) {
        printf("Invalid item number!\n");
        return;
    }

    AuctionItem *item = &auction_items[item_index];
    
    if(time(NULL) > item->end_time) {
        printf("Auction for this item has ended!\n");
        return;
    }

    float bid_amount;
    printf("Enter your bid (current bid is %.2f): ", item->current_bid);
    scanf("%f", &bid_amount);

    if(bid_amount <= item->current_bid) {
        printf("Bid must be higher than current bid!\n");
        return;
    }

    item->current_bid = bid_amount;
    strcpy(item->highest_bidder, username);
    printf("Bid placed successfully! Current highest bid is %.2f by %s.\n", item->current_bid, item->highest_bidder);
}

void view_auction_items() {
    for(int i = 0; i < item_count; i++) {
        AuctionItem item = auction_items[i];
        printf("Item %d: %s\n", i, item.name);
        printf("Starting Bid: %.2f\n", item.starting_bid);
        printf("Current Bid: %.2f\n", item.current_bid);
        printf("Highest Bidder: %s\n", item.highest_bidder);
        printf("Auction Ends At: %s", ctime(&item.end_time));
        printf("--------------------------\n");
    }
}

void show_menu() {
    printf("Digital Auction System\n");
    printf("1. Register User\n");
    printf("2. Create Auction Item\n");
    printf("3. Place Bid\n");
    printf("4. View Auction Items\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    do {
        show_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                register_user();
                break;
            case 2:
                create_auction_item();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                view_auction_items();
                break;
            case 5:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}