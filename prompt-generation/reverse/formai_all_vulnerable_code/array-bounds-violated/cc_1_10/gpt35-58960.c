//FormAI DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define DEFAULT_STARTING_PRICE 100
#define MAX_ITEMS 5

typedef struct {
    int id;
    char name[50];
    int current_bid;
    int highest_bidder_id;
} item;

typedef struct {
    int id;
    char name[50];
    int balance;
} bidder;

item items[MAX_ITEMS];
bidder bidders[MAX_BIDDERS];

int num_bidders = 0;
int num_items = 0;

void run_auction();
void display_menu();
void add_bidder();
void add_item();
void place_bid();

int main() {
    int choice;
    
    do {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                add_bidder();
                break;
            case 2:
                add_item();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                run_auction();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1-5.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

void run_auction() {
    int i, j;
    int current_bid, highest_bid;
    int highest_bidder_id;
    char input;

    for(i = 0; i < num_items; i++) {
        current_bid = items[i].current_bid;
        highest_bid = current_bid;
        highest_bidder_id = items[i].highest_bidder_id;

        printf("Item: %s\n", items[i].name);
        printf("Starting price: %d\n", DEFAULT_STARTING_PRICE);
        printf("Current bid: %d\n", current_bid);

        for(j = 0; j < num_bidders; j++) {
            if(bidders[j].balance >= highest_bid) {
                printf("%s has a balance of %d\n", bidders[j].name, bidders[j].balance);
                
                printf("Do you want to bid? (Y or N): ");
                scanf(" %c", &input);

                if(input == 'Y' || input == 'y') {
                    items[i].current_bid = highest_bid + 1;
                    highest_bid = items[i].current_bid;
                    highest_bidder_id = bidders[j].id;

                    printf("New bid: %d\n", highest_bid);
                }
            }
        }

        items[i].highest_bidder_id = highest_bidder_id;
        printf("Highest bid: %d\n", highest_bid);
        printf("Highest bidder: %s\n\n", bidders[highest_bidder_id].name);
    }
}

void display_menu() {
    printf("1. Add bidder\n");
    printf("2. Add item\n");
    printf("3. Place bid\n");
    printf("4. Run auction\n");
    printf("5. Exit\n\n");
}

void add_bidder() {
    if(num_bidders < MAX_BIDDERS) {
        bidder new_bidder;

        printf("Enter bidder name: ");
        scanf("%s", new_bidder.name);

        new_bidder.balance = 1000;
        new_bidder.id = num_bidders;

        bidders[num_bidders++] = new_bidder;
    }
    else {
        printf("Max number of bidders reached.\n");
    }
}

void add_item() {
    if(num_items < MAX_ITEMS) {
        item new_item;

        printf("Enter item name: ");
        scanf("%s", new_item.name);

        new_item.current_bid = DEFAULT_STARTING_PRICE;
        new_item.highest_bidder_id = -1;
        new_item.id = num_items;

        items[num_items++] = new_item;
    }
    else {
        printf("Max number of items reached.\n");
    }
}

void place_bid() {
    int bidder_id, item_id, bid_amount;

    printf("Enter bidder's ID: ");
    scanf("%d", &bidder_id);
    
    printf("Enter item's ID: ");
    scanf("%d", &item_id);

    printf("Enter bid amount: ");
    scanf("%d", &bid_amount);

    if(bidders[bidder_id].balance >= bid_amount && bid_amount > items[item_id].current_bid) {
        bidders[bidder_id].balance -= bid_amount;
        items[item_id].current_bid = bid_amount;
        items[item_id].highest_bidder_id = bidder_id;

        printf("Bid successful.\n");
    }
    else {
        printf("Bid unsuccessful.\n");
    }
}