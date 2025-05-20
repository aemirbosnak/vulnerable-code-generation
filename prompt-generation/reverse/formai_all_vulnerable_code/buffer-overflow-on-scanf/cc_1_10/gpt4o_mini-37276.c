//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    char name[50];
    float starting_price;
    float current_price;
    int bids_count;
    char highest_bidder[50];
} Item;

typedef struct {
    char bidder_name[50];
    float amount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int item_count = 0;

void display_menu() {
    printf("Digital Auction System\n");
    printf("1. Add Item\n");
    printf("2. Place Bid\n");
    printf("3. View Items\n");
    printf("4. View Bids\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Max items limit reached.\n");
        return;
    }
    Item new_item;
    printf("Enter item name: ");
    scanf(" %[^\n]", new_item.name);
    printf("Enter starting price: ");
    scanf("%f", &new_item.starting_price);
    new_item.current_price = new_item.starting_price;
    new_item.bids_count = 0;
    strcpy(new_item.highest_bidder, "None");
    items[item_count++] = new_item;
    printf("Item added successfully!\n");
}

void place_bid() {
    char bidder[50];
    printf("Enter your name: ");
    scanf(" %[^\n]", bidder);

    int item_index;
    printf("Enter item index to bid on (0 to %d): ", item_count - 1);
    scanf("%d", &item_index);
    
    if(item_index < 0 || item_index >= item_count) {
        printf("Invalid item index.\n");
        return;
    }

    float bid_amount;
    printf("Enter bid amount (must be greater than %.2f): ", items[item_index].current_price);
    scanf("%f", &bid_amount);

    if (bid_amount > items[item_index].current_price) {
        items[item_index].current_price = bid_amount;
        strcpy(items[item_index].highest_bidder, bidder);
        items[item_index].bids_count++;
        printf("Bid placed successfully!\n");
    } else {
        printf("Bid amount must be greater than the current price.\n");
    }
}

void view_items() {
    if (item_count == 0) {
        printf("No items available for auction.\n");
        return;
    }
    printf("\nItems available for auction:\n");
    for (int i = 0; i < item_count; i++) {
        printf("Item %d: %s\n", i, items[i].name);
        printf("Starting Price: %.2f\n", items[i].starting_price);
        printf("Current Price: %.2f\n", items[i].current_price);
        printf("Highest Bidder: %s\n", items[i].highest_bidder);
        printf("Number of Bids: %d\n\n", items[i].bids_count);
    }
}

void view_bids() {
    printf("\nBids placed:\n");
    for (int i = 0; i < item_count; i++) {
        printf("Item: %s\n", items[i].name);
        printf("Highest Bidder: %s\n", items[i].highest_bidder);
        printf("Current Price: %.2f\n", items[i].current_price);
        printf("Number of Bids: %d\n\n", items[i].bids_count);
    }
}

int main() {
    while (true) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                place_bid();
                break;
            case 3:
                view_items();
                break;
            case 4:
                view_bids();
                break;
            case 5:
                printf("Exiting auction system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}