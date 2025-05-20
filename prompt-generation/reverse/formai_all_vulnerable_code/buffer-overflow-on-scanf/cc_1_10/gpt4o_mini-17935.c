//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_ITEMS 100
#define MAX_BIDS 10
#define PASSWORD_HASH_LENGTH 64

typedef struct {
    char username[30];
    char password_hash[PASSWORD_HASH_LENGTH];
    int logged_in;
} User;

typedef struct {
    char item_name[50];
    float starting_bid;
    float highest_bid;
    char highest_bidder[30];
    time_t end_time;
} AuctionItem;

User users[MAX_USERS];
int user_count = 0;
AuctionItem items[MAX_ITEMS];
int item_count = 0;

void hash_password(const char *password, char *output_hash) {
    // Simple hash implementation for demonstration (not secure).
    snprintf(output_hash, PASSWORD_HASH_LENGTH, "%lx", (uintptr_t)password);
}

int register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return -1;
    }
    
    User new_user;
    printf("Enter username: ");
    scanf("%s", new_user.username);
    
    printf("Enter password: ");
    char password[30];
    scanf("%s", password);
    hash_password(password, new_user.password_hash);
    new_user.logged_in = 0; // Set user as logged out

    users[user_count++] = new_user;
    printf("User registered successfully!\n");
    return 0;
}

User *login_user() {
    char username[30], password[30];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password_hash, password) == 0) {
            users[i].logged_in = 1;
            printf("Login successful!\n");
            return &users[i];
        }
    }
    printf("Invalid login credentials.\n");
    return NULL;
}

void list_items() {
    if (item_count == 0) {
        printf("No items available for auction.\n");
        return;
    }
    
    for (int i = 0; i < item_count; i++) {
        printf("Item %d: %s, Starting Bid: %.2f, Highest Bid: %.2f, Highest Bidder: %s\n", 
                i + 1, items[i].item_name, items[i].starting_bid, items[i].highest_bid, items[i].highest_bidder);
    }
}

int create_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Item limit reached. Cannot add more items.\n");
        return -1;
    }
    
    AuctionItem new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.item_name);
    
    printf("Enter starting bid: ");
    scanf("%f", &new_item.starting_bid);
    
    new_item.highest_bid = new_item.starting_bid;
    new_item.highest_bidder[0] = '\0'; // No bids yet
    new_item.end_time = time(NULL) + 3600; // Auction ends in 1 hour

    items[item_count++] = new_item;
    printf("Auction item created successfully!\n");
    return 0;
}

int place_bid(User *user) {
    if (!user->logged_in) {
        printf("Please login to place a bid.\n");
        return -1;
    }

    list_items();
    
    int item_index;
    printf("Select item index to bid on (1 - %d): ", item_count);
    scanf("%d", &item_index);
    
    if (item_index < 1 || item_index > item_count) {
        printf("Invalid item index.\n");
        return -1;
    }

    AuctionItem *item = &items[item_index - 1];
    if (time(NULL) > item->end_time) {
        printf("This auction has already ended.\n");
        return -1;
    }

    float bid;
    printf("Enter your bid (must be higher than %.2f): ", item->highest_bid);
    scanf("%f", &bid);
    
    if (bid <= item->highest_bid) {
        printf("Bid must be higher than the current highest bid.\n");
        return -1;
    }

    item->highest_bid = bid;
    strcpy(item->highest_bidder, user->username);
    printf("Bid placed successfully!\n");
    return 0;
}

int main() {
    int choice;
    User *current_user = NULL;

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Create Auction Item\n");
        printf("4. List Auction Items\n");
        printf("5. Place Bid\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                current_user = login_user();
                break;
            case 3:
                create_item();
                break;
            case 4:
                list_items();
                break;
            case 5:
                place_bid(current_user);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}