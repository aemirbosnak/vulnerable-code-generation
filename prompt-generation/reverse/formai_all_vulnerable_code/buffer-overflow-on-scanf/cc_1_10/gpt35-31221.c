//FormAI DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 10
#define MAX_BID 10000

typedef struct {
    int id;
    char item_name[50];
    double current_bid;
    int bidder_id;
} auction_item;

int generate_bid(int max_bid) {
    srand(time(NULL));
    return rand() % max_bid + 1;
}

void display_item(auction_item item) {
    printf("Item id: %d\n", item.id);
    printf("Item name: %s\n", item.item_name);
    printf("Current bid: $%.2f\n", item.current_bid);
    printf("Bidder id: %d\n", item.bidder_id);
}

void display_auction_items(auction_item items[NUM_ITEMS]) {
    for(int i = 0; i < NUM_ITEMS; i++) {
        printf("Auction item #%d:\n", i+1);
        display_item(items[i]);
        printf("\n");
    }
}

int main() {
    auction_item auction_items[NUM_ITEMS] = {
        {1, "Vintage watch", 50.00, -1},
        {2, "Antique painting", 150.00, -1},
        {3, "Rare book", 75.00, -1},
        {4, "Diamond necklace", 5000.00, -1},
        {5, "Signed football jersey", 200.00, -1},
        {6, "Limited edition sculpture", 700.00, -1},
        {7, "Designer handbag", 250.00, -1},
        {8, "Framed movie poster", 30.00, -1},
        {9, "Musical instrument", 1000.00, -1},
        {10, "Vintage car", 15000.00, -1}
    };
    
    printf("Welcome to the digital auction system!\n");
    printf("There are %d items up for bid.\n", NUM_ITEMS);
    
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display all items\n");
        printf("2. Display item by id\n");
        printf("3. Place bid on item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                display_auction_items(auction_items);
                break;
            case 2:
                printf("Enter item id: ");
                int id_choice;
                scanf("%d", &id_choice);
                if(id_choice > NUM_ITEMS || id_choice <= 0) {
                    printf("Invalid item id.\n");
                } else {
                    display_item(auction_items[id_choice-1]);
                }
                break;
            case 3:
                printf("Enter item id: ");
                int bid_choice;
                scanf("%d", &bid_choice);
                if(bid_choice > NUM_ITEMS || bid_choice <= 0) {
                    printf("Invalid item id.\n");
                } else {
                    auction_item item = auction_items[bid_choice-1];
                    double bid = generate_bid(MAX_BID);
                    if(bid > item.current_bid) {
                        printf("Congratulations! You have the highest bid of $%.2f on %s.\n", bid, item.item_name);
                        item.bidder_id = rand() % 1000 + 1;
                        item.current_bid = bid;
                        auction_items[bid_choice-1] = item;
                    } else {
                        printf("Sorry, your bid of $%.2f is not higher than the current bid of $%.2f on %s.\n", bid, item.current_bid, item.item_name);
                    }
                }
                break;
            case 4:
                printf("Thank you for using the digital auction system.\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
        
    } while(choice != 4);
    
    return 0;
}