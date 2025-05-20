//FormAI DATASET v1.0 Category: Digital Auction System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
    int n=5; //number of items to be auctioned
    int bid_price[n]; //array to store the highest bid price for each item
    int bidder[n]; //array to store the bidder ID for each item
    int item_price[n]; //array to store the starting price for each item
    int i, j;
    srand(time(NULL)); //to generate random bidder ID
    for(i=0;i<n;i++){
        item_price[i] = rand()%1000 + 100; //random starting price between $100 and $1000
        bid_price[i] = item_price[i]; //initial bid price for each item
        bidder[i] = 0; //initial bidder ID for each item
    }
    printf("Welcome to our digital auction system!\n");
    while(1){
        printf("Current auction items are:\n"); //show the current items being auctioned
        for(i=0;i<n;i++){
            printf("%d. Item %d with starting price $%d. Highest bid so far is $%d by bidder #%d\n", i+1, i+1, item_price[i], bid_price[i], bidder[i]);
        }
        printf("\n");
        int choice;
        printf("Enter the item number you want to bid on (or 0 to exit): ");
        scanf("%d", &choice);
        if(choice==0){
            printf("Thank you for using our digital auction system!\n");
            break; //exit the program
        }
        else if(choice<1 || choice>n){
            printf("Invalid choice. Please try again.\n\n");
            continue; //go back to the beginning of the while loop
        }
        else{
            printf("Enter your bidder ID (or 0 for new bidder): ");
            int new_bidder;
            scanf("%d", &new_bidder);
            if(new_bidder!=0){ //if a bidder ID is entered
                for(i=0;i<n;i++){
                    if(bidder[i]==new_bidder){ //check if the bidder has already placed bid
                        printf("You have already placed a bid on Item %d. Highest bid is $%d\n", i+1, bid_price[i]);
                        break; //go back to the beginning of the while loop
                    }
                }
            }
            else{ //if a new bidder is entering the auction
                new_bidder = rand()%100 + 1; //random bidder ID between 1 and 100
                printf("Your bidder ID is %d. Please remember this for future bids.\n", new_bidder);
            }
            printf("Enter your bid amount: ");
            int new_price;
            scanf("%d", &new_price);
            if(new_price<=bid_price[choice-1]){ //check if the new bid is higher than the current highest bid
                printf("Your bid is not high enough. Current highest bid is $%d\n", bid_price[choice-1]);
            }
            else{ //if the new bid is higher than the current highest bid
                printf("Congratulations! You are now the highest bidder for Item %d with a bid of $%d\n", choice, new_price);
                bidder[choice-1] = new_bidder;
                bid_price[choice-1] = new_price;
            }
            printf("\n");
        }
    }
    return 0;
}