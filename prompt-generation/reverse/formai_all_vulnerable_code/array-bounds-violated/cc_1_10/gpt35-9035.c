//FormAI DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 20

struct Bid {
    char username[20];
    int amount;
};

struct Auction {
    char item_name[50];
    int current_bid;
    char current_bidder[20];
    struct Bid bids[MAX_BIDS];
    int num_bids;
};

struct Auction auctions[MAX_AUCTIONS];
int num_auctions = 0;

void create_auction() {
    if (num_auctions >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached.");
        return;
    }
    
    struct Auction new_auction;
    printf("Enter item name: ");
    scanf("%s", new_auction.item_name);
    printf("Enter starting bid: ");
    scanf("%d", &new_auction.current_bid);
    strcpy(new_auction.current_bidder, "none");
    
    auctions[num_auctions++] = new_auction;
    
    printf("Auction created successfully.\n");
}

void view_auctions() {
    printf("---Current Auctions---\n");
    for (int i = 0; i < num_auctions; i++) {
        printf("%d. %s - Current bid: %d by %s\n", i+1, auctions[i].item_name, auctions[i].current_bid, auctions[i].current_bidder);
    }
    printf("----------------------\n");
}

void bid_on_auction() {
    char username[20];
    int auction_num, bid_amount;
    printf("Enter your username: ");
    scanf("%s", username);
    view_auctions();
    printf("Enter auction number to bid on: ");
    scanf("%d", &auction_num);
    auction_num--; // subtract 1 to convert from user input (starting at 1) to array index (starting at 0)
    printf("Enter bid amount: ");
    scanf("%d", &bid_amount);
    if (bid_amount <= auctions[auction_num].current_bid) {
        printf("Bid must be higher than current bid.\n");
        return;
    }
    if (auctions[auction_num].num_bids >= MAX_BIDS) {
        printf("Maximum number of bids reached for this auction.\n");
        return;
    }
    
    // add bid to auction
    struct Bid new_bid;
    strcpy(new_bid.username, username);
    new_bid.amount = bid_amount;
    auctions[auction_num].bids[auctions[auction_num].num_bids++] = new_bid;
    auctions[auction_num].current_bid = bid_amount;
    strcpy(auctions[auction_num].current_bidder, username);
    
    printf("Bid accepted.\n");
}

int main() {
    int choice;
    do {
        printf("1. Create auction\n");
        printf("2. View auctions\n");
        printf("3. Bid on auction\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_auction();
                break;
            case 2:
                view_auctions();
                break;
            case 3:
                bid_on_auction();
                break;
            case 4:
                printf("Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    
    return 0;
}