//FormAI DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[100];
    double current_bid;
    char bidder[100];
};

void show_items(struct item items[]);
void place_bid(struct item items[], int item_number, char bidder[], double bid);
void show_winner(struct item items[], int item_number);

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    while (1) {
        printf("\nEnter an option:\n");
        printf("1. Add item\n");
        printf("2. Show items\n");
        printf("3. Place bid\n");
        printf("4. Show winner\n");
        printf("5. Exit\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            // Add item
            if (num_items == MAX_ITEMS) {
                printf("Maximum number of items reached.\n");
            } else {
                printf("Enter name for item: ");
                scanf("%s", items[num_items].name);

                items[num_items].current_bid = 0;
                items[num_items].bidder[0] = '\0';

                num_items++;
                printf("Item added successfully.\n");
            }

        } else if (option == 2) {
            // Show items
            show_items(items);

        } else if (option == 3) {
            // Place bid
            int item_number;
            printf("Enter item number: ");
            scanf("%d", &item_number);

            if (item_number < 0 || item_number >= num_items) {
                printf("Invalid item number.\n");
            } else {
                char bidder[100];
                printf("Enter bidder name: ");
                scanf("%s", bidder);

                double bid;
                printf("Enter bid amount: ");
                scanf("%lf", &bid);

                place_bid(items, item_number, bidder, bid);
                printf("Bid placed successfully.\n");
            }

        } else if (option == 4) {
            // Show winner
            int item_number;
            printf("Enter item number: ");
            scanf("%d", &item_number);

            if (item_number < 0 || item_number >= num_items) {
                printf("Invalid item number.\n");
            } else if (items[item_number].bidder[0] == '\0') {
                printf("No bid has been placed on this item.\n");
            } else {
                show_winner(items, item_number);
            }

        } else if (option == 5) {
            // Exit
            printf("Goodbye!\n");
            break;

        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}

void show_items(struct item items[]) {
    printf("Items:\n");
    printf("%-4s %-30s %-15s %-10s\n", "No.", "Name", "Current Bid", "Bidder");
    
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%-4d %-30s $%-14.2lf %-10s\n", i, items[i].name, items[i].current_bid, items[i].bidder);
        }
    }
}

void place_bid(struct item items[], int item_number, char bidder[], double bid) {
    if (bid <= items[item_number].current_bid) {
        printf("Bid must be higher than current bid.\n");
    } else {
        items[item_number].current_bid = bid;
        strncpy(items[item_number].bidder, bidder, 99);
        items[item_number].bidder[99] = '\0'; // Ensure it is null-terminated
    }
}

void show_winner(struct item items[], int item_number) {
    printf("Winner of item \"%s\" is %s with a bid of $%.2lf.\n", items[item_number].name, items[item_number].bidder, items[item_number].current_bid);
}