//FormAI DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LEN 20

typedef struct {
    char item_name[ITEM_NAME_LEN];
    int starting_price;
    int current_bid;
    char last_bidder_name[ITEM_NAME_LEN];
} item_t;

void display_menu();
void display_items(item_t items[], int count);
void add_item(item_t items[], int* count);
void bid_item(item_t* item);
int get_random_number(int min, int max);

int main() {
    srand(time(0));
    item_t items[MAX_ITEMS];
    int count = 0;
    char choice;

    while (1) {
        display_menu();
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                display_items(items, count);
                break;
            case '2':
                add_item(items, &count);
                break;
            case '3':
                if (count == 0) {
                    printf("No items available.\n");
                }
                else {
                    int item_index;
                    printf("Enter item number (1 - %d): ", count);
                    scanf("%d", &item_index);
                    if (item_index < 1 || item_index > count) {
                        printf("Invalid item number.\n");
                    }
                    else {
                        bid_item(&items[item_index-1]);
                    }
                }
                break;
            case '4':
                printf("Thanks for using our auction system. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\nAuction System\n");
    printf("---------------\n");
    printf("1. View items\n");
    printf("2. Add item\n");
    printf("3. Bid item\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void display_items(item_t items[], int count) {
    if (count == 0) {
        printf("No items available.\n");
    }
    else {
        printf("Item No.  Item Name           Starting Price  Current Bid    Last Bidder Name\n");
        printf("-------  ------------------  --------------  --------------  ------------------\n");
        for (int i = 0; i < count; i++) {
            printf("%-9d%-20s%-16d%-16d%-20s\n", i+1, items[i].item_name, items[i].starting_price, items[i].current_bid, items[i].last_bidder_name);
        }
    }
}

void add_item(item_t items[], int* count) {
    if (*count == MAX_ITEMS) {
        printf("Maximum items reached. Cannot add more items.\n");
        return;
    }

    item_t new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.item_name);
    printf("Enter starting price: ");
    scanf("%d", &new_item.starting_price);
    new_item.current_bid = new_item.starting_price;
    strcpy(new_item.last_bidder_name, "-");
    items[*count] = new_item;
    (*count)++;
}

void bid_item(item_t* item) {
    int bid_amount;
    char bidder_name[ITEM_NAME_LEN];
    printf("Enter bid amount: ");
    scanf("%d", &bid_amount);
    if (bid_amount <= item->current_bid) {
        printf("Bid amount must be higher than current bid.\n");
        return;
    }
    printf("Enter your name: ");
    scanf("%s", bidder_name);
    item->current_bid = bid_amount;
    strcpy(item->last_bidder_name, bidder_name);
    printf("Congratulations! You have the highest bid.\n");
}

int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}