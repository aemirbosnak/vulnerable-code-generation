//FormAI DATASET v1.0 Category: Digital Auction System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int item_id;
    char item_name[50];
    double base_price;
    int num_bids;
    double highest_bid;
} Auction_Item;

void print_item(Auction_Item item){
    printf("Item ID: %d\n", item.item_id);
    printf("Item Name: %s\n", item.item_name);
    printf("Base Price: $%.2lf\n", item.base_price);
    printf("Number of Bids: %d\n", item.num_bids);
    printf("Highest Bid: $%.2lf\n", item.highest_bid);
}

int main(){
    int item_count;
    printf("Enter the number of auction items: ");
    scanf("%d", &item_count);
    Auction_Item* items = (Auction_Item*) malloc(item_count * sizeof(Auction_Item));
    for(int i = 0; i < item_count; i++){
        printf("Enter details for item %d:\n", i+1);
        items[i].item_id = i+1;
        printf("Name: ");
        scanf("%s", items[i].item_name);
        printf("Base Price: $");
        scanf("%lf", &items[i].base_price);
        items[i].num_bids = 0;
        items[i].highest_bid = items[i].base_price;
        printf("\n");
    }
    char choice;
    do{
        printf("Enter choice:\n");
        printf("1. View items\n");
        printf("2. Place Bid\n");
        printf("3. Exit\n");
        choice = getchar();
        getchar(); // to clear the '\n' from the buffer
        switch(choice){
            case '1':
                printf("Auction Items:\n");
                for(int i = 0; i < item_count; i++){
                    printf("Item %d:\n", i+1);
                    print_item(items[i]);
                    printf("\n");
                }
                break;

            case '2':
                printf("Enter Item ID to Bid: ");
                int bid_id;
                scanf("%d", &bid_id);
                if(bid_id > item_count || bid_id < 1){
                    printf("Invalid Item ID!\n");
                    break;
                }
                printf("Current Highest Bid for %s: $%.2lf\n", items[bid_id-1].item_name, items[bid_id-1].highest_bid);
                double new_bid;
                printf("Enter New Bid: $");
                scanf("%lf", &new_bid);
                if(new_bid <= items[bid_id-1].highest_bid){
                    printf("Bid must be higher than current bid!\n");
                    break;
                }
                items[bid_id-1].num_bids++;
                items[bid_id-1].highest_bid = new_bid;
                printf("Bid Successful!\n");
                break;

            case '3':
                printf("Exiting Auction...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    }while(choice != '3');
    free(items);
    return 0;
}