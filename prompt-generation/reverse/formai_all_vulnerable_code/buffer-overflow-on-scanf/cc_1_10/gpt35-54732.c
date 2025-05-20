//FormAI DATASET v1.0 Category: Digital Auction System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct AuctionItem {
    char name[50];
    int starting_bid;
    int highest_bid;
    char highest_bidder[50];
};

int end_time;

void registerBid(struct AuctionItem *item) {
    int bid;
    char bidder[50];
    printf("Enter your bid:\n");
    scanf("%d", &bid);
    getchar();
    if (bid > item->highest_bid) {
        printf("New highest bid!\n");
        item->highest_bid = bid;
        printf("Enter your name:\n");
        fgets(bidder, 50, stdin);
        bidder[strcspn(bidder, "\n")] = 0;
        strcpy(item->highest_bidder, bidder);
    } else {
        printf("Your bid must be higher than the current highest bid.\n");
    }
}

int main() {
    srand(time(NULL));
    struct AuctionItem item;
    printf("Enter the name of the item:\n");
    fgets(item.name, 50, stdin);
    item.name[strcspn(item.name, "\n")] = 0;
    printf("Enter the starting bid:\n");
    scanf("%d", &item.starting_bid);
    getchar();
    item.highest_bid = item.starting_bid;
    printf("Starting bid set at %d\n", item.starting_bid);
    printf("Enter the end time (in seconds):\n");
    scanf("%d", &end_time);
    
    time_t start_time, current_time;
    start_time = time(NULL);
    current_time = start_time;
    int elapsed_time;
    while (current_time - start_time < end_time) {
        printf("Time remaining: %d seconds\n", end_time - (current_time - start_time));
        printf("Current highest bid: %d by %s\n", item.highest_bid, item.highest_bidder);
        printf("1. Bid\n");
        printf("2. Quit\n");
        int choice;
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                registerBid(&item);
                break;
            case 2:
                printf("Auction ended.\n");
                printf("Highest bid: %d by %s\n", item.highest_bid, item.highest_bidder);
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
        current_time = time(NULL);
    }
    printf("Auction ended.\n");
    printf("Highest bid: %d by %s\n", item.highest_bid, item.highest_bidder);
    return 0;
}