//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int price;
    int bid;
} Item;

Item items[] = {
    {"Painting", 1000, 0},
    {"Sculpture", 2000, 0},
    {"Vase", 3000, 0},
    {"Rug", 4000, 0},
    {"Lamp", 5000, 0},
};

int num_items = sizeof(items) / sizeof(Item);

int main() {
    int choice;
    int bid;
    int winner;
    int highest_bid;

    do {
        printf("Welcome to the Digital Auction System!\n");
        printf("1. View items\n");
        printf("2. Place a bid\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Items:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%s: $%d\n", items[i].name, items[i].price);
                }
                break;
            case 2:
                printf("Enter the item number you want to bid on: ");
                scanf("%d", &choice);
                choice--;
                if (choice < 0 || choice >= num_items) {
                    printf("Invalid item number.\n");
                } else {
                    printf("Enter your bid: ");
                    scanf("%d", &bid);
                    if (bid <= items[choice].price) {
                        printf("Your bid must be higher than the current price.\n");
                    } else {
                        items[choice].bid = bid;
                        printf("Your bid has been placed.\n");
                    }
                }
                break;
            case 3:
                highest_bid = 0;
                winner = -1;
                for (int i = 0; i < num_items; i++) {
                    if (items[i].bid > highest_bid) {
                        highest_bid = items[i].bid;
                        winner = i;
                    }
                }
                if (winner == -1) {
                    printf("No bids have been placed.\n");
                } else {
                    printf("The winner is %s with a bid of $%d.\n", items[winner].name, items[winner].bid);
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}