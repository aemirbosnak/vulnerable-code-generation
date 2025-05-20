//FormAI DATASET v1.0 Category: Digital Auction System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct to store information about each item being auctioned
struct auction_item{
    int item_id;
    char item_name[50];
    char item_description[100];
    float starting_bid;
    float highest_bid;
    char highest_bidder[50];
    int num_bids;
};

// Function to print the menu options
void print_menu(){
    printf("1. Add Item to Auction\n");
    printf("2. View Items in Auction\n");
    printf("3. Place Bid\n");
    printf("4. Exit\n");
}

// Main function
int main(){

    // Declare variables
    int choice;
    int num_items = 0;
    int item_id;
    char item_name[50];
    char item_description[100];
    float starting_bid;
    float highest_bid;
    char highest_bidder[50];
    int num_bids;
    int i;
    float bid_amount;

    // Allocate memory for the auction items array
    struct auction_item *auction_items = (struct auction_item*) malloc(sizeof(struct auction_item) * 10);

    do{
        // Print the menu
        print_menu();

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                // Add item to auction

                // Get the item details from the user
                printf("Enter the item ID: ");
                scanf("%d", &item_id);
                printf("Enter the item name: ");
                scanf("%s", item_name);
                printf("Enter the item description: ");
                scanf("%s", item_description);
                printf("Enter the starting bid: ");
                scanf("%f", &starting_bid);
                num_bids = 0;

                // Create a new auction item struct and add it to the array
                struct auction_item new_item = {
                    .item_id = item_id,
                    .starting_bid = starting_bid,
                    .highest_bid = starting_bid,
                    .num_bids = num_bids
                };
                strcpy(new_item.item_name, item_name);
                strcpy(new_item.item_description, item_description);
                strcpy(new_item.highest_bidder, "None");
                auction_items[num_items] = new_item;
                num_items++;
                printf("Item added successfully!\n");
                break;

            case 2:
                // View items in auction

                printf("Items in Auction:\n");
                for(i=0; i<num_items; i++){
                    printf("Item %d:\n", i+1);
                    printf("Item ID: %d\n", auction_items[i].item_id);
                    printf("Item Name: %s\n", auction_items[i].item_name);
                    printf("Item Description: %s\n", auction_items[i].item_description);
                    printf("Starting Bid: %.2f\n", auction_items[i].starting_bid);
                    printf("Highest Bid: %.2f\n", auction_items[i].highest_bid);
                    printf("Highest Bidder: %s\n", auction_items[i].highest_bidder);
                    printf("Number of Bids: %d\n", auction_items[i].num_bids);
                    printf("\n");
                }
                break;

            case 3:
                // Place bid
                
                // Get the item ID and bid amount from the user
                printf("Enter the item ID: ");
                scanf("%d", &item_id);
                printf("Enter your bid amount: ");
                scanf("%f", &bid_amount);

                // Find the item in the array and update its information if the bid is higher than the previous bid
                for(i=0; i<num_items; i++){
                    if(auction_items[i].item_id == item_id){
                        if(bid_amount > auction_items[i].highest_bid){
                            auction_items[i].highest_bid = bid_amount;
                            strcpy(auction_items[i].highest_bidder, "You");
                            auction_items[i].num_bids++;
                            printf("Bid placed successfully!\n");
                        }
                        else{
                            printf("Your bid is not higher than the current highest bid.\n");
                        }
                        break;
                    }
                }
                if(i == num_items){
                    printf("Item not found in auction.\n");
                }
                break;

            case 4:
                // Exit the program
                printf("Exiting program.\n");
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }

    }while(choice != 4);

    free(auction_items);
    return 0;
}