//Falcon-180B DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_TRIES 10

int main() {
    int i, j, num_tries = 0;
    int arr[MAX_SIZE];
    int size;
    int sum = 0;
    double mean, variance;
    char choice;

    // Seed random number generator
    srand(time(NULL));

    // Get array size from user
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Fill array with random numbers
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Calculate mean and variance
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    mean = (double)sum / size;
    for (i = 0; i < size; i++) {
        variance += pow((arr[i] - mean), 2);
    }
    variance /= size;

    // Print results
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);

    // Ask user if they want to continue
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        int num;

        // Get number of tries from user
        printf("Enter the number of tries (maximum %d): ", MAX_TRIES);
        scanf("%d", &num_tries);

        // Simulate coin flips
        int heads = 0;
        for (i = 0; i < num_tries; i++) {
            if (rand() % 2 == 0) {
                heads++;
            }
        }

        // Print results
        printf("Number of heads: %d\n", heads);
        printf("Percentage of heads: %.2f%%\n", (double)heads / num_tries * 100);
    }

    return 0;
}