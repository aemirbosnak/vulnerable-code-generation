//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 20
#define MAX_ITEMS 10
#define MAX_NAME_LEN 50

struct Bidder {
    char name[MAX_NAME_LEN];
    int balance;
    int bids[MAX_ITEMS];
};

struct Item {
    char name[MAX_NAME_LEN];
    int price;
    int current_bid;
    int bid_index;
};

void add_bidder(struct Bidder *bidders, int *num_bidders);
void add_item(struct Item *items, int *num_items);
void auction(struct Bidder *bidders, int num_bidders, struct Item *items, int num_items);
int get_bid(int min_bid, int bidder_balance, char *bidder_name);

int main() {
    srand(time(NULL));
    struct Bidder bidders[MAX_BIDDERS];
    struct Item items[MAX_ITEMS];
    int num_bidders = 0, num_items = 0, i;

    printf("Welcome to our digital auction system!\n\n");

    while (1) {
        int choice;
        printf("What would you like to do?\n");
        printf("1. Add bidder\n");
        printf("2. Add item\n");
        printf("3. Auction\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_bidder(bidders, &num_bidders);
                break;
            case 2:
                add_item(items, &num_items);
                break;
            case 3:
                auction(bidders, num_bidders, items, num_items);
                break;
            case 4:
                printf("\nThank you for using our system!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }
}

void add_bidder(struct Bidder *bidders, int *num_bidders) {
    if (*num_bidders == MAX_BIDDERS) {
        printf("\nMaximum number of bidders reached.\n\n");
        return;
    }

    struct Bidder new_bidder;
    printf("\nEnter bidder name: ");
    scanf("%s", new_bidder.name);
    printf("Enter bidder starting balance: ");
    scanf("%d", &new_bidder.balance);
    memset(new_bidder.bids, 0, sizeof(new_bidder.bids));

    bidders[*num_bidders] = new_bidder;
    (*num_bidders)++;

    printf("Bidder added successfully!\n\n");
}

void add_item(struct Item *items, int *num_items) {
    if (*num_items == MAX_ITEMS) {
        printf("\nMaximum number of items reached.\n\n");
        return;
    }

    struct Item new_item;
    printf("\nEnter item name: ");
    scanf("%s", new_item.name);
    printf("Enter item price: ");
    scanf("%d", &new_item.price);
    new_item.current_bid = new_item.price;
    new_item.bid_index = -1;

    items[*num_items] = new_item;
    (*num_items)++;

    printf("Item added successfully!\n\n");
}

void auction(struct Bidder *bidders, int num_bidders, struct Item *items, int num_items) {
    if (num_bidders == 0 || num_items == 0) {
        printf("\nThere are no bidders or items to auction.\n\n");
        return;
    }

    printf("\nStarting auction...\n");

    int i, j, winner_index = -1;
    for (i = 0; i < num_items; i++) {
        struct Item current_item = items[i];
        printf("\nAuctioning %s (starting price: %d)...\n", current_item.name, current_item.price);

        // find highest bidder
        for (j = 0; j < num_bidders; j++) {
            int bid = get_bid(current_item.current_bid, bidders[j].balance, bidders[j].name);
            if (bid > current_item.current_bid) {
                current_item.current_bid = bid;
                current_item.bid_index = j;
            }
        }

        if (current_item.bid_index == -1) {
            printf("\nNo one bid on %s. Item will not be sold.\n", current_item.name);
        } else {
            printf("\n%s won %s for %d!\n", bidders[current_item.bid_index].name, current_item.name, current_item.current_bid);
            bidders[current_item.bid_index].balance -= current_item.current_bid;

            // update bids
            for (j = 0; j < num_bidders; j++) {
                if (j != current_item.bid_index) {
                    bidders[j].bids[i] = 0;
                } else {
                    bidders[j].bids[i] = current_item.current_bid;
                }
            }

            // check if bidder is out of money
            if (bidders[current_item.bid_index].balance < 0) {
                printf("\n%s is out of money and cannot bid anymore!\n", bidders[current_item.bid_index].name);
            } else {
                printf("\n%s has %d remaining balance.\n", bidders[current_item.bid_index].name, bidders[current_item.bid_index].balance);
            }

            // check if bidders want to continue
            int num_continuing = 0;
            for (j = 0; j < num_bidders; j++) {
                if (bidders[j].balance >= current_item.current_bid) {
                    num_continuing++;
                }
            }

            if (num_continuing == 0) {
                printf("\nNo one else can afford to bid on %s.\n", current_item.name);
            } else {
                printf("\n%d bidders are still in the auction.\n", num_continuing);
                int continue_auction = rand() % 2;
                if (!continue_auction) {
                    printf("\nAuction ended early!\n");
                    break;
                }
            }

            // check for overall winner
            for (j = 0; j < num_bidders; j++) {
                int total_bids = 0;
                int k;
                for (k = 0; k < num_items; k++) {
                    total_bids += bidders[j].bids[k];
                }
                if (total_bids > current_item.price && j != winner_index) {
                    winner_index = j;
                }
            }

            if (winner_index != -1) {
                printf("\n%s is the current overall winner with a total bid of %d!\n", bidders[winner_index].name, bidders[winner_index].balance);
            }
        }
    }

    printf("\nAuction ended!\n\n");
}

int get_bid(int min_bid, int bidder_balance, char *bidder_name) {
    int bid;
    do {
        printf("\n%s, enter your bid (minimum %d, %d available balance): ", bidder_name, min_bid, bidder_balance);
        scanf("%d", &bid);
        if (bid < min_bid) {
            printf("\nBid too low! Please enter a higher bid.\n");
        } else if (bid > bidder_balance) {
            printf("\nInsufficient balance! Please enter a lower bid.\n");
        }
    } while (bid < min_bid || bid > bidder_balance);
    return bid;
}