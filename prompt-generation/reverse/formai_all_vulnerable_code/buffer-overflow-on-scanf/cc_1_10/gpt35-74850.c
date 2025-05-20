//FormAI DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 10
#define AUCTION_TIME 15.0
#define BIDDING_TIME 5.0

typedef struct item {
    char name[20];
    int id;
    float current_bid;
    char bidder[20];
} Item;

void generate_random_items(Item items[MAX_ITEMS]);
void print_items(Item items[MAX_ITEMS]);
int get_user_input();
Item get_highest_bidder(Item item, float new_bid);

int main() {
    Item items[MAX_ITEMS];
    generate_random_items(items);
    printf("Welcome to the Online Auction System!\n");
    printf("We have the following items for auction:\n\n");
    print_items(items);
    printf("\nEnter the ID number of the item you wish to place a bid on: ");
    int item_id = get_user_input();
    if (item_id < 1 || item_id > MAX_ITEMS) {
        printf("Invalid input. Closing Auction System.\n");
        return 1;
    }
    Item chosen_item = items[item_id - 1];
    printf("\nThe current highest bidder for %s is %s with a bid of %.2f\n", chosen_item.name, chosen_item.bidder, chosen_item.current_bid);
    printf("The auction for %s will start in %d seconds.\n", chosen_item.name, (int)AUCTION_TIME);
    /* Auction timer starts */
    float time_left = AUCTION_TIME;
    while (time_left > 0.0) {
        time_left -= 1.0;
        printf("Time left: %.0f seconds\n", time_left);
        sleep(1);
    }
    printf("\n%s is up for bidding! Enter your highest bid within 5 seconds: ", chosen_item.name);
    /* Bidding timer starts */
    time_left = BIDDING_TIME;
    while (time_left > 0.0) {
        time_left -= 1.0;
        int new_bid = get_user_input();
        if (new_bid > chosen_item.current_bid) {
            chosen_item = get_highest_bidder(chosen_item, (float)new_bid);
            printf("Highest bid so far is %.2f by %s\n", chosen_item.current_bid, chosen_item.bidder);
        }
    }
    printf("The auction for %s is now closed. The highest bidder is %s with a bid of %.2f. Thank you for participating!\n\n", chosen_item.name, chosen_item.bidder, chosen_item.current_bid);
    return 0;
}

void generate_random_items(Item items[MAX_ITEMS]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_ITEMS; i++) {
        Item new_item;
        sprintf(new_item.name, "Item-%d", i+1);
        new_item.id = i+1;
        new_item.current_bid = (float)rand()/(float)(RAND_MAX/1000);
        sprintf(new_item.bidder, "N/A");
        items[i] = new_item;
    }
}

void print_items(Item items[MAX_ITEMS]) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        Item cur_item = items[i];
        printf("%d. %s - Current highest bidder: %s - Current highest bid: %.2f\n", cur_item.id, cur_item.name, cur_item.bidder, cur_item.current_bid);
    }
}

int get_user_input() {
    int input;
    scanf("%d", &input);
    return input;
}

Item get_highest_bidder(Item item, float new_bid) {
    Item highest_bidder = item;
    highest_bidder.current_bid = new_bid;
    printf("New highest bid: %.2f by ", highest_bidder.current_bid);
    scanf("%s", highest_bidder.bidder);
    return highest_bidder;
}