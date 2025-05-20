//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include <stdio.h>

// defining the maximum number of coins
#define MAX_COINS 100

// function to perform selection sort
void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    // declaring and initializing variables
    int n, i, sum = 0;
    int coins[MAX_COINS];
    
    // taking input from the user
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    printf("Enter the values of coins:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    printf("Enter the desired sum: ");
    scanf("%d", &sum);
    
    // performing greedy algorithm
    selection_sort(coins, n);
    int count = 0, j = n - 1;
    while (sum > 0 && j >= 0) {
        if (sum >= coins[j]) {
            sum -= coins[j];
            count++;
        }
        else {
            j--;
        }
    }
    
    // printing the result
    if (sum == 0) {
        printf("Minimum number of coins required: %d\n", count);
    }
    else {
        printf("Sum cannot be obtained from the given coins.\n");
    }
    
    return 0;
}