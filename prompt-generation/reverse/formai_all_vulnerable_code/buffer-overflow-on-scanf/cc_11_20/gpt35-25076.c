//FormAI DATASET v1.0 Category: Digital Auction System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Structure for the auction item
typedef struct auction_item{
    int item_id;
    char item_name[50];
    int starting_bid;
    int current_bid;
    char highest_bidder[50];
} AuctionItem;

int main(){
    // Initialization of necessary variables
    int num_items = 5, choice, bid_amount;
    AuctionItem items[num_items];

    // Seed the random number generator for random starting bids
    srand(time(0));

    // Setup of the auction items
    for(int i=0; i<num_items; i++){
        items[i].item_id = i+1;
        printf("Enter item %d name: ", i+1);
        scanf("%s", items[i].item_name);
        items[i].starting_bid = rand()%1000; // Random starting bid between 0 and 1000
        items[i].current_bid = items[i].starting_bid;
        strcpy(items[i].highest_bidder, "No bids");
    }

    // Auction menu
    do{
        printf("\n\n---------\nAUCTION MENU\n---------\n");
        printf("1. View auction items\n");
        printf("2. Place a bid\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: // View auction items
                printf("\n\n---------\nAUCTION ITEMS\n---------");
                printf("\nItem ID\tItem Name\tStarting Bid\tCurrent Bid\tHighest Bidder\n");
                for(int i=0; i<num_items; i++){
                    printf("%d\t%s\t%d\t%d\t%s\n", items[i].item_id, items[i].item_name, items[i].starting_bid, items[i].current_bid, items[i].highest_bidder);
                }
                break;

            case 2: // Place a bid
                printf("Enter item ID to bid for: ");
                scanf("%d", &choice);
                printf("Enter bid amount: ");
                scanf("%d", &bid_amount);

                for(int i=0; i<num_items; i++){ // Find the item to bid for
                    if(items[i].item_id == choice){
                        if(bid_amount > items[i].current_bid){ // Check if the bid is greater than current bid
                            items[i].current_bid = bid_amount;
                            printf("Bid successful!\n");
                            printf("New current bid for %s is %d\n", items[i].item_name, items[i].current_bid);
                            printf("Enter your name: ");
                            scanf("%s", items[i].highest_bidder);
                        }
                        else{
                            printf("Bid amount should be greater than current bid!\n");
                        }
                        break;
                    }
                    else if(i == num_items-1){
                        printf("Invalid item ID entered!\n");
                    }
                }
                break;

            case 3: // Exit
                printf("Thank you for using the auction system.\n");
                exit(0);

            default:
                printf("Invalid choice entered!\n");
        }

    } while(1);
    
    return 0;
}