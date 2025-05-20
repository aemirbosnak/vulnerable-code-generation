//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char item_name[50];
    double start_bid;
    double bid_increment;
    int time_left;
    char highest_bidder[50];
    double highest_bid;
} Auction_Item;

int main() {
    Auction_Item item;
    char bidder_name[50];
    double bid_amount;
    int choice, hours, minutes, seconds, time_remaining, i;
    time_t start_time, current_time, end_time;

    printf("Welcome to the Digital Auction System\n");

    printf("Enter the name of the item: ");
    gets(item.item_name);

    printf("Enter the starting bid: $");
    scanf("%lf", &item.start_bid);

    printf("Enter the bid increment: $");
    scanf("%lf", &item.bid_increment);

    printf("Enter the duration of the auction in hours, minutes, and seconds (separated by spaces): ");
    scanf("%d %d %d", &hours, &minutes, &seconds);

    item.time_left = hours * 3600 + minutes * 60 + seconds;

    start_time = time(NULL);
    end_time = start_time + item.time_left;

    while (1) {
        time(&current_time);
        time_remaining = end_time - current_time;

        if (time_remaining <= 0) {
            printf("Auction for '%s' has ended.\n", item.item_name);
            printf("Highest bidder: %s\n", item.highest_bidder);
            printf("Highest bid: $%.2lf\n", item.highest_bid);
            break;
        }

        printf("Time remaining: %d hours, %d minutes, %d seconds\n", time_remaining / 3600, (time_remaining % 3600) / 60, time_remaining % 60);

        printf("Current Highest Bid: $%.2lf by %s\n", item.highest_bid, item.highest_bidder);

        printf("Enter 1 to bid on the item or 2 to exit: ");
        scanf("%d", &choice);

        if (choice == 2) break;

        printf("Enter your name: ");
        scanf("%s", bidder_name);

        printf("Enter your bid: $");
        scanf("%lf", &bid_amount);

        if (bid_amount < item.start_bid) {
            printf("Bid amount must be at least $%.2lf\n", item.start_bid);
        } else if (bid_amount < item.highest_bid + item.bid_increment) {
            printf("Bid amount must be at least $%.2lf higher than the current highest bid.\n", item.bid_increment);
        } else {
            strcpy(item.highest_bidder, bidder_name);
            item.highest_bid = bid_amount;
            printf("Bid accepted.\n");
        }
    }

    return 0;
}