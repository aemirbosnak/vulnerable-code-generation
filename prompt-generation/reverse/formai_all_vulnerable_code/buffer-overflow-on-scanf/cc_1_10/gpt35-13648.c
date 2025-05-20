//FormAI DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum number of bids
#define MAX_BIDS 100

// struct to store a bid
struct bid {
    char name[50];
    int amount;
};

// global variable to store current number of bids
int num_bids = 0;

// function to display all bids
void display_bids(struct bid *bids, int n) {
    int i;
    printf("\nCurrent Bids:");
    for (i = 0; i < n; i++) {
        printf("\n%d. %s - $%d", i+1, bids[i].name, bids[i].amount);
    }
}

// recursive function to handle bidding process
void bid(struct bid *bids, int min_bid) {
    int i, new_bid;
    char name[50];
    printf("\nEnter your name: ");
    scanf("%s", name);
    printf("\nEnter your bid: $");
    scanf("%d", &new_bid);
    if (new_bid < min_bid) {
        printf("\nYour bid is too low. The minimum bid is $%d.", min_bid);
        bid(bids, min_bid);
    } else {
        // add new bid to list of bids
        strcpy(bids[num_bids].name, name);
        bids[num_bids].amount = new_bid;
        num_bids++;
        // check if maximum number of bids has been reached
        if (num_bids == MAX_BIDS) {
            printf("\nThe auction is closed. Here are the final bids:");
            display_bids(bids, num_bids);
        } else {
            printf("\nYour bid has been accepted. Here are the current bids:");
            display_bids(bids, num_bids);
            printf("\n\nCurrent minimum bid is: $%d", bids[num_bids - 1].amount + 1);
            bid(bids, bids[num_bids - 1].amount + 1);
        }
    }
}

int main() {
    int min_bid;
    struct bid bids[MAX_BIDS];
    printf("Welcome to the Digital Auction System!\n");
    printf("\nEnter the minimum bid: $");
    scanf("%d", &min_bid);
    printf("\nThe minimum bid is: $%d", min_bid);
    bid(bids, min_bid);
    return 0;
}