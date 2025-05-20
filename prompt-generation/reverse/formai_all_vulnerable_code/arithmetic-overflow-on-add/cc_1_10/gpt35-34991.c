//FormAI DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct for the item being auctioned
typedef struct Item {
    char name[50];
    char description[100];
    double minimum_price;
    time_t end_time;
    double current_bid;
    char highest_bidder[50];
} Item;

int main() {
    // Define an array of items to be auctioned
    Item items[10];
    
    // Define variables for user input
    int choice;
    char bidder_name[50];
    int item_choice;
    double bid_amount;
    int i, j;
    
    // Initialize the items array with dummy data
    for (i = 0; i < 10; i++) {
        sprintf(items[i].name, "Item #%d", i+1);
        sprintf(items[i].description, "This is item #%d", i+1);
        items[i].minimum_price = 10.00;
        items[i].end_time = time(NULL) + 60*60*24; // 24 hours from now
        items[i].current_bid = items[i].minimum_price;
        strcpy(items[i].highest_bidder, "No bids yet");
    }
    
    // Welcome the user and give them the menu options
    printf("Welcome to the Digital Auction System!\n");
    do {
        printf("\nPlease choose an option:\n");
        printf("1. View auction items\n");
        printf("2. Bid on an item\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display the list of auction items
                printf("\nCurrent auction items:\n");
                for (i = 0; i < 10; i++) {
                    printf("%d. %s - %s - Minimum price: $%.2f - Ends at: %s", i+1, items[i].name, items[i].description, items[i].minimum_price, ctime(&items[i].end_time));
                    printf("   Current bid: $%.2f - Highest bidder: %s\n", items[i].current_bid, items[i].highest_bidder);
                }
                break;
            case 2:
                // Ask the user which item they want to bid on
                printf("\nWhich item would you like to bid on? (Enter the number): ");
                scanf("%d", &item_choice);
                item_choice--; // Convert choice to array index
                
                // Ask for the user's name and bid amount
                printf("Enter your name: ");
                scanf("%s", bidder_name);
                printf("Enter your bid: $");
                scanf("%lf", &bid_amount);
                
                // Check if the bid is greater than the current bid and minimum price
                if (bid_amount > items[item_choice].current_bid && bid_amount >= items[item_choice].minimum_price) {
                    // Update the item's current bid and highest bidder
                    items[item_choice].current_bid = bid_amount;
                    strcpy(items[item_choice].highest_bidder, bidder_name);
                    printf("Bid accepted!\n");
                } else {
                    printf("Bid rejected.\n");
                }
                break;
            case 3:
                // Exit the program
                printf("Goodbye!\n");
                return 0;
            default:
                // Notify the user of an invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}