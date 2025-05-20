//FormAI DATASET v1.0 Category: Digital Auction System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Global Structures
struct auction {
    int item_id;
    char item_name[20];
    float start_bid;
    float current_bid;
    char bidder_name[20];
};
struct auction items[100]; // creating an array of auction items to hold up to 100 items

// Global Variables
int item_count = 0; // counter for auction items added
int auction_is_active = 0; // flag to determine if an auction is currently active

// Display Menu
void display_menu() {
    printf("\nDigital Auction System Menu\n");
    printf("----------------------------------\n");
    printf("1. Add Item\n");
    printf("2. Manage Auction\n");
    printf("3. View Items\n");
    printf("4. Exit\n");
    printf("----------------------------------\n");
    printf("Enter your choice: ");
}

// Add Item Function
void add_item() {
    printf("\nAdd Item\n");
    printf("----------------------------------\n");
    printf("Enter Item Name: ");
    scanf("%s", items[item_count].item_name); // taking input for item name
    printf("Enter Starting Bid Amount: ");
    scanf("%f", &items[item_count].start_bid); // taking input for starting bid amount
    printf("Item Added Successfully!\n");
    items[item_count].item_id = item_count+1; // assigning unique id to item
    item_count++; // increase item counter
}

// Auction Management Function
void manage_auction() {
    printf("\nAuction Management\n");
    printf("----------------------------------\n");
    if(item_count == 0) {
        printf("No items in auction. Please add an item first.\n");
        return;
    }
    if(!auction_is_active) {
        printf("Auction Started!\n");
        auction_is_active = 1; // setting the auction flag to active
    }
    printf("Current Items in Auction\n");
    printf("----------------------------------\n");
    for(int i=0;i<item_count;i++) {
        printf("%d. %s - Starting Bid: %.2f\n", items[i].item_id, items[i].item_name, items[i].start_bid);
    }
    int item_choice;
    printf("Enter item number to bid: "); // taking input for item choice
    scanf("%d", &item_choice);
    if(item_choice < 0 || item_choice > item_count) {
        printf("Invalid item choice. Try again.\n");
        return;
    }
    float bid_amount;
    printf("Enter your bid amount: "); // taking input for bid amount
    scanf("%f", &bid_amount);
    if(bid_amount <= items[item_choice-1].current_bid || bid_amount < items[item_choice-1].start_bid) {
        printf("Your bid is lower than current bid or starting bid. Try again.\n");
        return;
    }
    strcpy(items[item_choice-1].bidder_name, "You"); // assigning the bidder name
    items[item_choice-1].current_bid = bid_amount; // updating current bid amount
    printf("Your bid of %.2f is successful!\n", bid_amount);
}

// View Items Function
void view_items() {
    printf("\nView Items\n");
    printf("----------------------------------\n");
    if(item_count == 0) {
        printf("No items in auction.\n");
        return;
    }
    printf("Current Items in Auction\n");
    printf("----------------------------------\n");
    for(int i=0;i<item_count;i++) {
        printf("%d. %s - Starting Bid: %.2f - Current Bid: %.2f - Bidder: %s\n", items[i].item_id, items[i].item_name, items[i].start_bid, items[i].current_bid, items[i].bidder_name);
    }
}

// Main Function
int main() {
    int choice;
    do {
        display_menu(); // calling display menu function
        scanf("%d", &choice); // taking user input for menu choice
        switch(choice) {
            case 1:
                add_item(); // calling add item function
                break;
            case 2:
                manage_auction(); // calling manage auction function
                break;
            case 3:
                view_items(); // calling view items function
                break;
            case 4:
                printf("Thank you for using Digital Auction System!\n");
                exit(0); // exiting program
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(1);
    return 0;
}