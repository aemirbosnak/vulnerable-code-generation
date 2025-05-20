//FormAI DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int item_number;
    float bid_amount;
    char bidder_name[30];
}Bidder;

int main(){
    int num_items, num_bidders;
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    printf("Enter number of bidders: ");
    scanf("%d", &num_bidders);

    Bidder *bids[num_items];
    for(int i=0; i<num_items; i++){
        bids[i] = (Bidder*)malloc(num_bidders*sizeof(Bidder));
    }

    for(int i=0; i<num_items; i++){
        printf("Item %d\n", i+1);
        for(int j=0; j<num_bidders; j++){
            bids[i][j].item_number = i+1;
            printf("Bidder %d Name: ", j+1);
            scanf("%s", bids[i][j].bidder_name);
            printf("Bidder %d Amount: ", j+1);
            scanf("%f", &bids[i][j].bid_amount);
        }
        printf("\n");
    }

    printf("============================\n");
    printf("        AUCTION RESULTS     \n");
    printf("============================\n");

    for(int i=0; i<num_items; i++){
        float highest_bid = 0;
        char highest_bidder[30];
        for(int j=0; j<num_bidders; j++){
            if(bids[i][j].bid_amount > highest_bid){
                highest_bid = bids[i][j].bid_amount;
                strcpy(highest_bidder, bids[i][j].bidder_name);
            }
        }
        printf("Item %d:\n", i+1);
        printf("Highest Bid: $%.2f\n", highest_bid);
        printf("Highest Bidder: %s\n", highest_bidder);
        printf("\n");
    }

    for(int i=0; i<num_items; i++){
        free(bids[i]);
    }

    return 0;
}