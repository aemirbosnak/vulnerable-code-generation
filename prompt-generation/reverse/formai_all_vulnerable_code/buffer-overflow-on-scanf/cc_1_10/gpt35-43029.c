//FormAI DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BIDS 10
#define ITEM_NAME_SIZE 50
#define NAME_SIZE 20

typedef struct {
    char bidder_name[NAME_SIZE]; 
    int bid_amount;
} bid;

typedef struct {
    char item_name[ITEM_NAME_SIZE]; 
    int starting_price;
    bid bids[MAX_BIDS];
    int num_bids;
} item;

// Function to get input from user
int get_input(char *input_str, int size) {
    fgets(input_str, size, stdin);
    int len = strlen(input_str);
    if(input_str[len-1] == '\n') {
        input_str[len-1] = '\0';
    }
    return len;
}

// Function to print out all bids on an item
void print_bids(item *auction_items, int item_choice) {
    printf("\nBids for %s:\n", auction_items[item_choice].item_name);
    printf("Starting price: %d\n", auction_items[item_choice].starting_price);
    for(int i=0; i<auction_items[item_choice].num_bids; i++) {
        printf("%s bid %d gold coins.\n", auction_items[item_choice].bids[i].bidder_name, auction_items[item_choice].bids[i].bid_amount);
    }
}

int main() {
    printf("Welcome to the Medieval Digital Auction House!\n");
    int num_items;
    printf("How many items are up for auction?\n");
    scanf("%d", &num_items);
    getchar(); // Clear the buffer
    item auction_items[num_items];

    // Get item information from user
    for(int i=0; i<num_items; i++) {
        printf("\nWhat is the name of item %d?\n", i+1);
        get_input(auction_items[i].item_name, ITEM_NAME_SIZE);
        printf("What is the starting price of %s?\n", auction_items[i].item_name);
        scanf("%d", &auction_items[i].starting_price);
        getchar(); // Clear buffer
        auction_items[i].num_bids = 0;
    }

    printf("\nThe following items are being auctioned:\n");
    for(int i=0; i<num_items; i++) {
        printf("%d. %s (Starting price: %d)\n", i+1, auction_items[i].item_name, auction_items[i].starting_price);
    }

    int item_choice;
    while(1) { // Loop until user decides to exit
        printf("\nWhat would you like to do?\n");
        printf("1. View all items for auction\n");
        printf("2. View bids on an item\n");
        printf("3. Place a bid on an item\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                printf("\nThe following items are being auctioned:\n");
                for(int i=0; i<num_items; i++) {
                    printf("%d. %s (Starting price: %d)\n", i+1, auction_items[i].item_name, auction_items[i].starting_price);
                }
                break;

            case 2:
                printf("\nWhich item would you like to see bids for?\n");
                scanf("%d", &item_choice);
                getchar();
                item_choice--; // Convert to 0-indexing
                print_bids(auction_items, item_choice);
                break;

            case 3:
                printf("\nWhich item would you like to bid on?\n");
                scanf("%d", &item_choice);
                getchar();
                item_choice--; // Convert to 0-indexing
                printf("What is your name?\n");
                char name[NAME_SIZE];
                get_input(name, NAME_SIZE);
                printf("How much would you like to bid on %s?\n", auction_items[item_choice].item_name);
                int bid_amount;
                scanf("%d", &bid_amount);
                getchar();

                if(bid_amount > auction_items[item_choice].starting_price) {
                    if(auction_items[item_choice].num_bids < MAX_BIDS) {
                        // Add the bid to the list of bids for this item
                        strcpy(auction_items[item_choice].bids[auction_items[item_choice].num_bids].bidder_name, name);
                        auction_items[item_choice].bids[auction_items[item_choice].num_bids].bid_amount = bid_amount;
                        auction_items[item_choice].num_bids++;
                        printf("Bid placed!\n");
                    } else {
                        printf("Sorry, there have already been the maximum number of bids on this item.\n");
                    }
                } else {
                    printf("Sorry, your bid must be higher than the starting price of %d gold coins.\n", auction_items[item_choice].starting_price);
                }
                break;

            case 4:
                printf("\nThank you for bidding! Goodbye.\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}