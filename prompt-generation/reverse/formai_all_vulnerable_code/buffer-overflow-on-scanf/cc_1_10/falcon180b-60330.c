//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 5

typedef struct {
    char name[50];
    double price;
    int id;
} Item;

void print_item(Item* item) {
    printf("Name: %s\n", item->name);
    printf("Price: $%.2f\n", item->price);
    printf("ID: %d\n\n", item->id);
}

int main() {
    srand(time(0));

    Item items[NUM_ITEMS];

    // Initialize items
    for (int i = 0; i < NUM_ITEMS; i++) {
        items[i].id = i + 1;
        sprintf(items[i].name, "Item %d", i + 1);
        items[i].price = rand() % 100 + 1;
    }

    // Print initial items
    printf("Initial Items:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        print_item(&items[i]);
    }

    // Start auction
    int current_item = 0;
    double current_price = items[current_item].price;

    while (current_price > 0) {
        printf("\nCurrent Item: %s\n", items[current_item].name);
        printf("Current Price: $%.2f\n", current_price);

        char input[50];
        scanf("%s", input);

        if (strcmp(input, "bid") == 0) {
            double bid_amount;
            scanf("%lf", &bid_amount);

            if (bid_amount > current_price) {
                current_price = bid_amount;
            } else {
                printf("Invalid bid amount.\n");
            }
        } else if (strcmp(input, "buy") == 0) {
            if (current_price <= 0) {
                printf("Item already sold.\n");
            } else {
                printf("You bought the item for $%.2f!\n", current_price);
                current_price = 0;
            }
        } else {
            printf("Invalid input.\n");
        }

        if (current_price <= 0) {
            current_item++;
            if (current_item >= NUM_ITEMS) {
                break;
            }
            current_price = items[current_item].price;
        }
    }

    return 0;
}