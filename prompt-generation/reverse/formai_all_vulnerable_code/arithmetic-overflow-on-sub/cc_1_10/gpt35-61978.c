//FormAI DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 1000
#define MAX_AUCTIONS 100
#define MAX_BIDS 1000

typedef struct {
    int user_id;
    float balance;
} User;

typedef struct {
    int auction_id;
    char item_name[50];
    float min_bid;
    int seller_id;
    int num_bids;
    float highest_bid;
    int bidder_id[MAX_BIDS];
    float bid_amount[MAX_BIDS];
} Auction;

int num_users = 0;
int num_auctions = 0;
User users[MAX_USERS];
Auction auctions[MAX_AUCTIONS];

void create_user() {
    User user;
    user.user_id = num_users + 1;
    user.balance = 0;
    num_users++;
    users[num_users-1] = user;
    printf("User created!\n");
}

void create_auction() {
    Auction auction;
    auction.auction_id = num_auctions + 1;
    printf("Enter item name: ");
    scanf("%s", &auction.item_name);
    printf("Enter minimum bid: ");
    scanf("%f", &auction.min_bid);
    printf("Enter seller ID: ");
    scanf("%d", &auction.seller_id);
    auction.num_bids = 0;
    auction.highest_bid = auction.min_bid;
    num_auctions++;
    auctions[num_auctions-1] = auction;
    printf("Auction created!\n");
}

void make_bid() {
    int auction_id, bidder_id;
    float bid_amount;
    printf("Enter auction ID: ");
    scanf("%d", &auction_id);
    printf("Enter bidder ID: ");
    scanf("%d", &bidder_id);
    printf("Enter bid amount: ");
    scanf("%f", &bid_amount);
    int auction_index = auction_id - 1;
    int bidder_index = bidder_id - 1;
    if (auctions[auction_index].num_bids == MAX_BIDS) {
        printf("Maximum number of bids reached for this auction.\n");
        return;
    }
    if (bid_amount <= auctions[auction_index].highest_bid) {
        printf("Bid amount is not high enough.\n");
        return;
    }
    if (users[bidder_index].balance < bid_amount) {
        printf("Bidder does not have enough balance.\n");
        return;
    }
    auctions[auction_index].num_bids++;
    auctions[auction_index].highest_bid = bid_amount;
    auctions[auction_index].bidder_id[auctions[auction_index].num_bids-1] = bidder_id;
    auctions[auction_index].bid_amount[auctions[auction_index].num_bids-1] = bid_amount;
    printf("Bid placed!\n");
}

void print_auction_details(Auction auction) {
    printf("Auction ID: %d\n", auction.auction_id);
    printf("Item: %s\n", auction.item_name);
    printf("Minimum bid: %.2f\n", auction.min_bid);
    printf("Seller ID: %d\n", auction.seller_id);
    printf("Number of bids: %d\n", auction.num_bids);
    printf("Highest bid: %.2f\n", auction.highest_bid);
    if (auction.num_bids > 0) {
        printf("Bidders:\n");
        for (int i=0; i<auction.num_bids; i++) {
            printf("%d - $%.2f\n", auction.bidder_id[i], auction.bid_amount[i]);
        }
    }
}

void view_auction() {
    int auction_id;
    printf("Enter auction ID: ");
    scanf("%d", &auction_id);
    int auction_index = auction_id - 1;
    if (auction_index >= num_auctions) {
        printf("Invalid auction ID.\n");
        return;
    }
    print_auction_details(auctions[auction_index]);
}

void view_auctions() {
    for (int i=0; i<num_auctions; i++) {
        print_auction_details(auctions[i]);
        printf("------------------\n");
    }
}

void check_balances() {
    for (int i=0; i<num_users; i++) {
        printf("User %d balance: $%.2f\n", users[i].user_id, users[i].balance);
    }
}

void randomize_bids() {
    for (int i=0; i<num_auctions; i++) {
        if (auctions[i].num_bids > 0) {
            int winner = rand() % auctions[i].num_bids;
            int winner_id = auctions[i].bidder_id[winner];
            float winning_bid = auctions[i].bid_amount[winner];
            auctions[i].seller_id = winner_id;
            users[winner_id-1].balance -= winning_bid;
            users[auctions[i].seller_id-1].balance += winning_bid;
            printf("Auction ID %d winner: User %d - $%.2f\n", auctions[i].auction_id, winner_id, winning_bid);
        }
    }
}

int main() {
    srand(time(0));
    int choice;
    while(1) {
        printf("1. Create user\n");
        printf("2. Create auction\n");
        printf("3. Place bid\n");
        printf("4. View auction\n");
        printf("5. View all auctions\n");
        printf("6. Check balances\n");
        printf("7. Randomize bids\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("------------------\n");
        switch(choice) {
            case 1:
                create_user();
                break;
            case 2:
                create_auction();
                break;
            case 3:
                make_bid();
                break;
            case 4:
                view_auction();
                break;
            case 5:
                view_auctions();
                break;
            case 6:
                check_balances();
                break;
            case 7:
                randomize_bids();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("------------------\n");
    }
    return 0;
}