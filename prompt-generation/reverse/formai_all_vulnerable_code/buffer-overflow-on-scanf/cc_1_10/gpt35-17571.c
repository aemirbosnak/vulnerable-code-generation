//FormAI DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

// Item structure
typedef struct {
    char name[50];
    int startingBid;
    int currentBid;
    char bidder[50];
    int status; // 0 = available, 1 = sold
} Item;

// Global variables
Item items[MAX_ITEMS];
int num_items = 0;

// Function prototypes
void add_item();
void display_items();
void bid_item();
void sold_items();

int main() {
    int choice;
    
    while (1) {
        printf("\n\nDigital Auction System Menu\n");
        printf("----------------------------\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Bid item\n");
        printf("4. Sold items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;

            case 2:
                display_items();
                break;

            case 3:
                bid_item();
                break;

            case 4:
                sold_items();
                break;

            case 5:
                printf("\nExiting from the Digital Auction System...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again...\n");
                break;
        }
    }

    return 0;
}

// Add item to the auction
void add_item() {
    if (num_items == MAX_ITEMS) {
        printf("\nSorry! Auction is full...\n");
        return;
    }

    Item item;

    printf("\nEnter the item name: ");
    scanf("%s", item.name);

    printf("Enter the starting bid: ");
    scanf("%d", &item.startingBid);

    strcpy(item.bidder, "");
    item.currentBid = item.startingBid;
    item.status = 0;

    items[num_items++] = item;

    printf("\n%s added to the auction successfully!\n", item.name);
}

// Display all items in the auction
void display_items() {
    if (num_items == 0) {
        printf("\nNo items are available in the auction...\n");
        return;
    }

    printf("\nAll items in the auction:\n");

    for (int i = 0; i < num_items; i++) {
        printf("%2d. %-20s - Starting bid: %6d - Current bid: %6d - Bidder name: %-20s - Status: %s\n",
               i + 1, items[i].name, items[i].startingBid, items[i].currentBid,
               items[i].bidder, items[i].status == 0 ? "Available" : "Sold");
    }
}

// Bid an item in the auction
void bid_item() {
    if (num_items == 0) {
        printf("\nNo items are available in the auction...\n");
        return;
    }

    int index;

    printf("\nEnter the item number to bid: ");
    scanf("%d", &index);

    index--;

    if (index < 0 || index >= num_items) {
        printf("\nInvalid item number! Please try again...\n");
        return;
    }

    if (items[index].status == 1) {
        printf("\nSorry! This item already sold to %s with a bid of %d...\n", items[index].bidder, items[index].currentBid);
        return;
    }

    int bid;

    printf("Enter your bid for %s: ", items[index].name);
    scanf("%d", &bid);

    if (bid <= items[index].currentBid) {
        printf("\nSorry! Your bid (%d) should be greater than the current bid (%d)...\n", bid, items[index].currentBid);
        return;
    }

    items[index].currentBid = bid;
    printf("\nCongratulations! You are now the highest bidder for %s with a bid of %d...\n", items[index].name, bid);

    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    strcpy(items[index].bidder, name);
}

// Display all sold items in the auction
void sold_items() {
    if (num_items == 0) {
        printf("\nNo items are available in the auction...\n");
        return;
    }

    printf("\nAll sold items in the auction:\n");

    for (int i = 0; i < num_items; i++) {
        if (items[i].status == 1) {
            printf("%2d. %-20s - Sold for: %6d - Sold to: %-20s\n",
               i + 1, items[i].name, items[i].currentBid, items[i].bidder);
        }
    }
}