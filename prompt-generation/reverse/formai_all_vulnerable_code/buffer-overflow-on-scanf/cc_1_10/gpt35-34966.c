//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_ITEM_COUNT 20

/*define a structure for Item*/
struct Item {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int bid;
};

/*function prototypes*/
void display_menu();
void add_item();
void remove_item();
void view_items();
void start_auction();

/*declare global variables*/
struct Item items[MAX_ITEM_COUNT];
int item_count = 0;

int main() {

    int choice;

    while(1) {
        display_menu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                view_items();
                break;
            case 4:
                start_auction();
                break;
            case 5:
                printf("\nThank you for using the Digital Auction System. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}

/*
 * display_menu - displays the main menu options
 */
void display_menu() {
    printf("\nDigital Auction System");
    printf("\n----------------------");
    printf("\n1. Add item");
    printf("\n2. Remove item");
    printf("\n3. View items");
    printf("\n4. Start auction");
    printf("\n5. Exit");
}

/*
 * add_item - allows the user to add an item to the auction list
 */
void add_item() {
    if(item_count >= MAX_ITEM_COUNT) {
        printf("\nMax number of items reached. Cannot add any more items.\n");
        return;
    }

    printf("\nEnter item name: ");
    scanf("%s", items[item_count].name);

    printf("\nEnter item description: ");
    scanf("%s", items[item_count].description);

    printf("\nEnter starting bid: ");
    scanf("%d", &items[item_count].bid);

    item_count++;

    printf("\nItem added successfully!\n");
}

/*
 * remove_item - allows the user to remove an item from the auction list
 */
void remove_item() {
    int item_index, i;
    char item_name[MAX_NAME_LEN];

    if(item_count == 0) {
        printf("\nNo items in the list. Cannot remove any items.\n");
        return;
    }

    printf("\nEnter name of item: ");
    scanf("%s", item_name);

    for(i=0; i<item_count; i++) {
        if(strcmp(items[i].name, item_name) == 0) {
            item_index = i;
            break;
        }
    }

    if(i == item_count) {
        printf("\nItem not found!\n");
        return;
    }

    for(i=item_index; i<(item_count-1); i++) {
        strcpy(items[i].name, items[i+1].name);
        strcpy(items[i].description, items[i+1].description);
        items[i].bid = items[i+1].bid;
    }

    item_count--;

    printf("\nItem removed successfully!\n");
}

/*
 * view_items - displays the list of items in the auction
 */
void view_items() {
    int i;

    if(item_count == 0) {
        printf("\nNo items in the list.\n");
        return;
    }

    printf("\nList of items:");
    for(i=0; i<item_count; i++) {
        printf("\n%d. %s (%s) - starting bid: %d", (i+1), items[i].name, items[i].description, items[i].bid);
    }
    printf("\n");
}

/*
 * start_auction - starts the auction for all items in the list
 */
void start_auction() {
    int i, j, highest_bid;
    char bidder_name[MAX_NAME_LEN];
    struct Item temp;

    if(item_count == 0) {
        printf("\nNo items in the list. Cannot start auction.\n");
        return;
    }

    printf("\nStarting auction for all items...\n\n");

    for(i=0; i<item_count; i++) {
        printf("\nAuctioning item: %s (%s)", items[i].name, items[i].description);

        highest_bid = items[i].bid;

        while(1) {
            printf("\nEnter bidder name (or press q to exit): ");
            scanf("%s", bidder_name);

            if(strcmp(bidder_name, "q") == 0) {
                break;
            }

            printf("\nEnter bid amount: ");
            scanf("%d", &j);

            if(j > highest_bid) {
                highest_bid = j;
                strcpy(items[i].name, bidder_name);
            } else {
                printf("\nBid amount must be greater than the current highest bid.\n");
            }
        }

        printf("\n%s won the auction for %s with a bid of %d\n", items[i].name, items[i].description, highest_bid);

        /*sort the items array based on the highest bid*/
        for(j=0; j<item_count; j++) {
            for(i=0; i<(item_count-j-1); i++) {
                if(items[i].bid < items[i+1].bid) {
                    temp = items[i];
                    items[i] = items[i+1];
                    items[i+1] = temp;
                }
            }
        }
    }
}