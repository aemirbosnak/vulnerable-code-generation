//FormAI DATASET v1.0 Category: Digital Auction System ; Style: realistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct auction_item {
    char name[30];
    char bidder[30];
    int price;
};

int main() {
    int choice, num_items = 0, i, j, max_bid, max_bid_index;
    struct auction_item *items = NULL;

    printf("Welcome to the Digital Auction System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add item\n");
        printf("2. Bid on item\n");
        printf("3. Show current items\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                items = realloc(items, (num_items + 1) * sizeof(struct auction_item));
                printf("Enter item name: ");
                scanf("%s", items[num_items].name);
                items[num_items].price = 0;
                items[num_items].bidder[0] = '\0';
                printf("Item added successfully!\n");
                num_items++;
                break;
            case 2:
                printf("Enter item number to bid on: ");
                scanf("%d", &i);
                i--;
                if (i < 0 || i >= num_items) {
                    printf("Invalid item number!\n");
                    break;
                }
                printf("Enter bid amount: ");
                scanf("%d", &max_bid);
                if (max_bid <= items[i].price) {
                    printf("Bid amount too low!\n");
                    break;
                }
                strcpy(items[i].bidder, "You");
                items[i].price = max_bid;
                printf("Bid successful!\n");
                break;
            case 3:
                printf("Current items:\n");
                printf("Name\tBidder\tPrice\n");
                for (i = 0; i < num_items; i++) {
                    printf("%s\t%s\t%d\n", items[i].name, items[i].bidder, items[i].price);
                }
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        // Update highest bidder
        max_bid = -1;
        max_bid_index = -1;
        for (i = 0; i < num_items; i++) {
            if (items[i].bidder[0] != '\0') {
                if (items[i].price > max_bid) {
                    max_bid = items[i].price;
                    max_bid_index = i;
                }
            }
        }
        if (max_bid_index != -1) {
            printf("Highest bidder for %s is %s with a bid of %d\n", items[max_bid_index].name, items[max_bid_index].bidder, items[max_bid_index].price);
        } else {
            printf("No items have been bid on yet.\n");
        }
    }

    free(items);
    return 0;
}