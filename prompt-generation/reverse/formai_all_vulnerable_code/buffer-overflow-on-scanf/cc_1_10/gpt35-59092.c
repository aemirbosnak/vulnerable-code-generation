//FormAI DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for Auction Item
typedef struct auction_item {
    char name[50];
    int minimum_bid;
    int current_bid;
    char bidder[50];
} Auction_Item;

// Function to display the auction item details
void display_item(Auction_Item item) {
    printf("==============================\n");
    printf("Item Name: %s\n", item.name);
    printf("Minimum Bid: %d\n", item.minimum_bid);
    printf("Current Bid: %d\n", item.current_bid);
    printf("Bidder: %s\n", item.bidder);
    printf("==============================\n");
}

int main() {
    // Initialize the auction items
    Auction_Item item1 = {"Guitar", 200, 0, ""};
    Auction_Item item2 = {"Painting", 500, 0, ""};
    Auction_Item item3 = {"Watch", 1000, 0, ""};
    
    // Display the auction items
    printf("Welcome to the Happy Auction System!\n");
    printf("Here are the items available for bidding:\n");
    display_item(item1);
    display_item(item2);
    display_item(item3);
    
    // Prompt the user to enter their name and bid for an item
    int choice;
    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("Which item would you like to bid on? ");
    scanf("%d", &choice);
    
    // Bid on the selected item
    Auction_Item *selected_item;
    switch(choice) {
        case 1:
            selected_item = &item1;
            break;
        case 2:
            selected_item = &item2;
            break;
        case 3:
            selected_item = &item3;
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            exit(0);
    }
    
    // Prompt the user to enter their bid
    int bid;
    printf("Please enter your bid: ");
    scanf("%d", &bid);
    
    // Check if the bid is higher than the current bid and the minimum bid
    if(bid > selected_item->current_bid && bid >= selected_item->minimum_bid) {
        selected_item->current_bid = bid;
        strcpy(selected_item->bidder, name);
        printf("Congratulations, %s! Your bid of %d has been accepted for the %s.\n", name, bid, selected_item->name);
    }
    else {
        printf("Sorry, your bid of %d is not accepted for the %s.\n", bid, selected_item->name);
    }
    
    // Display the updated item details
    display_item(*selected_item);
    
    printf("Thank you for using the Happy Auction System!\n");
    return 0;
}