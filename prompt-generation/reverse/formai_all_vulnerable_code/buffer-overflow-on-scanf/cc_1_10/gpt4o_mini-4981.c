//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_USERS 100
#define MAX_AUCTIONS 50
#define MAX_BIDS 100
#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20
#define MAX_ITEM_LEN 50

typedef struct {
    char username[MAX_USERNAME_LEN];
    unsigned char password_hash[SHA256_DIGEST_LENGTH];
} User;

typedef struct {
    char item_name[MAX_ITEM_LEN];
    double starting_price;
    double highest_bid;
    char highest_bidder[MAX_USERNAME_LEN];
    int bids_count;
} Auction;

User users[MAX_USERS];
int user_count = 0;

Auction auctions[MAX_AUCTIONS];
int auction_count = 0;

void hash_password(const char* password, unsigned char* hash) {
    SHA256((unsigned char*)password, strlen(password), hash);
}

int register_user(const char* username, const char* password) {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return -1;
    }
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists.\n");
            return -1;
        }
    }
    
    strcpy(users[user_count].username, username);
    hash_password(password, users[user_count].password_hash);
    user_count++;
    printf("User registered successfully!\n");
    return 0;
}

int login_user(const char* username, const char* password) {
    unsigned char password_hash[SHA256_DIGEST_LENGTH];
    hash_password(password, password_hash);
    
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            memcmp(users[i].password_hash, password_hash, SHA256_DIGEST_LENGTH) == 0) {
            printf("Login successful!\n");
            return 1;
        }
    }
    printf("Invalid username or password.\n");
    return 0;
}

void create_auction(const char* item_name, double starting_price) {
    if (auction_count >= MAX_AUCTIONS) {
        printf("Auction limit reached. Cannot create more auctions.\n");
        return;
    }
    
    strcpy(auctions[auction_count].item_name, item_name);
    auctions[auction_count].starting_price = starting_price;
    auctions[auction_count].highest_bid = starting_price;
    strcpy(auctions[auction_count].highest_bidder, "None");
    auctions[auction_count].bids_count = 0;
    
    auction_count++;
    printf("Auction for '%s' created successfully!\n", item_name);
}

void bid_on_auction(int auction_index, const char* bidder, double bid_amount) {
    if (auction_index < 0 || auction_index >= auction_count) {
        printf("Invalid auction index.\n");
        return;
    }
    if (bid_amount <= auctions[auction_index].highest_bid) {
        printf("Bid amount must be higher than the current highest bid.\n");
        return;
    }
    auctions[auction_index].highest_bid = bid_amount;
    strcpy(auctions[auction_index].highest_bidder, bidder);
    auctions[auction_index].bids_count++;
    printf("Bid placed successfully by '%s' on auction for '%s'.\n", bidder, auctions[auction_index].item_name);
}

void display_auctions() {
    for (int i = 0; i < auction_count; i++) {
        printf("Auction %d: Item: %s, Starting Price: %.2f, Current Highest Bid: %.2f, Highest Bidder: %s\n",
            i, auctions[i].item_name, auctions[i].starting_price, auctions[i].highest_bid, auctions[i].highest_bidder);
    }
}

int main() {
    int choice, index;
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN], item_name[MAX_ITEM_LEN];
    double starting_price, bid_amount;

    while (1) {
        printf("\nDigital Auction System\n");
        printf("1. Register\n2. Login\n3. Create Auction\n4. Bid on Auction\n5. Display Auctions\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                register_user(username, password);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                login_user(username, password);
                break;
            case 3:
                printf("Enter item name: ");
                scanf("%s", item_name);
                printf("Enter starting price: ");
                scanf("%lf", &starting_price);
                create_auction(item_name, starting_price);
                break;
            case 4:
                printf("Enter auction index to bid on: ");
                scanf("%d", &index);
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter bid amount: ");
                scanf("%lf", &bid_amount);
                bid_on_auction(index, username, bid_amount);
                break;
            case 5:
                display_auctions();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}