//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define NUM_ITEMS 5
#define COIN_SLOTS 4
#define MIN_COIN 1
#define MAX_COIN 2

typedef struct {
    char name[20];
    int price;
} Item;

Item items[NUM_ITEMS] = {
    {"Candy", 10},
    {"Chips", 20},
    {"Soda", 15},
    {"Gum", 5},
    {"Chocolate", 30}
};

int main() {
    int coin_slots[COIN_SLOTS] = {0};
    int selected_item = -1;
    int total_paid = 0;

    printf("Welcome to the Vending Machine!\n");

    while (selected_item < 0 || total_paid < items[selected_item].price) {
        printf("\nAvailable Items:\n");
        for (int i = 0; i < NUM_ITEMS; ++i) {
            printf("%d. %s - $%d\n", i + 1, items[i].name, items[i].price);
        }

        printf("\nInsert Coins: ");
        for (int i = 0; i < COIN_SLOTS; ++i) {
            int coin;
            scanf("%d", &coin);
            if (coin < MIN_COIN || coin > MAX_COIN) {
                printf("Invalid coin, please insert a valid coin.\n");
                i--;
                continue;
            }

            coin_slots[i] += coin;
            total_paid += coin;
        }

        printf("\nTotal Paid: $%d\n", total_paid);

        printf("\nSelect an Item: ");
        scanf("%d", &selected_item);

        if (selected_item < 0 || selected_item > NUM_ITEMS) {
            printf("Invalid selection, please select a valid item.\n");
            continue;
        }
    }

    int change = total_paid - items[selected_item].price;

    printf("\nItem Selected: %s\n", items[selected_item].name);
    printf("Total Paid: $%d\n", total_paid);
    printf("Change Due: $%d\n", change);

    return 0;
}