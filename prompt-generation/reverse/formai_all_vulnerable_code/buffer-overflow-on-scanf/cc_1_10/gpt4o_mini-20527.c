//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    char username[50];
    int user_id;
} User;

typedef struct {
    char item_name[100];
    float starting_price;
    float current_price;
    char highest_bidder[50];
    int item_id;
} Item;

typedef struct {
    char username[50];
    float amount;
} Bid;

User users[MAX_USERS];
Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];

int user_count = 0;
int item_count = 0;
int bid_count = 0;

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }
    
    printf("Enter username: ");
    scanf("%s", users[user_count].username);
    users[user_count].user_id = user_count + 1;
    user_count++;
    
    printf("User registered successfully! User ID: %d\n", users[user_count - 1].user_id);
}

void create_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Item limit reached. Cannot create more items.\n");
        return;
    }
    
    printf("Enter item name: ");
    scanf("%s", items[item_count].item_name);
    printf("Enter starting price: ");
    scanf("%f", &items[item_count].starting_price);
    items[item_count].current_price = items[item_count].starting_price;
    strcpy(items[item_count].highest_bidder, "None");
    items[item_count].item_id = item_count + 1;
    item_count++;
    
    printf("Item created successfully! Item ID: %d\n", items[item_count - 1].item_id);
}

void place_bid() {
    if (bid_count >= MAX_BIDS) {
        printf("Bid limit reached. Cannot place more bids.\n");
        return;
    }
    
    int item_id;
    float bid_amount;
    
    printf("Enter item ID to bid on: ");
    scanf("%d", &item_id);
    
    if (item_id < 1 || item_id > item_count) {
        printf("Invalid item ID.\n");
        return;
    }
    
    printf("Enter your username: ");
    scanf("%s", bids[bid_count].username);
    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);
    
    if (bid_amount <= items[item_id - 1].current_price) {
        printf("Bid amount must be higher than the current price of the item: %.2f\n", items[item_id - 1].current_price);
        return;
    }
    
    items[item_id - 1].current_price = bid_amount;
    strcpy(items[item_id - 1].highest_bidder, bids[bid_count].username);
    bids[bid_count].amount = bid_amount;
    bid_count++;
    
    printf("Bid placed successfully! Current highest bid: %.2f by %s\n", items[item_id - 1].current_price, items[item_id - 1].highest_bidder);
}

void view_items() {
    if (item_count == 0) {
        printf("No items available for auction.\n");
        return;
    }
    
    printf("Items available for auction:\n");
    for (int i = 0; i < item_count; i++) {
        printf("ID: %d, Name: %s, Current Price: %.2f, Highest Bidder: %s\n",
               items[i].item_id, items[i].item_name, items[i].current_price, items[i].highest_bidder);
    }
}

void start_auction_system() {
    int choice;
    do {
        printf("\nDigital Auction System\n");
        printf("1. Register User\n");
        printf("2. Create Item\n");
        printf("3. Place Bid\n");
        printf("4. View Items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                create_item();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                view_items();
                break;
            case 5:
                printf("Exiting Auction System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    start_auction_system();
    return 0;
}