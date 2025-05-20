//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 10
#define MAX_NUMBERS 100

void sort_array(int arr[], int n) {
    // Simple Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void input_numbers(int player_id, int numbers[], int *count) {
    int n;
    printf("Player %d, how many numbers do you want to enter? (max %d) ", player_id, MAX_NUMBERS);
    scanf("%d", &n);
    
    if (n > MAX_NUMBERS) {
        printf("You can only enter a maximum of %d numbers.\n", MAX_NUMBERS);
        n = MAX_NUMBERS; // Limit the input
    }

    printf("Enter your numbers (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[*count + i]);
    }
    *count += n; // Update the total count of numbers
}

int main() {
    int players, numbers[MAX_PLAYERS * MAX_NUMBERS], total_numbers = 0;

    printf("Welcome to the Multiplayer Sorting Game!\n");
    printf("How many players will participate? (max %d) ", MAX_PLAYERS);
    scanf("%d", &players);

    if (players > MAX_PLAYERS) {
        printf("Maximum number of players is %d. Setting to maximum.\n", MAX_PLAYERS);
        players = MAX_PLAYERS; // Limit the input
    }

    for (int i = 1; i <= players; i++) {
        input_numbers(i, numbers, &total_numbers);
    }

    printf("Sorting %d numbers...\n", total_numbers);
    sort_array(numbers, total_numbers);

    printf("Sorted numbers: ");
    for (int i = 0; i < total_numbers; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}