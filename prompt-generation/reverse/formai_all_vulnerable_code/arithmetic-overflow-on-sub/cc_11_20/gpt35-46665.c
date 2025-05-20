//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 100
#define MAX_ITEM_NAME 50
#define MAX_SOLD_ITEMS 10

typedef struct{
    char item_name[MAX_ITEM_NAME];
    int min_bid;
    int current_bid;
    char bidder_name[20];
} Auction_Item;

typedef struct{
    Auction_Item items[MAX_SOLD_ITEMS];
    int num_sold;
} Sold_Items;

typedef struct{
    Auction_Item items[MAX_BIDS];
    int num_items;
} Auction_Items;

int main(){
    srand(time(0));
    Auction_Items auction_items;
    Sold_Items sold_items;
    auction_items.num_items = 0;
    sold_items.num_sold = 0;

    printf("Welcome to the Cyber Auction System!\n");

    while(1){
        printf("\nSelect an option:\n");
        printf("1. Add an auction item\n");
        printf("2. View current auction items\n");
        printf("3. Bid on an auction item\n");
        printf("4. View sold items\n");
        printf("5. Quit\n");

        int choice;
        scanf("%d", &choice);

        if(choice == 1){
            if(auction_items.num_items >= MAX_BIDS){
                printf("Maximum auction items reached. Cannot add more.\n");
            }
            else{
                Auction_Item new_item;
                printf("Enter item name: ");
                scanf("%s", new_item.item_name);
                printf("Enter minimum bid: ");
                scanf("%d", &new_item.min_bid);
                new_item.current_bid = new_item.min_bid;
                strcpy(new_item.bidder_name, "None");
                auction_items.items[auction_items.num_items] = new_item;
                auction_items.num_items++;
                printf("New auction item added!\n");
            }
        }
        else if(choice == 2){
            printf("Current auction items:\n");
            printf("%-20s %-10s %-10s\n", "Item Name", "Min Bid", "Current Bid");
            for(int i = 0; i < auction_items.num_items; i++){
                printf("%-20s %-10d %-10d\n", auction_items.items[i].item_name, 
                auction_items.items[i].min_bid, auction_items.items[i].current_bid);
            }
        }
        else if(choice == 3){
            printf("Enter the item number to bid on: ");
            int item_num;
            scanf("%d", &item_num);
            item_num--; // adjust for 0-based array index
            
            if(item_num >= auction_items.num_items || item_num < 0){
                printf("Invalid item number.\n");
                continue;
            }

            Auction_Item* item = &auction_items.items[item_num];
            printf("You are bidding on item: %s\n", item->item_name);
            printf("The current bid is: %d\n", item->current_bid);
            printf("What is your bid? ");
            int new_bid;
            scanf("%d", &new_bid);
            if(new_bid <= item->current_bid){
                printf("Sorry, your bid is too low. Please try again.\n");
            }
            else{
                printf("Congratulations! You are now the highest bidder.\n");
                item->current_bid = new_bid;
                printf("Please enter your name for the bidder list: ");
                char bidder[20];
                scanf("%s", bidder);
                strcpy(item->bidder_name, bidder);
            }
        }
        else if(choice == 4){
            printf("Sold items:\n");
            printf("%-20s %-10s %-10s %-20s\n", "Item Name", "Min Bid", "Final Bid", "Bidder Name");
            for(int i = 0; i < sold_items.num_sold; i++){
                Auction_Item item = sold_items.items[i];
                printf("%-20s %-10d %-10d %-20s\n", item.item_name, item.min_bid, item.current_bid, item.bidder_name);
            }
        }
        else if(choice == 5){
            printf("Thank you for using the Cyber Auction System!\n");
            break;
        }
        else{
            printf("Invalid choice. Please try again.\n");
        }

        // Check for sold items and move them to the sold items list
        for(int i = 0; i < auction_items.num_items; i++){
            Auction_Item* item = &auction_items.items[i];
            if(item->current_bid > item->min_bid && rand()%2 == 0){
                printf("Item %s has been sold to %s for %d.\n", item->item_name, item->bidder_name, item->current_bid);
                sold_items.items[sold_items.num_sold] = *item;
                sold_items.num_sold++;
                // remove from auction items list by moving last item to current index
                auction_items.items[i] = auction_items.items[auction_items.num_items-1];
                auction_items.num_items--;
                i--; // check the item that got moved to this index
            }
        }
    }
    return 0;
}