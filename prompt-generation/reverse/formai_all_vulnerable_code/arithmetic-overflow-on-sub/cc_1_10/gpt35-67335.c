//FormAI DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i,j,n,temp;
    int bid;
    int max_bid = 0;
    int winner;
    int time_limit = 30;
    int start_time = time(NULL);
    int end_time = start_time + time_limit;

    printf("\nWelcome to the Digital Auction System\n");
    printf("Time limit for this auction is %d seconds\n", time_limit);
    printf("\nPlease enter number of bidders: ");
    scanf("%d",&n);

    int* bids = (int*)malloc(n*sizeof(int));
    char** bidder_name = (char**)malloc(n*sizeof(char*));

    for(i = 0; i < n; i++){
        bidder_name[i] = (char*)malloc(100*sizeof(char));
        printf("\nEnter name of bidder %d: ", i+1);
        scanf("%s", bidder_name[i]);
        printf("Enter the bid price: ");
        scanf("%d",&bids[i]);
        if(bids[i] > max_bid) {
            max_bid = bids[i];
            winner = i;
        }
    }

    printf("\nDigital Auction begins now!!!\n");
    while(time(NULL) < end_time){
        printf("Time left: %d seconds\n", end_time - time(NULL));
    }

    printf("\n\nAuction ends!!!\n");
    printf("The winner of the auction is: %s with the bid amount of $%d\n", bidder_name[winner], max_bid);

    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(bids[i] > bids[j]){
                temp = bids[i];
                bids[i] = bids[j];
                bids[j] = temp;

                char* temp_name = bidder_name[i];
                bidder_name[i] = bidder_name[j];
                bidder_name[j] = temp_name;
            }
        }
    }

    printf("\nBid summary:\n");
    for(i = n-1; i >= 0; i--){
        printf("%s bid $%d\n", bidder_name[i], bids[i]);
    }

    free(bids);
    for(i = 0; i < n; i++){
        free(bidder_name[i]);
    }
    free(bidder_name);

    return 0;
}