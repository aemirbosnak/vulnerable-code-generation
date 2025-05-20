//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Bidder{
    char name[20];
    int bid;
    int coins;
};

int main(){
    int n, maxBid = 0, winnerIndex = -1;
    printf("Enter number of bidders: ");
    scanf("%d", &n);
    struct Bidder bidders[n];
    for(int i=0;i<n;i++){
        printf("Enter bidder %d name: ", i+1);
        scanf("%s", bidders[i].name);
        printf("Enter bidder %d coins: ", i+1);
        scanf("%d", &bidders[i].coins);
        bidders[i].bid = -1;
    }

    int expectedBids = n;
    while(expectedBids--){
        printf("\n\nNext item!\n");
        printf("Starting bid: ");
        scanf("%d", &maxBid);
        int i = 0;
        while(i < n){
            if(bidders[i].coins < maxBid){
                printf("%s is out of coins!\n", bidders[i].name);
                for(int j=i;j<n-1;j++){
                    bidders[j] = bidders[j+1];
                }
                n--;
            }
            else{
                int randBid = rand() % (bidders[i].coins - maxBid + 1) + maxBid;
                printf("%s's turn: ", bidders[i].name);
                scanf("%d", &bidders[i].bid);
                if(bidders[i].bid < randBid){
                    printf("Invalid bid!\n");
                }
                else{
                    bidders[i].coins -= bidders[i].bid;
                    maxBid = bidders[i].bid;
                    winnerIndex = i;
                }
                i++;
            }
        }
        printf("\n\nItem sold to %s for %d coins!\n", bidders[winnerIndex].name, bidders[winnerIndex].bid);
    }

    printf("\n\nBidding is complete!\n");
    printf("Final results:\n");
    for(int i=0;i<=winnerIndex;i++){
        printf("%s won an item for %d coins with %d coins left.\n", bidders[i].name, bidders[i].bid, bidders[i].coins);
    }
    for(int i=winnerIndex+1;i<n;i++){
        printf("%s can't afford to bid.\n", bidders[i].name);
    }
    return 0;
}