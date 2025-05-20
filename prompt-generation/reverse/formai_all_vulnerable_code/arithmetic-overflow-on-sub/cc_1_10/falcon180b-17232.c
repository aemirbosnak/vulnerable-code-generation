//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000

// Function to find the maximum profit that can be obtained
int findMaxProfit(int *profit, int n) {
    int maxProfit = 0;
    int currentProfit = 0;

    // Iterate through the array and calculate the maximum profit
    for (int i = 0; i < n; i++) {
        currentProfit += profit[i];
        if (currentProfit < 0) {
            currentProfit = 0;
        }
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
        }
    }

    return maxProfit;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Initialize the profit array with random values
    int profit[n];
    for (int i = 0; i < n; i++) {
        profit[i] = rand() % MAX_NUM;
    }

    // Sort the profit array in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (profit[i] > profit[j]) {
                int temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    // Find the maximum profit that can be obtained
    int maxProfit = findMaxProfit(profit, n);

    // Print the result
    printf("The maximum profit that can be obtained is: %d\n", maxProfit);

    return 0;
}