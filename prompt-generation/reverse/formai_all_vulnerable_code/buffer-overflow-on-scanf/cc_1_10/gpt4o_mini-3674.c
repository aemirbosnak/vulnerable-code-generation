//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_BIDS 100
#define MAX_ITEM_NAME 50

typedef struct {
    char username[30];
} User;

typedef struct {
    char item_name[MAX_ITEM_NAME];
    float starting_price;
    float highest_bid;
    int highest_bidder_index;
    int end_time; // Auction end time in seconds
} AuctionItem;

User users[MAX_USERS];
int user_count = 0;

AuctionItem auction;

// Function to register a new user
void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached! Cannot register more users.\n");
        return;
    }

    printf("Enter your username: ");
    scanf("%s", users[user_count].username);
    user_count++;
    printf("User %s registered successfully!\n", users[user_count - 1].username);
}

// Function to create a new auction item
void create_auction_item() {
    printf("Enter item name for auction: ");
    scanf("%s", auction.item_name);
    
    printf("Enter starting price for %s: ", auction.item_name);
    scanf("%f", &auction.starting_price);
    
    auction.highest_bid = auction.starting_price;
    auction.highest_bidder_index = -1;

    printf("Enter auction duration in seconds: ");
    scanf("%d", &auction.end_time);
    printf("Auction item %s created successfully with starting price %.2f!\n",
           auction.item_name, auction.starting_price);
}

// Function to place a bid
void place_bid() {
    if (user_count == 0) {
        printf("No users available! Register a user first!\n");
        return;
    }

    printf("Enter your username: ");
    char username[30];
    scanf("%s", username);

    int user_index = -1;
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            user_index = i;
            break;
        }
    }

    if (user_index == -1) {
        printf("User not found. Please register first!\n");
        return;
    }

    float bid;
    printf("Enter your bid (current highest bid is %.2f): ", auction.highest_bid);
    scanf("%f", &bid);

    if (bid > auction.highest_bid) {
        auction.highest_bid = bid;
        auction.highest_bidder_index = user_index;
        printf("Bid placed successfully by %s with bid amount %.2f!\n",
               users[user_index].username, bid);
    } else {
        printf("Your bid must be higher than the current highest bid!\n");
    }
}

// Function to display auction results
void display_results() {
    if (auction.highest_bidder_index == -1) {
        printf("No bids were placed in the auction for %s.\n", auction.item_name);
    } else {
        printf("The auction for %s has ended.\n", auction.item_name);
        printf("The winning bid is %.2f from user %s!\n",
               auction.highest_bid, users[auction.highest_bidder_index].username);
    }
}

// Main function to drive the auction system
int main() {
    int choice;
    int auction_running = 1;

    printf("Welcome to the Digital Auction System!\n");
    
    while (auction_running) {
        printf("\n1. Register User\n2. Create Auction Item\n3. Place Bid\n4. End Auction\n5. Display Results\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                create_auction_item();
                break;
            case 3:
                if (auction.end_time > 0) {
                    place_bid();
                } else {
                    printf("Auction is not active! Please create an auction first.\n");
                }
                break;
            case 4:
                auction.end_time = 0; // Ends the auction
                printf("Auction has ended!\n");
                break;
            case 5:
                display_results();
                break;
            case 6:
                auction_running = 0;
                printf("Exiting the auction system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}