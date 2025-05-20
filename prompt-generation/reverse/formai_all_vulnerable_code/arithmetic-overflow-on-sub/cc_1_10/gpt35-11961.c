//FormAI DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 20

typedef struct Bidder {
    char name[20];
    int raised_amount;
} Bidder;

typedef struct Item {
    char name[20];
    int id;
    int current_bid;
    Bidder current_bidder;
} Item;

int main() {
    int bidders_num, items_num, bidder_choice, item_choice, bid_amount;
    Bidder bidders[MAX_BIDDERS];
    Item items[MAX_ITEMS];
    srand(time(NULL));

    printf("Welcome to our digital auction system!\n\n");
    printf("Please enter the number of bidders (up to %d):\n", MAX_BIDDERS);
    scanf("%d", &bidders_num);

    printf("\nPlease enter the number of items (up to %d):\n", MAX_ITEMS);
    scanf("%d", &items_num);

    printf("\nGreat! Now let's register the bidders:\n");
    for (int i = 0; i < bidders_num; i++) {
        printf("Enter bidder %d's name:\n", i+1);
        scanf("%s", bidders[i].name);
        bidders[i].raised_amount = 0;
    }

    printf("\nNext, let's add the items to the auction:\n");
    for (int i = 0; i < items_num; i++) {
        printf("Enter the name of item %d:\n", i+1);
        scanf("%s", items[i].name);
        items[i].id = i+1;
        items[i].current_bid = rand() % 100; // starting bid randomized between 0-99
    }

    printf("\nAlright, the auction is now open!\n");
    while (1) {
        printf("\nHere are the current items on auction:\n");
        for (int i = 0; i < items_num; i++) {
            printf("%d. %s\n", items[i].id, items[i].name);
            printf("Current bid: $%d by bidder %s\n", items[i].current_bid, items[i].current_bidder.name);
            printf("----------------------------------------------------\n");
        }

        printf("Enter your bidder number (1-%d) or 0 to exit:\n", bidders_num);
        scanf("%d", &bidder_choice);
        if (bidder_choice == 0) {
            break;
        }

        printf("Welcome bidder %s! Which item would you like to bid on? (Enter item number):\n", bidders[bidder_choice-1].name);
        scanf("%d", &item_choice);

        printf("Enter the amount you would like to bid on item %s (current bid: $%d):\n", items[item_choice-1].name, items[item_choice-1].current_bid);
        scanf("%d", &bid_amount);

        if (bid_amount > items[item_choice-1].current_bid) {
            // update current bidder and current bid
            items[item_choice-1].current_bidder = bidders[bidder_choice-1];
            items[item_choice-1].current_bid = bid_amount;

            // update bidder's raised amount
            bidders[bidder_choice-1].raised_amount += bid_amount;

            printf("\nCongratulations bidder %s! You are now the leading bidder for %s with a bid of $%d!\n", bidders[bidder_choice-1].name, items[item_choice-1].name, bid_amount);
        } else {
            printf("\nSorry bidder %s, your bid of $%d is not higher than the current bid of $%d for item %s\n", bidders[bidder_choice-1].name, bid_amount, items[item_choice-1].current_bid, items[item_choice-1].name);
        }
    }

    printf("\nThank you for participating!\n");

    return 0;
}