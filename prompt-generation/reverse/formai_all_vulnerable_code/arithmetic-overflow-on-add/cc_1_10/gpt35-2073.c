//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct auction_item{
    int item_id;
    char item_name[50];
    float min_bid;
    float current_bid;
    int bidder_id;
};

struct bidder{
    int bidder_id;
    char bidder_name[50];
    float balance;
};

int num_items;
int num_bidders;

struct auction_item items[20];
struct bidder bidders[20];

void print_items(){
    printf("\n");
    printf("\t\tCurrent Items Up for Auction\n");
    printf("------------------------------------------------------------\n");
    printf("ID\tItem Name\tMin Bid\t\tCurrent Bid\tBidder ID\n");
    printf("------------------------------------------------------------\n");
    for(int i=0;i<num_items;i++){
        printf("%d\t%s\t\t%.2f\t\t%.2f\t\t%d\n",items[i].item_id,items[i].item_name,items[i].min_bid,items[i].current_bid,items[i].bidder_id);
    }
    printf("\n");
}

void print_bidders(){
    printf("\n");
    printf("\t\tRegistered Bidders\n");
    printf("------------------------------------------------------------\n");
    printf("ID\tBidder Name\tBalance\n");
    printf("------------------------------------------------------------\n");
    for(int i=0;i<num_bidders;i++){
        printf("%d\t%s\t\t%.2f\n",bidders[i].bidder_id,bidders[i].bidder_name,bidders[i].balance);
    }
    printf("\n");
}

void make_bid(int bidder_id,int item_id,float bid_amount){

    if(items[item_id].bidder_id==bidder_id){
        printf("You are already the highest bidder for this item.\n");
    }
    else if(bid_amount<items[item_id].min_bid){
        printf("Your bid amount is less than the minimum bid price.\n");
    }
    else if(bid_amount<=items[item_id].current_bid){
        printf("Your bid amount must be higher than the current bid price.\n");
    }
    else if(bidders[bidder_id].balance<bid_amount){
        printf("Your account balance is not sufficient to make this bid.\n");
    }
    else{
        items[item_id].current_bid = bid_amount;
        items[item_id].bidder_id = bidder_id;
        printf("Bid made successfully!\n");
    }
}

void end_auction(){
    printf("\n\n\t\tAUCTION RESULTS\n");
    printf("----------------------------------------------------------------------\n");
    printf("Item Name\t\t\tCurrent Bid\t\tBidder Name\n");
    printf("----------------------------------------------------------------------\n");
    for(int i=0;i<num_items;i++){
        printf("%s\t\t\t%.2f\t\t\t%s\n",items[i].item_name,items[i].current_bid,bidders[items[i].bidder_id].bidder_name);
    }
    printf("----------------------------------------------------------------------\n");
}


int main(){

    printf("\n\n---- Welcome to the Digital Auction System ----\n");

    printf("\nEnter the number of items up for auction : ");
    scanf("%d",&num_items);

    printf("\nEnter the number of bidders : ");
    scanf("%d",&num_bidders);

    for(int i=0;i<num_items;i++){
        printf("\nEnter details for Item %d : \n",i+1);
        printf("Item Name : ");
        fflush(stdin);
        gets(items[i].item_name);
        printf("Minimum bid price : ");
        scanf("%f",&items[i].min_bid);
        items[i].current_bid = items[i].min_bid;
        items[i].item_id = i+1;
        items[i].bidder_id = -1;
    }

    for(int i=0;i<num_bidders;i++){
        printf("\nEnter details for Bidder %d : \n",i+1);
        printf("Bidder Name : ");
        fflush(stdin);
        gets(bidders[i].bidder_name);
        printf("Account Balance : ");
        scanf("%f",&bidders[i].balance);
        bidders[i].bidder_id = i+1;
    }

    printf("\n\nAuction details have been set. Here are the details : \n");

    print_items();

    print_bidders();

    printf("\n\n---- Let the bidding begin! ----\n");

    srand(time(NULL));

    for(int i=0;i<7;i++){
        printf("\n\n---- Round %d of bidding ----\n",i+1);
        int bidder_id = (rand()%num_bidders)+1;
        int item_id = (rand()%num_items);
        float bid_amount = items[item_id].current_bid + (rand()%50)+1;
        printf("Bidder %s is bidding for Item %s with bid amount %.2f\n",bidders[bidder_id-1].bidder_name,items[item_id].item_name,bid_amount);
        make_bid(bidder_id-1,item_id,bid_amount);
        print_items();
    }

    end_auction();

    printf("\n\n---- Thank you for using the Digital Auction System ----\n");

    return 0;
}