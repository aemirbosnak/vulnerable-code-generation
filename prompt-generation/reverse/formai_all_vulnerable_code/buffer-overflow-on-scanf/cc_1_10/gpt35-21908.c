//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 1000
#define MAX_BIDDERS 100

struct item {
    char name[50];
    char desc[200];
    double start_price;
    double current_bid;
    int bidder_index;
    int status;  // 0 -> unsold, 1 -> sold
};

struct bidder {
    char name[50];
    double max_bid;
    double current_bid;
};

int num_items = 0;
int num_bidders = 0;
struct item items[MAX_ITEMS];
struct bidder bidders[MAX_BIDDERS];

// Function to add an item to the auction system
void add_item() {
    if (num_items == MAX_ITEMS) {
        printf("Maximum limit of items reached.\n");
        return;
    }
    struct item new_item;
    printf("Enter item name (max 50 characters): ");
    fgets(new_item.name, 50, stdin);
    new_item.name[strcspn(new_item.name, "\n")] = 0;
    printf("Enter item description (max 200 characters): ");
    fgets(new_item.desc, 200, stdin);
    new_item.desc[strcspn(new_item.desc, "\n")] = 0;
    printf("Enter starting price: ");
    scanf("%lf", &new_item.start_price);
    new_item.current_bid = new_item.start_price;
    new_item.status = 0;
    new_item.bidder_index = -1;
    items[num_items++] = new_item;
    getchar();  // Consume newline
    printf("Item added successfully.\n");
}

// Function to add a bidder to the auction system
void add_bidder() {
    if (num_bidders == MAX_BIDDERS) {
        printf("Maximum limit of bidders reached.\n");
        return;
    }
    struct bidder new_bidder;
    printf("Enter bidder name (max 50 characters): ");
    fgets(new_bidder.name, 50, stdin);
    new_bidder.name[strcspn(new_bidder.name, "\n")] = 0;
    printf("Enter maximum bid: ");
    scanf("%lf", &new_bidder.max_bid);
    new_bidder.current_bid = 0;
    bidders[num_bidders++] = new_bidder;
    getchar();  // Consume newline
    printf("Bidder added successfully.\n");
}

// Function to list all the items in the auction
void list_items() {
    if (num_items == 0) {
        printf("No items in auction.\n");
        return;
    }
    printf("Items in auction:\n");
    printf("%-4s%-20s%-20s%10s%10s\n", "ID", "Name", "Description", "Price", "Status");
    for (int i = 0; i < num_items; i++) {
        printf("%-4d%-20s%-20s%10.2lf%10s\n", i, items[i].name, items[i].desc,
                items[i].current_bid, items[i].status == 0 ? "Unsold" : "Sold");
    }
}

// Function to list all the bidders in the auction
void list_bidders() {
    if (num_bidders == 0) {
        printf("No bidders in auction.\n");
        return;
    }
    printf("Bidders in auction:\n");
    printf("%-4s%-20s%-20s%10s\n", "ID", "Name", "Maximum Bid", "Current Bid");
    for (int i = 0; i < num_bidders; i++) {
        printf("%-4d%-20s%10.2lf%10.2lf\n", i, bidders[i].name, bidders[i].max_bid, bidders[i].current_bid);
    }
}

// Function to handle the bidding for an item
void bid_for_item() {
    if (num_items == 0) {
        printf("No items in auction.\n");
        return;
    }
    int item_id;
    printf("Enter item ID: ");
    scanf("%d", &item_id);
    if (item_id < 0 || item_id >= num_items) {
        printf("Invalid item ID.\n");
        return;
    }
    if (items[item_id].status == 1) {
        printf("Item is already sold.\n");
        return;
    }
    struct item this_item = items[item_id];
    printf("Enter bidder ID: ");
    int bidder_id;
    scanf("%d", &bidder_id);
    if (bidder_id < 0 || bidder_id >= num_bidders) {
        printf("Invalid bidder ID.\n");
        return;
    }
    struct bidder this_bidder = bidders[bidder_id];
    if (this_bidder.max_bid < this_item.current_bid + 1) {
        printf("Bid must be greater than or equal to current bid + 1.\n");
        return;
    }
    if (this_bidder.max_bid < this_item.start_price) {
        printf("Bid must be greater than or equal to starting price.\n");
        return;
    }
    items[item_id].current_bid = this_item.current_bid + 1;
    items[item_id].bidder_index = bidder_id;
    if (this_bidder.current_bid == 0) {
        this_bidder.current_bid = items[item_id].start_price;
    }
    else {
        this_bidder.current_bid = items[item_id].current_bid;
    }
    bidders[bidder_id].current_bid = this_bidder.current_bid;
    printf("Bid accepted.\n");
}

// Function to end the auction and display results
void end_auction() {
    if (num_items == 0) {
        printf("No items in auction.\n");
        return;
    }
    printf("Auction has ended.\n");
    printf("Items in auction:\n");
    printf("%-4s%-20s%-20s%10s%10s%-20s\n", "ID", "Name", "Description", "Price", "Status", "Winning Bidder");
    for (int i = 0; i < num_items; i++) {
        if (items[i].status == 0) {
            printf("%-4d%-20s%-20s%10.2lf%10s", i, items[i].name, items[i].desc,
                    items[i].current_bid, "Sold");
            if (items[i].bidder_index != -1) {
                printf("%-20s", bidders[items[i].bidder_index].name);
            }
            else {
                printf("%-20s", "No bids");
            }
            printf("\n");
        }
    }
}

int main() {
    bool exit_program = false;
    while (!exit_program) {
        printf("\nWelcome to the auction system.\n");
        printf("1. Add Item\n");
        printf("2. Add Bidder\n");
        printf("3. List Items\n");
        printf("4. List Bidders\n");
        printf("5. Bid for Item\n");
        printf("6. End Auction\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();  // Consume newline
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_bidder();
                break;
            case 3:
                list_items();
                break;
            case 4:
                list_bidders();
                break;
            case 5:
                bid_for_item();
                break;
            case 6:
                end_auction();
                exit_program = true;
                break;
            case 7:
                exit_program = true;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}