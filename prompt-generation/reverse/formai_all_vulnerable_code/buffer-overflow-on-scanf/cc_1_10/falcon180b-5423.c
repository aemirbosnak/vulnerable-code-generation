//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_COINS 1000
#define MAX_ITEMS 100
#define MAX_VALUE 1000

// Function to find the maximum value that can be obtained
int findMaxValue(int* items, int n, int* coins, int m, int W) {
    int i, j, max_val = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (items[i] <= coins[j]) {
                int temp_val = items[i] + findMaxValue(items + i + 1, n - i - 1, coins + j + 1, m - j - 1, W - items[i]);
                if (temp_val > max_val) {
                    max_val = temp_val;
                }
            }
        }
    }
    return max_val;
}

// Function to print the items selected
void printItems(int* items, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", items[i]);
    }
    printf("\n");
}

// Function to generate random items and their values
void generateItems(int* items, int n) {
    int i;
    srand(time(0));
    for (i = 0; i < n; i++) {
        items[i] = rand() % MAX_VALUE;
    }
}

// Function to generate random coins and their values
void generateCoins(int* coins, int m) {
    int i;
    srand(time(0));
    for (i = 0; i < m; i++) {
        coins[i] = rand() % MAX_VALUE;
    }
}

// Function to find the maximum value that can be obtained using greedy algorithm
int greedy(int* items, int n, int* coins, int m, int W) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (items[i] <= coins[j]) {
                return items[i] + greedy(items + i + 1, n - i - 1, coins + j + 1, m - j - 1, W - items[i]);
            }
        }
    }
    return 0;
}

int main() {
    int i, n, m, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight limit: ");
    scanf("%d", &W);
    int items[n];
    generateItems(items, n);
    printf("The items and their values are:\n");
    printItems(items, n);
    printf("Enter the number of coins: ");
    scanf("%d", &m);
    int coins[m];
    generateCoins(coins, m);
    printf("The coins and their values are:\n");
    printItems(coins, m);
    int max_val = findMaxValue(items, n, coins, m, W);
    printf("The maximum value that can be obtained is: %d\n", max_val);
    int max_val_greedy = greedy(items, n, coins, m, W);
    printf("The maximum value that can be obtained using greedy algorithm is: %d\n", max_val_greedy);
    return 0;
}