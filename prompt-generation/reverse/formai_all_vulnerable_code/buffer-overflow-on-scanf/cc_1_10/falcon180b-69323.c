//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COINS 6

void generateRandomCoins(int coins[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        coins[i] = rand() % 101;
    }
}

int main() {
    int coins[MAX_COINS];
    int n;

    printf("Enter the number of coins (between 1 and %d): ", MAX_COINS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_COINS) {
        printf("Invalid number of coins.\n");
        return 1;
    }

    generateRandomCoins(coins, n);

    printf("The coins are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");

    int maxValue = coins[0];
    for (int i = 1; i < n; i++) {
        if (coins[i] > maxValue) {
            maxValue = coins[i];
        }
    }

    printf("The maximum value is %d.\n", maxValue);

    int totalValue = 0;
    for (int i = 0; i < n; i++) {
        totalValue += coins[i];
    }

    printf("The total value is %d.\n", totalValue);

    return 0;
}