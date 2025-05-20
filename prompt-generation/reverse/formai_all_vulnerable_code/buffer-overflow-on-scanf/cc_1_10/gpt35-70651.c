//FormAI DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,k;
    int bid[10],price[10];
    char buyer[10][50],seller[10][50];

    printf("===============Welcome to the Digital Auction System===============\n\n");

    //Enter Buyer details
    for(i=0;i<5;i++)
    {
        printf("Enter Buyer %d name: ",i+1);
        scanf("%s",&buyer[i]);
    }

    //Enter Seller Details
    for(i=0;i<5;i++)
    {
        printf("\nEnter Seller %d name: ",i+1);
        scanf("%s",&seller[i]);
    }

    //Instructions for Buyers
    printf("\nDear Buyers,\n\nThis is a digital auction system. You can bid for items sold by the sellers and the highest bid wins the item. Good Luck!\n\n");

    //Enter Item details
    for(i=0;i<5;i++)
    {
        printf("Enter Item %d Starting Price: $",i+1);
        scanf("%d",&price[i]);
    }

    //Bidding Starts
    srand(time(0));
    for(i=0;i<5;i++)
    {
        printf("\n\nItem %d Bidding Has Started!\n",i+1);
        for(j=0;j<5;j++)
        {
            printf("\nBid for Item %d by %s: $",i+1,buyer[j]);
            scanf("%d",&bid[j]);
        }
        int win_bid = bid[0], win_bid_idx = 0;
        for(j=1;j<5;j++)
        {
            if(bid[j]>win_bid)
            {
                win_bid = bid[j];
                win_bid_idx = j;
            }
        }
        printf("%s Has Won Item %d for $%d\n",buyer[win_bid_idx],i+1,win_bid);
    }

    printf("\n\nThank You For Using Our Digital Auction System!\n\n");
    return 0;
}