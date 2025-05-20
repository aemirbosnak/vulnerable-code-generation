//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BIDS 10 // maximum number of bids allowed

typedef struct{
    char name[20]; // bidder name
    float amount; // bid amount
} Bid;

int main(){
    Bid bids[MAX_BIDS]; // array of bids
    int num_bids = 0; // number of bids made
    
    char item_name[30]; // name of the item being auctioned
    float min_bid; // minimum bid required
    int auction_time; // time in minutes for auction
    
    printf("Enter the name of the item being auctioned: ");
    scanf("%s", item_name);
    
    printf("Enter the minimum bid required: ");
    scanf("%f", &min_bid);
    
    printf("Enter the time for auction (in minutes): ");
    scanf("%d", &auction_time);
    
    char input[20]; // input for menu
    
    int time_left = auction_time; // time left for auction
    while(time_left > 0){
        printf("Time left: %d minutes\n", time_left);
        printf("Menu:\n");
        printf("1. View item details\n");
        printf("2. Place bid\n");
        printf("3. View current bids\n");
        printf("Enter option: ");
        
        scanf("%s", input);
        
        int option = atoi(input);
        switch(option){
            case 1:
                printf("Item: %s\n", item_name);
                printf("Minimum bid required: %.2f\n", min_bid);
                break;
            case 2:
                if(num_bids < MAX_BIDS){
                    Bid new_bid;
                    
                    printf("Enter your name: ");
                    scanf("%s", new_bid.name);
                    
                    printf("Enter your bid amount: ");
                    scanf("%f", &new_bid.amount);
                    
                    if(new_bid.amount >= min_bid){
                        bids[num_bids++] = new_bid;
                        printf("Bid placed successfully!\n");
                    }
                    else{
                        printf("Bid amount too low!\n");
                    }
                }
                else{
                    printf("Maximum number of bids reached!\n");
                }
                break;
            case 3:
                printf("Current Bids:\n");
                for(int i=0; i<num_bids; i++){
                    printf("%s : %.2f\n", bids[i].name, bids[i].amount);
                }
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
        
        time_left--;
    }
    
    printf("Auction over!\n");
    printf("Winner: %s\n", bids[num_bids-1].name);
    printf("Winning bid: %.2f\n", bids[num_bids-1].amount);
    
    return 0;
}