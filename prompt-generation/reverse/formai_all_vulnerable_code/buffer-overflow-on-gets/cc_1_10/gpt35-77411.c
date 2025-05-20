//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Claude Shannon
/* A Digital Auction System Program in C */
/* By Claude Shannon */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 50

struct Item {
    int id;
    char name[50];
    char description[100];
    float start_price;
    float current_price;
    int time_remaining;
    char auction_end_time[100];
    char bidder[50];
    int bidder_count;
};

struct Bidder {
    char name[50];
    float wallet;
    int bid_count;
};

struct Item items[MAX_ITEMS];
struct Bidder bidders[MAX_BIDDERS];

int item_count = 0;
int bidder_count = 0;

void add_item() {
    if (item_count == MAX_ITEMS) {
        printf("The auction has reached its maximum capacity.\n");
        return;
    }

    int id;
    char name[50];
    char description[100];
    float start_price;
    int time_remaining;

    printf("Enter the ID of the item: ");
    scanf("%d", &id);
    fflush(stdin);

    printf("Enter the name of the item: ");
    gets(name);

    printf("Enter the description of the item: ");
    gets(description);

    printf("Enter the starting price of the item: ");
    scanf("%f", &start_price);

    printf("Enter the time remaining for bidding in minutes: ");
    scanf("%d", &time_remaining);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(items[item_count].auction_end_time, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min + time_remaining, tm.tm_sec);
    items[item_count].id = id;
    strcpy(items[item_count].name, name);
    strcpy(items[item_count].description, description);
    items[item_count].start_price = start_price;
    items[item_count].current_price = start_price;
    items[item_count].time_remaining = time_remaining;
    items[item_count].bidder_count = 0;

    item_count++;

    printf("The item has been added to the auction\n");
}

void register_bidder() {
    if (bidder_count == MAX_BIDDERS) {
        printf("The bidder limit has been reached.\n");
        return;
    }

    char name[50];
    float wallet;

    printf("Enter your name: ");
    gets(name);

    printf("Enter your wallet balance: ");
    scanf("%f", &wallet);

    strcpy(bidders[bidder_count].name, name);
    bidders[bidder_count].wallet = wallet;
    bidders[bidder_count].bid_count = 0;

    bidder_count++;

    printf("You are now registered as a bidder.\n");
}

void list_items() {
    printf("ID\tNAME\t\tDESCRIPTION\t\t\t\tPRICE\t\tTIME REMAINING\tAUCTION END TIME\n");
    for (int i = 0; i < item_count; i++) {
        printf("%d\t%s\t%s\t%.2f\t\t%d minutes\t%s\n", items[i].id, items[i].name, items[i].description, items[i].current_price, items[i].time_remaining, items[i].auction_end_time);
    }
}

void bid_on_item() {
    int item_id, bidder_id;
    float amount;

    printf("Enter the ID of the item to bid on: ");
    scanf("%d", &item_id);

    printf("Enter your bidder ID: ");
    scanf("%d", &bidder_id);

    printf("Enter your bid amount: ");
    scanf("%f", &amount);

    if (item_id >= item_count || bidder_id >= bidder_count) {
        printf("Invalid item ID or bidder ID.\n");
        return;
    }

    if (items[item_id].time_remaining <= 0) {
        printf("The bidding for this item has already ended.\n");
        return;
    }

    if (items[item_id].bidder_count > 0 && strcmp(items[item_id].bidder, bidders[bidder_id].name) == 0) {
        printf("You are already the highest bidder for this item.\n");
        return;
    }

    if (amount <= items[item_id].current_price) {
        printf("Your bid is too low.\n");
        return;
    }

    if (amount > bidders[bidder_id].wallet) {
        printf("You do not have enough money in your wallet to place this bid.\n");
        return;
    }

    bidders[bidder_id].wallet -= amount;

    if (items[item_id].bidder_count > 0) {
        bidders[items[item_id].bidder_count-1].wallet += items[item_id].current_price;
    }

    strcpy(items[item_id].bidder, bidders[bidder_id].name);
    items[item_id].current_price = amount;
    items[item_id].bidder_count++;

    printf("Your bid has been placed.\n");
}

void close_auction() {
    for (int i = 0; i < item_count; i++) {
        if (items[i].time_remaining <= 0) {
            printf("The auction for %s has ended.\n", items[i].name);
            printf("%d bids were placed on the item.\n", items[i].bidder_count);
            if (items[i].bidder_count > 0) {
                printf("%s won the item with a bid of %.2f.\n", items[i].bidder, items[i].current_price);
                for (int j = 0; j < bidder_count; j++) {
                    if (strcmp(bidders[j].name, items[i].bidder) == 0) {
                        bidders[j].wallet -= items[i].current_price;
                        bidders[j].bid_count++;
                        break;
                    }
                }
            } else {
                printf("The item had no bids.\n");
            }
        }
    }
}

int main() {
    int choice;

    do {
        printf("------ Digital Auction System ------\n");
        printf("1. Add item\n");
        printf("2. Register bidder\n");
        printf("3. List items\n");
        printf("4. Bid on item\n");
        printf("5. Close auction\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                register_bidder();
                break;
            case 3:
                list_items();
                break;
            case 4:
                bid_on_item();
                break;
            case 5:
                close_auction();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}