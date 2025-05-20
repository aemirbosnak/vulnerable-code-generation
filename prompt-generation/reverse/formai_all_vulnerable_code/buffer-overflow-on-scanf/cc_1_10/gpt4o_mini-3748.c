//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_BID_HISTORY 100

typedef struct {
    int id;
    char name[50];
    float starting_price;
    float current_price;
    int highest_bidder_id;
    int active; // 1 for active, 0 for closed
} Item;

typedef struct {
    int bidder_id;
    float bid_amount;
} Bid;

Item items[MAX_ITEMS];
Bid bid_history[MAX_BID_HISTORY];
int item_count = 0;
int bid_count = 0;

void add_item(char *name, float starting_price) {
    if (item_count < MAX_ITEMS) {
        items[item_count].id = item_count + 1;
        strcpy(items[item_count].name, name);
        items[item_count].starting_price = starting_price;
        items[item_count].current_price = starting_price;
        items[item_count].highest_bidder_id = 0;
        items[item_count].active = 1;
        item_count++;
        printf("Item '%s' added with starting price %.2f\n", name, starting_price);
    } else {
        printf("Error: Max item limit reached\n");
    }
}

void place_bid(int item_id, int bidder_id, float bid_amount) {
    if (item_id > 0 && item_id <= item_count && items[item_id - 1].active) {
        if (bid_amount > items[item_id - 1].current_price) {
            items[item_id - 1].current_price = bid_amount;
            items[item_id - 1].highest_bidder_id = bidder_id;
            bid_history[bid_count].bidder_id = bidder_id;
            bid_history[bid_count].bid_amount = bid_amount;
            bid_count++;
            printf("Bid of %.2f placed by bidder %d for item '%s'\n",
                   bid_amount, bidder_id, items[item_id - 1].name);
        } else {
            printf("Error: Bid must be higher than current price %.2f\n",
                   items[item_id - 1].current_price);
        }
    } else {
        printf("Error: Item not found or auction closed\n");
    }
}

void display_items() {
    printf("\n=== Current Auction Items ===\n");
    for (int i = 0; i < item_count; i++) {
        printf("Item ID: %d, Name: %s, Starting Price: %.2f, Current Price: %.2f, Highest Bidder: %d\n",
               items[i].id, items[i].name, items[i].starting_price,
               items[i].current_price, items[i].highest_bidder_id);
    }
}

void close_auction(int item_id) {
    if (item_id > 0 && item_id <= item_count) {
        items[item_id - 1].active = 0;
        printf("Auction for item '%s' closed. Final Price: %.2f\n",
               items[item_id - 1].name, items[item_id - 1].current_price);
    } else {
        printf("Error: Item not found\n");
    }
}

int main() {
    char command[50];
    int id, bidder_id;
    float price;
    
    printf("Welcome to the Digital Auction System!\n");
    
    while (1) {
        printf("\nCommands: add, bid, display, close, exit\n");
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char item_name[50];
            printf("Enter item name: ");
            scanf("%s", item_name);
            printf("Enter starting price: ");
            scanf("%f", &price);
            add_item(item_name, price);
        } else if (strcmp(command, "bid") == 0) {
            printf("Enter item ID: ");
            scanf("%d", &id);
            printf("Enter bidder ID: ");
            scanf("%d", &bidder_id);
            printf("Enter bid amount: ");
            scanf("%f", &price);
            place_bid(id, bidder_id, price);
        } else if (strcmp(command, "display") == 0) {
            display_items();
        } else if (strcmp(command, "close") == 0) {
            printf("Enter item ID to close auction: ");
            scanf("%d", &id);
            close_auction(id);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the system. Goodbye!\n");
            break;
        } else {
            printf("Error: Unknown command\n");
        }
    }
    
    return 0;
}