//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_COINS 6

typedef struct {
    int value;
    char name[10];
} Coin;

void generateRandomCoins(Coin coins[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        coins[i].value = rand() % 101;
        sprintf(coins[i].name, "Coin %d", i + 1);
    }
}

int compareCoins(const void *a, const void *b) {
    return (*(Coin *)a).value - (*(Coin *)b).value;
}

void printCoins(Coin coins[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", coins[i].name, coins[i].value);
    }
}

int main() {
    Coin coins[MAX_COINS];
    int n;

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    if (n > MAX_COINS) {
        printf("Error: Too many coins.\n");
        return 1;
    }

    generateRandomCoins(coins, n);

    qsort(coins, n, sizeof(Coin), compareCoins);

    printf("Sorted by value:\n");
    printCoins(coins, n);

    return 0;
}