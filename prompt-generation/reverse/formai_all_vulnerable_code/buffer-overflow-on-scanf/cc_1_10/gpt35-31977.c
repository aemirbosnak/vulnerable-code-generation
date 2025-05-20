//FormAI DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int max_items = 10; // Maximum number of items that can be auctioned
    int items_sold = 0; // Number of items already auctioned
    int item_price[max_items]; // Array to store the prices of each item
    int item_max_bid[max_items]; // Array to store the maximum bid for each item
    int current_bid; // Variable to store the current bid
    int item_number; // Variable to store the item number to be auctioned
    int bid_number; // Variable to store the bid number
    
    srand(time(NULL)); // Seed the random number generator with current time
    
    // Auction Loop
    while(items_sold < max_items){
        item_number = items_sold + 1;
        item_price[items_sold] = rand() % 1000; // Set a random price for the item
        item_max_bid[items_sold] = (item_price[items_sold] * 120) / 100; // Set the maximum bid for the item
        
        printf("\nItem %d is up for Auction\n", item_number);
        printf("Starting price: $%d\n", item_price[items_sold]);
        printf("Maximum bid allowed: $%d\n", item_max_bid[items_sold]);
        
        // Bidding Loop
        while(1){
            printf("Enter your bid amount in dollars: $");
            scanf("%d", &current_bid);
            
            if(current_bid > item_price[items_sold] && current_bid <= item_max_bid[items_sold]){
                item_price[items_sold] = current_bid;
                printf("You are the current highest bidder! The current bid is now $%d\n", item_price[items_sold]);
                
                printf("Do you want to increase the maximum bid you are willing to offer for this item? (1 for Yes, 0 for No): ");
                scanf("%d", &bid_number);
                if(bid_number == 1){
                    printf("Enter the new maximum bid amount: $");
                    scanf("%d", &item_max_bid[items_sold]);
                }
                
            }
            else if(current_bid <= item_price[items_sold]){
                printf("The bid amount should be greater than the current highest bid of $%d\n", item_price[items_sold]);
            }
            else if(current_bid > item_max_bid[items_sold]){
                printf("Your bid exceeds the maximum allowed bid of $%d\n", item_max_bid[items_sold]);
            }
            
            printf("\n"); // Add some spacing
            
            // End bidding if maximum bid is reached
            if(item_price[items_sold] == item_max_bid[items_sold]){
                printf("Maximum bid for Item %d reached. The item is sold for $%d!\n", item_number, item_price[items_sold]);
                items_sold++; // Increment the number of items sold
                break; // Move on to next item
            }
        }
    }
    
    printf("\nThere are no more items up for Auction. Thank you for participating!\n");
    
    return 0;
}