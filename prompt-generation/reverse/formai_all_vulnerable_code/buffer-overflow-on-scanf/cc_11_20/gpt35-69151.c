//FormAI DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct auction_item{
    char name[50];
    float base_price;
    float current_bid;
    char bidder[50];
};

int main(){
    int choice, num_items = 0;
    struct auction_item items[50];

    do{
        printf("\n------ Digital Auction System ------\n");
        printf("1. Add item for auction\n");
        printf("2. View items for auction\n");
        printf("3. Bid on an item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(num_items == 50){
                    printf("Maximum items reached!\n");
                    break;
                }
                printf("\nEnter item name: ");
                scanf("%s", items[num_items].name);
                printf("Enter base price: ");
                scanf("%f", &items[num_items].base_price);
                items[num_items].current_bid = items[num_items].base_price;
                strcpy(items[num_items].bidder, "None");
                printf("\nItem added successfully!\n");
                num_items++;
                break;

            case 2:
                if(num_items == 0){
                    printf("No items to display!\n");
                    break;
                }
                printf("\n------ Items for Auction ------\n");
                for(int i=0; i<num_items; i++){
                    printf("\nItem %d\n", i+1);
                    printf("Name: %s\n", items[i].name);
                    printf("Base Price: $%.2f\n", items[i].base_price);
                    printf("Current Bid: $%.2f\n", items[i].current_bid);
                    printf("Bidder: %s\n", items[i].bidder);
                }
                break;

            case 3:
                if(num_items == 0){
                    printf("No items to bid on!\n");
                    break;
                }
                int item_id;
                printf("\nEnter item ID to bid on: ");
                scanf("%d", &item_id);
                item_id--;
                if(item_id >= num_items){
                    printf("Invalid item ID!\n");
                    break;
                }
                float bid_amount;
                printf("Enter bid amount: ");
                scanf("%f", &bid_amount);
                if(bid_amount <= items[item_id].current_bid){
                    printf("Bid amount should be greater than current bid!\n");
                    break;
                }
                strcpy(items[item_id].bidder, "John Doe"); // Assume John Doe is the bidder
                items[item_id].current_bid = bid_amount;
                printf("\nBid successful!\n");
                break;

            case 4:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }while(1); // Infinite loop

    return 0;
}