//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100
#define BUCKET_COUNT 10

void bucketSort(int arr[], int n);
void displayBuckets(int buckets[][MAX_NUMBERS], int bucketSizes[], int count);
void playGame(int playerCount);

int main() {
    int playerCount;

    printf("Welcome to the Bucket Sort Multiplayer Game!\n");
    printf("How many players are participating (1-10)? ");
    scanf("%d", &playerCount);

    if (playerCount < 1 || playerCount > 10) {
        printf("Invalid player count. Exiting game.\n");
        return 1;
    }

    playGame(playerCount);
    return 0;
}

void playGame(int playerCount) {
    int numbers[MAX_NUMBERS];
    int totalNumbers = 0;

    for (int i = 1; i <= playerCount; i++) {
        printf("\nPlayer %d, please enter up to %d numbers (enter -1 to stop): \n", i, MAX_NUMBERS);
        while (totalNumbers < MAX_NUMBERS) {
            int num;
            printf("Enter number (or -1 to finish): ");
            scanf("%d", &num);
            if (num == -1) {
                break;
            }
            if (num < 0) {
                printf("Please enter non-negative integers only.\n");
                continue;
            }
            numbers[totalNumbers++] = num;
        }
    }

    printf("\nNumbers entered by players: \n");
    for (int i = 0; i < totalNumbers; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    bucketSort(numbers, totalNumbers);
    printf("\nSorted numbers: \n");
    for (int i = 0; i < totalNumbers; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    int buckets[BUCKET_COUNT][MAX_NUMBERS];
    int bucketSizes[BUCKET_COUNT] = {0};

    int max_value = arr[0];
    int min_value = arr[0];

    // Find the max and min values for range
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }

    // Range of values in buckets
    int range = (max_value - min_value + 1) / BUCKET_COUNT + 1;

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min_value) / range;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort individual buckets and merge
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            // Sort this bucket using insertion sort
            for (int j = 0; j < bucketSizes[i]; j++) {
                int temp = buckets[i][j];
                int k = j - 1;

                while (k >= 0 && buckets[i][k] > temp) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = temp;
            }
            // Merge the sorted bucket back into arr
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}