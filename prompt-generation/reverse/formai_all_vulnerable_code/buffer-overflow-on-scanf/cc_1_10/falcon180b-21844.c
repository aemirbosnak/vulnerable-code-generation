//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_VALUES 50

int values[MAX_VALUES];
int coins[MAX_COINS];
int n, m;

void generate_values() {
    for (int i = 0; i < n; i++) {
        values[i] = rand() % 1000;
    }
}

void generate_coins() {
    coins[0] = 1;
    for (int i = 1; i < m; i++) {
        coins[i] = coins[i-1] * 2;
    }
}

int main() {
    printf("Enter number of values: ");
    scanf("%d", &n);
    printf("Enter number of coins: ");
    scanf("%d", &m);

    generate_values();
    generate_coins();

    int max_value = values[0];
    for (int i = 1; i < n; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    int sum = 0;
    int coins_used = 0;

    for (int i = m-1; i >= 0; i--) {
        while (sum + coins[i] <= max_value) {
            sum += coins[i];
            coins_used++;
        }
    }

    printf("Minimum number of coins required: %d\n", coins_used);

    return 0;
}