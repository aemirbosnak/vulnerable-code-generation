//FormAI DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 50 //maximum length of the item name
#define MAX_LIST 100 //maximum number of items that can be put for auction
#define MIN_PRICE 100 //minimum price that can be set for the item
#define MAX_BIDS 100 //maximum number of bids that can be placed on an item
#define MAX_BIDDERS 10 //maximum number of bidders that can participate in an auction

//Structure for an item
typedef struct item{
    int item_id; //unique id of item
    char name[MAX_NAME]; //name of the item
    int current_bid_price; //current price of the item
    int min_bid_price; //minimum bid price for the item
    int num_bids; //number of bids on the item
    int max_bids; //maximum number of bids that can be placed on the item
    int bidder_ids[MAX_BIDS]; //IDs of bidders who have placed bids on the item
    int bid_prices[MAX_BIDS]; //prices of bids placed on the item
    int num_bidders; //number of bidders currently participating in the bid
} ITEM;

//Structure for a bidder
typedef struct bidder{
    int bidder_id; //unique id of bidder
    char name[MAX_NAME]; //name of the bidder
    int balance; //amount of money the bidder has
    int num_bids; //number of bids placed by the bidder
    int max_bids; //maximum number of bids that the bidder can place
    int bid_item_ids[MAX_BIDS]; //IDs of items on which the bidder has placed bids
    int bid_prices[MAX_BIDS]; //prices of bids placed by the bidder
} BIDDER;

ITEM items[MAX_LIST];
BIDDER bidders[MAX_BIDDERS];

int num_items = 0, num_bidders = 0; //global variables to keep track of the number of items and bidders

//Function to add a new item to the auction
void add_item(){
    if(num_items >= MAX_LIST){ //If maximum number of items has been reached
        printf("The auction cannot hold more items.");
        return;
    }
    else{
        printf("Enter the name of the item: ");
        scanf("%s", items[num_items].name);
        printf("Enter the minimum bid price: ");
        scanf("%d", &items[num_items].min_bid_price);
        if(items[num_items].min_bid_price < MIN_PRICE){ //If minimum bid price is too low
            printf("The minimum bid price for an item is %d", MIN_PRICE);
            return;
        }
        else{
            items[num_items].item_id = num_items + 1;
            items[num_items].current_bid_price = items[num_items].min_bid_price;
            printf("Enter the maximum number of bids: ");
            scanf("%d", &items[num_items].max_bids);
            items[num_items].num_bids = 0;
            items[num_items].num_bidders = 0;
            num_items++;
            printf("The item has been added to the auction.");
        }
    }
}

//Function to add a new bidder to the auction
void add_bidder(){
    if(num_bidders >= MAX_BIDDERS){ //If maximum number of bidders has been reached
        printf("The auction cannot accomodate more bidders.");
        return;
    }
    else{
        printf("Enter the name of the bidder: ");
        scanf("%s", bidders[num_bidders].name);
        printf("Enter the balance of the bidder: ");
        scanf("%d", &bidders[num_bidders].balance);
        bidders[num_bidders].bidder_id = num_bidders + 1;
        printf("Enter the maximum number of bids the bidder can make: ");
        scanf("%d", &bidders[num_bidders].max_bids);
        bidders[num_bidders].num_bids = 0;
        num_bidders++;
        printf("The bidder has been added to the auction.");
    }
}

//Function to display the list of items currently available for auction
void display_items(){
    printf("\nList of items currently available for auction:\n");
    printf("ID\tITEM NAME\tMINIMUM BID PRICE\t\tCURRENT BID PRICE\t\tNUMBER OF BIDS\n");
    for(int i=0;i<num_items;i++){
        printf("%d\t%s\t\t%d\t\t\t%d\t\t\t%d\n", items[i].item_id, items[i].name, items[i].min_bid_price, items[i].current_bid_price, items[i].num_bids);
    }
}

//Function to display the list of bidders currently participating in the auction
void display_bidders(){
    printf("\nList of bidders currently participating in the auction:\n");
    printf("ID\tBIDDER NAME\tBALANCE\t\tMAXIMUM BIDS\t\tNUMBER OF BIDS\n");
    for(int i=0;i<num_bidders;i++){
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\n", bidders[i].bidder_id, bidders[i].name, bidders[i].balance, bidders[i].max_bids, bidders[i].num_bids);
    }
}

//Function to place a bid on an item
void place_bid(){
    int item_id, bidder_id, bid_price;
    printf("Enter the ID of the item you want to bid on: ");
    scanf("%d", &item_id);
    if(item_id < 1 || item_id > num_items){ //If the item ID entered is invalid
        printf("Invalid item ID.");
        return;
    }
    else{
        printf("Enter your bidder ID: ");
        scanf("%d", &bidder_id);
        if(bidder_id < 1 || bidder_id > num_bidders){ //If the bidder ID entered is invalid
            printf("Invalid bidder ID.");
            return;
        }
        else{
            printf("Enter your bid price: ");
            scanf("%d", &bid_price);
            if(bid_price <= items[item_id-1].current_bid_price){ //If the bid price entered is not higher than the current bid price
                printf("Your bid price should be higher than the current bid price.");
                return;
            }
            else if(bid_price > bidders[bidder_id-1].balance){ //If the bidder's balance is insufficient to place the bid
                printf("Insufficient balance.");
                return;
            }
            else if(items[item_id-1].num_bids >= items[item_id-1].max_bids){ //If the maximum number of bids on the item has been reached
                printf("The maximum number of bids for this item has been reached.");
                return;
            }
            else if(bidders[bidder_id-1].num_bids >= bidders[bidder_id-1].max_bids){ //If the maximum number of bids that the bidder can place has been reached
                printf("You have already reached the maximum number of bids you can make.");
                return;
            }
            else{
                //Update item information
                items[item_id-1].current_bid_price = bid_price;
                items[item_id-1].bidder_ids[items[item_id-1].num_bids] = bidder_id;
                items[item_id-1].bid_prices[items[item_id-1].num_bids] = bid_price;
                items[item_id-1].num_bids++;
                if(items[item_id-1].num_bids == 1){
                    items[item_id-1].num_bidders++;
                }

                //Update bidder information
                bidders[bidder_id-1].balance -= bid_price;
                bidders[bidder_id-1].bid_item_ids[bidders[bidder_id-1].num_bids] = item_id;
                bidders[bidder_id-1].bid_prices[bidders[bidder_id-1].num_bids] = bid_price;
                bidders[bidder_id-1].num_bids++;

                printf("Your bid has been placed successfully.");
            }
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("\nWelcome to the Digital Auction System\n");
        printf("1. Add an item to the auction\n");
        printf("2. Add a bidder to the auction\n");
        printf("3. Display the list of items\n");
        printf("4. Display the list of bidders\n");
        printf("5. Place a bid\n");
        printf("6. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_item();
                    break;
            case 2: add_bidder();
                    break;
            case 3: display_items();
                    break;
            case 4: display_bidders();
                    break;
            case 5: place_bid();
                    break;
            case 6: printf("Thank you for using the Digital Auction System.");
                    exit(0);
            default: printf("Invalid choice. Please try again.");
                     break;
        }
    }
    return 0;
}