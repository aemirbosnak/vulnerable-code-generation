//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_ITEMS 100
#define NAME_LEN 50
#define DESCRIPTION_LEN 200

typedef struct {
    char name[NAME_LEN];
    float bid_amount;
} User;

typedef struct {
    char item_name[NAME_LEN];
    char description[DESCRIPTION_LEN];
    float starting_price;
    float current_price;
    int highest_bidder_index;
    int is_open;
} AuctionItem;

User users[MAX_USERS];
AuctionItem items[MAX_ITEMS];
int user_count = 0;
int item_count = 0;

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached! Cannot register more users.\n");
        return;
    }
    printf("Enter your name: ");
    scanf("%s", users[user_count].name);
    users[user_count].bid_amount = 0;
    user_count++;
    printf("User %s registered successfully!\n", users[user_count - 1].name);
}

void list_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Item limit reached! Cannot add more items.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", items[item_count].item_name);
    printf("Enter item description: ");
    getchar(); // clear newline character
    fgets(items[item_count].description, DESCRIPTION_LEN, stdin);
    printf("Enter starting price: ");
    scanf("%f", &items[item_count].starting_price);

    items[item_count].current_price = items[item_count].starting_price;
    items[item_count].highest_bidder_index = -1;
    items[item_count].is_open = 1;
    item_count++;
    printf("Item %s listed successfully!\n", items[item_count - 1].item_name);
}

void place_bid() {
    char item_name[NAME_LEN];
    printf("Enter the name of the item you want to bid on: ");
    scanf("%s", item_name);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].item_name, item_name) == 0 && items[i].is_open) {
            float bid_amount;
            printf("Current Price: %.2f, Enter your bid amount: ", items[i].current_price);
            scanf("%f", &bid_amount);
            if (bid_amount > items[i].current_price) {
                items[i].current_price = bid_amount;
                items[i].highest_bidder_index = user_count - 1; // assume last registered user is bidding
                printf("Bid of %.2f placed successfully!\n", bid_amount);
                return;
            } else {
                printf("Bid must be higher than the current price!\n");
                return;
            }
        }
    }
    printf("Item not found or auction is closed.\n");
}

void close_auction() {
    char item_name[NAME_LEN];
    printf("Enter the name of the item to close auction: ");
    scanf("%s", item_name);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].item_name, item_name) == 0 && items[i].is_open) {
            items[i].is_open = 0;
            if (items[i].highest_bidder_index != -1) {
                printf("Auction closed! Congratulations %s, you won the item %s for %.2f!\n", 
                        users[items[i].highest_bidder_index].name, 
                        items[i].item_name, 
                        items[i].current_price);
            } else {
                printf("Auction closed! No bids were placed on the item %s.\n", items[i].item_name);
            }
            return;
        }
    }
    printf("Item not found or auction is already closed.\n");
}

void display_menu() {
    printf("\n === Digital Auction System === \n");
    printf("1. Register User\n");
    printf("2. List Item for Auction\n");
    printf("3. Place Bid\n");
    printf("4. Close Auction\n");
    printf("5. Exit\n");
    printf("==============================\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                list_item();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                close_auction();
                break;
            case 5:
                printf("Exiting the Auction System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}