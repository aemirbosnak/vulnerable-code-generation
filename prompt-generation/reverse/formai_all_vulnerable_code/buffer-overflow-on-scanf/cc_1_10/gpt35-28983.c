//FormAI DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL)); // seeding of random number generator using current time
    
    // auction parameters
    int starting_price = 100;
    int current_bid;
    int min_increment = 10;
    int max_increment = 50;
    int auction_time = 30; // in seconds
    
    // bidder information
    char bidder_name[50];
    int bidder_bid;
    
    // auction initialization
    printf("Welcome to the Digital Auction System!\n\n");
    printf("Item for auction: Smart TV\n");
    printf("Starting price: $%d\n\n", starting_price);
    
    current_bid = starting_price;
    time_t start_time = time(NULL);
    time_t end_time = start_time + auction_time; // setting end time of auction
    
    // auction loop
    while(time(NULL) < end_time){
        // display current bid
        printf("Current bid: $%d\n", current_bid);
        
        // accept bidder's name and bid value
        printf("Enter your name: ");
        scanf("%s", bidder_name);
        
        printf("Enter your bid: ");
        scanf("%d", &bidder_bid);
        
        // check if bid is valid and higher than current bid
        if(bidder_bid < current_bid + min_increment){
            printf("Your bid is too low. Please bid higher than $%d\n", current_bid + min_increment);
        }
        else if(bidder_bid > current_bid + max_increment){
            printf("Your bid is too high. Please bid lower than $%d\n", current_bid + max_increment);
        }
        else{
            // update current bid and display successful bid
            current_bid = bidder_bid;
            printf("Congratulations, %s! Your bid of $%d is currently the highest.\n\n", bidder_name, current_bid);
        }
        
    }
    
    // display auction results
    printf("\n\nAuction is over!\n");
    printf("The highest bid was $%d by %s.\n", current_bid, bidder_name);
    printf("Congratulations to the winner!\n");
    
    return 0;
}