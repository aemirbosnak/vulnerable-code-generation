//FormAI DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum number of items and bidders
#define MAX_ITEMS 50
#define MAX_BIDDERS 20

// Define struct for item information
struct Item {
    char name[50];
    double start_price;
    double current_bid;
    char current_bidder[50];
    time_t end_time;
    int is_sold;
};

// Define struct for bidder information
struct Bidder {
    char name[50];
    double balance;
};

// Define global variables for items and bidders
struct Item items[MAX_ITEMS];
struct Bidder bidders[MAX_BIDDERS];
int num_items = 0;
int num_bidders = 0;

// Function to add a new item to the auction
void add_item() {
    struct Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter starting price: ");
    scanf("%lf", &item.start_price);
    item.current_bid = item.start_price;
    printf("Enter end time (in seconds): ");
    scanf("%ld", &item.end_time);
    item.end_time = time(NULL) + item.end_time;
    item.is_sold = 0;
    items[num_items++] = item;
    printf("Item added successfully!\n\n");
}

// Function to add a new bidder to the auction
void add_bidder() {
    struct Bidder bidder;
    printf("Enter bidder name: ");
    scanf("%s", bidder.name);
    printf("Enter starting balance: ");
    scanf("%lf", &bidder.balance);
    bidders[num_bidders++] = bidder;
    printf("Bidder added successfully!\n\n");
}

// Function to display all items in the auction
void display_items() {
    printf("Current items in auction:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s\tCurrent Bid: $%.2lf\tEnd Time: %s", i+1, items[i].name, items[i].current_bid, ctime(&items[i].end_time));
    }
    printf("\n");
}

// Function to display all bidders in the auction
void display_bidders() {
    printf("Current bidders in auction:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%d. %s\tBalance: $%.2lf\n", i+1, bidders[i].name, bidders[i].balance);
    }
    printf("\n");
}

// Function to get the index of a bidder based on their name
int get_bidder_index(char* name) {
    for (int i = 0; i < num_bidders; i++) {
        if (strcmp(name, bidders[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to place a bid on an item
void place_bid() {
    int item_index, bidder_index;
    double new_bid;
    char bidder_name[50];
    display_items();
    printf("Enter the item number to bid on: ");
    scanf("%d", &item_index);
    item_index--;
    printf("Enter your name: ");
    scanf("%s", bidder_name);
    bidder_index = get_bidder_index(bidder_name);
    if (bidder_index == -1) {
        printf("Bidder not found!\n\n");
        return;
    }
    printf("Enter your bid: ");
    scanf("%lf", &new_bid);
    if (new_bid <= items[item_index].current_bid) {
        printf("Your bid must be higher than the current bid!\n\n");
        return;
    }
    if (new_bid > bidders[bidder_index].balance) {
        printf("Insufficient funds to place bid!\n\n");
        return;
    }
    strcpy(items[item_index].current_bidder, bidder_name);
    items[item_index].current_bid = new_bid;
    printf("Bid placed successfully!\n\n");
}

// Function to end the auction and sell all items to the highest bidder
void end_auction() {
    printf("Auction ended!\n");
    for (int i = 0; i < num_items; i++) {
        if (!items[i].is_sold && (time(NULL) >= items[i].end_time)) {
            int bidder_index = get_bidder_index(items[i].current_bidder);
            bidders[bidder_index].balance -= items[i].current_bid;
            printf("%s sold to %s for $%.2lf!\n", items[i].name, items[i].current_bidder, items[i].current_bid);
            items[i].is_sold = 1;
        }
    }
    printf("Thanks for participating in the auction!\n");
}

int main() {
    int choice;
    printf("Welcome to the Medieval Digital Auction System!\n\n");
    do {
        printf("Please select an option:\n");
        printf("1. Add item\n");
        printf("2. Add bidder\n");
        printf("3. Place bid\n");
        printf("4. Display items\n");
        printf("5. Display bidders\n");
        printf("6. End auction\n");
        printf("7. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_bidder();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                display_items();
                break;
            case 5:
                display_bidders();
                break;
            case 6:
                end_auction();
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 7);
    return 0;
}