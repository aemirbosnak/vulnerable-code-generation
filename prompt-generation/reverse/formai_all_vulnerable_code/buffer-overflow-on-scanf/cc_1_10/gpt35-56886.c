//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include<stdio.h>
#include<string.h>
#define MAX_BIDS 10 // Maximum number of bids that can be entered
#define MAX_NAME_LEN 20 // Maximum length of bidder's name

struct Bid { // Structure of a single bid
    char bidder_name[MAX_NAME_LEN];
    float bid_amount;
};

int num_bids = 0; // Number of bids currently in the system
struct Bid bids[MAX_BIDS]; // Array of current bids

void add_bid() {
    if(num_bids >= MAX_BIDS) {
        printf("\nMaximum number of bids reached.\n");
        return;
    }

    struct Bid new_bid;
    printf("\nEnter bidder name: ");
    scanf("%s", new_bid.bidder_name);
    printf("Enter bid amount: ");
    scanf("%f", &new_bid.bid_amount);

    bids[num_bids++] = new_bid;

    printf("\nBid successfully added.\n");
}

void display_bids() {
    if(num_bids == 0) {
        printf("\nNo bids found.\n");
        return;
    }
    printf("\nCurrent Bids:\n");
    for(int i=0; i<num_bids; i++) {
        printf("%s: %.2f\n", bids[i].bidder_name, bids[i].bid_amount);
    }
}

void find_highest_bid() {
    if(num_bids == 0) {
        printf("\nNo bids found.\n");
        return;
    }

    float highest_bid = 0;
    char highest_bidder_name[MAX_NAME_LEN];
    for(int i=0; i<num_bids; i++) {
        if(bids[i].bid_amount > highest_bid) {
            highest_bid = bids[i].bid_amount;
            strcpy(highest_bidder_name, bids[i].bidder_name);
        }
    }
    printf("\n%s has the highest bid of %.2f\n", highest_bidder_name, highest_bid);
}

int main() {
    int choice;

    while(1) {
        printf("\nDigital Auction System");
        printf("\n1. Add a bid");
        printf("\n2. Display all bids");
        printf("\n3. Find highest bid");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_bid(); break;
            case 2: display_bids(); break;
            case 3: find_highest_bid(); break;
            case 4: return 0;
            default: printf("\nInvalid choice.\n"); break;
        }
    }
    return 0;
}