//FormAI DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Structure to hold item details
struct item{
    char name[50];
    int minBid;
    int currentBid;
    char bidder[20];
};

int main(){
    int numItems;
    printf("Enter the number of items to be auctioned: ");
    scanf("%d", &numItems);

    //Dynamically allocating memory for items
    struct item *items = (struct item*)malloc(numItems * sizeof(struct item));

    //Taking input for each item
    for(int i=0; i<numItems; i++){
        printf("Enter the name of the item %d: ", i+1);
        scanf("%s", items[i].name);

        printf("Enter the minimum bid for item %d: ", i+1);
        scanf("%d", &items[i].minBid);

        //Setting current bid to min bid initially
        items[i].currentBid = items[i].minBid;

        //Initial bidder is set to None
        strcpy(items[i].bidder, "None");
    }

    //Displaying item details
    printf("\n*********************AUCTION ITEMS**********************\n");
    for(int i=0; i<numItems; i++){
        printf("\nItem %d: %s\n", i+1, items[i].name);
        printf("Minimum bid: %d\n", items[i].minBid);
        printf("Current bid: %d\n", items[i].currentBid);
        printf("Current bidder: %s\n\n", items[i].bidder);
    }

    //Starting the bidding process
    int numBidders;
    printf("Enter the number of bidders: ");
    scanf("%d", &numBidders);

    int bids[numBidders][numItems];

    srand(time(NULL)); //Seeding the random number generator

    //Taking bids for each item from each bidder
    for(int i=0; i<numItems; i++){
        printf("\nBIDDING FOR ITEM %s HAS STARTED!\n", items[i].name);
        printf("Minimum bid: %d\n", items[i].minBid);
        for(int j=0; j<numBidders; j++){
            printf("\nBIDDER %d ENTER YOUR BID: ", j+1);
            scanf("%d", &bids[j][i]);
            //Randomly selecting a bidder as the current bidder if bid is higher than current bid
            if(bids[j][i] > items[i].currentBid){
                items[i].currentBid = bids[j][i];
                strcpy(items[i].bidder, "Bidder");
                char str[2];
                sprintf(str, "%d", j+1);
                strcat(items[i].bidder, str);
                printf("\nBID ACCEPTED\n");
            }
            else{
                printf("\nBID REJECTED\n");
            }
        }
        printf("\nBIDDING FOR ITEM %s HAS ENDED!\n", items[i].name);
    }

    //Displaying final item details
    printf("\n********************FINAL ITEM DETAILS*******************\n");
    for(int i=0; i<numItems; i++){
        printf("\nItem %d: %s\n", i+1, items[i].name);
        printf("Minimum bid: %d\n", items[i].minBid);
        printf("Current bid: %d\n", items[i].currentBid);
        printf("Current bidder: %s\n\n", items[i].bidder);
    }

    free(items); //Freeing dynamically allocated memory

    return 0;
}