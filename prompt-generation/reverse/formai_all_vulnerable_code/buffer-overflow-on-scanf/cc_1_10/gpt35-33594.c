//FormAI DATASET v1.0 Category: Digital Auction System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct auction{  
    char item_name[100];
    int base_price;
    int bid_price;
    char current_bidder[20];
    int time_left;
} Auction;

void start_auction(Auction *item){
    printf("\nWelcome to our digital auction system.\n\n");
    printf("Please enter the following details about your item of choice...\n");

    printf("Item name: ");
    scanf("%s", item->item_name);

    printf("Base price: ");
    scanf("%d", &item->base_price);

    item->bid_price = item->base_price - 1;

    printf("\nAuction has started!\n\n");

    strcpy(item->current_bidder, "No one yet");

    item->time_left = 60;

    printf("Auction ends in %d seconds.\n\n", item->time_left);
}

void place_bid(Auction *item){
    int bid;
    char bidder_name[20];
    printf("\nCurrent bid: %d\n", item->bid_price);

    printf("Your name: ");
    scanf("%s", bidder_name);

    printf("Your bid: ");
    scanf("%d", &bid);

    if(bid > item->bid_price && bid >= (item->bid_price * 1.1)){
        item->bid_price = bid;
        strcpy(item->current_bidder, bidder_name);
    } 
    else {
        printf("\nSorry, your bid should be 10 percent higher than the current bid.\n");
    }

    printf("\nCurrent bid: %d\n", item->bid_price);
    printf("Current bidder: %s\n", item->current_bidder);
}

int main(){
    Auction item;
    start_auction(&item);

    int choice;

    do{
        printf("\nEnter 1 to place a bid or 2 to exit: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(item.time_left > 10){
                    place_bid(&item);
                    item.time_left -= 10;
                    printf("\nTime left: %d\n", item.time_left);
                } 
                else {
                    printf("\nSorry, auction has ended.\n");
                    exit(0);
                }
                break;

            case 2:
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}