//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_COINS 10000
#define MAX_VALUES 1000

int main() {
    srand(time(NULL));

    int num_coins = rand() % MAX_COINS + 1;
    int *values = malloc(num_coins * sizeof(int));
    for (int i = 0; i < num_coins; i++) {
        values[i] = rand() % MAX_VALUES + 1;
    }

    printf("Welcome to the Greedy Coin Collector!\n");
    printf("You have %d coins to collect.\n", num_coins);
    printf("Each coin has a value between 1 and %d.\n", MAX_VALUES);

    int max_value = values[0];
    for (int i = 1; i < num_coins; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    int max_coins = num_coins;
    int num_collected = 0;

    while (num_collected < num_coins) {
        int best_value = 0;
        int best_index = -1;

        for (int i = 0; i < num_coins; i++) {
            if (values[i] > best_value && values[i] <= max_value - num_collected) {
                best_value = values[i];
                best_index = i;
            }
        }

        if (best_index == -1) {
            printf("You have collected all the coins!\n");
            break;
        }

        max_value -= best_value;
        num_collected++;

        printf("You collected a coin worth %d.\n", best_value);
    }

    printf("You collected %d coins with a total value of %d.\n", num_collected, max_value);

    return 0;
}