//FormAI DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// declaring variables for auction system
char item_name[50];                      
int base_price, highest_bid, num_bids;

// function to display the menu
void display_menu() {
    printf("------ Auction System ------\n");
    printf("1. Set Item Name\n");
    printf("2. Set Base Price\n");
    printf("3. Place Bid\n");
    printf("4. Display Information\n");
    printf("5. Exit\n");
}

// function to set item name
void set_item_name() {
    printf("Enter the item name: ");
    scanf("%s", item_name);
    printf("Item name set successfully!\n");
}

// function to set base price
void set_base_price() {
    printf("Enter the base price: ");
    scanf("%d", &base_price);
    highest_bid = base_price;
    printf("Base price set successfully!\n");
}

// function to place bid
void place_bid() {
    int bid_amount;
    printf("Enter the bid amount: ");
    scanf("%d", &bid_amount);
    if (bid_amount > highest_bid) {
        highest_bid = bid_amount;
        num_bids++;
        printf("Bid placed successfully!\n");
    } else {
        printf("Bid amount must be higher than the highest bid.\n");
    }
}

// function to display information
void display_info() {
    printf("\nItem Name       : %s\n", item_name);
    printf("Base Price      : %d\n", base_price);
    printf("Highest Bid     : %d\n", highest_bid);
    printf("Number of Bids  : %d\n\n", num_bids);
}

int main() {
    int choice;
    num_bids = 0;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                set_item_name();
                break;
            case 2:
                set_base_price();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                display_info();
                break;
            case 5:
                printf("Exiting Auction System...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}