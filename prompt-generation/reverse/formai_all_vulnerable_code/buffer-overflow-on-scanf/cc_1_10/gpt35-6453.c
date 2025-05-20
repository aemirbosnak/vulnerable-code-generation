//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define constants */
#define MAX_BIDDERS 10
#define MAX_ITEMS 10
#define MAX_ITEM_NAME_LEN 20
#define MAX_ITEM_DESC_LEN 50

/* Define structures */
typedef struct {
    char name[MAX_ITEM_NAME_LEN];
    char desc[MAX_ITEM_DESC_LEN];
    int current_bid;
    int bidder_idx;
    int bid_time;
} Item;

typedef struct {
    char name[20];
    int balance;
    int item_count;
    Item items[MAX_ITEMS];
} Bidder;

/* Define global variables */
Bidder bidders[MAX_BIDDERS];
int num_bidders = 1;
Item items[MAX_ITEMS];
int num_items = 1;

/* Helper functions */
int get_bidder_by_name(char *name) {
    int i;
    for (i = 0; i < num_bidders; i++) {
        if (strcmp(bidders[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int get_item_by_name(char *name) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void print_item_info(Item item) {
    printf("Item name: %s\n", item.name);
    printf("Item description: %s\n", item.desc);
    printf("Current bid: %d\n", item.current_bid);
    if (item.bidder_idx >= 0) {
        printf("Current highest bidder: %s\n", bidders[item.bidder_idx].name);
    } else {
        printf("There are currently no bids on this item.\n");
    }
}

/* Main program */
int main() {
    /* Seed random number generator */
    srand(time(NULL));

    /* Welcome message */
    printf("Welcome to the Cyberpunk Digital Auction System! Register to get started.\n");

    /* Register bidder */
    printf("Please enter your name: ");
    scanf("%s", bidders[0].name);
    bidders[0].balance = 1000;
    bidders[0].item_count = 0;
    printf("Thank you for registering, %s. Your starting balance is %d.\n", bidders[0].name, bidders[0].balance);

    /* Main loop */
    while (1) {
        /* Get user input */
        char input[50];
        printf("Please enter a command: ");
        scanf("%s", input);

        /* Parse input */
        if (strcmp(input, "list_items") == 0) {
            /* List all items */
            int i;
            for (i = 0; i < num_items; i++) {
                printf("%d. %s\n", i + 1, items[i].name);
            }
        } else if (strcmp(input, "create_item") == 0) {
            /* Create new item */
            if (num_items >= MAX_ITEMS) {
                printf("Sorry, the maximum amount of items has been reached.\n");
            } else {
                char name[MAX_ITEM_NAME_LEN];
                char desc[MAX_ITEM_DESC_LEN];
                int starting_bid;

                printf("Please enter the name of the item: ");
                scanf("%s", name);
                printf("Please enter a description for the item: ");
                scanf("%s", desc);
                printf("Please enter the starting bid for the item: ");
                scanf("%d", &starting_bid);

                strcpy(items[num_items].name, name);
                strcpy(items[num_items].desc, desc);
                items[num_items].current_bid = starting_bid;
                items[num_items].bidder_idx = -1;
                items[num_items].bid_time = rand() % 180 + 60;

                printf("%s has been added to the auction.\n", items[num_items].name);
                num_items++;
            }
        } else if (strcmp(input, "info") == 0) {
            /* Get info on item */
            char name[MAX_ITEM_NAME_LEN];
            printf("Please enter the name of the item: ");
            scanf("%s", name);

            int item_idx = get_item_by_name(name);
            if (item_idx == -1) {
                printf("Sorry, that item was not found.\n");
            } else {
                print_item_info(items[item_idx]);
            }
        } else if (strcmp(input, "bid") == 0) {
            /* Bid on item */
            char name[MAX_ITEM_NAME_LEN];
            char bidder_name[20];
            int bid_amount;

            printf("Please enter the name of the item: ");
            scanf("%s", name);
            printf("Please enter your name: ");
            scanf("%s", bidder_name);
            printf("Please enter your bid amount: ");
            scanf("%d", &bid_amount);

            int item_idx = get_item_by_name(name);
            if (item_idx == -1) {
                printf("Sorry, that item was not found.\n");
            } else {
                int bidder_idx = get_bidder_by_name(bidder_name);
                if (bidder_idx == -1) {
                    if (num_bidders >= MAX_BIDDERS) {
                        printf("Sorry, the maximum amount of bidders has been reached.\n");
                    } else {
                        strcpy(bidders[num_bidders].name, bidder_name);
                        bidders[num_bidders].balance = 1000;
                        bidders[num_bidders].item_count = 0;
                        bidder_idx = num_bidders;
                        num_bidders++;
                        printf("Thank you for registering, %s. Your starting balance is %d.\n", bidder_name, bidders[bidder_idx].balance);
                    }
                }
                if (bid_amount > items[item_idx].current_bid && bid_amount <= bidders[bidder_idx].balance) {
                    items[item_idx].current_bid = bid_amount;
                    items[item_idx].bidder_idx = bidder_idx;
                    items[item_idx].bid_time = rand() % 180 + 60;
                    printf("Bid successful! %s is currently the highest bidder for %s with a bid of %d.\n", bidder_name, name, bid_amount);
                } else {
                    printf("Sorry, your bid was unsuccessful.\n");
                }
            }
        } else if (strcmp(input, "end_auction") == 0) {
            /* End auction and display results */
            printf("Auction has ended!\n");

            int i;
            for (i = 0; i < num_items; i++) {
                printf("Item: %s\n", items[i].name);
                printf("Description: %s\n", items[i].desc);
                if (items[i].bidder_idx == -1) {
                    printf("No bids were placed on this item.\n");
                } else {
                    printf("Winning bidder: %s\n", bidders[items[i].bidder_idx].name);
                    bidders[items[i].bidder_idx].balance -= items[i].current_bid;
                    bidders[items[i].bidder_idx].items[bidders[items[i].bidder_idx].item_count++] = items[i];
                }
                printf("----------------------------\n");
            }

            /* Reset items */
            num_items = 0;

            /* Reset bidders */
            int j;
            for (j = 0; j < num_bidders; j++) {
                bidders[j].balance = 1000;
                bidders[j].item_count = 0;
            }
            printf("All bidders have had their account balance reset to 1000.\n");

            /* Reset auction */
            printf("The auction will begin again shortly.\n");
            sleep(5);
            printf("The auction has begun!\n");
        } else {
            /* Invalid command */
            printf("Invalid command. Please try again.\n");
        }

        /* Check if items have ended */
        int i;
        for (i = 0; i < num_items; i++) {
            if (items[i].bid_time == 0) {
                printf("%s has ended!\n", items[i].name);
                if (items[i].bidder_idx == -1) {
                    printf("No bids were placed on this item.\n");
                } else {
                    printf("%s won %s with a bid of %d!\n", bidders[items[i].bidder_idx].name, items[i].name, items[i].current_bid);
                    bidders[items[i].bidder_idx].balance -= items[i].current_bid;
                    bidders[items[i].bidder_idx].items[bidders[items[i].bidder_idx].item_count++] = items[i];
                }
                printf("----------------------------\n");
                /* Choose new starting bid */
                int new_starting_bid = items[i].current_bid + 1;
                /* Reset item */
                strcpy(items[i].name, "");
                strcpy(items[i].desc, "");
                items[i].current_bid = new_starting_bid;
                items[i].bidder_idx = -1;
                items[i].bid_time = rand() % 180 + 60;
            } else {
                items[i].bid_time--;
            }
        }
    }

    return 0;
}