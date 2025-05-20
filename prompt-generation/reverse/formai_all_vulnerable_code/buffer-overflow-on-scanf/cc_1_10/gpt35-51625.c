//FormAI DATASET v1.0 Category: Digital Auction System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants
#define MAX_NAME_LEN 20
#define MAX_DESC_LEN 100
#define MAX_BID_LEN 10
#define MAX_ITEM_NUM 100
#define MAX_BID_NUM 1000

// define structures
typedef struct {
    char name[MAX_NAME_LEN];
    char desc[MAX_DESC_LEN];
    int curr_bid;
    char curr_bidder[MAX_NAME_LEN];
    int min_bid;
} Item;

typedef struct {
    char bidder[MAX_NAME_LEN];
    int bid;
} Bid;

// declare global variables
Item items[MAX_ITEM_NUM];
Bid bids[MAX_BID_NUM];
int num_items = 0;
int num_bids = 0;

// function prototypes
void add_item();
void display_items();
void place_bid();

int main() {
    int choice = 0;
    do {
        printf("\n--- Digital Auction System ---\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Place Bid\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                printf("Thank you for using the Digital Auction System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void add_item() {
    if (num_items == MAX_ITEM_NUM) {
        printf("Sorry, the maximum number of items has been reached.\n");
        return;
    }

    Item item;
    printf("\nEnter item name (max %d characters): ", MAX_NAME_LEN);
    scanf("%s", item.name);
    printf("Enter item description (max %d characters): ", MAX_DESC_LEN);
    scanf(" %[^\n]s", item.desc);
    printf("Enter minimum bid (in dollars): ");
    scanf("%d", &item.min_bid);

    item.curr_bid = item.min_bid;
    strcpy(item.curr_bidder, "None");

    items[num_items++] = item;

    printf("Item added successfully!\n");
}

void display_items() {
    if (num_items == 0) {
        printf("No items to display.\n");
        return;
    }

    printf("\n--- List of Items ---\n");
    printf("%-20s %-30s %-10s %-15s\n", "Name", "Description", "Min. Bid", "Curr. Bidder");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s %-30s %-10d %-15s\n", items[i].name, items[i].desc, items[i].min_bid, items[i].curr_bidder);
    }
}

void place_bid() {
    if (num_items == 0) {
        printf("No items to bid on.\n");
        return;
    }

    Bid bid;
    int item_num = 0;
    printf("\nEnter your name (max %d characters): ", MAX_NAME_LEN);
    scanf("%s", bid.bidder);
    printf("Enter your bid amount (in dollars): ");
    scanf("%d", &bid.bid);

    while (item_num < 1 || item_num > num_items) {
        printf("Enter the item number you wish to bid on (1-%d): ", num_items);
        scanf("%d", &item_num);
        if (item_num < 1 || item_num > num_items) {
            printf("Invalid item number. Please try again.\n");
        }
    }

    Item item = items[item_num-1];

    if (bid.bid < item.min_bid) {
        printf("Sorry, your bid of %d dollars is less than the minimum bid of %d dollars.\n", bid.bid, item.min_bid);
        return;
    }

    if (bid.bid <= item.curr_bid) {
        printf("Sorry, your bid of %d dollars must be greater than the current bid of %d dollars.\n", bid.bid, item.curr_bid);
        return;
    }

    item.curr_bid = bid.bid;
    strcpy(item.curr_bidder, bid.bidder);
    items[item_num-1] = item;

    bids[num_bids++] = bid;

    printf("Bid placed successfully!\n");
}