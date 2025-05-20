//FormAI DATASET v1.0 Category: Digital Auction System ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct item{
    char name[20];
    int bid;
}items[10];

int main(){
    int n = 0;
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        items[i].bid = rand()%1000;
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Starting bid for item %s is %d\n", items[i].name, items[i].bid);
    }
    printf("\nGet ready! The auction will start soon.\n");
    printf("Type 'q' to exit the auction anytime.\n\n");
    while(n < 10){
        int temp_bid = 0, bid_index;
        char choice;
        printf("The current bid for item %s is %d. Enter your bid: ", items[n].name, items[n].bid);
        scanf("%d", &temp_bid);
        if(temp_bid <= items[n].bid){
            printf("Sorry, your bid must be higher than the current one.\n");
            continue;
        }
        items[n].bid = temp_bid;
        printf("Bid accepted. The new bid for item %s is %d\n", items[n].name, items[n].bid);
        printf("Do you want to bid for the next item? (y/n): ");
        scanf(" %c", &choice);
        if(choice == 'n'){
            bid_index = rand()%10;
            while(bid_index == n){
                bid_index = rand()%10;
            }
            printf("Congratulations! You won the auction for item %s by bidding %d\n", items[n].name, items[n].bid);
            printf("The next item is %s with a starting bid of %d\n", items[bid_index].name, items[bid_index].bid);
            n = bid_index;
        }else if(choice == 'q'){
            printf("Thanks for participating in the auction. Have a nice day!\n");
            return 0;
        }else{
            n++;
        }
    }
    printf("Congratulations! You won the auction for item %s by bidding %d\n", items[n-1].name, items[n-1].bid);
    printf("Thanks for participating in the auction. Have a nice day!\n");
    return 0;
}