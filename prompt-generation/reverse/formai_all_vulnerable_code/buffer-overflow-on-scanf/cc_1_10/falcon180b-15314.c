//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COINS 6
#define MAX_VALUES 6

int values[MAX_VALUES] = {1, 5, 10, 25, 50, 100};
int dp[MAX_VALUES + 1][MAX_COINS + 1] = {0};

void initialize() {
    int i, j;
    for (i = 0; i <= MAX_VALUES; i++) {
        dp[i][0] = 0;
    }
    for (i = 0; i <= MAX_COINS; i++) {
        dp[0][i] = 0;
    }
}

int max_coins(int value, int nCoins) {
    int i;
    if (value == 0) {
        return 0;
    }
    if (nCoins == 0) {
        return 0;
    }
    if (dp[value][nCoins]!= 0) {
        return dp[value][nCoins];
    }
    for (i = 1; i <= MAX_COINS; i++) {
        if (values[i] <= value) {
            if (dp[value - values[i]][nCoins - 1] + 1 > dp[value][nCoins]) {
                dp[value][nCoins] = dp[value - values[i]][nCoins - 1] + 1;
            }
        }
    }
    return dp[value][nCoins];
}

int main() {
    srand(time(0));
    int i, j, nCoins, value;
    printf("Enter the number of coins: ");
    scanf("%d", &nCoins);
    printf("Enter the values of the coins:\n");
    for (i = 1; i <= MAX_COINS; i++) {
        scanf("%d", &values[i]);
    }
    printf("Enter the value to be paid:\n");
    scanf("%d", &value);
    initialize();
    int maxCoins = max_coins(value, nCoins);
    printf("The maximum number of coins required to pay %d is %d.\n", value, maxCoins);
    return 0;
}