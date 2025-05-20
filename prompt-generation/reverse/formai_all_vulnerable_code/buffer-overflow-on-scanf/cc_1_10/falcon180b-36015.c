//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main() {
    int n, i, j, k, max, pos;
    int arr[MAX];
    int coin[MAX];
    int count[MAX];
    int sum[MAX];

    // Get the number of coins from the user
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    // Get the value of each coin from the user
    printf("Enter the value of each coin: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }

    // Get the number of items from the user
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Get the value of each item from the user
    printf("Enter the value of each item: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize the count array
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Initialize the sum array
    for (i = 0; i < n; i++) {
        sum[i] = 0;
    }

    // Initialize the maximum value
    max = 0;

    // Find the maximum value of the items
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Initialize the position of the last coin
    pos = n - 1;

    // Initialize the value of the last coin
    max = coin[pos];

    // Initialize the value of the sum
    sum[n - 1] = max;

    // Initialize the value of the count
    count[n - 1] = 1;

    // Initialize the position of the last coin
    pos--;

    // Find the minimum number of coins required to make the given amount
    for (i = n - 2; i >= 0; i--) {
        while (sum[i] + coin[pos] <= arr[i]) {
            sum[i] += coin[pos];
            count[i]++;
            pos--;
        }
    }

    // Print the minimum number of coins required to make the given amount
    printf("The minimum number of coins required to make the given amount is: %d\n", count[0]);

    return 0;
}