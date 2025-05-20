//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_ITEMS 5

int num_coins = 0;
int coins[MAX_COINS];
int num_items = 0;
int items[MAX_ITEMS];
int num_selected = 0;
int selected_items[MAX_ITEMS];

int main() {
    // Initialize coins and items
    coins[0] = 1;
    coins[1] = 5;
    coins[2] = 10;
    coins[3] = 25;
    coins[4] = 50;
    coins[5] = 100;

    items[0] = 1;
    items[1] = 5;
    items[2] = 10;
    items[3] = 25;
    items[4] = 50;

    // Initialize num_selected and selected_items
    num_selected = 0;
    selected_items[0] = 0;

    // Prompt user for number of items to select
    printf("Enter number of items to select: ");
    scanf("%d", &num_selected);

    // Prompt user for selected items
    printf("Enter selected items (0-4): ");
    for (int i = 0; i < num_selected; i++) {
        scanf("%d", &selected_items[i]);
    }

    // Initialize variables for greedy algorithm
    int total_value = 0;
    int current_coin = 0;

    // Greedy algorithm to minimize number of coins
    for (int i = 0; i < num_selected; i++) {
        int item_value = items[selected_items[i]];
        while (current_coin < MAX_COINS && coins[current_coin] <= item_value) {
            current_coin++;
        }
        total_value += coins[current_coin];
    }

    printf("Total value: %d\n", total_value);

    return 0;
}