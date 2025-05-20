//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_ITEM_LENGTH 100
#define MAX_BID_LENGTH 10
#define MAX_BIDDERS 10

struct bidder {
    char name[MAX_NAME_LENGTH];
    int total_bids;
    float highest_bid;
};

struct item {
    char name[MAX_ITEM_LENGTH];
    float starting_bid;
    int number_of_bids;
    struct bidder bidders[MAX_BIDDERS];
    bool sold;
    struct bidder winning_bidder;
};

int get_bidder_index(struct bidder bidders[], char *name, int number_of_bidders) {
    for (int i = 0; i < number_of_bidders; i++) {
        if (strcmp(bidders[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int number_of_items;
    printf("Enter the number of items: ");
    scanf("%d", &number_of_items);

    struct item auctions[number_of_items];

    // Initialize auctions
    for (int i = 0; i < number_of_items; i++) {
        printf("\nItem %d\n", i + 1);
        printf("Enter the name of the item: ");
        scanf("%s", auctions[i].name);
        printf("Enter the starting bid: ");
        scanf("%f", &auctions[i].starting_bid);
        auctions[i].number_of_bids = 0;
        auctions[i].sold = false;
    }

    // Start auction
    printf("\nStarting auction...\n");
    char command[MAX_ITEM_LENGTH], bidder_name[MAX_NAME_LENGTH], bid_amount[MAX_BID_LENGTH];
    while (true) {
        printf("\nEnter a command (bid <item name> <bidder name> <bid amount>, quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        if (strcmp(command, "bid") == 0) {
            scanf("%s%s", bidder_name, bid_amount);
            char item_name[MAX_ITEM_LENGTH];
            scanf("%s", item_name);

            int item_index = -1;
            for (int i = 0; i < number_of_items; i++) {
                if (strcmp(auctions[i].name, item_name) == 0) {
                    item_index = i;
                    break;
                }
            }

            if (item_index == -1) {
                printf("Item does not exist.\n");
                continue;
            }

            if (auctions[item_index].sold) {
                printf("This item has already been sold.\n");
                continue;
            }

            int bidder_index = get_bidder_index(auctions[item_index].bidders, bidder_name, auctions[item_index].number_of_bids);
            if (bidder_index == -1) {
                // Create new bidder
                strcpy(auctions[item_index].bidders[auctions[item_index].number_of_bids].name, bidder_name);
                auctions[item_index].bidders[auctions[item_index].number_of_bids].total_bids = 1;
                auctions[item_index].bidders[auctions[item_index].number_of_bids].highest_bid = atof(bid_amount);
                auctions[item_index].number_of_bids++;
            } else {
                // Update existing bidder
                auctions[item_index].bidders[bidder_index].total_bids++;
                if (atof(bid_amount) > auctions[item_index].bidders[bidder_index].highest_bid) {
                    auctions[item_index].bidders[bidder_index].highest_bid = atof(bid_amount);
                }
            }

            // Update winning bidder
            if (atof(bid_amount) > auctions[item_index].winning_bidder.highest_bid) {
                auctions[item_index].winning_bidder = auctions[item_index].bidders[bidder_index];
                auctions[item_index].winning_bidder.highest_bid = atof(bid_amount);
            }

            printf("Bid accepted.\n");
        }

        else {
            printf("Invalid command. Try again.\n");
        }
    }

    // End auction
    printf("\nEnding auction...\n");

    for (int i = 0; i < number_of_items; i++) {
        printf("\nItem %d\nName: %s\nStarting Bid: %.2f\n", i+1, auctions[i].name, auctions[i].starting_bid);
        if (auctions[i].number_of_bids == 0) {
            printf("No bids were placed on this item.\n");
        } else {
            printf("Winning bidder: %s\n", auctions[i].winning_bidder.name);
            printf("Winning bid: $%.2f\n", auctions[i].winning_bidder.highest_bid);
            printf("Number of bids: %d\n", auctions[i].number_of_bids);
            printf("Bidders:\n");
            for (int j = 0; j < auctions[i].number_of_bids; j++) {
                printf("%s ($%.2f, %d bids)\n", auctions[i].bidders[j].name, auctions[i].bidders[j].highest_bid, auctions[i].bidders[j].total_bids);
            }
        }
    }

    return 0;
}