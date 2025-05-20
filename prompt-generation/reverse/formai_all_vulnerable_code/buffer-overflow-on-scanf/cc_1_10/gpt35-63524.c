//FormAI DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 10

typedef struct {
    char name[20];
    float starting_bid;
    float current_bid;
    char highest_bidder[20];
    time_t end_time;
    int active;
} AuctionItem;

typedef struct {
    char name[20];
    float balance;
    int active;
} Bidder;

void start_auction(AuctionItem *item) {
    item->active = 1;
    item->end_time = time(NULL) + 60; // auction lasts 60 seconds
    printf("Auction started for %s, starting bid $%.2f\n", item->name, item->starting_bid);
}

void place_bid(Bidder *bidder, AuctionItem *item, float bid) {
    if (strcmp(bidder->name, item->highest_bidder) == 0) {
        printf("%s, you are already the highest bidder.\n", bidder->name);
    } else if (bid <= item->current_bid) {
        printf("%s, your bid must be higher than the current bid of $%.2f.\n", bidder->name, item->current_bid);
    } else if (bid > bidder->balance) {
        float max_bid = bidder->balance;
        printf("%s, your bid exceeds your available balance of $%.2f. The maximum bid you can place is $%.2f.\n", bidder->name, bidder->balance, max_bid);
    } else {
        item->current_bid = bid;
        strcpy(item->highest_bidder, bidder->name);
        printf("%s has placed a bid of $%.2f on %s.\n", bidder->name, bid, item->name);
    }
}

void end_auction(AuctionItem *item) {
    if (item->active) {
        item->active = 0;
        printf("Auction for %s has ended. The winner is %s with a bid of $%.2f\n", item->name, item->highest_bidder, item->current_bid);
    }
}

int main() {
    AuctionItem items[MAX_ITEMS];
    Bidder bidders[MAX_BIDDERS];
    int num_items = 0;
    int num_bidders = 0;

    printf("Welcome to the digital auction system!\n");
    printf("Please enter your name: ");
    scanf("%s", bidders[num_bidders].name);
    printf("Please enter your starting balance: $");
    scanf("%f", &bidders[num_bidders].balance);
    bidders[num_bidders].active = 1;
    num_bidders++;

    while (1) {
        printf("Select an option:\n");
        printf("1. Add an item for auction\n");
        printf("2. Start an auction\n");
        printf("3. Place a bid\n");
        printf("4. End an auction\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_items >= MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                    break;
                }
                printf("Enter the name of the item: ");
                scanf("%s", items[num_items].name);
                printf("Enter the starting bid: $");
                scanf("%f", &items[num_items].starting_bid);
                items[num_items].current_bid = items[num_items].starting_bid;
                items[num_items].active = 0;
                num_items++;
                printf("Item added for auction.\n");
                break;
            }
            case 2: {
                int item;
                printf("Select an item to auction:\n");
                for (int i = 0; i < num_items; i++) {
                    if (!items[i].active) {
                        printf("%d. %s ($%.2f)\n", i + 1, items[i].name, items[i].starting_bid);
                    }
                }
                scanf("%d", &item);
                if (item < 1 || item > num_items || items[item - 1].active) {
                    printf("Invalid selection.\n");
                    break;
                }
                start_auction(&items[item - 1]);
                break;
            }
            case 3: {
                int bidder, item;
                float bid;
                printf("Select a bidder:\n");
                for (int i = 0; i < num_bidders; i++) {
                    if (bidders[i].active) {
                        printf("%d. %s ($%.2f available)\n", i + 1, bidders[i].name, bidders[i].balance);
                    }
                }
                scanf("%d", &bidder);
                if (bidder < 1 || bidder > num_bidders || !bidders[bidder - 1].active) {
                    printf("Invalid selection.\n");
                    break;
                }
                printf("Select an item to bid on:\n");
                for (int i = 0; i < num_items; i++) {
                    if (items[i].active && strcmp(items[i].highest_bidder, bidders[bidder - 1].name) != 0) {
                        printf("%d. %s (current bid $%.2f)\n", i + 1, items[i].name, items[i].current_bid);
                    }
                }
                scanf("%d", &item);
                if (item < 1 || item > num_items || !items[item - 1].active) {
                    printf("Invalid selection.\n");
                    break;
                }
                printf("Enter your bid: $");
                scanf("%f", &bid);
                place_bid(&bidders[bidder - 1], &items[item - 1], bid);
                break;
            }
            case 4: {
                int item;
                printf("Select an item to end the auction:\n");
                for (int i = 0; i < num_items; i++) {
                    if (items[i].active) {
                        printf("%d. %s (current bid $%.2f)\n", i + 1, items[i].name, items[i].current_bid);
                    }
                }
                scanf("%d", &item);
                if (item < 1 || item > num_items || !items[item - 1].active) {
                    printf("Invalid selection.\n");
                    break;
                }
                end_auction(&items[item - 1]);
                break;
            }
            case 5: {
                printf("Exiting...\n");
                return 0;
            }
            default: {
                printf("Invalid option.\n");
                break;
            }
        }
    }
}