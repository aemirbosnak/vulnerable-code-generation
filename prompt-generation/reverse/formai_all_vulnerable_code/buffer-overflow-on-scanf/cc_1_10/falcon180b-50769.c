//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef struct{
    int id;
    char name[50];
    char email[50];
    int bid;
}Bidder;

typedef struct{
    char name[50];
    int base_price;
}Item;

void createBidder(Bidder* bidder){
    printf("Enter bidder ID: ");
    scanf("%d",&bidder->id);
    printf("Enter bidder name: ");
    scanf("%s",bidder->name);
    printf("Enter bidder email: ");
    scanf("%s",bidder->email);
    bidder->bid = 0;
}

void displayBidder(Bidder bidder){
    printf("Bidder ID: %d\n",bidder.id);
    printf("Bidder Name: %s\n",bidder.name);
    printf("Bidder Email: %s\n",bidder.email);
    printf("Current Bid: %d\n",bidder.bid);
}

void createItem(Item* item){
    printf("Enter item name: ");
    scanf("%s",item->name);
    printf("Enter base price: ");
    scanf("%d",&item->base_price);
}

void displayItem(Item item){
    printf("Item Name: %s\n",item.name);
    printf("Base Price: %d\n",item.base_price);
}

int compareBidders(Bidder* bidder1,Bidder* bidder2){
    if(bidder1->bid > bidder2->bid)
        return 1;
    else if(bidder1->bid < bidder2->bid)
        return -1;
    else
        return 0;
}

int main(){
    int num_bidders,num_items,i,j;
    printf("Enter number of bidders: ");
    scanf("%d",&num_bidders);
    Bidder* bidders = (Bidder*)malloc(num_bidders*sizeof(Bidder));
    for(i=0;i<num_bidders;i++){
        createBidder(&bidders[i]);
    }

    printf("Enter number of items: ");
    scanf("%d",&num_items);
    Item* items = (Item*)malloc(num_items*sizeof(Item));
    for(i=0;i<num_items;i++){
        createItem(&items[i]);
    }

    int max_bid[num_items];
    for(i=0;i<num_items;i++){
        max_bid[i] = items[i].base_price;
    }

    int flag = TRUE;
    while(flag){
        flag = FALSE;
        for(i=0;i<num_items;i++){
            if(max_bid[i] == items[i].base_price){
                for(j=0;j<num_bidders;j++){
                    if(bidders[j].bid >= max_bid[i] && bidders[j].bid!= 0){
                        max_bid[i] = bidders[j].bid;
                        flag = TRUE;
                        break;
                    }
                }
            }
        }
    }

    printf("\nAuction Results:\n");
    for(i=0;i<num_items;i++){
        printf("Item %d:\n",i+1);
        displayItem(items[i]);
        printf("Highest Bid: %d\n",max_bid[i]);
        printf("Winner: ");
        for(j=0;j<num_bidders;j++){
            if(bidders[j].bid == max_bid[i] && bidders[j].bid!= 0){
                displayBidder(bidders[j]);
                break;
            }
        }
        printf("\n");
    }

    return 0;
}