//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to find the maximum value in an array
int max(int arr[], int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

// Function to implement the greedy algorithm
int greedy_algorithm(int arr[], int size, int num_coins) {
    int i = size - 1;
    while (i >= 0 && num_coins > 0) {
        if (arr[i] <= num_coins) {
            num_coins -= arr[i];
            i--;
        } else {
            i--;
        }
    }
    return i + 1;
}

int main() {
    int arr[MAX_SIZE];
    int size, num_coins;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the number of coins from the user
    printf("Enter the number of coins: ");
    scanf("%d", &num_coins);

    // Find the maximum value in the array
    int max_val = max(arr, size);

    // Calculate the minimum number of coins required to make the maximum value
    int min_coins = max_val;
    for (int i = 0; i < size; i++) {
        if (arr[i] <= max_val) {
            min_coins = min_coins - arr[i];
        }
    }

    // Calculate the maximum number of coins that can be made using the greedy algorithm
    int max_coins = max_val * num_coins;

    // Implement the greedy algorithm
    int coins_made = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] <= num_coins) {
            coins_made += arr[i];
            num_coins -= arr[i];
        }
    }

    // Print the results
    printf("Minimum number of coins required: %d\n", min_coins);
    printf("Maximum number of coins that can be made: %d\n", max_coins);
    printf("Number of coins made using the greedy algorithm: %d\n", coins_made);

    return 0;
}