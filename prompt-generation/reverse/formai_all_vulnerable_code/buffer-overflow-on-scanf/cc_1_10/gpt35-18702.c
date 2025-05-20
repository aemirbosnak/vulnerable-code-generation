//FormAI DATASET v1.0 Category: Digital Auction System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 1000
#define MAX_BIDDERS 100

// Define a structure for an auction item
typedef struct {
    int id;
    char name[50];
    char description[100];
    double starting_price;
    double current_bid;
    int current_bidder_id;
    int time_remaining;
} AuctionItem;

// Define a structure for a bidder
typedef struct {
    int id;
    char name[50];
    double balance;
} Bidder;

// Define an array for auction items and a counter for the number of items in the array
AuctionItem auction_items[MAX_ITEMS];
int num_items = 0;

// Define an array for bidders and a counter for the number of bidders in the array
Bidder bidders[MAX_BIDDERS];
int num_bidders = 0;

// Function to display the main menu
void display_menu() {
    printf("\nDigital Auction System\n");
    printf("1. List all items for auction\n");
    printf("2. Add new item to auction\n");
    printf("3. Remove item from auction\n");
    printf("4. List all bidders\n");
    printf("5. Add new bidder\n");
    printf("6. Remove bidder\n");
    printf("7. Bid on item\n");
    printf("8. Display item information\n");
    printf("9. Exit\n");
    printf("Please enter your choice: ");
}

// Function to list all items for auction
void list_items() {
    printf("\nItems currently up for auction:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - Current Bid: $%.2lf - Time Remaining: %d minutes\n", auction_items[i].id, auction_items[i].name, auction_items[i].current_bid, auction_items[i].time_remaining);
    }
}

// Function to add a new item to the auction
void add_item() {
    AuctionItem new_item;
    new_item.id = num_items + 1;
    printf("\nEnter the name of the item: ");
    scanf(" %[^\n]s", new_item.name);
    printf("Enter a short description of the item: ");
    scanf(" %[^\n]s", new_item.description);
    printf("Enter the starting price: $");
    scanf("%lf", &new_item.starting_price);
    new_item.current_bid = new_item.starting_price;
    new_item.current_bidder_id = -1;
    printf("Enter the length of the auction (in minutes): ");
    scanf("%d", &new_item.time_remaining);
    auction_items[num_items] = new_item;
    num_items++;
    printf("\nItem added to auction!\n");
}

// Function to remove an item from the auction
void remove_item() {
    int item_id;
    printf("\nEnter the ID of the item to remove: ");
    scanf("%d", &item_id);
    for (int i = 0; i < num_items; i++) {
        if (auction_items[i].id == item_id) {
            for (int j = i; j < num_items - 1; j++) {
                auction_items[j] = auction_items[j + 1];
            }
            num_items--;
            printf("\nItem removed from auction!\n");
            return;
        }
    }
    printf("\nItem not found!\n");
}

// Function to list all bidders
void list_bidders() {
    printf("\nCurrent bidders:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%d. %s - Balance: $%.2lf\n", bidders[i].id, bidders[i].name, bidders[i].balance);
    }
}

// Function to add a new bidder
void add_bidder() {
    Bidder new_bidder;
    new_bidder.id = num_bidders + 1;
    printf("\nEnter the name of the bidder: ");
    scanf(" %[^\n]s", new_bidder.name);
    printf("Enter the starting balance: $");
    scanf("%lf", &new_bidder.balance);
    bidders[num_bidders] = new_bidder;
    num_bidders++;
    printf("\nBidder added to auction!\n");
}

// Function to remove a bidder from the auction
void remove_bidder() {
    int bidder_id;
    printf("\nEnter the ID of the bidder to remove: ");
    scanf("%d", &bidder_id);
    for (int i = 0; i < num_bidders; i++) {
        if (bidders[i].id == bidder_id) {
            for (int j = i; j < num_bidders - 1; j++) {
                bidders[j] = bidders[j + 1];
            }
            num_bidders--;
            printf("\nBidder removed from auction!\n");
            return;
        }
    }
    printf("\nBidder not found!\n");
}

// Function to bid on an item
void bid_on_item() {
    int item_id, bidder_id;
    double bid_amount;
    printf("\nEnter the ID of the item to bid on: ");
    scanf("%d", &item_id);
    printf("Enter the ID of the bidder: ");
    scanf("%d", &bidder_id);
    printf("Enter the bid amount: $");
    scanf("%lf", &bid_amount);
    for (int i = 0; i < num_items; i++) {
        if (auction_items[i].id == item_id) {
            if (bid_amount > auction_items[i].current_bid && bidder_id != auction_items[i].current_bidder_id) {
                auction_items[i].current_bid = bid_amount;
                auction_items[i].current_bidder_id = bidder_id;
                printf("\nBid accepted!\n");
                return;
            } else {
                printf("\nBid rejected!\n");
                return;
            }
        }
    }
    printf("\nItem not found!\n");
}

// Function to display information about an item
void display_item_info() {
    int item_id;
    printf("\nEnter the ID of the item to display: ");
    scanf("%d", &item_id);
    for (int i = 0; i < num_items; i++) {
        if (auction_items[i].id == item_id) {
            printf("\nItem Information:\n");
            printf("Name: %s\n", auction_items[i].name);
            printf("Description: %s\n", auction_items[i].description);
            printf("Starting Price: $%.2lf\n", auction_items[i].starting_price);
            printf("Current Bid: $%.2lf\n", auction_items[i].current_bid);
            printf("Current Bidder: %s\n", auction_items[i].current_bidder_id == -1 ? "No bidder" : bidders[auction_items[i].current_bidder_id - 1].name);
            printf("Time Remaining: %d minutes\n", auction_items[i].time_remaining);
            return;
        }
    }
    printf("\nItem not found!\n");
}

int main() {
    int choice;
    srand(time(NULL));
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                list_items();
                break;
            case 2:
                add_item();
                break;
            case 3:
                remove_item();
                break;
            case 4:
                list_bidders();
                break;
            case 5:
                add_bidder();
                break;
            case 6:
                remove_bidder();
                break;
            case 7:
                bid_on_item();
                break;
            case 8:
                display_item_info();
                break;
            case 9:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}