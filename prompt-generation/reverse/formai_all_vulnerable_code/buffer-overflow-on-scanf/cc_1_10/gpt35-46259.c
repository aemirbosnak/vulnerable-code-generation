//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct auction_item {
    char* name;
    float starting_price;
    float current_bid;
    char* highest_bidder;
} AuctionItem;

void print_item(AuctionItem* item) {
    printf("Item Name: %s\n", item->name);
    printf("Starting Price: $%.2f\n", item->starting_price);
    printf("Current Bid: $%.2f\n", item->current_bid);
    printf("Highest Bidder: %s\n", item->highest_bidder);
}

int main() {
    int num_items, choice;
    printf("Welcome to the Digital Auction System!\n");
    printf("How many items will be auctioned off today?\n");
    scanf("%d", &num_items);

    AuctionItem* items = malloc(num_items * sizeof(AuctionItem));
    for(int i = 0; i < num_items; i++) {
        items[i].name = malloc(100 * sizeof(char)); // assuming the item name will be less than 100 characters
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter the starting price of %s: ", items[i].name);
        scanf("%f", &items[i].starting_price);
        items[i].current_bid = items[i].starting_price;
        items[i].highest_bidder = malloc(100 * sizeof(char)); // assuming bidders name will be less than 100 characters
        strcpy(items[i].highest_bidder, "None");
        printf("\n");
    }

    while(1) {
        printf("Which item would you like to bid on?\n");
        for(int i = 0; i < num_items; i++) {
            printf("%d. %s\n", i+1, items[i].name);
        }
        printf("%d. Exit\n", num_items+1);
        scanf("%d", &choice);
        if(choice == num_items+1) {
            printf("Thank you for using the Digital Auction System!\n");
            break;
        }
        else if(choice < 1 || choice > num_items) {
            printf("Invalid choice. Please try again.\n");
        }
        else {
            float bid_amount;
            printf("Enter your bid for %s: $", items[choice-1].name);
            scanf("%f", &bid_amount);
            if(bid_amount < items[choice-1].current_bid){
                printf("Bid amount must be higher than the current bid of $%.2f\n", items[choice-1].current_bid);
            }
            else {
                items[choice-1].current_bid = bid_amount;
                char bidder_name[100];
                printf("Congratulations! You are the highest bidder for %s with a bid of $%.2f.\n", items[choice-1].name, bid_amount);
                printf("Please enter your name: ");
                scanf("%s", bidder_name);
                strcpy(items[choice-1].highest_bidder, bidder_name);
                printf("\n");
            }
        }
    }

    // free allocated memory
    for(int i = 0; i < num_items; i++) {
        free(items[i].name);
        free(items[i].highest_bidder);
    }
    free(items);
    return 0;
}