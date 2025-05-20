//FormAI DATASET v1.0 Category: Digital Auction System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
#define MAX_BIDS 5 // Maximum number of bids for a single item
#define MAX_ITEMS 10 // Maximum number of items in the auction
 
struct Item {
    char name[50];
    int current_bid;
    char highest_bidder[50];
    int num_bids;
    int bids[MAX_BIDS];
};
 
int main() {
    struct Item items[MAX_ITEMS];
    int num_items = 0;
    int choice;
    srand(time(NULL)); // Seed the random number generator
 
    while(1) {
        printf("--------------------\n");
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Bid on Item\n");
        printf("4. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch(choice) {
            case 1: {
                // Add a new item to the auction
                printf("Enter the name of the item: ");
                scanf("%s", items[num_items].name);
                items[num_items].current_bid = rand() % 100;
                strcpy(items[num_items].highest_bidder, "None");
                items[num_items].num_bids = 0;
                num_items++;
                printf("Item added successfully!\n");
                break;
            }
            case 2: {
                // List all the items in the auction
                if(num_items == 0) {
                    printf("No items in the auction.\n");
                } else {
                    printf("Name\tCurrent Bid\tHighest Bidder\n");
                    for(int i = 0; i < num_items; i++) {
                        printf("%s\t%d\t\t%s\n", items[i].name, items[i].current_bid, items[i].highest_bidder);
                    }
                }
                break;
            }
            case 3: {
                // Bid on an item
                char item_name[50];
                int bid_amount;
                int item_index;
                printf("Enter the name of the item you want to bid on: ");
                scanf("%s", item_name);
 
                for(int i = 0; i < num_items; i++) {
                    if(strcmp(item_name, items[i].name) == 0) {
                        // Item found
                        item_index = i;
                        break;
                    } else if(i == num_items - 1) {
                        // Item not found
                        printf("Item not found.\n");
                        goto END;
                    }
                }
 
                printf("Enter your bid amount: ");
                scanf("%d", &bid_amount);
 
                if(bid_amount <= items[item_index].current_bid) {
                    printf("Bid must be greater than current bid.\n");
                    goto END;
                } else {
                    strcpy(items[item_index].highest_bidder, "John Doe"); // Set the highest bidder to the current bidder for simplicity. In real life, we would store bidder information separately.
                    items[item_index].num_bids++;
                    items[item_index].current_bid = bid_amount;
                    items[item_index].bids[items[item_index].num_bids - 1] = bid_amount;
                    printf("Bid successful!\n");
                }
 
                END:
                break;
            }
            case 4: {
                // Exit the program
                printf("Goodbye!\n");
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
 
    return 0;
}