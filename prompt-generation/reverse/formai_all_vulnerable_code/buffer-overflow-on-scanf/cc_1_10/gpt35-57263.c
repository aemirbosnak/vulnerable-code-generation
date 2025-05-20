//FormAI DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int choice;
    int bid;
    int max_bid = 0;
    int winner;
    int count=0;
    char items[3][30]={"Item 1","Item 2","Item 3"};

    srand(time(NULL));

    printf("Welcome to the Digital Auction System\n\n");
    printf("Available Items:\n");
    for (int i = 0; i < 3; i++){
        printf("%d. %s\n",i+1,items[i]);
    }
    printf("\nEnter the item number you want to bid on:");
    scanf("%d",&choice);
    if (choice < 1 || choice > 3){
        printf("Invalid choice. Exiting program.\n");
        return 0;
    }
    printf("Item chosen: %s\n",items[choice-1]);
    printf("Bidding starts now. Starting price: $50\n");

    while(count<15){
        printf("Enter your bid for this item: $");
        scanf("%d",&bid);
        if (bid > max_bid){
            printf("Current highest bid: $%d\n",bid);
            max_bid = bid;
            winner = rand()%10;
        }
        else{
            printf("Your bid is less than the current highest bid.\n");
            continue;
        }
        count++;
    }

    printf("\n\n\n\nThe auction has ended for %s.\n",items[choice-1]);
    printf("The winner of the auction is Bidder %d with a bid of $%d\n",winner,max_bid);
    printf("Thank you for using the Digital Auction System.");

    return 0;
}